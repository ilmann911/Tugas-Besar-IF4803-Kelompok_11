#include "hakim.h"
#include "terdakwa.h"
#include "relation.h"

#include <iostream>

using namespace std;

void createListHakim(ListHakim &L){
    L.first = NULL;
    L.last = NULL;
}
adrHakim createElmHakim(infotypeHakim x){
    adrHakim P = new elmHakim;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    P->child = NULL;
    return P;
}
void insertFirstHakim(ListHakim &L, adrHakim P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}
void insertLastHakim(ListHakim &L, adrHakim P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}
void insertAfterHakim(ListHakim &L, adrHakim P, adrHakim Prec){
    P->next = Prec->next;
    P->prev = Prec;
    if(Prec->next != NULL){
        Prec->next->prev = P;
    } else {
        L.last = P;
    }
    Prec->next = P;
}
void deleteFirstHakim(ListHakim &L, adrHakim &P){
    P = L.first;
    if(L.first != NULL){
        L.first = L.first->next;
        if(L.first != NULL){
            L.first->prev = NULL;
        } else {
            L.last = NULL;
        }
        P->next = NULL;
    }
}
void deleteLastHakim(ListHakim &L, adrHakim &P){
    P = L.last;
    if(L.last != NULL){
        L.last = L.last->prev;
        if(L.last != NULL){
            L.last->next = NULL;
        } else {
            L.first = NULL;
        }
        P->prev = NULL;
    }
}    
void deleteAfterHakim(ListHakim &L, adrHakim &P, adrHakim Prec){
    P = Prec->next;
    if(P != NULL){
        Prec->next = P->next;
        if(P->next != NULL){
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}
adrHakim findHakim(ListHakim L, string kode){
    adrHakim P = L.first;
    while(P != NULL){
        if(P->info.kode == kode){
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void viewHakim(ListHakim L){
    adrHakim P = L.first;
    if(P == NULL){
        cout << "Data hakim kosong!" << endl;
    } else {
        cout << "Daftar Hakim:" << endl;
        while(P != NULL){
            cout << "Kode: " << P->info.kode << ", Nama: " << P->info.nama << ", Pengalaman: " << P->info.pengalaman << " tahun" << endl;
            P = P->next;
        }
    }
}
adrHakim findMaxPengalaman(ListHakim L){
    adrHakim P = L.first;
    adrHakim maxP = NULL;
    int maxPengalaman = -1;
    while(P != NULL){
        if(P->info.pengalaman > maxPengalaman){
            maxPengalaman = P->info.pengalaman;
            maxP = P;
        }
        P = P->next;
    }
    return maxP;
}
void countHakim(ListHakim L, int &count){
    adrHakim P = L.first;
    count = 0;
    while(P != NULL){
        count++;
        P = P->next;
    }
}