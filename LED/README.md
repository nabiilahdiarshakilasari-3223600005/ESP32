# ESP32-S3: 3 LED Blinking dengan FreeRTOS
Program dengan menampilakn cara menggunakan FreeRTOS multitasking pada ESP32-S3 untuk menyalakan tiga LED yang berkedip secara independen, setiap LED dikontrol oleh task terpisah dan task di jalankan pada core yang berbeda
## Deskripsi Singkat
LED merah dikendalikan oleh core 0
LED hijau dan biru dikendalikan oleh core 1
Setiap LED berkedip dengan interval berbeda :
- Merah    : 300ms
- Hijau    :500ms
- Biru     :700ms
## Konfigurasi Pin
| LED | GPIO ESP32 | GND |
| :--- | :---: | :---: |
| Merah | 2 | GND |
| Hijau | 5 | GND |
| Biru | 16 | GND |
## Foto Hasil Simulasi
<img width="363" height="703" alt="3 LED" src="https://github.com/user-attachments/assets/139bdb8e-74e1-4308-9bbd-8ad39f6cfd06" />

## Video Demonstrasi

![3LED](https://github.com/user-attachments/assets/46159ff7-6a58-4918-a2c2-9c42790cf472)
