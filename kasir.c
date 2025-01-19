#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nama[100];
    double harga;
    int jumlah;
    double total;
} Barang;

void tambahBarang(Barang* daftarBarang, int* jumlahBarang, char* nama, double harga, int jumlah) {
    Barang barang;
    strcpy(barang.nama, nama);
    barang.harga = harga;
    barang.jumlah = jumlah;
    barang.total = harga * jumlah;

    daftarBarang[*jumlahBarang] = barang;
    (*jumlahBarang)++;
    printf("%s x%d ditambahkan ke daftar belanja.\n", nama, jumlah);
}

void tampilkanRincian(Barang* daftarBarang, int jumlahBarang, double totalHarga) {
    printf("\n--- Rincian Belanja ---\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("%s - Harga: %.2f - Jumlah: %d - Total: %.2f\n", daftarBarang[i].nama, daftarBarang[i].harga, daftarBarang[i].jumlah, daftarBarang[i].total);
    }
    printf("\nTotal Belanja: %.2f\n", totalHarga);
}

void bayar(double totalHarga, double uangDibayar) {
    if (uangDibayar >= totalHarga) {
        double kembalian = uangDibayar - totalHarga;
        printf("\nTotal yang harus dibayar: %.2f\n", totalHarga);
        printf("Uang yang dibayar: %.2f\n", uangDibayar);
        printf("Kembalian: %.2f\n", kembalian);
    } else {
        printf("\nUang yang dibayar kurang dari total belanja. Transaksi dibatalkan.\n");
    }
}

int main() {
    Barang daftarBarang[100];
    int jumlahBarang = 0;
    double totalHarga = 0;
    int pilihan;
    char namaBarang[100];
    double harga;
    int jumlah;
    double uangDibayar;

    while (1) {
        printf("\nMenu Kasir\n");
        printf("1. Tambah barang\n");
        printf("2. Tampilkan rincian belanja\n");
        printf("3. Bayar\n");
        printf("4. Keluar\n");
        printf("Pilih menu (1/2/3/4): ");
        scanf("%d", &pilihan);
        getchar(); // Clear buffer setelah input pilihan

        if (pilihan == 1) {
            printf("Masukkan nama barang: ");
            fgets(namaBarang, sizeof(namaBarang), stdin);
            // Menghapus newline di akhir namaBarang
            namaBarang[strcspn(namaBarang, "\n")] = '\0';

            printf("Masukkan harga barang: ");
            scanf("%lf", &harga);

            printf("Masukkan jumlah barang: ");
            scanf("%d", &jumlah);

            tambahBarang(daftarBarang, &jumlahBarang, namaBarang, harga, jumlah);
            totalHarga += harga * jumlah;
        } else if (pilihan == 2) {
            tampilkanRincian(daftarBarang, jumlahBarang, totalHarga);
        } else if (pilihan == 3) {
            tampilkanRincian(daftarBarang, jumlahBarang, totalHarga);
            printf("Masukkan uang yang dibayar: ");
            scanf("%lf", &uangDibayar);
            bayar(totalHarga, uangDibayar);
        } else if (pilihan == 4) {
            printf("Terima kasih, sampai jumpa!\n");
            break;
        } else {
            printf("Pilihan tidak valid, coba lagi.\n");
        }
    }

    return 0;
}