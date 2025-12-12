#include <iostream>
#include "main.h"

using namespace std;

void menuUser(ListHakim L) {
    int pilihan;
    while (pilihan != 0) {
        cout << "========== MENU USER ===========" << endl;
        cout << "1. Lihat Semua Data" << endl;
        cout << "2. Cari Data Hakim" << endl;
        cout << "3. Cari Data Terdakwa" << endl;
        cout << "0. Kembali" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1) {
            viewHakim(L);

        } else if (pilihan == 2) {
            string kode;
            cout << "Masukkan Kode Hakim: "; cin >> kode;
            adrHakim P = findHakim(L, kode);
            if (P != nullptr) {
                cout << "Ditemukan: " << P->info.nama << " (Pengalaman: " << P->info.pengalaman << " thn)" << endl;
                cout << "Daftar Terdakwa:" << endl;
                viewTerdakwa(P);
            } else {
                cout << "Data Hakim tidak ditemukan." << endl;
            }

        } else if (pilihan == 3) {
            string noReg;
            cout << "Masukkan No Registrasi Terdakwa: "; cin >> noReg;

            // Mencari Terdakwa di seluruh list Hakim
            adrHakim P = L.first;
            bool found = false;

            while (P != nullptr) {
                adrTerdakwa C = findTerdakwa(P, noReg);
                if (C != nullptr) {
                    cout << "Ditemukan Terdakwa: " << C->info.nama << endl;
                    cout << "Status: Ditangani oleh Hakim " << P->info.nama << endl;
                    found = true;
                    break;
                }
                P = P->next;
            }

            if (!found) {
                cout << "Data Terdakwa tidak ditemukan di manapun." << endl;
            }
        }
        cout << endl;
    };
}
