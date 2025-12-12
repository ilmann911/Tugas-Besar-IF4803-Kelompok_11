#include "terdakwa.h"
#include <iostream>

using namespace std;

adrTerdakwa createElmTerdakwa(infotypeTerdakwa x) {
    adrTerdakwa P = new elmTerdakwa;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertLastTerdakwa(adrHakim P, adrTerdakwa c) {
    if (P->nextChild == nullptr) {
        P->nextChild = c;
    } else {
        adrTerdakwa Q = P->nextChild;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = c;
        c->prev = Q; // DLL logic
    }
}

void deleteFirstTerdakwa(adrHakim P, adrTerdakwa &c) {
    if (P->nextChild == nullptr) {
        c = nullptr;
        cout << "Tidak ada terdakwa" << endl;
    } else if (P->nextChild->next == nullptr) {
        c = P->nextChild;
        P->nextChild = nullptr;
    } else {
        c = P->nextChild;
        P->nextChild = c->next;
        P->nextChild->prev = nullptr;
        c->next = nullptr;
    }
}

void deleteAfterTerdakwa(adrTerdakwa Prec, adrTerdakwa &c) {
    c = Prec->next;
    if (c != nullptr) {
        Prec->next = c->next;
        if (c->next != nullptr) {
            c->next->prev = Prec;
        }
        c->next = nullptr;
        c->prev = nullptr;
    }
}

void viewTerdakwa(adrHakim P) {
    adrTerdakwa Q = P->nextChild;
    if (Q == nullptr) {
        cout << "   (Tidak ada terdakwa)" << endl;
    }
    while (Q != nullptr) {
        cout << "   - " << Q->info.nama << " (" << Q->info.tuntutan << ")" << endl;
        Q = Q->next;
    }
}
