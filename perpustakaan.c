#include <stdio.h>
#include <string.h>

#define MAX_BUKU 100
#define MAX_JUDUL 100
#define MAX_PENULIS 100

typedef struct {
    char judul[MAX_JUDUL];
    char penulis[MAX_PENULIS];
    int tahun_terbit;
} Buku;

Buku perpustakaan[MAX_BUKU];
int jumlah_buku = 0;

void tambah_buku() {
    if (jumlah_buku >= MAX_BUKU) {
        printf("Perpustakaan penuh! Tidak dapat menambah buku.\n");
        return;
    }

    Buku buku_baru;
    printf("Masukkan judul buku: ");
    getchar();  // Membersihkan newline dari buffer
    fgets(buku_baru.judul, MAX_JUDUL, stdin);
    buku_baru.judul[strcspn(buku_baru.judul, "\n")] = '\0';  // Menghapus newline di akhir

    printf("Masukkan penulis buku: ");
    fgets(buku_baru.penulis, MAX_PENULIS, stdin);
    buku_baru.penulis[strcspn(buku_baru.penulis, "\n")] = '\0';  // Menghapus newline di akhir

    printf("Masukkan tahun terbit buku: ");
    scanf("%d", &buku_baru.tahun_terbit);

    perpustakaan[jumlah_buku++] = buku_baru;
    printf("Buku '%s' berhasil ditambahkan.\n", buku_baru.judul);
}

void hapus_buku() {
    char judul[MAX_JUDUL];
    printf("Masukkan judul buku yang akan dihapus: ");
    getchar();  // Membersihkan newline dari buffer
    fgets(judul, MAX_JUDUL, stdin);
    judul[strcspn(judul, "\n")] = '\0';  // Menghapus newline di akhir

    int found = 0;
    for (int i = 0; i < jumlah_buku; i++) {
        if (strcmp(perpustakaan[i].judul, judul) == 0) {
            // Geser semua buku setelah buku yang dihapus
            for (int j = i; j < jumlah_buku - 1; j++) {
                perpustakaan[j] = perpustakaan[j + 1];
            }
            jumlah_buku--;
            printf("Buku '%s' berhasil dihapus.\n", judul);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Buku '%s' tidak ditemukan.\n", judul);
    }
}

void tampilkan_buku() {
    if (jumlah_buku == 0) {
        printf("Tidak ada buku di perpustakaan.\n");
    } else {
        printf("Daftar Buku Perpustakaan:\n");
        for (int i = 0; i < jumlah_buku; i++) {
            printf("Judul: %s, Penulis: %s, Tahun Terbit: %d\n",
                   perpustakaan[i].judul, perpustakaan[i].penulis, perpustakaan[i].tahun_terbit);
        }
    }
}

void menu() {
    int pilihan;
    while (1) {
        printf("\nMenu Perpustakaan:\n");
        printf("1. Tambah Buku\n");
        printf("2. Hapus Buku\n");
        printf("3. Tampilkan Daftar Buku\n");
        printf("4. Keluar\n");
        printf("Pilih menu (1/2/3/4): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambah_buku();
                break;
            case 2:
                hapus_buku();
                break;
            case 3:
                tampilkan_buku();
                break;
            case 4:
                printf("Terima kasih! Keluar dari program.\n");
                return;
            default:
                printf("Pilihan tidak valid, coba lagi.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}