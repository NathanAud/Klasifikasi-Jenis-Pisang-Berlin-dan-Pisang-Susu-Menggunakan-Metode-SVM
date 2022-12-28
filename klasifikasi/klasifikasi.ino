#include <LiquidCrystal_I2C.h>
#include "HX711.h"
#include "pca.h"
#include "svm.h"

enum Pin : byte
{
    s0 = 8,
    s1 = 9,
    s2 = 10,
    s3 = 11,
    out = 12,
    dout = 3,
    sck = 2,
    echo = 4,
    trig = 7,
    tombol = 5
};

enum Feature
{
    red, green, blue, berat, panjang, NUM_OF_FEATURES
};

LiquidCrystal_I2C lcd(0x27, 16, 2);

constexpr float mean[]{20.51851851851852, 33.55555555555556, 52.22222222222222, 52.22851851851852, 10.306666666666665};
constexpr float stdDev[]{11.209686189714647, 18.714884813437855, 30.15187892104132, 5.41559319530783, 0.6920393908720215};

HX711 scale;
constexpr float calibration_factor{422.036};

Eloquent::ML::Port::PCA pca;
Eloquent::ML::Port::SVM clf;


void setup()
{
    // init pin
    Pin inputs[]{out, echo};
    Pin outputs[]{s0, s1, s2, s3, trig, (Pin)LED_BUILTIN};
    for(Pin pin : inputs)
        pinMode(pin, INPUT);
    pinMode(tombol, INPUT_PULLUP);

    for(Pin pin : outputs)
        pinMode(pin, OUTPUT);

    // init LCD
    lcd.init();
    lcd.backlight();
    lcd.clear();

    // init serial
    Serial.begin(9600);
    
    // init HX711
    scale.begin(dout, sck);
    scale.set_scale(calibration_factor);
    scale.tare(); 


    // init TCS
    digitalWrite(s0, HIGH);
    digitalWrite(s1, LOW);

}

void loop()
{
    lcd.clear();
    lcd.print("Letakkan pisang,");
    lcd.setCursor(0,1);
    lcd.print("tekan tombol");
    while(digitalRead(tombol)) digitalWrite(LED_BUILTIN, digitalRead(tombol));

    lcd.clear();
    lcd.print("Processing....");

    // input
    float input[NUM_OF_FEATURES];

    input[red] = standardize(readColor(red), red);
    input[green] = standardize(readColor(green), green);
    input[blue] = standardize(readColor(blue), blue);
    input[berat] = standardize(readBerat(), berat);
    input[panjang] = standardize(readPanjang(), panjang);

    for(float i : input) {Serial.print(i); Serial.print('\t');}
    Serial.println();

    // pca
    pca.transform(input);
    for(float i : input) {Serial.print(i); Serial.print('\t');}
    Serial.println();

    // klasifikasi
    lcd.clear();
    lcd.print("Jenis Pisang:");
    lcd.setCursor(0,1);
    auto prediction{clf.predictLabel(input)};
    lcd.print(prediction);
    Serial.println(prediction);
    delay(5000);
}

float standardize(float nilai, Feature fitur)
{
    Serial.println(nilai);
    return (nilai-mean[fitur]) / stdDev[fitur];
}


long readColor(Feature color)
{
    long data{};
    switch(color)
    {
    case red:
        digitalWrite(s2,LOW);
        digitalWrite(s3,LOW);
        break;
    
    case green:
        digitalWrite(s2,HIGH);
        digitalWrite(s3,HIGH);
        break;

    case blue:
        digitalWrite(s2,LOW);
        digitalWrite(s3,HIGH);
        
    default:
        break;
    }
    for(int i{}; i<10; i++){
        data += pulseIn(out,LOW);
    }
    data /= 10;
    return data;
}


float readBerat()
{
    return scale.get_units(10);
}


float readPanjang()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
    
  return 15.83 - (pulseIn(echo, HIGH) / 29.0 / 2);
}