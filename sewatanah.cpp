#include<iostream>
using namespace std;

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
