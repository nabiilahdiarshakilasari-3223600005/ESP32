
# ESP32-S3: Pembacaan Potensiometer dengan FreeRTOS

Program ini menampilkan cara menggunakan FreeRTOS multitasking pada ESP32-S3 untuk membaca nilai potensiometer secara independen menggunakan dua core prosesor. Setiap core menjalankan task terpisah yang membaca nilai ADC dan menampilkannya ke Serial Monitor.

## Deskripsi Singkat
ESP32-S3 memiliki dua core (Core 0 dan Core 1) yang dapat digunakan untuk menjalankan dua task secara bersamaan.  
Dalam program ini, task pertama dijalankan pada **Core 0**, dan task kedua dijalankan pada **Core 1**.  
Kedua task membaca nilai potensiometer yang terhubung ke pin ADC (`GPIO 4`) dengan interval waktu 300 ms, lalu menampilkan nilai **Raw ADC**, **hasil konversi tegangan**, serta **ID core** tempat task berjalan.

## Konfigurasi Pin
| Komponen      | GPIO ESP32 | Keterangan       |
|----------------|-------------|------------------|
| Potensiometer  | 4 (ADC)     | Input analog     |
| VCC            | 3.3V        | Tegangan referensi |
| GND            | GND         | Ground           |

## Foto Hasil Simulasi
<img width="605" height="438" alt="Potensiometer" src="https://github.com/user-attachments/assets/1b879012-8073-41b8-a252-1f8878b42676" />

## Vide![2-Push-Buttom_2](https://github.com/user-attachments/assets/b2fec44b-ae89-499d-b645-e22f306045e7)
o Demonstrasi

https://drive.google.com/file/d/10gdp7GRcmaB0fZP7GJle0OzZrEkcoiQT/view?usp=sharing



