#include <stdio.h>
#include <string.h>

#define MAX_PESANAN 10

// Struktur untuk menyimpan menu dan harga
typedef struct {
    char nama[50];
    int harga;
} MenuItem;

// Struktur untuk menyimpan pesanan
typedef struct {
    char nama[50];
    int jumlah;
} PesananItem;

// Daftar menu dan harga
MenuItem menu[] = {
    {"Kopi", 15000},
    {"Teh", 10000},
    {"Espresso", 20000},
    {"Cappuccino", 25000},
    {"Kue", 12000}
};

int menuCount = sizeof(menu) / sizeof(menu[0]);
PesananItem pesanan[MAX_PESANAN];
int pesananCount = 0;

// Menampilkan menu
void tampilkanMenu() {
    printf("\n--- Menu Kafe ---\n");
    for (int i = 0; i < menuCount; i++) {
        printf("%d. %s: Rp %d\n", i + 1, menu[i].nama, menu[i].harga);
    }
}

// Menambahkan pesanan
void tambahPesanan() {
    while (1) {
        tampilkanMenu();
        printf("\nMasukkan nomor item yang ingin dipesan (ketik 0 untuk selesai): ");
        int pilihan;
        scanf("%d", &pilihan);
        getchar();  // Membersihkan newline setelah input nomor

        if (pilihan == 0) {
            break;
        }

        if (pilihan >= 1 && pilihan <= menuCount) {
            printf("Berapa banyak %s yang ingin dipesan? ", menu[pilihan - 1].nama);
            int jumlah;
            scanf("%d", &jumlah);

            // Tambahkan pesanan ke dalam daftar pesanan
            if (pesananCount < MAX_PESANAN) {
                int found = 0;
                for (int i = 0; i < pesananCount; i++) {
                    if (strcmp(pesanan[i].nama, menu[pilihan - 1].nama) == 0) {
                        pesanan[i].jumlah += jumlah;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    strcpy(pesanan[pesananCount].nama, menu[pilihan - 1].nama);
                    pesanan[pesananCount].jumlah = jumlah;
                    pesananCount++;
                }
                printf("%d %s telah ditambahkan ke pesanan.\n", jumlah, menu[pilihan - 1].nama);
            } else {
                printf("Tidak dapat menambahkan pesanan. Maksimal pesanan tercapai.\n");
            }
        } else {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}

// Menghitung total harga pesanan
int hitungTotal() {
    int total = 0;
    for (int i = 0; i < pesananCount; i++) {
        for (int j = 0; j < menuCount; j++) {
            if (strcmp(pesanan[i].nama, menu[j].nama) == 0) {
                total += menu[j].harga * pesanan[i].jumlah;
            }
        }
    }
    return total;
}

// Menampilkan pesanan
void tampilkanPesanan() {
    if (pesananCount == 0) {
        printf("\nTidak ada pesanan.\n");
    } else {
        printf("\n--- Pesanan Anda ---\n");
        for (int i = 0; i < pesananCount; i++) {
            for (int j = 0; j < menuCount; j++) {
                if (strcmp(pesanan[i].nama, menu[j].nama) == 0) {
                    printf("%s x %d = Rp %d\n", pesanan[i].nama, pesanan[i].jumlah, menu[j].harga * pesanan[i].jumlah);
                }
            }
        }
        printf("\nTotal yang harus dibayar: Rp %d\n", hitungTotal());
    }
}

int main() {
    int pilihan;

    while (1) {
        printf("\n--- Selamat Datang di Kafe! ---\n");
        printf("1. Lihat Menu\n");
        printf("2. Tambah Pesanan\n");
        printf("3. Lihat Pesanan dan Total\n");
        printf("4. Keluar\n");

        printf("Pilih menu (1-4): ");
        scanf("%d", &pilihan);
        getchar();  // Membersihkan newline setelah input

        switch (pilihan) {
            case 1:
                tampilkanMenu();
                break;
            case 2:
                tambahPesanan();
                break;
            case 3:
                tampilkanPesanan();
                break;
            case 4:
                printf("Terima kasih telah mengunjungi kafe kami. Sampai jumpa!\n");
                return 0;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    }

    return 0;
}