#include "terdakwa.h"

void createListTerdakwa(adrHakim P) {
    P->nextChild = NULL;
}

adrTerdakwa createElmTerdakwa(infotypeTerdakwa x) {
    adrTerdakwa P = new elmTerdakwa;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirstTerdakwa(adrHakim P, adrTerdakwa c) {
    if (P->nextChild == NULL) {
        P->nextChild = c;
    } else {
        c->next = P->nextChild;
        P->nextChild->prev = c;
        P->nextChild = c;
    }
}

void insertLastTerdakwa(adrHakim P, adrTerdakwa c) {
    if (P->nextChild == NULL) {
        P->nextChild = c;
    } else {
        adrTerdakwa Q = P->nextChild;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = c;
        c->prev = Q;
    }
}

void insertAfterTerdakwa(adrTerdakwa Prec, adrTerdakwa c) {
    c->next = Prec->next;
    c->prev = Prec;
    Prec->next = c;
    if (c->next != NULL) {
        c->next->prev = c;
    }
}

void deleteFirstTerdakwa(adrHakim P, adrTerdakwa &c) {
    if (P->nextChild == NULL) {
        c = NULL;
        cout << "Tidak ada terdakwa" << endl;
    } else if (P->nextChild->next == NULL) {
        c = P->nextChild;
        P->nextChild = NULL;
    } else {
        c = P->nextChild;
        P->nextChild = c->next;
        P->nextChild->prev = NULL;
        c->next = NULL;
    }
}

void deleteLastTerdakwa(adrHakim P, adrTerdakwa &c) {
    if (P->nextChild == NULL) {
        c = NULL;
        cout << "Tidak ada terdakwa" << endl;
    } else {
        adrTerdakwa Q = P->nextChild;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        c = Q;
        if (c->prev == NULL) {
            P->nextChild = NULL;
        } else {
            c->prev->next = NULL;
            c->prev = NULL;
        }
    }
}

void deleteAfterTerdakwa(adrTerdakwa Prec, adrTerdakwa &c) {
    c = Prec->next;
    if (c != NULL) {
        Prec->next = c->next;
        if (c->next != NULL) {
            c->next->prev = Prec;
        }
        c->next = NULL;
        c->prev = NULL;
    }
}

adrTerdakwa findTerdakwa(adrHakim P, string noRegistrasi) {
    adrTerdakwa Q = P->nextChild;
    while (Q != NULL) {
        if (Q->info.noRegistrasi == noRegistrasi) {
            return Q;
        }
        Q = Q->next;
    }
    return NULL;
}

void viewTerdakwa(adrHakim P) {
    adrTerdakwa Q = P->nextChild;
    if (Q == NULL) {
        cout << "   (Tidak ada terdakwa)" << endl;
    }
    while (Q != NULL) {
        cout << "   > " << Q->info.nama << " [" << Q->info.tuntutan << "]" << endl;
        Q = Q->next;
    }
}
