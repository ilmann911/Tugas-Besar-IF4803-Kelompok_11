#ifndef HAKIM_H_INCLUDED
#define HAKIM_H_INCLUDED

#include <iostream>
#include "terdakwa.h"

using namespace std;

typedef struct elmHakim *adrHakim;

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


#endif // HAKIM_H_INCLUDED
