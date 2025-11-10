# ESP32-S3 : Dual Core dengan OLED SSD1306
Dengan menunjukkan cara menjalankan dua task secara paralel di ESP32-S3 satu task menghitung nilai counter di Core 0, dan task lain menampilkan hasilnya ke layar OLED SSD1306 di Core 1.
## Deskripsi Singkat
- Menggunakan dua core prosesor ESP32-S3:
  - Core 0 → Menjalankan counter yang bertambah setiap 100 ms
  - Core 1 → Menampilkan hasil counter di layar OLED
- Komunikasi dengan OLED menggunakan protokol I2C
- Tampilan OLED menunjukkan:
  - Judul: “ESP32-S3 Dual Core”
  - Nilai counter yang terus naik setiap detik
## Konfigurasi Pin
| KOMPONEN | GPIO  | Keterangan | 
| :--- | :---: | :---: |
| SDA | 14 | Jalur data I2C |
| SCL | 13 | Jalur clock I2C |
| VCC | 3.3V | Sumber daya 3.3 volt |
| GND | GND | Ground umum |
## Hasil yang Diharapkan 
- OLED menampilkan tulisan
<img width="269" height="58" alt="image" src="https://github.com/user-attachments/assets/1cabde41-e4fa-4789-b28f-2d823e7e7c16" />

- Angka counter meningkat setiap detik
- Menunjukkan pembagian tugas antara dua core prosesor ESP32-S3.
## Foto Hasil Simulasi
<img width="737" height="677" alt="OLED" src="https://github.com/user-attachments/assets/2ab48cea-baac-4094-9209-66f92fb2897e" />

## Video Demonstrasi
https://drive.google.com/file/d/1isDE2zEqmYDSJx6awIpXEZYNZ1_k7RO9/view?usp=drive_link
