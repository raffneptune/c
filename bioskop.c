#include <stdio.h>

void show_films() {
    printf("Daftar Film yang Tersedia:\n");
    printf("1. Film A - Harga: Rp 50000\n");
    printf("2. Film B - Harga: Rp 60000\n");
    printf("3. Film C - Harga: Rp 70000\n");
    printf("4. Film D - Harga: Rp 55000\n");
}

int pilih_film() {
    int pilihan;
    printf("\nPilih film (1-4): ");
    while (1) {
        if (scanf("%d", &pilihan) == 1 && pilihan >= 1 && pilihan <= 4) {
            return pilihan;
        } else {
            printf("Pilihan tidak valid, coba lagi: ");
            while (getchar() != '\n'); // Clear input buffer
        }
    }
}

void beli_tiket() {
    int pilihan, jumlah_tiket, total_harga;
    
    while (1) {
        show_films();
        pilihan = pilih_film();
        
        // Menghitung harga berdasarkan film yang dipilih
        switch (pilihan) {
            case 1:
                total_harga = 50000;
                break;
            case 2:
                total_harga = 60000;
                break;
            case 3:
                total_harga = 70000;
                break;
            case 4:
                total_harga = 55000;
                break;
        }
        
        // Input jumlah tiket
        printf("Masukkan jumlah tiket yang ingin dibeli: ");
        scanf("%d", &jumlah_tiket);
        
        total_harga *= jumlah_tiket; // Menghitung total harga
        
        printf("\nTiket untuk film ");
        switch (pilihan) {
            case 1: printf("Film A "); break;
            case 2: printf("Film B "); break;
            case 3: printf("Film C "); break;
            case 4: printf("Film D "); break;
        }
        printf("(%d tiket) berhasil dipesan.\n", jumlah_tiket);
        printf("Total harga: Rp %d\n", total_harga);
        
        // Tanya apakah ingin membeli tiket lagi
        char lagi;
        printf("\nApakah Anda ingin membeli tiket lagi? (y/t): ");
        while (getchar() != '\n'); // Clear input buffer
        scanf("%c", &lagi);
        
        if (lagi == 't' || lagi == 'T') {
            printf("Terima kasih telah membeli tiket di bioskop kami!\n");
            break;
        }
    }
}

int main() {
    beli_tiket();
    return 0;
}