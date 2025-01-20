#include <stdio.h>

// Fungsi untuk menghitung gaji total
double hitungGaji(double gajiPokok, double tunjangan, double potongan) {
    return gajiPokok + tunjangan - potongan;
}

int main() {
    double gajiPokok, tunjangan, potongan, gajiTotal;

    // Menampilkan judul program
    printf("Program Perhitungan Gaji Karyawan\n");

    // Input data
    printf("Masukkan gaji pokok: Rp ");
    scanf("%lf", &gajiPokok);
    printf("Masukkan tunjangan: Rp ");
    scanf("%lf", &tunjangan);
    printf("Masukkan potongan: Rp ");
    scanf("%lf", &potongan);

    // Menghitung gaji total
    gajiTotal = hitungGaji(gajiPokok, tunjangan, potongan);

    // Menampilkan hasil perhitungan
    printf("\nRingkasan Gaji:\n");
    printf("Gaji Pokok: Rp %.2lf\n", gajiPokok);
    printf("Tunjangan: Rp %.2lf\n", tunjangan);
    printf("Potongan: Rp %.2lf\n", potongan);
    printf("Gaji Total: Rp %.2lf\n", gajiTotal);

    return 0;
}