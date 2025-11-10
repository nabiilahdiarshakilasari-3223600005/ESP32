# ESP32-S3 : Dua Tombol di Dua Core (FreeRTOS)
Dengan menampilkan cara menggunakan FreeRTOS multitasking pada ESP32-S3 untuk membaca dua tombol push button yang dijalankan secara paralel pada dua core berbeda. Tiap tombol dikontrol oleh task yang berjalan di core tersendiri.
## Deskripsi Singkat
- Tombol 1 (GPIO 47) dijalankan pada Core 0
- Tombol 2 (GPIO 21) dijalankan pada Core 1
- Setiap tombol dibaca menggunakan task terpisah yang berjalan bersamaan
- Output status tombol (DITEKAN / DILEPAS) ditampilkan melalui Serial Monitor
### Konfigurasi Pin
| TOMBOL | GPIO  | Koneksi Tambahan |
| :--- | :---: | :---: |
| Tombol 1 | 47 | GND |
| Tombol 2 | 21 | GND |
### Foto Hasil Simulasi
<img width="338" height="432" alt="2 Push Buttom" src="https://github.com/user-attachments/assets/3db5d27d-4265-4d8f-8bd2-a1034165c3d1" />

### Video Demonstrasi
https://drive.google.com/file/d/1GLFFcO742P14t_WABj2CZcJFS3eLlPm6/view?usp=drive_link
