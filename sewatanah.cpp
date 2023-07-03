#include <iostream>
#include <conio.h>
using namespace std;

struct TanahSawah {
    float luas;
    string lokasi;
    float harga;
    bool terjual;
};

// Fungsi untuk membandingkan harga tanah sawah (untuk sorting)
bool comparePrice(const TanahSawah& a, const TanahSawah& b) {
    return a.harga < b.harga; // Mengubah tanda perbandingan menjadi kurang dari
}

// Fungsi untuk menampilkan seluruh data tanah sawah
void displayTanahSawah(const TanahSawah* tanahs, int size) {
    cout << "Data Tanah Sawah:" << endl;
    cout << "==============================================================\n";
    cout << "Lokasi         | Luas (hektar) | Harga per Hektar |  Terjual | \n";
    cout << "==============================================================\n";
    for (int i = 0; i < size; i++) {
        cout.width(13);
        cout << left << tanahs[i].lokasi << " |";
        cout.width(14);
        cout << fixed << tanahs[i].luas << " |";
        cout.width(17);
        cout << fixed << tanahs[i].harga << " |";
        cout.width(10);
        cout << (tanahs[i].terjual ? "sudah" : "belum") << "|\n";
    }
    cout << "==============================================================\n";
}

// Fungsi untuk melakukan sorting manual
void manualSort(TanahSawah* tanahs, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (tanahs[j].harga > tanahs[j + 1].harga) {
                swap(tanahs[j], tanahs[j + 1]);
            }
        }
    }
}
int main() {
    const int MAX_TANAH = 5;
    TanahSawah tanahs[MAX_TANAH];

    // Menambahkan data tanah sawah
    tanahs[0] = {10, "Desa mojoroto " , 50000000, false};
    tanahs[1] = {8 , "Desa pojok    " , 40000000, false};
    tanahs[2] = {5 , "Desa kwadungan" , 30000000, true };
    tanahs[3] = {6 , "Desa kweden   " , 45000000, true };
    tanahs[4] = {7 , "Desa semen    " , 35000000, true };

    // Menampilkan seluruh data tanah sawah
    displayTanahSawah(tanahs, MAX_TANAH);

    // Sorting tanah sawah berdasarkan harga terendah sampai tertinggi
    manualSort(tanahs, MAX_TANAH);

    cout << endl << "Tanah Sawah dengan Harga Terendah sampai Tertinggi:" << endl;
    for (int i = 0; i < MAX_TANAH; i++) {
        cout << " Lokasi: " << tanahs[i].lokasi << " , Harga: " << fixed << tanahs[i].harga << endl;
    }
// Menampilkan lokasi tanah sawah yang tersedia (belum terjual)
    cout << endl << "Lokasi Tanah Sawah yang Tersedia (Belum Terjual):" << endl;
    for (int i = 0; i < MAX_TANAH; i++) {
        if (!tanahs[i].terjual) {
            cout << "Lokasi: " << tanahs[i].lokasi << endl;
        }
    }
// Menghitung total harga jual jika tanah sawah dibeli
    double totalHargaJual = 0;
    for (int i = 0; i < MAX_TANAH; i++) {
        if (!tanahs[i].terjual) {
            totalHargaJual += tanahs[i].harga;
        }
    }

    cout << endl << "Total Harga Jual Jika Semua Tanah Sawah Dibeli: " << fixed << totalHargaJual << endl;

    system("pause");
    return 0;
}
