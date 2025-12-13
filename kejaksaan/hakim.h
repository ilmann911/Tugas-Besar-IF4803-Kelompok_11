#ifndef HAKIM_H_INCLUDED
#define HAKIM_H_INCLUDED

#include <iostream>
#include <utility>

typedef struct elmHakim *adrHakim;

#include "terdakwa.h"

using namespace std;

struct infotypeHakim {
    string kode;
    string nama;
    int pengalaman;
};

struct elmHakim {
    infotypeHakim info;
    adrHakim next;
    adrTerdakwa nextChild;
};

struct ListHakim {
    adrHakim first;
};

void createListHakim(ListHakim &L);
adrHakim createElmHakim(infotypeHakim x);

void insertFirstHakim(ListHakim &L, adrHakim P);
void insertLastHakim(ListHakim &L, adrHakim P);
void insertAfterHakim(ListHakim &L, adrHakim P, adrHakim Prec);

void deleteFirstHakim(ListHakim &L, adrHakim &P);
void deleteLastHakim(ListHakim &L, adrHakim &P);
void deleteAfterHakim(ListHakim &L, adrHakim &P, adrHakim Prec);

adrHakim findHakim(ListHakim L, string kode);
void viewHakim(ListHakim L);

int countTerdakwa(adrHakim P);
int countKasusTerdakwa(ListHakim L, string t);

void viewAllData(ListHakim L);

void printAllTerdakwa(ListHakim L);

void loadDataDummy(ListHakim &L);

#endif // HAKIM_H_INCLUDED
