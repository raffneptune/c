#include <stdio.h>
#include <string.h>

#define MAX_ANTRIAN 10
#define MAX_NAMA 50

// Struktur untuk kendaraan
typedef struct {
    char nama[MAX_NAMA];
    char golongan[MAX_NAMA];
} Kendaraan;

// Struktur untuk Gerbang Tol
typedef struct {
    Kendaraan antrian[MAX_ANTRIAN];
    int jumlah_antrian;
} GerbangTol;

// Struktur untuk Sistem Tol
typedef struct {
    int tarif_golongan_1;
    int tarif_golongan_2;
    int tarif_golongan_3;
} SistemTol;

// Fungsi untuk menambah kendaraan ke antrian
void tambah_antrian(GerbangTol *gerbang, char *nama, char *golongan) {
    if (gerbang->jumlah_antrian < MAX_ANTRIAN) {
        strcpy(gerbang->antrian[gerbang->jumlah_antrian].nama, nama);
        strcpy(gerbang->antrian[gerbang->jumlah_antrian].golongan, golongan);
        gerbang->jumlah_antrian++;
        printf("%s ditambahkan ke antrian.\n", nama);
    } else {
        printf("Antrian penuh, tidak bisa menambah kendaraan.\n");
    }
}

// Fungsi untuk memproses kendaraan pertama dalam antrian
void proses_kendaraan(GerbangTol *gerbang) {
    if (gerbang->jumlah_antrian > 0) {
        printf("%s sedang diproses.\n", gerbang->antrian[0].nama);
        // Geser antrian ke depan
        for (int i = 0; i < gerbang->jumlah_antrian - 1; i++) {
            gerbang->antrian[i] = gerbang->antrian[i + 1];
        }
        gerbang->jumlah_antrian--;
    } else {
        printf("Antrian kosong, tidak ada kendaraan yang diproses.\n");
    }
}

// Fungsi untuk menampilkan antrian kendaraan
void tampilkan_antrian(GerbangTol *gerbang) {
    if (gerbang->jumlah_antrian > 0) {
        printf("Antrian kendaraan saat ini:\n");
        for (int i = 0; i < gerbang->jumlah_antrian; i++) {
            printf("%s - %s\n", gerbang->antrian[i].nama, gerbang->antrian[i].golongan);
        }
    } else {
        printf("Antrian kosong.\n");
    }
}

// Fungsi untuk menghitung biaya tol berdasarkan golongan dan jarak
void hitung_biaya(SistemTol *sistem, char *golongan, int jarak) {
    int tarif = 0;
    
    if (strcmp(golongan, "golongan_1") == 0) {
        tarif = sistem->tarif_golongan_1;
    } else if (strcmp(golongan, "golongan_2") == 0) {
        tarif = sistem->tarif_golongan_2;
    } else if (strcmp(golongan, "golongan_3") == 0) {
        tarif = sistem->tarif_golongan_3;
    } else {
        printf("Golongan kendaraan tidak valid!\n");
        return;
    }
    
    int biaya = tarif * jarak;
    printf("Biaya tol untuk %s dengan jarak %d km adalah: %d IDR\n", golongan, jarak, biaya);
}

// Program utama
int main() {
    GerbangTol gerbang = {0};
    SistemTol sistem = {5000, 10000, 15000}; // Tarif untuk golongan 1, 2, dan 3

    // Menambah kendaraan ke antrian
    tambah_antrian(&gerbang, "Mobil Kecil - Golongan 1", "golongan_1");
    tambah_antrian(&gerbang, "Truk Kecil - Golongan 2", "golongan_2");
    tambah_antrian(&gerbang, "Truk Besar - Golongan 3", "golongan_3");
    
    // Menampilkan antrian kendaraan
    tampilkan_antrian(&gerbang);

    // Proses kendaraan pertama
    proses_kendaraan(&gerbang);

    // Menghitung biaya tol untuk kendaraan pertama
    hitung_biaya(&sistem, "golongan_1", 10);  // Misalnya jarak 10 km
    
    return 0;
}