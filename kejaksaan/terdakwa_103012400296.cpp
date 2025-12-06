#include "hakim.h"
#include "terdakwa.h"
#include "relation.h"

#include <iostream>

using namespace std;

void createListTerdakwa(ListTerdakwa &L){
    L.first = NULL;
}
adrTerdakwa createElmTerdakwa(infotypeTerdakwa x){
    adrTerdakwa P = new elmTerdakwa;
    P->info = x;
    P->next = NULL;
    return P;
}
void insertFirstTerdakwa(ListTerdakwa &L, adrTerdakwa P){
    if(L.first == NULL){
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}
void insertLastTerdakwa(ListTerdakwa &L, adrTerdakwa P){
    if(L.first == NULL){
        L.first = P;
    } else {
        adrTerdakwa Q = L.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}
void insertAfterTerdakwa(ListTerdakwa &L, adrTerdakwa P, adrTerdakwa Prec){
}
void deleteFirstTerdakwa(ListTerdakwa &L, adrTerdakwa &P);
void deleteLastTerdakwa(ListTerdakwa &L, adrTerdakwa &P);    
void deleteAfterTerdakwa(ListTerdakwa &L, adrTerdakwa &P, adrTerdakwa Prec);
adrTerdakwa findTerdakwa(ListTerdakwa L, string noRegistrasi);
void viewTerdakwa(ListTerdakwa L);
void countTerdakwa(ListTerdakwa L, int &count);
