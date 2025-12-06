#ifndef HAKIM_H_INCLUDED
#define HAKIM_H_INCLUDED

#include <iostream>
#include "terdakwa.h"

using namespace std;

struct infotypeHakim {
    string kode;
    string nama;
    int pengalaman;
};

typedef struct elmHakim *adrHakim;

struct elmHakim {
    infotypeHakim info;
    adrHakim next;
    adrhakim prev;
    adrTerdakwa child;
};

struct ListHakim {
    adrHakim first;
    adrHakim last;
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
adrHakim findMaxPengalaman(ListHakim L);
void countHakim(ListHakim L, int &count);

#endif // HAKIM_H_INCLUDED
