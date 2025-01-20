#include <stdio.h>
#include <string.h>

#define MAX_KENDARAAN 50

typedef struct {
    char kendaraan[100];
} Parkir;

void masukParkir(Parkir parkir[], int *jumlahParkir, int kapasitas) {
    if (*jumlahParkir < kapasitas) {
        printf("Masukkan nama kendaraan yang ingin parkir: ");
        scanf(" %[^\n]", parkir[*jumlahParkir].kendaraan);
        (*jumlahParkir)++;
        printf("Kendaraan berhasil masuk ke area parkir.\n");
    } else {
        printf("Parkir sudah penuh!\n");
    }
}

void keluarParkir(Parkir parkir[], int *jumlahParkir) {
    char kendaraan[100];
    int ditemukan = 0;

    printf("Masukkan nama kendaraan yang ingin keluar: ");
    scanf(" %[^\n]", kendaraan);

    for (int i = 0; i < *jumlahParkir; i++) {
        if (strcmp(parkir[i].kendaraan, kendaraan) == 0) {
            ditemukan = 1;
            // Geser kendaraan lainnya ke posisi sebelumnya
            for (int j = i; j < *jumlahParkir - 1; j++) {
                strcpy(parkir[j].kendaraan, parkir[j + 1].kendaraan);
            }
            (*jumlahParkir)--;
            printf("Kendaraan %s telah keluar dari area parkir.\n", kendaraan);
            break;
        }
    }

    if (!ditemukan) {
        printf("Kendaraan %s tidak ditemukan di parkir.\n", kendaraan);
    }
}

void statusParkir(Parkir parkir[], int jumlahParkir) {
    if (jumlahParkir > 0) {
        printf("Kendaraan yang terparkir:\n");
        for (int i = 0; i < jumlahParkir; i++) {
            printf("%s\n", parkir[i].kendaraan);
        }
    } else {
        printf("Area parkir kosong.\n");
    }
}

int main() {
    int kapasitasParkir, jumlahParkir = 0;
    Parkir parkir[MAX_KENDARAAN];

    printf("Masukkan kapasitas parkir: ");
    scanf("%d", &kapasitasParkir);

    int pilihan;
    do {
        printf("\nPilih menu:\n");
        printf("1. Masukkan kendaraan\n");
        printf("2. Keluarkan kendaraan\n");
        printf("3. Lihat status parkir\n");
        printf("4. Keluar\n");

        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                masukParkir(parkir, &jumlahParkir, kapasitasParkir);
                break;
            case 2:
                keluarParkir(parkir, &jumlahParkir);
                break;
            case 3:
                statusParkir(parkir, jumlahParkir);
                break;
            case 4:
                printf("Terima kasih telah menggunakan sistem parkir!\n");
                break;
            default:
                printf("Pilihan tidak valid, coba lagi.\n");
        }
    } while (pilihan != 4);

    return 0;
}