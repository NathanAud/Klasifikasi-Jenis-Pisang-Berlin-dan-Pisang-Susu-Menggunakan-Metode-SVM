#include "HX711.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

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
};

enum Color
{
    red, green, blue
};

HX711 scale;
constexpr float calibration_factor{422.036};

void setup()
{
    // init pin
    Pin inputs[]{out, echo};
    Pin outputs[]{s0, s1, s2, s3, trig};
    for(Pin pin : inputs)
        pinMode(pin, INPUT);
    
    for(Pin pin : outputs)
        pinMode(pin, OUTPUT);

    // init serial
    Serial.begin(9600);
    
    // init HX711
    scale.begin(dout, sck);
    scale.set_scale(calibration_factor);
    scale.tare(); 

    // init LCD
    lcd.init();
    lcd.backlight();
    lcd.clear();

    // init TCS
    digitalWrite(s0, HIGH);
    digitalWrite(s1, LOW);

    Serial.println("0: susu\t1:berlin");
    Serial.println("red,green,blue,berat,jarak,jenis");
}

void loop()
{
    while(!Serial.available()){
      lcd.clear();
      lcd.print(jarak());
      delay(1000);
    } ;
    char jenisPisang = Serial.read();

    printColor(red);
    Serial.print(",");
    printColor(green);
    Serial.print(",");
    printColor(blue);
    Serial.print(",");
    printBerat();
    Serial.print(",");
    printJarak();
    Serial.print(',');
    Serial.print(jenisPisang);
    Serial.println();
    
}


void printColor(Color color)
{
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
        break;

    default:
        break;
    }
    
    long data{};
    for(int i{}; i<10; i++){
        data += pulseIn(out,LOW);
    }
    data /= 10;

    Serial.print(data);
}

void printBerat()
{
    Serial.print(scale.get_units(10));
}

void printJarak()
{
    Serial.print(jarak());
}

float jarak()
{
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    return 15.83 - (pulseIn(echo, HIGH) / 29.0 / 2);
}