#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BIAYA_PER_MENIT 2000

typedef struct {
    int nomor;
    int tersedia;
    time_t mulaiSewa;
    double durasiSewa;
} Komputer;

void sewaKomputer(Komputer *komputer) {
    if (komputer->tersedia) {
        komputer->tersedia = 0;
        komputer->mulaiSewa = time(NULL);
        printf("Komputer %d telah disewa.\n", komputer->nomor);
    } else {
        printf("Komputer %d sedang disewa.\n", komputer->nomor);
    }
}

void selesaiSewa(Komputer *komputer) {
    if (!komputer->tersedia) {
        time_t selesaiSewa = time(NULL);
        komputer->durasiSewa = difftime(selesaiSewa, komputer->mulaiSewa) / 60;  // durasi dalam menit
        double biaya = komputer->durasiSewa * BIAYA_PER_MENIT;
        komputer->tersedia = 1;
        printf("Komputer %d selesai disewa. Durasi: %.2f menit.\n", komputer->nomor, komputer->durasiSewa);
        printf("Biaya yang harus dibayar: Rp %.2f\n", biaya);
    } else {
        printf("Komputer %d belum disewa.\n", komputer->nomor);
    }
}

void tampilkanKomputer(Komputer komputer[], int jumlahKomputer) {
    printf("\nDaftar Komputer:\n");
    for (int i = 0; i < jumlahKomputer; i++) {
        printf("Komputer %d: %s\n", komputer[i].nomor, komputer[i].tersedia ? "Tersedia" : "Sedang disewa");
    }
}

int main() {
    int jumlahKomputer = 5;
    Komputer komputer[jumlahKomputer];
    for (int i = 0; i < jumlahKomputer; i++) {
        komputer[i].nomor = i + 1;
        komputer[i].tersedia = 1;
    }

    int pilihan;
    int nomor;
    while (1) {
        printf("\n--- Menu Warnet ---\n");
        printf("1. Tampilkan Daftar Komputer\n");
        printf("2. Sewa Komputer\n");
        printf("3. Selesai Sewa Komputer\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanKomputer(komputer, jumlahKomputer);
                break;
            case 2:
                printf("Masukkan nomor komputer yang ingin disewa: ");
                scanf("%d", &nomor);
                if (nomor >= 1 && nomor <= jumlahKomputer) {
                    sewaKomputer(&komputer[nomor - 1]);
                } else {
                    printf("Nomor komputer tidak valid!\n");
                }
                break;
            case 3:
                printf("Masukkan nomor komputer yang selesai disewa: ");
                scanf("%d", &nomor);
                if (nomor >= 1 && nomor <= jumlahKomputer) {
                    selesaiSewa(&komputer[nomor - 1]);
                } else {
                    printf("Nomor komputer tidak valid!\n");
                }
                break;
            case 4:
                printf("Terima kasih telah menggunakan layanan warnet!\n");
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    }

    return 0;
}