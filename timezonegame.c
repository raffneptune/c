#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Maksimal jumlah pengguna
#define MAX_USERS 100

// Struktur untuk menyimpan data pengguna
struct User {
    char name[50];
    int kredit;
    char permainan[10][20];  // Menyimpan riwayat permainan, maksimal 10 permainan
    int permainanCount;  // Menghitung jumlah permainan yang dimainkan
};

// Array untuk menyimpan pengguna
struct User users[MAX_USERS];
int userCount = 0;  // Menghitung jumlah pengguna terdaftar

// Fungsi untuk mendaftar pengguna baru
void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Tidak dapat mendaftar pengguna baru. Batas maksimum pengguna tercapai.\n");
        return;
    }

    char name[50];
    printf("Masukkan nama pengguna: ");
    scanf("%s", name);

    // Cek apakah pengguna sudah terdaftar
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("Pengguna dengan nama %s sudah terdaftar.\n", name);
            return;
        }
    }

    // Menambahkan pengguna baru
    strcpy(users[userCount].name, name);
    users[userCount].kredit = 0;
    users[userCount].permainanCount = 0;
    userCount++;
    printf("Selamat datang, %s! Akun Anda telah dibuat.\n", name);
}

// Fungsi untuk membeli kredit
void buyCredits(char* userName) {
    int creditAmount;
    printf("Berapa banyak kredit yang ingin Anda beli? (1 kredit = 5000 IDR): ");
    scanf("%d", &creditAmount);

    // Cari pengguna berdasarkan nama
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, userName) == 0) {
            users[i].kredit += creditAmount;
            printf("%d kredit telah ditambahkan ke akun Anda.\n", creditAmount);
            return;
        }
    }

    printf("Pengguna tidak ditemukan. Silakan mendaftar terlebih dahulu.\n");
}

// Fungsi untuk bermain game
void playGame(char* userName) {
    // Cari pengguna berdasarkan nama
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, userName) == 0) {
            if (users[i].kredit < 1) {
                printf("Anda tidak memiliki kredit cukup untuk bermain game. Silakan beli kredit terlebih dahulu.\n");
                return;
            }

            printf("Pilih permainan yang ingin dimainkan:\n");
            printf("1. Pac-Man (1 kredit)\n");
            printf("2. Street Fighter (2 kredit)\n");
            printf("3. Racing Game (3 kredit)\n");

            int gameChoice;
            scanf("%d", &gameChoice);

            if (gameChoice == 1 && users[i].kredit >= 1) {
                users[i].kredit -= 1;
                printf("Anda sedang bermain Pac-Man! Semoga berhasil!\n");
            } else if (gameChoice == 2 && users[i].kredit >= 2) {
                users[i].kredit -= 2;
                printf("Anda sedang bermain Street Fighter! Bertarunglah dengan kuat!\n");
            } else if (gameChoice == 3 && users[i].kredit >= 3) {
                users[i].kredit -= 3;
                printf("Anda sedang bermain Racing Game! Gaspol!\n");
            } else {
                printf("Anda tidak memiliki kredit cukup untuk memilih permainan ini.\n");
                return;
            }

            // Simulasi hasil permainan (acak)
            srand(time(NULL));
            int result = rand() % 2; // 0 = Kalah, 1 = Menang
            printf("Memulai permainan...\n");
            printf("Hasil permainan: %s\n", result == 1 ? "Menang" : "Kalah");

            // Menyimpan riwayat permainan
            strcpy(users[i].permainan[users[i].permainanCount], result == 1 ? "Menang" : "Kalah");
            users[i].permainanCount++;

            return;
        }
    }

    printf("Pengguna tidak ditemukan. Silakan mendaftar terlebih dahulu.\n");
}

// Fungsi untuk mengecek saldo kredit
void checkBalance(char* userName) {
    // Cari pengguna berdasarkan nama
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, userName) == 0) {
            printf("Sisa kredit Anda: %d kredit.\n", users[i].kredit);
            return;
        }
    }

    printf("Pengguna tidak ditemukan. Silakan mendaftar terlebih dahulu.\n");
}

// Menu utama
int main() {
    while (1) {
        printf("\nMenu Utama:\n");
        printf("1. Daftar pengguna baru\n");
        printf("2. Beli kredit\n");
        printf("3. Mainkan game\n");
        printf("4. Cek saldo kredit\n");
        printf("5. Keluar\n");

        int choice;
        printf("Pilih menu (1/2/3/4/5): ");
        scanf("%d", &choice);

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            char userName[50];
            printf("Masukkan nama pengguna untuk membeli kredit: ");
            scanf("%s", userName);
            buyCredits(userName);
        } else if (choice == 3) {
            char userName[50];
            printf("Masukkan nama pengguna untuk bermain game: ");
            scanf("%s", userName);
            playGame(userName);
        } else if (choice == 4) {
            char userName[50];
            printf("Masukkan nama pengguna untuk cek saldo: ");
            scanf("%s", userName);
            checkBalance(userName);
        } else if (choice == 5) {
            printf("Terima kasih telah bermain di Timezone Mall! Sampai jumpa lagi!\n");
            break;
        } else {
            printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }
    }

    return 0;
}