#ifndef TERDAKWA_H_INCLUDED
#define TERDAKWA_H_INCLUDED

#include <iostream>

typedef struct elmTerdakwa *adrTerdakwa;

#include "hakim.h"

using namespace std;

struct infotypeTerdakwa {
    string noRegistrasi;
    string nama;
    string tuntutan;
    int lamaVonis;
};

struct elmTerdakwa {
    infotypeTerdakwa info;
    adrTerdakwa next;
    adrTerdakwa prev;
};

void createListChild(adrHakim P);
adrTerdakwa createElmTerdakwa(infotypeTerdakwa x);

void insertFirstTerdakwa(adrHakim P, adrTerdakwa c);
void insertLastTerdakwa(adrHakim P, adrTerdakwa c);
void insertAfterTerdakwa(adrTerdakwa Prec, adrTerdakwa c);

void deleteFirstTerdakwa(adrHakim P, adrTerdakwa &c);
void deleteLastTerdakwa(adrHakim P, adrTerdakwa &c);
void deleteAfterTerdakwa(adrTerdakwa Prec, adrTerdakwa &c);

adrTerdakwa findTerdakwa(adrHakim P, string noRegistrasi);
void viewTerdakwa(adrHakim P);
#endif // TERDAKWA_H_INCLUDED
