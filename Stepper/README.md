# ESP32-S3: Kontrol Stepper Motor dengan A4988

Program ini menunjukkan cara mengontrol **stepper motor** menggunakan **driver A4988** yang terhubung ke **ESP32-S3**.  
Stepper motor digerakkan dengan memberikan sinyal pulsa (step) dan arah (direction) melalui dua pin utama.  
Dalam contoh ini, motor akan berputar **searah jarum jam (CW)** dan **berlawanan arah jarum jam (CCW)** secara bergantian.

## Deskripsi Singkat

Driver **A4988** berfungsi untuk mengatur arus dan arah pada kumparan motor stepper menggunakan sinyal dari mikrokontroler.  
ESP32-S3 mengirimkan sinyal **STEP** untuk mengatur jumlah langkah dan **DIR** untuk menentukan arah putaran.  
Setiap pulsa STEP membuat motor berputar satu langkah; jumlah total langkah per putaran tergantung pada tipe motor (biasanya 200 langkah per putaran untuk 1.8°/step).

## Konfigurasi Pin

| Komponen      | GPIO ESP32 | Keterangan            |
|----------------|-------------|-----------------------|
| DIR (Direction)| 17          | Menentukan arah putaran (CW/CCW) |
| STEP (Step)    | 16          | Mengatur jumlah langkah motor    |
| VCC            | 5V          | Tegangan driver A4988            |
| GND            | GND         | Ground bersama ESP32             |

## Foto Hasil Simulasi
<img width="1091" height="822" alt="Stepper" src="https://github.com/user-attachments/assets/5eb5fe0f-8d52-4c2a-ba22-b84a142722b3" />

## Video Demonstrasi
![Stepper](https://github.com/user-attachments/assets/c14d4bfe-1c1e-48ed-90b9-2ddec096c8ac)


