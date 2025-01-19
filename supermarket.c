#include <stdio.h>
#include <string.h>

// Daftar produk dan harga
typedef struct {
    char nama[50];
    int harga;
} Produk;

Produk produk[] = {
    {"Apel", 10000},
    {"Pisang", 8000},
    {"Jeruk", 12000},
    {"Mangga", 15000},
    {"Semangka", 20000}
};

int totalProduk = 5;

// Fungsi untuk menampilkan daftar produk
void tampilkanProduk() {
    printf("\nDaftar Produk Supermarket:\n");
    for (int i = 0; i < totalProduk; i++) {
        printf("%s: Rp %d\n", produk[i].nama, produk[i].harga);
    }
}

// Fungsi untuk menambah barang ke keranjang
void tambahKeKeranjang(char keranjang[][50], int jumlah[], int *keranjangSize, const char* produkNama, int produkJumlah) {
    int found = 0;
    for (int i = 0; i < *keranjangSize; i++) {
        if (strcmp(keranjang[i], produkNama) == 0) {
            jumlah[i] += produkJumlah;
            found = 1;
            break;
        }
    }
    if (!found) {
        strcpy(keranjang[*keranjangSize], produkNama);
        jumlah[*keranjangSize] = produkJumlah;
        (*keranjangSize)++;
    }
}

// Fungsi untuk menghitung total belanjaan
int hitungTotal(char keranjang[][50], int jumlah[], int keranjangSize) {
    int total = 0;
    for (int i = 0; i < keranjangSize; i++) {
        for (int j = 0; j < totalProduk; j++) {
            if (strcmp(keranjang[i], produk[j].nama) == 0) {
                total += produk[j].harga * jumlah[i];
                break;
            }
        }
    }
    return total;
}

int main() {
    char keranjang[50][50];
    int jumlah[50];
    int keranjangSize = 0;
    char pilihan[50];
    int jumlahBarang;
    
    while (1) {
        tampilkanProduk();
        printf("\nMasukkan nama produk yang ingin dibeli (atau ketik 'selesai' untuk keluar): ");
        fgets(pilihan, sizeof(pilihan), stdin);
        pilihan[strcspn(pilihan, "\n")] = 0;  // Menghapus karakter newline
        
        if (strcmp(pilihan, "selesai") == 0 || strcmp(pilihan, "Selesai") == 0) {
            break;
        }
        
        int ditemukan = 0;
        for (int i = 0; i < totalProduk; i++) {
            if (strcmp(produk[i].nama, pilihan) == 0) {
                ditemukan = 1;
                printf("Berapa banyak %s yang ingin Anda beli? ", pilihan);
                scanf("%d", &jumlahBarang);
                getchar();  // Membersihkan buffer input
                tambahKeKeranjang(keranjang, jumlah, &keranjangSize, produk[i].nama, jumlahBarang);
                break;
            }
        }
        
        if (!ditemukan) {
            printf("Produk tidak tersedia. Silakan pilih produk yang ada.\n");
        }
    }
    
    // Menampilkan keranjang belanja
    printf("\nKeranjang Belanja Anda:\n");
    int total = 0;
    for (int i = 0; i < keranjangSize; i++) {
        for (int j = 0; j < totalProduk; j++) {
            if (strcmp(keranjang[i], produk[j].nama) == 0) {
                int subtotal = produk[j].harga * jumlah[i];
                printf("%s: %d x Rp %d = Rp %d\n", keranjang[i], jumlah[i], produk[j].harga, subtotal);
                total += subtotal;
                break;
            }
        }
    }
    
    printf("\nTotal Belanja: Rp %d\n", total);
    
    return 0;
}