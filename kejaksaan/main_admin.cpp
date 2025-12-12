#include <iostream>
#include "main.h"

using namespace std;


void menuAdmin(ListHakim &L) {
    int pilihan;
    while (pilihan != 0) {
        cout << "========== MENU ADMIN ==========" << endl;
        cout << "1. Tambah Hakim (Parent)" << endl;
        cout << "2. Tambah Terdakwa (Child)" << endl;
        cout << "3. Hapus Hakim" << endl;
        cout << "4. Hapus Terdakwa" << endl;
        cout << "5. Lihat Semua Data" << endl;
        cout << "0. Kembali" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1) {
            infotypeHakim dataH;
            cout << "Masukkan Kode Hakim      : "; cin >> dataH.kode;
            cout << "Masukkan Nama Hakim      : "; cin >> dataH.nama;
            cout << "Masukkan Pengalaman (thn): "; cin >> dataH.pengalaman;

            insertLastHakim(L, createElmHakim(dataH));
            cout << "[Success] Data Hakim berhasil ditambahkan." << endl;

        } else if (pilihan == 2) {
            // --- INSERT CHILD ---
            string kodeHakim;
            cout << "Masukkan Kode Hakim Parent: "; cin >> kodeHakim;

            adrHakim H = findHakim(L, kodeHakim);
            if (H != nullptr) {
                infotypeTerdakwa dataT;
                cout << "Masukkan No Registrasi   : "; cin >> dataT.noRegistrasi;
                cout << "Masukkan Nama Terdakwa   : "; cin >> dataT.nama;
                cout << "Masukkan Tuntutan        : "; cin >> dataT.tuntutan;

                insertLastTerdakwa(H, createElmTerdakwa(dataT));
                cout << "[Success] Data Terdakwa berhasil ditambahkan ke Hakim " << H->info.nama << "." << endl;
            } else {
                cout << "[Error] Hakim dengan kode tersebut tidak ditemukan." << endl;
            }

        } else if (pilihan == 3) {
            // --- DELETE PARENT ---
            string kode;
            cout << "Masukkan Kode Hakim yang akan dihapus: "; cin >> kode;

            adrHakim P = L.first;
            adrHakim prec = nullptr;

            while (P != nullptr && P->info.kode != kode) {
                prec = P;
                P = P->next;
            }

            if (P != nullptr) {
                adrHakim deletedNode;
                if (P == L.first) {
                    deleteFirstHakim(L, deletedNode);
                } else if (P->next == nullptr) {
                    deleteLastHakim(L, deletedNode);
                } else {
                    deleteAfterHakim(L, deletedNode, prec);
                }
                cout << "[Success] Hakim " << deletedNode->info.nama << " berhasil dihapus." << endl;
            } else {
                cout << "[Error] Data Hakim tidak ditemukan." << endl;
            }

        } else if (pilihan == 4) {
            string kodeHakim, noReg;
            cout << "Masukkan Kode Hakim Parent: "; cin >> kodeHakim;

            adrHakim H = findHakim(L, kodeHakim);
            if (H != nullptr) {
                cout << "Masukkan No Registrasi Terdakwa: "; cin >> noReg;

                adrTerdakwa C = H->nextChild;
                adrTerdakwa precC = nullptr;
                bool found = false;

                while (C != nullptr) {
                    if (C->info.noRegistrasi == noReg) {
                        found = true;
                        break;
                    }
                    precC = C;
                    C = C->next;
                }

                if (found) {
                    adrTerdakwa deletedChild;
                    if (precC == nullptr) {
                        deleteFirstTerdakwa(H, deletedChild);
                    } else if (C->next == nullptr) {
                        deleteLastTerdakwa(H, deletedChild);
                    } else {
                        deleteAfterTerdakwa(precC, deletedChild);
                    }
                    cout << "[Success] Terdakwa " << deletedChild->info.nama << " berhasil dihapus." << endl;
                } else {
                    cout << "[Error] Terdakwa tidak ditemukan." << endl;
                }
            } else {
                cout << "[Error] Hakim tidak ditemukan." << endl;
            }

        } else if (pilihan == 5) {
            viewHakim(L);
        }
        cout << endl;
    };
}
