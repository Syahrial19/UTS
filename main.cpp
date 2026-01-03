#include <iostream>
#include "panen.h"
using namespace std;

int main() {
    List L;
    createList(L);

    int pilihan;
    Panen data;

    do {
        cout << "\n=== MENU DATA PANEN ===\n";
        cout << "1. Tambah data panen di awal list\n";
        cout << "2. Tampilkan semua data\n";
        cout << "3. Cari panen terbanyak\n";
        cout << "4. Tampilkan Tanaman yang panen berdasarkan bulan\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            cout << "Nama tanaman   : ";
            getline(cin, data.namaTanaman);
            cout << "Bulan panen    : ";
            getline(cin, data.bulan);
            cout << "Jumlah (kg)    : ";
            cin >> data.jumlah;
            cin.ignore();

            tambahData(L, data);
            cout << "Data berhasil ditambahkan.\n";
            break;

        case 2:
            tampilkanList(L);
            break;

        case 3: {
            address max = panenTerbanyak(L);
            if (max != nullptr) {
                cout << "Panen terbanyak:\n";
                cout << max->info.namaTanaman << " | "
                     << max->info.bulan << " | "
                     << max->info.jumlah << " kg\n";
            } else {
                cout << "List kosong\n";
            }
            break;
        }

        case 4: {
            string bulanCari;
            cout << "Masukkan bulan: ";
            getline(cin, bulanCari);
            panenBulanan(L, bulanCari);
            break;
        }

        case 0:
            cout << "Keluar dari program.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
