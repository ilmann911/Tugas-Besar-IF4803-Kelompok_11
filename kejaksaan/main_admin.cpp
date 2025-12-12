#include <iostream>
#include "main.h"

using namespace std;

ListHakim L;
adrHakim P;
adrTerdakwa Q;
infotypeHakim x;
infotypeTerdakwa y;
string kodePrec;

void menuAdmin(ListHakim &L) {
    int pilihan = -99;
    while (pilihan != 0)
    {
        system("cls");
        cout << "========== MENU ADMIN ==========" << endl;
        cout << "1. Hakim(Parent)" << endl;
        cout << "2. Terdakwa(Child)" << endl;
        cout << "0. Kembali" << endl;
        cout << "================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan)
        {
            case 1:
                cout << "Kamu masuk ke Menu Hakim." << endl;
                menuHakim(L);
                continue;
            case 2:
                cout << "Kamu masuk ke Menu Terdakwa." << endl;
                menuTerdakwa(L);
                continue;
            default:
                if (pilihan != 0)
                {
                    cout << "Pilihan tidak valid." << endl;
                    system("pause");
                }
                continue;
        }
    }
}

void menuHakim(ListHakim &L) {
        int pilihan = -99;
        adrHakim PrecHakim;
        while (pilihan != 0)
        {
            system("cls");
            cout << "======= MENU HAKIM (PARENT) =======" << endl;
            cout << "1. Insert First" << endl;
            cout << "2. Insert Last" << endl;
            cout << "3. Insert After" << endl;
            cout << "4. Delete First" << endl;
            cout << "5. Delete Last" << endl;
            cout << "6. Delete After" << endl;
            cout << "7. View Hakim" << endl;
            cout << "8. Search Hakim" << endl;
            cout << "0. Kembali" << endl;
            cout << "===================================" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;
            cout << endl;

            switch (pilihan)
            {
                case 1:
                    cout << "Insert First Hakim" << endl;
                    cin >> x.kode >> x.nama >> x.pengalaman;
                    P = createElmHakim(x);
                    insertFirstHakim(L, P);
                    cout << "Hakim berhasil ditambahkan di awal list." << endl;
                    break;
                case 2:
                    cout << "Insert Last Hakim" << endl;
                    cin >> x.kode >> x.nama >> x.pengalaman;
                    P = createElmHakim(x);
                    insertLastHakim(L, P);
                    cout << "Hakim berhasil ditambahkan di akhir list." << endl;
                    break;
                case 3:
                    cout << "Insert After Hakim" << endl;
                    cin >> kodePrec;
                    cout << "Masukkan data Hakim baru: ";
                    cin >> x.kode >> x.nama >> x.pengalaman;
                    P = createElmHakim(x);
                    PrecHakim = findHakim(L, kodePrec);
                    if (PrecHakim != nullptr) {
                        insertAfterHakim(L, P, PrecHakim);
                        cout << "Hakim berhasil ditambahkan setelah Hakim dengan kode " << kodePrec << "." << endl;
                    } else {
                        cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    }
                    break;
                case 4:
                    cout << "Delete First Hakim" << endl;
                    deleteFirstHakim(L, P);
                    cout << "Hakim dengan kode " << P->info.kode << " berhasil dihapus dari awal list." << endl;
                    break;
                case 5:
                    cout << "Delete Last Hakim" << endl;
                    deleteLastHakim(L, P);
                    cout << "Hakim dengan kode " << P->info.kode << " berhasil dihapus dari akhir list." << endl;
                    break;
                case 6:
                    cout << "Delete After Hakim" << endl;
                    cin >> kodePrec;
                    PrecHakim = findHakim(L, kodePrec);
                    if (PrecHakim != nullptr && PrecHakim->next != nullptr) {
                        deleteAfterHakim(L, P, PrecHakim);
                        cout << "Hakim dengan kode " << P->info.kode << " berhasil dihapus setelah Hakim dengan kode " << kodePrec << "." << endl;
                    } else {
                        cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan atau tidak memiliki Hakim setelahnya." << endl;
                    }
                    break;
                case 7:
                    cout << "View Hakim" << endl;  
                    viewHakim(L);
                    break;
                case 8:
                    cout << "Search Hakim" << endl;
                    cin >> kodePrec;
                    PrecHakim = findHakim(L, kodePrec);
                    if (PrecHakim != nullptr) {
                        cout << "Hakim ditemukan: " << PrecHakim->info.nama << ", Pengalaman: " << PrecHakim->info.pengalaman << " tahun." << "dengan kode" << PrecHakim->info.kode << endl;
                    } else {
                        cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    }
                    break;
                default:
                    if (pilihan != 0)
                    {
                        cout << "Pilihan tidak valid." << endl;
                        system("pause");
                    }
                    continue;
            }
        }
    }
    
