# ESP32-S3: Kontrol Servo Motor

Program ini menunjukkan cara mengendalikan **servo motor** menggunakan **ESP32-S3** dan pustaka **ESP32Servo.h**.  
Servo digunakan untuk mengatur sudut pergerakan secara presisi, misalnya untuk robotik, sistem kendali, atau aktuator mekanik kecil.  
Dalam program ini, servo akan bergerak secara otomatis dari 0° ke 180°, kemudian kembali ke 0°, dengan jeda waktu teratur.

## Deskripsi Singkat

Servo motor merupakan perangkat aktuator yang dapat bergerak ke sudut tertentu berdasarkan sinyal PWM (*Pulse Width Modulation*).  
ESP32-S3 dapat menghasilkan sinyal PWM melalui pin digital menggunakan pustaka **ESP32Servo**, yang membuat kendali servo menjadi sederhana.  
Pada contoh ini, servo dihubungkan ke pin **GPIO 17**, dan pergerakannya dikontrol dengan perintah `myServo.write()` untuk mengatur sudut dari **0° hingga 180°**.

## Konfigurasi Pin

| Komponen     | GPIO ESP32 | Keterangan           |
|---------------|-------------|----------------------|
| Servo Signal  | 17          | Pin kontrol PWM      |
| VCC (Merah)   | 5V atau 3.3V | Tegangan servo (tergantung tipe) |
| GND (Hitam)   | GND         | Ground bersama ESP32 |

## Foto Hasil Simulasi
<img width="587" height="412" alt="Servo" src="https://github.com/user-attachments/assets/ad2d9994-603a-4759-8805-fb369f9433e9" />

## Video Demonstrasi
![Motor-Servo](https://github.com/user-attachments/assets/af896166-e6b2-48b8-8c7b-5dfa1723d046)
