# ESP32-S3 : Buzzer dengan Tone Manual
Dengan menunjukkan cara menghasilkan suara dari buzzer aktif atau pasif menggunakan fungsi manual (tanpa tone()).Frekuensi diatur menggunakan perhitungan periode gelombang, dan sinyal dikirim secara langsung ke pin GPIO 15.
## Deskripsi Singkat
- Pin Buzzer: GPIO 15
- Menghasilkan dua nada bergantian:
  - Nada 1: 1000 Hz (1 kHz) selama 500 ms
  - Nada 2: 2000 Hz (2 kHz) selama 500 ms
- Setiap nada dipisahkan dengan jeda 300 ms
- Proses dilakukan secara manual menggunakan fungsi toneManual().
- Program menghasilkan dua nada berurutan — pertama 1 kHz (rendah), kemudian 2 kHz (tinggi)
## Konfigurasi Pin
| KOMPONEN | GPIO  | Keterangan | 
| :--- | :---: | :---: |
| Buzzer(+) | 15 | Output sinyal suara |
| Buzzer(-) | GND | Ground umum |
## Foto Hasil Simulasi
<img width="593" height="473" alt="Buzzer" src="https://github.com/user-attachments/assets/26536714-f0ee-44cd-8036-526f956df158" />

## Video Demonstrasi
https://drive.google.com/file/d/1hNiSyfE4Q9e6eAvovC0qp9INhx_u-0ji/view?usp=drive_link
