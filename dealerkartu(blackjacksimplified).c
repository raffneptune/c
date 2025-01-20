#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DECK_SIZE 52

// Daftar kartu dalam deck (dalam format string)
const char* deck[DECK_SIZE] = {
    "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", // 13 kartu set pertama
    "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", // 13 kartu set kedua
    "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", // 13 kartu set ketiga
    "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"  // 13 kartu set keempat
};

// Fungsi untuk menghitung nilai kartu
int card_value(const char* card) {
    if (strcmp(card, "J") == 0 || strcmp(card, "Q") == 0 || strcmp(card, "K") == 0) {
        return 10;
    } else if (strcmp(card, "A") == 0) {
        return 11; // Menganggap Ace = 11 untuk kesederhanaan
    } else {
        return atoi(card); // Kartu angka (2-10)
    }
}

// Fungsi untuk membagikan kartu secara acak
const char* deal_card(int* deck_index) {
    int random_index = rand() % DECK_SIZE;
    while (random_index == *deck_index) {
        random_index = rand() % DECK_SIZE; // Pastikan kartu yang sama tidak dibagikan dua kali
    }
    *deck_index = random_index;
    return deck[random_index];
}

// Fungsi untuk menghitung total nilai kartu dalam hand
int calculate_hand(const char* hand[], int hand_size) {
    int total = 0;
    for (int i = 0; i < hand_size; i++) {
        total += card_value(hand[i]);
    }
    return total;
}

void start_game() {
    int deck_index = -1; // Menyimpan indeks kartu yang sudah dibagikan
    srand(time(0)); // Menginisialisasi seed untuk random number generator

    // Kartu untuk pemain dan dealer
    const char* player_hand[10]; // Memungkinkan maksimal 10 kartu
    const char* dealer_hand[10];

    int player_hand_size = 0;
    int dealer_hand_size = 0;

    // Membagikan dua kartu untuk pemain dan dealer
    player_hand[player_hand_size++] = deal_card(&deck_index);
    player_hand[player_hand_size++] = deal_card(&deck_index);

    dealer_hand[dealer_hand_size++] = deal_card(&deck_index);
    dealer_hand[dealer_hand_size++] = deal_card(&deck_index);

    // Menampilkan kartu awal pemain dan dealer (satu kartu dealer tersembunyi)
    printf("Kartu Anda: ");
    for (int i = 0; i < player_hand_size; i++) {
        printf("%s ", player_hand[i]);
    }
    printf("dengan nilai %d\n", calculate_hand(player_hand, player_hand_size));

    printf("Kartu Dealer: %s dan kartu tersembunyi\n", dealer_hand[0]);

    // Giliran pemain
    while (calculate_hand(player_hand, player_hand_size) < 21) {
        char action[10];
        printf("Apakah Anda ingin 'Hit' atau 'Stand'? ");
        scanf("%s", action);

        if (strcmp(action, "hit") == 0) {
            player_hand[player_hand_size++] = deal_card(&deck_index);
            printf("Kartu Anda sekarang: ");
            for (int i = 0; i < player_hand_size; i++) {
                printf("%s ", player_hand[i]);
            }
            printf("dengan nilai %d\n", calculate_hand(player_hand, player_hand_size));
        } else if (strcmp(action, "stand") == 0) {
            break;
        } else {
            printf("Pilihan tidak valid. Pilih 'Hit' atau 'Stand'.\n");
        }
    }

    // Jika pemain melebihi 21
    if (calculate_hand(player_hand, player_hand_size) > 21) {
        printf("Nilai kartu Anda melebihi 21! Anda kalah!\n");
        return;
    }

    // Giliran dealer (dealer akan 'hit' sampai total kartu >= 17)
    printf("Kartu Dealer sekarang: ");
    for (int i = 0; i < dealer_hand_size; i++) {
        printf("%s ", dealer_hand[i]);
    }
    printf("dengan nilai %d\n", calculate_hand(dealer_hand, dealer_hand_size));

    while (calculate_hand(dealer_hand, dealer_hand_size) < 17) {
        printf("Dealer memukul kartu...\n");
        dealer_hand[dealer_hand_size++] = deal_card(&deck_index);
        printf("Kartu Dealer sekarang: ");
        for (int i = 0; i < dealer_hand_size; i++) {
            printf("%s ", dealer_hand[i]);
        }
        printf("dengan nilai %d\n", calculate_hand(dealer_hand, dealer_hand_size));
    }

    // Menentukan pemenang
    int player_total = calculate_hand(player_hand, player_hand_size);
    int dealer_total = calculate_hand(dealer_hand, dealer_hand_size);

    if (dealer_total > 21) {
        printf("Dealer melebihi 21! Anda menang!\n");
    } else if (player_total > dealer_total) {
        printf("Anda menang!\n");
    } else if (player_total < dealer_total) {
        printf("Dealer menang!\n");
    } else {
        printf("Hasil seri!\n");
    }
}

int main() {
    printf("Selamat datang di permainan Dealer Kartu!\n");
    start_game();
    return 0;
}