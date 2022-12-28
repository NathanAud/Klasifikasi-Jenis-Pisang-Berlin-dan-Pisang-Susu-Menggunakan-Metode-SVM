# Klasifikasi Jenis Pisang Berlin dan Pisang Susu Menggunakan Metode SVM

Sistem berbasis Arduino Uno untuk mengklasifikasikan pisang berlin dan pisang susu.

Sistem ini merupakan tugas akhir untuk mata kuliah Sistem Pengenalan Pola.

[Video Presentasi dan Demo Alat](https://www.youtube.com/watch?v=uouXQePehg0&t=2s)


## Deskripsi
Sistem ini berguna untuk mengklasifikasikan jenis pisang berlin dan pisang susu. Pisang diletakkan di atas sensor berat, berdekatan dengan sensor warna, dan menempel dengan tembok di depan sensor jarak. Saat pisang sudah di posisi, tombol hanya perlu ditekan untuk langsung menampilkan hasil klasifikasi pada LCD. 

Sistem menerima masukan fitur-fitur dari ketiga sensor. Lalu, dilakukan standardisasi dan Principal Component Analysis untuk mengurangi dimensi data (dan menambah nilai tugas akhir). Setelah itu, nilai-nilai hasil PCA dimasukkan ke model klasifikasi Support Vector Machine untuk mengklasifikasikannya ke salah satu dari kedua kelas. Terakhir, hasil klasifikasi dikeluarkan dan ditampilkan ke layar LCD. 

### Fitur
* Nilai bacaan sensor warna untuk warna merah*
* Nilai bacaan sensor warna untuk warna hijau*
* Nilai bacaan sensor warna untuk warna biru*
* Panjang Pisang
* Berat Pisang

*nilai bacaan sensor warna tidak dikonversi ke nilai RGB sungguhan.

### Kelas
* Pisang susu (direpresentasikan sebagai 0)
* Pisang berlin (direpresentasikan sebagai 1)


## Komponen
### Hardware
* Arduino Uno
* Sensor Warna TCS3200
* Sensor Ultrasonik HC-SR04
* Sensor Load Cell HX711
* Push Button
* LCD 16x2 dengan I2C

### Software
* Arduino IDE
* Python 3.10.8
* Library:
    * Arduino:
        * [LiquidCrystal I2C](https://github.com/johnrickman/LiquidCrystal_I2C)
        * [HX711 Arduino Library](https://github.com/bogde/HX711)
    * Python:
        * [matplotlib](https://matplotlib.org)
        * [pandas](https://pandas.pydata.org)
        * [scikit-learn](https://scikit-learn.org/)
        * [micromlgen](https://eloquentarduino.com/libraries/micromlgen/)