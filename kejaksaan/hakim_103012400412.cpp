#include <iostream>
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
    t.noRegistrasi = "T001"; t.nama = "Asep_Kurnia"; t.tuntutan = "Pencurian";
    Q = createElmTerdakwa(t);
    insertLastTerdakwa(P, Q);

    t.noRegistrasi = "T002"; t.nama = "Ujang_Sutisna"; t.tuntutan = "Penipuan";
    Q = createElmTerdakwa(t);
    insertLastTerdakwa(P, Q);

    // --- DATA HAKIM 2 ---
    h.kode = "H002";
    h.nama = "Siti_Aminah";
    h.pengalaman = 8;
    P = createElmHakim(h);
    insertLastHakim(L, P);

    // Terdakwa untuk Hakim 2
    t.noRegistrasi = "T003"; t.nama = "Dewi_Persik"; t.tuntutan = "Korupsi";
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