void menuTerdakwa(ListHakim &L) {
    adrHakim parentHakim;
    string noRegPrec;
    int pilihan = -99;
    adrTerdakwa PrecTerdakwa;
    while (pilihan != 0)
    {
        system("cls");
        cout << "====== MENU TERDAKWA (CHILD) ======" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Insert After" << endl;
        cout << "4. Delete First" << endl;
        cout << "5. Delete Last" << endl;
        cout << "6. Delete After" << endl;
        cout << "7. View Terdakwa" << endl;
        cout << "8. Search Terdakwa" << endl;
        cout << "0. Kembali" << endl;
        cout << "===================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan)
        {
            case 1:
                cout << "Insert First Terdakwa" << endl;
                cout << "Masukkan kode hakim: " << endl;
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);
                if (parentHakim == nullptr) {
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    break;
                }else{
                    cin >> y.noRegistrasi >> y.nama >> y.tuntutan;
                    Q = createElmTerdakwa(y);
                    insertFirstTerdakwa(parentHakim, Q);
                    cout << "Terdakwa berhasil ditambahkan di awal list." << endl;
                }
                break;
            case 2:
                cout << "Insert Last Terdakwa" << endl;
                cout << "Masukkan kode hakim: " << endl;
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);
                if (parentHakim == nullptr) {
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    break;
                }else{
                    cin >> y.noRegistrasi >> y.nama >> y.tuntutan;
                    Q = createElmTerdakwa(y);
                    insertLastTerdakwa(parentHakim, Q);
                    cout << "Terdakwa berhasil ditambahkan di akhir list." << endl;
                }
                break;
            case 3:
                cout << "Insert After Terdakwa" << endl;
                cout << "Masukkan kode hakim: " << endl;
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);
                if (parentHakim == nullptr) {
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    break;
                }else{
                    cout << "Masukkan data Terdakwa baru: ";
                    cin >> y.noRegistrasi >> y.nama >> y.tuntutan;
                    Q = createElmTerdakwa(y);
                    cout << "Masukkan no registrasi terdakwa sebelumnya: ";
                    cin >> noRegPrec;
                    PrecTerdakwa = findTerdakwa(parentHakim, noRegPrec);
                    if (PrecTerdakwa != nullptr) {
                        insertAfterTerdakwa(parentHakim, Q, PrecTerdakwa);
                        cout << "Terdakwa berhasil ditambahkan setelah Terdakwa dengan no registrasi " << noRegPrec << "." << endl;
                    } else {
                        cout << "Terdakwa dengan no registrasi " << noRegPrec << " tidak ditemukan." << endl;
                    }
                }
                break;
            case 4:
                cout << "Delete First Terdakwa" << endl;
                cout << "Masukkan kode hakim: " << endl;
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);
                if (parentHakim == nullptr) {
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    break;
                }else{
                    deleteFirstTerdakwa(parentHakim, Q);
                    cout << "Terdakwa dengan no registrasi " << Q->info.noRegistrasi << " berhasil dihapus dari awal list." << endl;
                }
                break;
            case 5:
                cout << "Delete Last Terdakwa" << endl;
                cout << "Masukkan kode hakim: " << endl;
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);
                if (parentHakim == nullptr) {
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    break;
                }else{
                    deleteLastTerdakwa(parentHakim, Q);
                    cout << "Terdakwa dengan no registrasi " << Q->info.noRegistrasi << " berhasil dihapus dari akhir list." << endl;
                }
                break;
            case 6:
                cout << "Delete After Terdakwa" << endl;
                cout << "Masukkan kode hakim: " << endl;
                cin >> kodePrec;    
                parentHakim = findHakim(L, kodePrec);
                if (parentHakim == nullptr) {
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    break;
                }else{
                    cout << "Masukkan no registrasi terdakwa sebelumnya: ";
                    cin >> noRegPrec;
                    PrecTerdakwa = findTerdakwa(parentHakim, noRegPrec);
                    if (PrecTerdakwa != nullptr && PrecTerdakwa->next != nullptr) {
                        deleteAfterTerdakwa(parentHakim, Q, PrecTerdakwa);
                        cout << "Terdakwa dengan no registrasi " << Q->info.noRegistrasi << " berhasil dihapus setelah Terdakwa dengan no registrasi " << noRegPrec << "." << endl;
                    } else {
                        cout << "Terdakwa dengan no registrasi " << noRegPrec << " tidak ditemukan atau tidak memiliki Terdakwa setelahnya." << endl;
                    }
                break;
            case 7:
                cout << " View Terdakwa " << endl;
                cout << "Masukkan kode hakim: " << endl;
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);
                if (parentHakim == nullptr) {
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    break;
                }else{
                    viewTerdakwa(parentHakim);  
                }
                break;
            case 8:
                cout << " Search Terdakwa " << endl;
                cout << "Masukkan kode hakim: " << endl;
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);
                if (parentHakim == nullptr) {
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    break;
                }else{
                    cout << "Masukkan no registrasi terdakwa yang dicari: ";
                    cin >> noRegPrec;
                    PrecTerdakwa = findTerdakwa(parentHakim, noRegPrec);
                    if (PrecTerdakwa != nullptr) {
                        cout << "Terdakwa ditemukan: " << PrecTerdakwa->info.nama << ", Tuntutan: " << PrecTerdakwa->info.tuntutan << "." << "dengan no registrasi" << PrecTerdakwa->info.noRegistrasi << endl;
                    } else {
                        cout << "Terdakwa dengan no registrasi " << noRegPrec << " tidak ditemukan." << endl;
                    }
                }
                break;
            default:
                if (pilihan != 0)
                {
                    cout << "Pilihan tidak valid." << endl;
                    system("pause");
                }
                continue;
        }
    }
    
    
    
    
    /*int pilihan;
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
    };*/
}
