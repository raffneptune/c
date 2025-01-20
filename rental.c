#include <stdio.h>

typedef struct {
    char name[50];
    int rate_per_hour;
} RentalItem;

void display_items(RentalItem items[], int item_count) {
    printf("Barang yang tersedia untuk disewa:\n");
    for (int i = 0; i < item_count; i++) {
        printf("%d. %s - Rp%d per jam\n", i + 1, items[i].name, items[i].rate_per_hour);
    }
}

int calculate_cost(int rate_per_hour, int hours) {
    return rate_per_hour * hours;
}

int main() {
    RentalItem items[] = {
        {"Sepeda", 5000},
        {"Skuter", 10000},
        {"Mobil", 50000}
    };
    int item_count = sizeof(items) / sizeof(items[0]);
    int choice, hours;

    while (1) {
        printf("\nSelamat datang di sistem rental!\n");
        printf("1. Sewa barang\n");
        printf("2. Keluar\n");
        printf("Pilih menu: ");
        if (scanf("%d", &choice) != 1) {
            printf("Input tidak valid, coba lagi.\n");
            while(getchar() != '\n');  // Clear invalid input
            continue;
        }

        if (choice == 1) {
            display_items(items, item_count);

            printf("Pilih barang yang ingin disewa (1/2/3): ");
            if (scanf("%d", &choice) != 1 || choice < 1 || choice > item_count) {
                printf("Pilihan tidak valid!\n");
                continue;
            }

            printf("Berapa jam Anda ingin menyewa %s? ", items[choice - 1].name);
            if (scanf("%d", &hours) != 1 || hours <= 0) {
                printf("Durasi tidak valid!\n");
                continue;
            }

            int total_cost = calculate_cost(items[choice - 1].rate_per_hour, hours);
            printf("Total biaya untuk menyewa %s selama %d jam adalah: Rp%d\n", items[choice - 1].name, hours, total_cost);
        } 
        else if (choice == 2) {
            printf("Terima kasih telah menggunakan sistem rental!\n");
            break;
        } 
        else {
            printf("Pilihan tidak valid, coba lagi.\n");
        }
    }

    return 0;
}