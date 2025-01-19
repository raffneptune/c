#include <stdio.h>

// Fungsi untuk penjumlahan
double tambah(double x, double y) {
    return x + y;
}

// Fungsi untuk pengurangan
double kurang(double x, double y) {
    return x - y;
}

// Fungsi untuk perkalian
double kali(double x, double y) {
    return x * y;
}

// Fungsi untuk pembagian
double bagi(double x, double y) {
    if (y != 0) {
        return x / y;
    } else {
        printf("Tidak bisa membagi dengan nol\n");
        return 0;  // Mengembalikan nilai 0 jika pembagian dengan nol
    }
}

int main() {
    int pilihan;
    double num1, num2;

    // Menampilkan menu operasi
    printf("Pilih operasi:\n");
    printf("1. Tambah\n");
    printf("2. Kurang\n");
    printf("3. Kali\n");
    printf("4. Bagi\n");

    // Meminta input pilihan operasi
    printf("Masukkan pilihan (1/2/3/4): ");
    scanf("%d", &pilihan);

    // Meminta input angka
    printf("Masukkan angka pertama: ");
    scanf("%lf", &num1);
    printf("Masukkan angka kedua: ");
    scanf("%lf", &num2);

    // Melakukan operasi sesuai dengan pilihan pengguna
    switch (pilihan) {
        case 1:
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, tambah(num1, num2));
            break;
        case 2:
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, kurang(num1, num2));
            break;
        case 3:
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, kali(num1, num2));
            break;
        case 4:
            double hasilBagi = bagi(num1, num2);
            if (num2 != 0) {  // Mengecek apakah pembagian berhasil
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, hasilBagi);
            }
            break;
        default:
            printf("Pilihan tidak valid!\n");
            break;
    }

    return 0;
}