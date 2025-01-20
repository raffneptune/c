#include <stdio.h>

void display_menu() {
    printf("Selamat datang di SPBU!\n");
    printf("Pilih jenis bahan bakar:\n");
    printf("1. Premium (Rp 10.000 per liter)\n");
    printf("2. Pertalite (Rp 12.000 per liter)\n");
    printf("3. Pertamax (Rp 15.000 per liter)\n");
}

float calculate_total_price(int fuel_type, float liters) {
    float price_per_liter = 0;

    if (fuel_type == 1) {
        price_per_liter = 10000;  // Harga Premium
    } else if (fuel_type == 2) {
        price_per_liter = 12000;  // Harga Pertalite
    } else if (fuel_type == 3) {
        price_per_liter = 15000;  // Harga Pertamax
    }

    return price_per_liter * liters;
}

int main() {
    int fuel_type;
    float liters, total_price;

    display_menu();

    // Input pilihan bahan bakar
    printf("Masukkan pilihan (1/2/3): ");
    if (scanf("%d", &fuel_type) != 1 || (fuel_type < 1 || fuel_type > 3)) {
        printf("Pilihan tidak valid.\n");
        return 1;
    }

    // Input jumlah liter yang ingin dibeli
    printf("Masukkan jumlah liter: ");
    if (scanf("%f", &liters) != 1 || liters <= 0) {
        printf("Jumlah liter tidak valid.\n");
        return 1;
    }

    // Menghitung total harga
    total_price = calculate_total_price(fuel_type, liters);

    // Menampilkan struk pembayaran
    printf("\n--- STRUK PEMBAYARAN ---\n");
    if (fuel_type == 1) {
        printf("Bahan Bakar: Premium\n");
    } else if (fuel_type == 2) {
        printf("Bahan Bakar: Pertalite\n");
    } else if (fuel_type == 3) {
        printf("Bahan Bakar: Pertamax\n");
    }
    printf("Jumlah Liter: %.2f liter\n", liters);
    printf("Total Pembayaran: Rp %.0f\n", total_price);
    printf("-------------------------\n");
    printf("Terima kasih telah menggunakan layanan kami!\n");

    return 0;
}