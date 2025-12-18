#include <iostream>
#include "main.h"

using namespace std;

void menuUser(ListHakim L) {
    int pilihan = -99;

    ListHakim LH;
    //createListHakim(LH);

    //loadDataDummy(LH);

    system("cls");

    while (pilihan != 0) {
        cout << "================ MENU STUDY CASE ================" << endl;
        cout << "1. Menjumlahkan terdakawa dari seorang hakim" << endl;
        cout << "2. Mengurutkan hakim berdasarkan pengalaman" << endl;
        cout << "3. Menampilkan terdakwa dengan vonis diatas X tahun" << endl;
        cout << "4. Menambahkan hakim dengan pengalaman tertentu" << endl;
        cout << "5. Menghapus hakim dengan pengalaman tertentu" << endl;
        cout << "6. Menambah terdakwa dengan lama vonis tertentu" << endl;
        cout << "7. Menghapus terdakwa dengan lama vonis tertentu" << endl;
        cout << "8. Mencari hakim dengan terdakwa tertentu" << endl;
        cout << "0. Kembali" << endl;
        cout << "=================================================" << endl;

        cout << "Pilihan: ";

            if (!(cin >> pilihan)) {
                cout << "-------------------------------------------------" << endl;
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
            {
                string kodeHakim;
                cout << "Masukkan kode hakim: ";
                cin >> kodeHakim;
                adrHakim hakim = findHakim(L, kodeHakim);
                if (hakim != nullptr) {
                    int jumlahTerdakwa = countTerdakwa(hakim);
                    cout << "Jumlah terdakwa yang ditangani oleh hakim " << hakim->info.nama << " adalah: " << jumlahTerdakwa << endl;
                    cout << endl;
                } else {
                    cout << "Hakim dengan kode " << kodeHakim << " tidak ditemukan." << endl;
                    cout << endl;
                }
            }
            break;
        case 2:
            {
                ListHakim sortedList;
                createListHakim(sortedList);

                adrHakim current = L.first;
                while (current != nullptr) {
                    adrHakim next = current->next;
                    current->next = nullptr;
                    insertSortedHakim(sortedList, current);
                    current = next;
                }

                cout << "Hakim setelah diurutkan berdasarkan pengalaman:" << endl;
                viewHakim(sortedList);
                cout << endl;
                break;
            }
        case 3:
            {
                int x;
                cout << "Masukkan nilai X (tahun): ";
                cin >> x;
                cout << "Terdakwa dengan vonis diatas " << x << " tahun:" << endl;
                adrHakim P = L.first;
                bool found = false;

                while (P != nullptr) {
                    adrTerdakwa Q = P->nextChild;
                    while (Q != nullptr) {
                        if (Q->info.lamaVonis > x) {
                            cout << "- " << Q->info.nama << " (Vonis: " << Q->info.lamaVonis << " tahun)" << endl;
                            found = true;
                        }
                        Q = Q->next;
                    }
                    P = P->next;
                }

                if (!found) {
                    cout << "Tidak ada terdakwa dengan vonis diatas " << x << " tahun." << endl;
                }
                cout << endl;
            }
            break;
        case 4:
            {
                infotypeHakim x;
                adrHakim P;
                cout << "Masukkan data Hakim baru (kode, nama, pengalaman): ";
                cin >> x.kode >> x.nama >> x.pengalaman;
                P = createElmHakim(x);
                insertSortedHakim(L, P);
                cout << "Hakim berhasil ditambahkan." << endl;
                cout << endl;
            }
            break;
        case 5:
            {
                int pengalaman;
                cout << "Masukkan pengalaman hakim yang akan dihapus: ";
                cin >> pengalaman;

                adrHakim P = L.first;
                adrHakim prec = nullptr;
                bool found = false;

                while (P != nullptr) {
                    if (P->info.pengalaman == pengalaman) {
                        found = true;
                        break;
                    }
                    prec = P;
                    P = P->next;
                }

                if (found) {
                    adrHakim deletedNode;
                    if (P == L.first) {
                        deleteFirstHakim(L, deletedNode);
                    } else if (P->next == nullptr) {
                        deleteLastHakim(L, deletedNode);
                    } else {
                        deleteAfterHakim(L, deletedNode, prec);
                    }
                    cout << "Hakim dengan pengalaman " << pengalaman << " tahun berhasil dihapus." << endl;
                } else {
                    cout << "Tidak ditemukan hakim dengan pengalaman " << pengalaman << " tahun." << endl;
                }
                cout << endl;
            }
            break;
        case 6:
            {
                string kodeHakim;
                infotypeTerdakwa y;
                cout << "Masukkan kode hakim: ";
                cin >> kodeHakim;
                adrHakim hakim = findHakim(L, kodeHakim);
                if (hakim != nullptr) {
                    cout << "Masukkan data Terdakwa baru (noRegistrasi, nama, tuntutan, lamaVonis): ";
                    cin >> y.noRegistrasi >> y.nama >> y.tuntutan >> y.lamaVonis;
                    adrTerdakwa Q = createElmTerdakwa(y);
                    insertLastTerdakwa(hakim, Q);
                    cout << "Terdakwa berhasil ditambahkan ke hakim " << hakim->info.nama << "." << endl;
                    cout << endl;
                } else {
                    cout << "Hakim dengan kode " << kodeHakim << " tidak ditemukan." << endl;
                    cout << endl;
                }
            }
            break;
        case 7:
            {
                string kodeHakim;
                int lamaVonis;
                cout << "Masukkan kode hakim: ";
                cin >> kodeHakim;
                adrHakim hakim = findHakim(L, kodeHakim);
                if (hakim != nullptr) {
                    cout << "Masukkan lama vonis terdakwa yang akan dihapus: ";
                    cin >> lamaVonis;

                    adrTerdakwa P = hakim->nextChild;
                    adrTerdakwa prec = nullptr;
                    bool found = false;

                    while (P != nullptr) {
                        if (P->info.lamaVonis == lamaVonis) {
                            found = true;
                            break;
                        }
                        prec = P;
                        P = P->next;
                    }

                    if (found) {
                        adrTerdakwa deletedNode;
                        if (P == hakim->nextChild) {
                            deleteFirstTerdakwa(hakim, deletedNode);
                        } else if (P->next == nullptr) {
                            deleteLastTerdakwa(hakim, deletedNode);
                        } else {
                            deleteAfterTerdakwa(prec, deletedNode);
                        }
                        cout << "Terdakwa dengan lama vonis " << lamaVonis << " tahun berhasil dihapus." << endl;
                    } else {
                        cout << "Tidak ditemukan terdakwa dengan lama vonis " << lamaVonis << " tahun." << endl;
                    }
                    cout << endl;
                } else {
                    cout << "Hakim dengan kode " << kodeHakim << " tidak ditemukan." << endl;
                    cout << endl;
                }
            }
            break;
        case 8:
            {
                string noRegistrasi;
                cout << "Masukkan no registrasi terdakwa yang dicari: ";
                cin >> noRegistrasi;

                adrHakim P = L.first;
                bool found = false;

                while (P != nullptr) {
                    adrTerdakwa Q = findTerdakwa(P, noRegistrasi);
                    if (Q != nullptr) {
                        cout << "Terdakwa " << Q->info.nama << " ditangani oleh Hakim " << P->info.nama << "." << endl;
                        found = true;
                        break;
                    }
                    P = P->next;
                }

                if (!found) {
                    cout << "Terdakwa dengan no registrasi " << noRegistrasi << " tidak ditemukan." << endl;
                }
                cout << endl;
            }
        default:
                if(pilihan != 0)
                {
                    cout << "Pilihan tidak valid." << endl;
                    system("pause");
                }
                continue;
        }
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
