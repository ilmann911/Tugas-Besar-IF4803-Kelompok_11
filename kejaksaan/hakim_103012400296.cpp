#include <iostream>
#include "hakim.h"

using namespace std;

void createListHakim(ListHakim &L) {
    L.first = nullptr;
}

void insertFirstHakim(ListHakim &L, adrHakim P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertAfterHakim(ListHakim &L, adrHakim P, adrHakim Prec) {
    P->next = Prec->next;
    Prec->next = P;
}

void deleteLastHakim(ListHakim &L, adrHakim &P) {
    if (L.first == nullptr) {
        P = nullptr;
        cout << "List Hakim Kosong" << endl;
    } else if (L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    } else {
        adrHakim Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

adrHakim findHakim(ListHakim L, string kode) {
    adrHakim P = L.first;
    while (P != nullptr) {
        if (P->info.kode == kode) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

int countTerdakwa(adrHakim P) {
    int count = 0;
    adrTerdakwa Q = P->nextChild;
    while (Q != nullptr) {
        count++;
        Q = Q->next;
    }
    return count;
}

void printAllTerdakwa(ListHakim L) {
    cout << "=== DAFTAR SELURUH TERDAKWA ===" << endl;
    adrHakim P = L.first;
    bool adaData = false;

    while (P != nullptr) {
        adrTerdakwa Q = P->nextChild;

        while (Q != nullptr) {
            cout << "- " << Q->info.nama
                 << " (No.Reg: " << Q->info.noRegistrasi
                 << ", Tuntutan: " << Q->info.tuntutan
                 << ", Lama Vonis: " << Q->info.lamaVonis << ")" << endl;

            adaData = true;
            Q = Q->next;
        }
        P = P->next;
    }

    if (!adaData) {
        cout << "Belum ada data terdakwa sama sekali." << endl;
    }
}
