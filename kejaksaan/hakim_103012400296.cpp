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
