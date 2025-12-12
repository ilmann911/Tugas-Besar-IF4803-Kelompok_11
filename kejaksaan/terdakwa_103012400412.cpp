#include "terdakwa.h"
#include <iostream>

using namespace std;

void createListChild(adrHakim P) {
    P->nextChild = nullptr;
}

void insertFirstTerdakwa(adrHakim P, adrTerdakwa c) {
    if (P->nextChild == nullptr) {
        P->nextChild = c;
    } else {
        c->next = P->nextChild;
        P->nextChild->prev = c;
        P->nextChild = c;
    }
}

void insertAfterTerdakwa(adrTerdakwa Prec, adrTerdakwa c) {
    c->next = Prec->next;
    c->prev = Prec;
    Prec->next = c;
    if (c->next != nullptr) {
        c->next->prev = c;
    }
}


void deleteLastTerdakwa(adrHakim P, adrTerdakwa &c) {
    if (P->nextChild == nullptr) {
        c = nullptr;
        cout << "Tidak ada terdakwa" << endl;
    } else {
        adrTerdakwa Q = P->nextChild;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        c = Q;
        if (c->prev == nullptr) {
            P->nextChild = nullptr;
        } else {
            c->prev->next = nullptr;
            c->prev = nullptr;
        }
    }
}

adrTerdakwa findTerdakwa(adrHakim P, string noRegistrasi) {
    adrTerdakwa Q = P->nextChild;
    while (Q != nullptr) {
        if (Q->info.noRegistrasi == noRegistrasi) {
            return Q;
        }
        Q = Q->next;
    }
    return nullptr;
}

