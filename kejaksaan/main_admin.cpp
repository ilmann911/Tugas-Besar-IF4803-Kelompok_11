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
        cout << "======== MENU TEST CASE ========" << endl;
        cout << "1. Hakim(Parent)" << endl;
        cout << "2. Terdakwa(Child)" << endl;
        cout << "3. View Semua Data" << endl;
        cout << "0. Kembali" << endl;
        cout << "================================" << endl;

        cout << "Pilihan: ";

        if (!(cin >> pilihan)) {
            cout << "--------------------------------" << endl;
            cout << "Pilihan tidak valid" << endl;
            cout << "Silakan coba lagi \n" << endl;

            cin.clear();
            cin.ignore(10000, '\n');
            pilihan = -99;
            system("pause");

            continue;
        }

        cout << endl;

        switch (pilihan)
        {
            case 1:
                menuHakim(L);
                continue;
            case 2:
                menuTerdakwa(L);
                continue;
            case 3:
                alldata(L);
                continue;
            default:
                if (pilihan != 0)
                {
                    cout << "--------------------------------" << endl;
                    cout << "Pilihan tidak valid \n" << endl;
                    system("pause");
                }
                continue;
        }
    }
}

void menuHakim(ListHakim &L) {
        int pilihan = -99;
        adrHakim PrecHakim;
        system("cls");
        while (pilihan != 0)
        {
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

            if (!(cin >> pilihan)) {
                cout << "--------------------------------" << endl;
                cout << "Pilihan tidak valid" << endl;
                cout << "Silakan coba lagi \n" << endl;

                cin.clear();
                cin.ignore(10000, '\n');
                pilihan = -99;
                system("pause");

                continue;
            }

            cout << endl;

            switch (pilihan)
            {
                case 1:
                    cout << "Insert First Hakim" << endl;
                    cout << "-----------------------------------" << endl;
                    cout << "Masukkan kode hakim baru: ";
                    cin >> x.kode;

                    if (findHakim(L, x.kode) != nullptr) {
                        cout << "-----------------------------------" << endl;
                        cout << "GAGAL: Kode Hakim " << x.kode << " sudah terdaftar!" << endl;
                    } else {

                        cout << "Masukkan nama hakim baru: ";
                        cin >> x.nama;
                        cout << "Masukkan lama pengalaman hakim baru (tahun): ";
                        cin >> x.pengalaman;
                        P = createElmHakim(x);
                        insertFirstHakim(L, P);
                        cout << "-----------------------------------" << endl;
                        cout << "Hakim berhasil ditambahkan di awal list." << endl;
                    }
                    cout << endl;
                    break;
                case 2:
                    cout << "Insert Last Hakim" << endl;
                    cout << "-----------------------------------" << endl;
                    cout << "Masukkan kode hakim baru: ";
                    cin >> x.kode;
                    if (findHakim(L, x.kode) != nullptr) {
                    cout << "-----------------------------------" << endl;
                    cout << "GAGAL: Kode Hakim " << x.kode << " sudah terdaftar!" << endl;
                    } else {
                        cout << "Masukkan nama hakim baru: ";
                        cin >> x.nama;
                        cout << "Masukkan lama pengalaman hakim baru (tahun): ";
                        cin >> x.pengalaman;
                        P = createElmHakim(x);
                        insertLastHakim(L, P);
                        cout << "-----------------------------------" << endl;
                        cout << "Hakim berhasil ditambahkan di akhir list." << endl;
                    }
                    cout << endl;
                    break;
                case 3:
                    cout << "Insert After Hakim" << endl;
                    cout << "-----------------------------------" << endl;
                    cout << "Masukkan kode hakim sebelumnya: ";
                    cin >> kodePrec;
                    PrecHakim = findHakim(L, kodePrec);

                    if (PrecHakim == nullptr) {
                        cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    } else {
                        cout << "Masukkan kode hakim baru: ";
                        cin >> x.kode;
                        if (findHakim(L, x.kode) != nullptr) {
                            cout << "-----------------------------------" << endl;
                            cout << "GAGAL: Kode Hakim " << x.kode << " sudah terdaftar!" << endl;
                        } else {
                            cout << "Masukkan nama hakim baru: ";
                            cin >> x.nama;
                            cout << "Masukkan lama pengalaman hakim baru (tahun): ";
                            cin >> x.pengalaman;
                            P = createElmHakim(x);
                            insertAfterHakim(L, P, PrecHakim);
                            cout << "-----------------------------------" << endl;
                            cout << "Hakim berhasil ditambahkan setelah Hakim kode " << kodePrec << "." << endl;
                        }
                    }
                cout << endl;
                break;
                case 4:
                    cout << "Delete First Hakim" << endl;
                    cout << "-----------------------------------" << endl;

                    if (L.first == nullptr) {
                        cout << "GAGAL: List Hakim Kosong! Tidak ada data yang bisa dihapus." << endl;
                    } else {
                        deleteFirstHakim(L, P);
                        if (P != nullptr) {
                            cout << "SUKSES: Hakim dengan kode " << P->info.kode << " berhasil dihapus dari awal list." << endl;
                        }
                    }
                    cout << endl;
                    break;
                case 5:
                    cout << "Delete Last Hakim" << endl;
                    cout << "-----------------------------------" << endl;

                    if (L.first == nullptr) {
                        cout << "GAGAL: List Hakim Kosong! Tidak ada data yang bisa dihapus." << endl;
                    } else {
                        deleteLastHakim(L, P);
                        if (P != nullptr) {
                            cout << "SUKSES: Hakim dengan kode " << P->info.kode << " berhasil dihapus dari akhir list." << endl;
                        }
                    }
                    cout << endl;
                    break;
                case 6:
                    cout << "Delete After Hakim" << endl;
                    cout << "-----------------------------------" << endl;

                    if (L.first == nullptr) {
                        cout << "GAGAL: List Hakim Kosong! Tidak ada data yang bisa dihapus." << endl;
                    }
                    else if (L.first->next == nullptr) {
                        cout << "GAGAL: Tidak bisa melakukan delete after, jumlah list kurang (hanya ada 1 data)." << endl;
                    }
                    else {
                        cout << "Masukkan kode hakim sebelumnya (Prec): ";
                        cin >> kodePrec;
                        cout << "-----------------------------------" << endl;

                        PrecHakim = findHakim(L, kodePrec);

                        if (PrecHakim == nullptr) {
                            cout << "GAGAL: Hakim prec (" << kodePrec << ") tidak ditemukan." << endl;
                        } else if (PrecHakim->next == nullptr) {
                            cout << "GAGAL: Tidak ada hakim setelah " << kodePrec << " untuk dihapus." << endl;
                        } else {
                            deleteAfterHakim(L, P, PrecHakim);
                            if (P != nullptr) {
                                cout << "SUKSES: Hakim dengan kode " << P->info.kode << " berhasil dihapus setelah " << kodePrec << "." << endl;
                            }
                        }
                    }
                    cout << endl;
                    break;
                case 7:
                    cout << "View Hakim" << endl;
                    viewHakim(L);
                    cout << endl;
                    break;
                case 8:
                    cout << "Search Hakim" << endl;
                    cout << "-----------------------------------" << endl;
                    if (L.first == nullptr){
                        cout << "List kosong \n" << endl;
                    }else{
                        cout << "Masukkan kode hakim yang dicari: ";
                        cin >> kodePrec;
                        PrecHakim = findHakim(L, kodePrec);
                        cout << "-----------------------------------" << endl;
                        if (PrecHakim != nullptr) {
                            cout << "Hakim ditemukan: " << PrecHakim->info.nama << ", Pengalaman: " << PrecHakim->info.pengalaman << " tahun,"<< " " << "Kode: " << PrecHakim->info.kode << endl;
                            cout << endl;
                        } else {
                            cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                            cout << endl;
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
    }

void menuTerdakwa(ListHakim &L) {
    adrHakim parentHakim;
    string noRegPrec;
    int pilihan = -99;
    adrTerdakwa PrecTerdakwa;
    system("cls");
    while (pilihan != 0)
    {
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

            if (!(cin >> pilihan)) {
                cout << "--------------------------------" << endl;
                cout << "Pilihan tidak valid" << endl;
                cout << "Silakan coba lagi \n" << endl;

                cin.clear();
                cin.ignore(10000, '\n');
                pilihan = -99;
                system("pause");

                continue;
            }

            cout << endl;

        switch (pilihan)
        {
            case 1:
                cout << "Insert First Terdakwa" << endl;
                cout << "-----------------------------------" << endl;
                cout << "Masukkan kode hakim: ";
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);
                if (parentHakim == nullptr) {
                    cout << "-----------------------------------" << endl;
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    break;
                } else {
                    cout << "Masukkan No Registrasi Terdakwa: ";
                    cin >> y.noRegistrasi;
                    // --- CEK DUPLIKASI TERDAKWA DI HAKIM TSB ---
                    if (findTerdakwa(parentHakim, y.noRegistrasi) != nullptr) {
                        cout << "-----------------------------------" << endl;
                        cout << "GAGAL: No Registrasi " << y.noRegistrasi << " sudah ada di Hakim ini! \n" << endl;
                    } else {
                        cout << "Masukkan Nama Terdakwa: "; cin >> y.nama;
                        cout << "Masukkan Tuntutan: "; cin >> y.tuntutan;
                        cout << "Masukkan Lama Vonis: "; cin >> y.lamaVonis;

                        Q = createElmTerdakwa(y);
                        insertFirstTerdakwa(parentHakim, Q);
                        cout << "-----------------------------------" << endl;
                        cout << "Terdakwa berhasil ditambahkan di awal list \n" << endl;
                    }
                }
                break;
            case 2:
                cout << "Insert Last Terdakwa" << endl;
                cout << "-----------------------------------" << endl;
                cout << "Masukkan kode hakim: ";
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);
                if (parentHakim == nullptr) {
                    cout << "-----------------------------------" << endl;
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                    break;
                }else{
                    cout << "Masukkan No Registrasi Terdakwa: ";
                    cin >> y.noRegistrasi;
                    if (findTerdakwa(parentHakim, y.noRegistrasi) != nullptr) {
                        cout << "-----------------------------------" << endl;
                        cout << "GAGAL: No Registrasi " << y.noRegistrasi << " sudah ada di Hakim ini!" << endl;
                    } else {
                        cout << "Masukkan Nama Terdakwa: "; cin >> y.nama;
                        cout << "Masukkan Tuntutan: "; cin >> y.tuntutan;
                        cout << "Masukkan Lama Vonis: "; cin >> y.lamaVonis;

                        Q = createElmTerdakwa(y);
                        insertLastTerdakwa(parentHakim, Q);
                        cout << "-----------------------------------" << endl;
                        cout << "Terdakwa berhasil ditambahkan di akhir list." << endl;
                    }
                }
                break;
            case 3:
                cout << "Insert After Terdakwa" << endl;
                cout << "-----------------------------------" << endl;
                cout << "Masukkan kode hakim: ";
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);
                if (parentHakim == nullptr) {
                    cout << "-----------------------------------" << endl;
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan \n" << endl;
                } else {
                    cout << "Masukkan No Registrasi Terdakwa Sebelumnya: ";
                    cin >> noRegPrec;
                    PrecTerdakwa = findTerdakwa(parentHakim, noRegPrec);

                    if (PrecTerdakwa == nullptr) {
                        cout << "-----------------------------------" << endl;
                        cout << "Terdakwa sebelumnya (" << noRegPrec << ") tidak ditemukan \n" << endl;
                    } else {
                        cout << "Masukkan No Registrasi Terdakwa Baru: ";
                        cin >> y.noRegistrasi;
                        if (findTerdakwa(parentHakim, y.noRegistrasi) != nullptr) {
                            cout << "-----------------------------------" << endl;
                            cout << "GAGAL: No Registrasi " << y.noRegistrasi << " sudah ada di Hakim ini! \n" << endl;
                        } else {
                            cout << "Masukkan Nama Terdakwa: "; cin >> y.nama;
                            cout << "Masukkan Tuntutan: "; cin >> y.tuntutan;
                            cout << "Masukkan Lama Vonis: "; cin >> y.lamaVonis;

                            Q = createElmTerdakwa(y);
                            insertAfterTerdakwa(PrecTerdakwa, Q);
                            cout << "-----------------------------------" << endl;
                            cout << "Terdakwa berhasil ditambahkan \n" << endl;
                        }
                    }
                }
                break;
            case 4:
                cout << "Delete First Terdakwa" << endl;
                cout << "-----------------------------------" << endl;
                cout << "Masukkan kode hakim: ";
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);

                if (parentHakim == nullptr) {
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                } else {
                    if (parentHakim->nextChild == nullptr) {
                        cout << "GAGAL: List Terdakwa kosong pada Hakim ini." << endl;
                    } else {
                        deleteFirstTerdakwa(parentHakim, Q);
                        if (Q != nullptr) {
                            cout << "SUKSES: Terdakwa " << Q->info.nama << " (" << Q->info.noRegistrasi << ") dihapus dari awal." << endl;
                        }
                    }
                }
                break;
            case 5:
                cout << "Delete Last Terdakwa" << endl;
                cout << "-----------------------------------" << endl;
                cout << "Masukkan kode hakim: ";
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);

                if (parentHakim == nullptr) {
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                } else {
                    if (parentHakim->nextChild == nullptr) {
                        cout << "GAGAL: List Terdakwa kosong pada Hakim ini." << endl;
                    } else {
                        deleteLastTerdakwa(parentHakim, Q);
                        if (Q != nullptr) {
                            cout << "SUKSES: Terdakwa " << Q->info.nama << " (" << Q->info.noRegistrasi << ") dihapus dari akhir." << endl;
                        }
                    }
                }
                break;
            case 6:
                cout << "Delete After Terdakwa" << endl;
                cout << "-----------------------------------" << endl;
                cout << "Masukkan kode hakim: ";
                cin >> kodePrec;
                parentHakim = findHakim(L, kodePrec);

                if (parentHakim == nullptr) {
                    cout << "Hakim dengan kode " << kodePrec << " tidak ditemukan." << endl;
                } else {
                    if (parentHakim->nextChild == nullptr) {
                         cout << "GAGAL: List Terdakwa kosong pada Hakim ini." << endl;
                    }
                    else if (parentHakim->nextChild->next == nullptr) {
                        cout << "GAGAL: Tidak bisa melakukan delete after, jumlah list kurang (hanya ada 1 data)." << endl;
                    }
                    else {
                        cout << "Masukkan no registrasi terdakwa sebelumnya: ";
                        cin >> noRegPrec;
                        PrecTerdakwa = findTerdakwa(parentHakim, noRegPrec);

                        if (PrecTerdakwa != nullptr && PrecTerdakwa->next != nullptr) {
                            deleteAfterTerdakwa(PrecTerdakwa, Q);
                            if (Q != nullptr) {
                                cout << "SUKSES: Terdakwa dengan no registrasi " << Q->info.noRegistrasi << " berhasil dihapus setelah " << noRegPrec << "." << endl;
                            }
                        } else {
                            cout << "GAGAL: Terdakwa (" << noRegPrec << ") tidak ditemukan atau tidak memiliki data setelahnya." << endl;
                        }
                    }
                }
                break;
            case 7:
                printAllTerdakwa(L);
                cout << endl;
                break;
            case 8:
                cout << "Search Terdakwa " << endl;
                cout << "-----------------------------------" << endl;
                if (L.first == nullptr){
                    cout << "List kosong \n" << endl;
                }else{
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
                }
                break;
            default:
                if (pilihan != 0)
                {
                    cout << "-----------------------------------" << endl;
                    cout << "Pilihan tidak valid \n" << endl;
                    system("pause");
                    cout << " " << endl;
                }
                continue;
        }
    }
}

void alldata(ListHakim L) {
    viewAllData(L);
    cout << endl;
    system("pause");
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
//}
