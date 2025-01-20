#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICLES 10

// Struktur untuk kendaraan
typedef struct {
    char model[50];
    int price;
    int stock;
} Vehicle;

// Daftar kendaraan yang tersedia
Vehicle vehicles[MAX_VEHICLES];
int vehicle_count = 0;

// Menambahkan kendaraan ke diler
void addVehicle(char *model, int price, int stock) {
    if (vehicle_count < MAX_VEHICLES) {
        strcpy(vehicles[vehicle_count].model, model);
        vehicles[vehicle_count].price = price;
        vehicles[vehicle_count].stock = stock;
        vehicle_count++;
    } else {
        printf("Diler sudah penuh, tidak bisa menambah kendaraan.\n");
    }
}

// Menampilkan semua kendaraan yang tersedia
void displayVehicles() {
    if (vehicle_count == 0) {
        printf("Tidak ada kendaraan di diler.\n");
        return;
    }

    printf("\nKendaraan yang Tersedia di Diler:\n");
    for (int i = 0; i < vehicle_count; i++) {
        printf("%d. Model: %s, Harga: Rp%d, Stok: %d\n", i + 1, vehicles[i].model, vehicles[i].price, vehicles[i].stock);
    }
}

// Memeriksa ketersediaan kendaraan dan melakukan pembelian
void purchaseVehicle() {
    displayVehicles();

    if (vehicle_count == 0) {
        return;
    }

    int choice, quantity;
    printf("\nPilih kendaraan (masukkan nomor): ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > vehicle_count) {
        printf("Pilihan tidak valid.\n");
        return;
    }

    printf("Berapa banyak yang ingin dibeli? ");
    scanf("%d", &quantity);

    // Memilih kendaraan yang dipilih
    Vehicle *selectedVehicle = &vehicles[choice - 1];

    // Mengecek apakah kendaraan tersedia dalam jumlah yang diminta
    if (selectedVehicle->stock >= quantity) {
        int totalPrice = selectedVehicle->price * quantity;
        printf("\nPembelian Sukses! Total Harga: Rp%d\n", totalPrice);
        selectedVehicle->stock -= quantity;
    } else {
        printf("\nStok tidak cukup.\n");
    }
}

int main() {
    int choice;

    // Menambahkan beberapa kendaraan ke diler
    addVehicle("Mobil Sedan", 300000000, 10);
    addVehicle("Motor Sport", 100000000, 5);
    addVehicle("Mobil SUV", 500000000, 3);

    while (1) {
        // Menampilkan menu
        printf("\n--- Menu Diler Kendaraan ---\n");
        printf("1. Lihat kendaraan yang tersedia\n");
        printf("2. Pembelian kendaraan\n");
        printf("3. Keluar\n");

        printf("\nPilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayVehicles();
                break;
            case 2:
                purchaseVehicle();
                break;
            case 3:
                printf("Terima kasih telah mengunjungi diler kami!\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}