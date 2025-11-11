# ESP32-S3: Pembacaan Rotary Encoder

Program ini menunjukkan cara membaca **rotary encoder** menggunakan board **ESP32-S3**.  
Rotary encoder digunakan untuk mendeteksi arah dan jumlah putaran (searah atau berlawanan jarum jam), serta memiliki tombol tekan (push button) yang bisa digunakan untuk fungsi tambahan seperti reset nilai.

## Deskripsi Singkat

Rotary encoder menghasilkan dua sinyal digital (CLK dan DT) yang berubah secara bergantian saat knob diputar.  
Dengan membaca perubahan urutan sinyal tersebut, ESP32 dapat menentukan apakah putaran dilakukan ke **kanan (CW – Clockwise)** atau ke **kiri (CCW – Counter Clockwise)**.  
Selain itu, tombol **SW** pada encoder dapat ditekan untuk menjalankan aksi tambahan, misalnya **mereset nilai counter**.

## Konfigurasi Pin

| Komponen        | GPIO ESP32 | Keterangan                 |
|-----------------|-------------|----------------------------|
| CLK (Clock)     | 8           | Sinyal utama rotasi        |
| DT (Data)       | 9           | Sinyal arah rotasi         |
| SW (Switch)     | 10          | Tombol tekan (aktif LOW)   |
| VCC             | 3.3V        | Tegangan referensi         |
| GND             | GND         | Ground                     |

## Foto Hasil Simulasi
<img width="502" height="417" alt="Retory Encoder" src="https://github.com/user-attachments/assets/698a35f5-ea6a-49a0-8ad8-09437286daeb" />

## Video Demonstrasi

![Retory-Encoder](https://github.com/user-attachments/assets/94bd1fae-b86f-44dd-b854-c06246265cba)
