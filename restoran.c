#include <stdio.h>

#define MAX_MENU 6

// Struktur untuk menyimpan menu
typedef struct {
    char nama[50];
    int harga;
} Menu;

// Struktur untuk menyimpan pesanan
typedef struct {
    Menu menu;
    int jumlah;
} Pesanan;

void tampilkanMenu(Menu menu[], int menuCount) {
    printf("\nMenu Restoran:\n");
    for (int i = 0; i < menuCount; i++) {
        printf("%d. %s - Rp%d\n", i + 1, menu[i].nama, menu[i].harga);
    }
}

int hitungTotal(Pesanan pesanan[], int pesananCount) {
    int total = 0;
    for (int i = 0; i < pesananCount; i++) {
        total += pesanan[i].menu.harga * pesanan[i].jumlah;
    }
    return total;
}

void tampilkanPesanan(Pesanan pesanan[], int pesananCount) {
    if (pesananCount == 0) {
        printf("\nBelum ada pesanan.\n");
    } else {
        printf("\nPesanan Anda:\n");
        for (int i = 0; i < pesananCount; i++) {
            printf("%s x %d - Rp%d\n", pesanan[i].menu.nama, pesanan[i].jumlah, pesanan[i].menu.harga * pesanan[i].jumlah);
        }
        printf("Total Harga: Rp%d\n", hitungTotal(pesanan, pesananCount));
    }
}

int main() {
    Menu menu[MAX_MENU] = {
        {"Nasi Goreng", 25000},
        {"Mie Goreng", 20000},
        {"Sate Ayam", 30000},
        {"Ayam Penyet", 35000},
        {"Es Teh", 5000},
        {"Es Jeruk", 7000}
    };

    Pesanan pesanan[MAX_MENU];
    int pesananCount = 0;
    int pilihan, jumlah;

    while (1) {
        printf("\n-- Menu Utama --\n");
        printf("1. Lihat Menu\n");
        printf("2. Tambah Pesanan\n");
        printf("3. Tampilkan Pesanan\n");
        printf("4. Hitung Total\n");
        printf("5. Keluar\n");

        printf("Pilih opsi (1-5): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanMenu(menu, MAX_MENU);
                break;
            case 2:
                tampilkanMenu(menu, MAX_MENU);
                printf("\nPilih nomor menu untuk dipesan (0 untuk selesai): ");
                scanf("%d", &pilihan);

                if (pilihan == 0) break;

                if (pilihan > 0 && pilihan <= MAX_MENU) {
                    printf("Berapa banyak %s yang ingin dipesan? ", menu[pilihan - 1].nama);
                    scanf("%d", &jumlah);

                    pesanan[pesananCount].menu = menu[pilihan - 1];
                    pesanan[pesananCount].jumlah = jumlah;
                    pesananCount++;

                    printf("%d %s ditambahkan ke pesanan.\n", jumlah, menu[pilihan - 1].nama);
                } else {
                    printf("Nomor menu tidak valid!\n");
                }
                break;
            case 3:
                tampilkanPesanan(pesanan, pesananCount);
                break;
            case 4:
                printf("Total Harga: Rp%d\n", hitungTotal(pesanan, pesananCount));
                break;
            case 5:
                printf("Terima kasih telah berkunjung!\n");
                return 0;
            default:
                printf("Opsi tidak valid!\n");
                break;
        }
    }

    return 0;
}