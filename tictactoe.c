#include <stdio.h>

#define SIZE 3

// Fungsi untuk menampilkan papan permainan
void print_board(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Fungsi untuk mengecek apakah pemain menang
int check_win(char board[SIZE][SIZE], char player) {
    // Mengecek baris
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Mengecek kolom
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Mengecek diagonal
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Fungsi untuk mengecek apakah papan penuh
int is_board_full(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Fungsi utama permainan
void play_game() {
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    char current_player = 'X';
    int row, col;

    while (1) {
        print_board(board);

        // Meminta pemain untuk memilih posisi
        printf("Player %c, pilih baris dan kolom (1-3) untuk posisi: ", current_player);
        scanf("%d %d", &row, &col);
        row--; col--; // Mengurangi 1 untuk indeks array

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Posisi tidak valid atau sudah terisi, coba lagi.\n");
            continue;
        }

        // Menandai posisi dengan simbol pemain saat ini
        board[row][col] = current_player;

        // Mengecek apakah pemain menang
        if (check_win(board, current_player)) {
            print_board(board);
            printf("Selamat! Pemain %c menang!\n", current_player);
            break;
        }

        // Mengecek apakah papan penuh (seri)
        if (is_board_full(board)) {
            print_board(board);
            printf("Permainan berakhir dengan seri!\n");
            break;
        }

        // Ganti giliran pemain
        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

// Fungsi utama
int main() {
    play_game();
    return 0;
}