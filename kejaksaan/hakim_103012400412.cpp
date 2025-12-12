#include <iostream>
#include "hakim.h"

using namespace std;

void createListHakim(ListHakim &L) {
    L.first = nullptr;
}

adrHakim createElmHakim(infotypeHakim x) {
    adrHakim P = new elmHakim;
    P->info = x;
    P->next = nullptr;
    P->nextChild = nullptr;
    return P;
}

void insertFirstHakim(ListHakim &L, adrHakim P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
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

void insertAfterHakim(ListHakim &L, adrHakim P, adrHakim Prec) {
    P->next = Prec->next;
    Prec->next = P;
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

void deleteAfterHakim(ListHakim &L, adrHakim &P, adrHakim Prec) {
    P = Prec->next;
    if (P != nullptr) {
        Prec->next = P->next;
        P->next = nullptr;
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
