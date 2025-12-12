#include <iostream>
#include "main.h"

using namespace std;

void menuUser(ListHakim L) {
   int pilihan = -99;
   while (pilihan != 0) {
        system("cls");
        cout << "============== MENU STUDY CASE ===============" << endl;
        cout << "1. Menjumlahkan terdakawa dari seorang hakim" << endl;
        cout << "2. Jumlah kasus dari seorang terdakwa" << endl;
        cout << "3. Menampilkan terdakwa dengan jumlah kasus terbanyak" << endl;
        cout << "0. Kembali" << endl;
        cout << "===============================================" << endl;
    }
    cout << "Pilihan: ";
    cin >> pilihan;
    cout << endl;
    switch (pilihan)
    {
    case 1:
        {
            string kodeHakim;
            cout << "Masukkan kode hakim: ";
            cin >> kodeHakim;
            adrHakim hakim = findHakim(L, kodeHakim);
            if (hakim != nullptr) {
                int jumlahTerdakwa = countTerdakwa(hakim);
                cout << "Jumlah terdakwa yang ditangani oleh hakim " << hakim->info.nama << " adalah: " << jumlahTerdakwa << endl;
            } else {
                cout << "Hakim dengan kode " << kodeHakim << " tidak ditemukan." << endl;
            }
        }
        break;
    
    default:
        exit(1);
    }
   
   
   
   
    /*int pilihan;
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
    };*/
}
