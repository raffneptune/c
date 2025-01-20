#include <stdio.h>
#include <string.h>

#define MAX_KERETA 10

// Struktur untuk menyimpan informasi kereta
typedef struct {
    char nama_kereta[50];
    char tujuan[50];
    char waktu_berangkat[10];
    int kapasitas;
    int terisi;
} Kereta;

// Struktur untuk sistem kereta
typedef struct {
    Kereta kereta_list[MAX_KERETA];
    int jumlah_kereta;
} SistemKereta;

// Fungsi untuk menampilkan informasi kereta
void tampilkan_info(Kereta kereta) {
    printf("Nama Kereta: %s\n", kereta.nama_kereta);
    printf("Tujuan: %s\n", kereta.tujuan);
    printf("Waktu Berangkat: %s\n", kereta.waktu_berangkat);
    printf("Kapasitas: %d\n", kereta.kapasitas);
    printf("Terisi: %d/%d\n", kereta.terisi, kereta.kapasitas);
    printf("\n");
}

// Fungsi untuk memesan tiket kereta
void pesan_tiket(Kereta *kereta, int jumlah_tiket) {
    if (kereta->terisi + jumlah_tiket <= kereta->kapasitas) {
        kereta->terisi += jumlah_tiket;
        printf("Berhasil memesan %d tiket untuk %s.\n", jumlah_tiket, kereta->nama_kereta);
    } else {
        printf("Maaf, hanya tersisa %d tiket untuk %s.\n", kereta->kapasitas - kereta->terisi, kereta->nama_kereta);
    }
}

// Fungsi untuk menambahkan kereta ke sistem
void tambah_kereta(SistemKereta *sistem_kereta, Kereta kereta) {
    if (sistem_kereta->jumlah_kereta < MAX_KERETA) {
        sistem_kereta->kereta_list[sistem_kereta->jumlah_kereta] = kereta;
        sistem_kereta->jumlah_kereta++;
    } else {
        printf("Sistem kereta penuh, tidak bisa menambahkan kereta baru.\n");
    }
}

// Fungsi untuk menampilkan jadwal semua kereta
void tampilkan_jadwal(SistemKereta sistem_kereta) {
    printf("Jadwal Kereta:\n");
    for (int i = 0; i < sistem_kereta.jumlah_kereta; i++) {
        tampilkan_info(sistem_kereta.kereta_list[i]);
    }
}

// Fungsi untuk memesan tiket untuk kereta tertentu
void pesan_tiket_kereta(SistemKereta *sistem_kereta, char nama_kereta[], int jumlah_tiket) {
    int ditemukan = 0;
    for (int i = 0; i < sistem_kereta->jumlah_kereta; i++) {
        if (strcmp(sistem_kereta->kereta_list[i].nama_kereta, nama_kereta) == 0) {
            pesan_tiket(&sistem_kereta->kereta_list[i], jumlah_tiket);
            ditemukan = 1;
            break;
        }
    }
    if (!ditemukan) {
        printf("Kereta dengan nama %s tidak ditemukan.\n", nama_kereta);
    }
}

int main() {
    SistemKereta sistem_kereta;
    sistem_kereta.jumlah_kereta = 0;

    // Menambahkan beberapa kereta ke sistem
    Kereta kereta1 = {"Ekspres Jakarta", "Bandung", "10:00", 100, 0};
    Kereta kereta2 = {"Argo Bromo", "Surabaya", "15:00", 150, 0};
    Kereta kereta3 = {"Kelas Ekonomi", "Yogyakarta", "12:00", 200, 0};

    tambah_kereta(&sistem_kereta, kereta1);
    tambah_kereta(&sistem_kereta, kereta2);
    tambah_kereta(&sistem_kereta, kereta3);

    int pilihan;
    char nama_kereta[50];
    int jumlah_tiket;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tampilkan Jadwal Kereta\n");
        printf("2. Pesan Tiket Kereta\n");
        printf("3. Keluar\n");

        printf("Pilih menu (1/2/3): ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            tampilkan_jadwal(sistem_kereta);
        } else if (pilihan == 2) {
            printf("Masukkan nama kereta yang ingin dipesan: ");
            getchar(); // Membersihkan newline dari buffer input
            fgets(nama_kereta, 50, stdin);
            nama_kereta[strcspn(nama_kereta, "\n")] = '\0'; // Menghapus newline di akhir string
            printf("Masukkan jumlah tiket yang ingin dipesan: ");
            scanf("%d", &jumlah_tiket);
            pesan_tiket_kereta(&sistem_kereta, nama_kereta, jumlah_tiket);
        } else if (pilihan == 3) {
            printf("Terima kasih telah menggunakan sistem kereta.\n");
            break;
        } else {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}