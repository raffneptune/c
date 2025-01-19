#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  // Untuk fungsi sleep

#define MAX_ANTRIAN 10

// Struktur untuk Barbershop
typedef struct {
    char antrian[MAX_ANTRIAN][50]; // Array untuk menyimpan nama pelanggan
    int depan, belakang; // Indeks untuk antrian
    int buka; // Status barbershop
} Barbershop;

// Fungsi untuk menginisialisasi Barbershop
void inisialisasiBarbershop(Barbershop* b) {
    b->depan = -1;
    b->belakang = -1;
    b->buka = 1;
}

// Fungsi untuk membuka Barbershop
void bukaBarbershop() {
    printf("Barbershop sedang buka, silakan masuk!\n");
}

// Fungsi untuk menutup Barbershop
void tutupBarbershop(Barbershop* b) {
    b->buka = 0;
    printf("Barbershop sudah tutup. Terima kasih sudah datang!\n");
}

// Fungsi untuk menambah pelanggan ke dalam antrian
void tambahPelanggan(Barbershop* b, const char* nama) {
    if (b->buka == 1) {
        if (b->belakang < MAX_ANTRIAN - 1) {
            b->belakang++;
            strcpy(b->antrian[b->belakang], nama);
            if (b->depan == -1) {
                b->depan = 0;
            }
            printf("%s telah masuk ke antrian.\n", nama);
        } else {
            printf("Antrian sudah penuh!\n");
        }
    } else {
        printf("Barbershop sudah tutup. Anda tidak bisa mendaftar.\n");
    }
}

// Fungsi untuk memproses pelanggan
void prosesPelanggan(Barbershop* b) {
    if (b->depan != -1) {
        printf("Sedang melayani %s...\n", b->antrian[b->depan]);
        sleep(2);  // Simulasi waktu pemotongan rambut
        printf("%s telah selesai dilayani.\n", b->antrian[b->depan]);

        // Menggeser antrian
        for (int i = 0; i < b->belakang; i++) {
            strcpy(b->antrian[i], b->antrian[i + 1]);
        }
        b->belakang--;
        if (b->belakang == -1) {
            b->depan = -1;  // Jika antrian kosong
        }
    } else {
        printf("Tidak ada pelanggan di antrian.\n");
    }
}

// Fungsi untuk menampilkan antrian
void tampilkanAntrian(Barbershop* b) {
    if (b->depan != -1) {
        printf("Antrian pelanggan:\n");
        for (int i = b->depan; i <= b->belakang; i++) {
            printf("%d. %s\n", i - b->depan + 1, b->antrian[i]);
        }
    } else {
        printf("Tidak ada pelanggan di antrian.\n");
    }
}

int main() {
    Barbershop barbershop;
    inisialisasiBarbershop(&barbershop);
    bukaBarbershop();

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Tambah Pelanggan\n");
        printf("2. Proses Pelanggan\n");
        printf("3. Lihat Antrian\n");
        printf("4. Tutup Barbershop\n");
        printf("5. Keluar\n");
        
        int pilihan;
        printf("Pilih menu (1-5): ");
        scanf("%d", &pilihan);
        getchar();  // Membersihkan karakter newline setelah scanf

        if (pilihan == 1) {
            char nama[50];
            printf("Masukkan nama pelanggan: ");
            fgets(nama, sizeof(nama), stdin);
            nama[strcspn(nama, "\n")] = '\0';  // Menghapus karakter newline dari input
            tambahPelanggan(&barbershop, nama);
        }
        else if (pilihan == 2) {
            prosesPelanggan(&barbershop);
        }
        else if (pilihan == 3) {
            tampilkanAntrian(&barbershop);
        }
        else if (pilihan == 4) {
            tutupBarbershop(&barbershop);
            break;
        }
        else if (pilihan == 5) {
            printf("Terima kasih telah menggunakan program ini!\n");
            break;
        }
        else {
            printf("Pilihan tidak valid, coba lagi.\n");
        }
    }

    return 0;
}