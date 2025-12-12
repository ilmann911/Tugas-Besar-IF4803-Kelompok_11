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
