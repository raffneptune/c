#include <stdio.h>
#include <string.h>

#define MAX_SISWA 5
#define MAX_NAMA 50

// Daftar nama siswa/pegawai
const char* daftar_nama[MAX_SISWA] = {"Ali", "Budi", "Citra", "Dewi", "Eka"};

// Fungsi untuk mencatat absensi
void catat_absensi() {
    char status;
    char absensi[MAX_SISWA][MAX_NAMA];

    printf("Daftar Nama:\n");
    for (int i = 0; i < MAX_SISWA; i++) {
        printf("%d. %s\n", i + 1, daftar_nama[i]);
    }

    for (int i = 0; i < MAX_SISWA; i++) {
        printf("Apakah %s hadir? (y/n): ", daftar_nama[i]);
        scanf(" %c", &status);  // Spasi sebelum %c untuk mengabaikan karakter newline sebelumnya

        if (status == 'y' || status == 'Y') {
            strcpy(absensi[i], "Hadir");
        } else if (status == 'n' || status == 'N') {
            strcpy(absensi[i], "Tidak Hadir");
        } else {
            strcpy(absensi[i], "Status Tidak Valid");
        }
    }

    printf("\nAbsensi Hari Ini:\n");
    for (int i = 0; i < MAX_SISWA; i++) {
        printf("%s: %s\n", daftar_nama[i], absensi[i]);
    }
}

int main() {
    // Menjalankan fungsi untuk mencatat absensi
    catat_absensi();

    return 0;
}