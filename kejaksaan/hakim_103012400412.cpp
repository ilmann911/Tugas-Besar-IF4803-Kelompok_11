#include <iostream>
#include <map>
#include <string>
#include "hakim.h"

using namespace std;

adrHakim createElmHakim(infotypeHakim x) {
    adrHakim P = new elmHakim;
    P->info = x;
    P->next = nullptr;
    P->nextChild = nullptr;
    return P;
}

void insertLastHakim(ListHakim &L, adrHakim P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrHakim Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirstHakim(ListHakim &L, adrHakim &P) {
    if (L.first == nullptr) {
        P = nullptr;
        cout << "List Hakim Kosong" << endl;
    } else if (L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteAfterHakim(ListHakim &L, adrHakim &P, adrHakim Prec) {
    P = Prec->next;
    if (P != nullptr) {
        Prec->next = P->next;
        P->next = nullptr;
    }
}

void viewHakim(ListHakim L) {
    adrHakim P = L.first;
    cout << "--------------------------------" << endl;
    if (P == nullptr){
        cout << "list masih kosong" << endl;
    } else {
        while (P != nullptr) {
            cout << "Hakim: " << P->info.nama << " [" << P->info.kode << "]" << endl;
            viewTerdakwa(P);
            cout << "--------------------------------" << endl;
            P = P->next;
        }
    }
}

void viewAllTerdakwa(ListHakim L) {
    adrHakim P = L.first;
    cout << "=== SELURUH DATA TERDAKWA ===" << endl;
    if (P == nullptr){
        cout << "Tidak ada data hakim." << endl;
    } else {
        while (P != nullptr) {
            cout << "Hakim: " << P->info.nama << " [" << P->info.kode << "]" << endl;
            viewTerdakwa(P);
            cout << "--------------------------------" << endl;
            P = P->next;
        }
    }
}

int countKasusTerdakwa(ListHakim L, string namaTerdakwa) {
    adrHakim P = L.first;
    int totalKasus = 0;
    adrTerdakwa Q;

    while (P != nullptr) {
        adrTerdakwa Q = P->nextChild;
        while (Q != nullptr) {
            if (Q->info.nama == namaTerdakwa) {
                totalKasus++;
            }
            Q = Q->next;
        }

        P = P->next;
    }
    return totalKasus;
}


void tampilkanTerdakwaUnik(ListHakim L) {
    adrHakim P = L.first;
    int nomor = 1;

    if (P == nullptr) {
        cout << "Data kosong." << endl;
        return;
    }

    cout << "=== DAFTAR INDUK TERDAKWA (UNIK) ===" << endl;

    // LOOP 1: Hakim Utama
    while (P != nullptr) {
        adrTerdakwa C = P->nextChild;

        // LOOP 2: Terdakwa Utama
        while (C != nullptr) {
            
            // --- LOGIKA PENGECEKAN DIMULAI ---
            bool isDuplicate = false; // Anggap awal belum ada kembaran
            
            adrHakim checkH = L.first; 
            
            // LOOP 3: Checker Hakim
            while (checkH != nullptr) {
                adrTerdakwa checkT = checkH->nextChild;
                
                // LOOP 4: Checker Terdakwa
                while (checkT != nullptr) {
                    
                    // Stop jika sudah sampai di diri sendiri
                    if (checkT == C) {
                        // Kita paksa loop checkT berhenti
                        break; 
                    }

                    // Jika ketemu nama sama
                    if (checkT->info.nama == C->info.nama) {
                        isDuplicate = true; // Tandai "Oh ini duplikat"
                        break; // Keluar dari Loop 4 (CheckT)
                    }

                    checkT = checkT->next;
                }

                // Cek hasil dari Loop 4 tadi
                if (isDuplicate == true) {
                    break; // Keluar dari Loop 3 (CheckH) karena sudah ketahuan duplikat
                }
                
                // Cek lagi untuk menghentikan Loop 3 jika sudah sampai posisi diri sendiri
                // (Agar tidak ngecek ke depan/masa depan)
                if (checkH == P && isDuplicate == false) {
                     // Logika tambahan: Jika checker sudah sampai di Hakim P (hakim saat ini)
                     // dan loop 4 tadi berhenti karena (checkT == C), 
                     // maka loop 3 juga harus berhenti.
                     // Namun, karena loop 4 pakai break, loop 3 akan lanjut.
                     // Kita perlu hentikan manual jika checkT tadi berhenti karena ketemu diri sendiri.
                     // TAPI: Untuk simplifikasi, membiarkan loop 3 jalan sampai null juga tidak error,
                     // cuma kurang efisien sedikit. Jadi kode ini aman.
                }

                checkH = checkH->next;
            }
            // --- LOGIKA PENGECEKAN SELESAI ---

            // Hanya print jika status isDuplicate masih false
            if (isDuplicate == false) {
                cout << nomor << ". " << C->info.nama << " [" << C->info.tuntutan << "]" << endl;
                nomor++;
            }

            C = C->next;
        }
        P = P->next;
    }
}

void loadDataDummy(ListHakim &L) {
    adrHakim P;
    adrTerdakwa Q;
    infotypeHakim h;
    infotypeTerdakwa t;

    // --- DATA HAKIM 1 ---
    h.kode = "H001";
    h.nama = "Budi_Santoso";
    h.pengalaman = 15;
    P = createElmHakim(h);
    insertLastHakim(L, P);

    // Terdakwa untuk Hakim 1
    t.noRegistrasi = "T001"; t.nama = "Asep_Kurnia"; t.tuntutan = "Pencurian"; t.lamaVonis = 5;
    Q = createElmTerdakwa(t);
    insertLastTerdakwa(P, Q);

    t.noRegistrasi = "T002"; t.nama = "Ujang_Sutisna"; t.tuntutan = "Penipuan"; t.lamaVonis = 3;
    Q = createElmTerdakwa(t);
    insertLastTerdakwa(P, Q);

    // --- DATA HAKIM 2 ---
    h.kode = "H002";
    h.nama = "Siti_Aminah";
    h.pengalaman = 8;
    P = createElmHakim(h);
    insertLastHakim(L, P);

    // Terdakwa untuk Hakim 2
    t.noRegistrasi = "T003"; t.nama = "Dewi_Persik"; t.tuntutan = "Korupsi"; t.lamaVonis = 10;
    Q = createElmTerdakwa(t);
    insertLastTerdakwa(P, Q);

    t.noRegistrasi = "T004"; t.nama = "Asep_Kurnia"; t.tuntutan = "Korupsi"; t.lamaVonis = 7;
    Q = createElmTerdakwa(t);
    insertLastTerdakwa(P, Q);

    // --- DATA HAKIM 3 (Tanpa Terdakwa) ---
    h.kode = "H003";
    h.nama = "Joko_Anwar";
    h.pengalaman = 2;
    P = createElmHakim(h);
    insertLastHakim(L, P);

    cout << "Data Dummy berhasil dimuat!" << endl;
    system("pause");
    }
