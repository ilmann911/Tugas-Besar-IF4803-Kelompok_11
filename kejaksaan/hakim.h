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
};

#endif // HAKIM_H_INCLUDED
