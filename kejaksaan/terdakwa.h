#ifndef TERDAKWA_H_INCLUDED
#define TERDAKWA_H_INCLUDED

#include <iostream>
using namespace std;

struct infotypeTerdakwa {
    string noRegistrasi;
    string nama;
    string tuntutan;
};

typedef struct elmTerdakwa *adrTerdakwa;

struct elmTerdakwa {
    infotypeTerdakwa info;
    adrTerdakwa next;
};

struct ListTerdakwa {
    adrTerdakwa first;
};

void createListTerdakwa(ListTerdakwa &L);
adrTerdakwa createElmTerdakwa(infotypeTerdakwa x);
void insertFirstTerdakwa(ListTerdakwa &L, adrTerdakwa P);
void insertLastTerdakwa(ListTerdakwa &L, adrTerdakwa P);
void insertAfterTerdakwa(ListTerdakwa &L, adrTerdakwa P, adrTerdakwa Prec);
void deleteFirstTerdakwa(ListTerdakwa &L, adrTerdakwa &P);
void deleteLastTerdakwa(ListTerdakwa &L, adrTerdakwa &P);    
void deleteAfterTerdakwa(ListTerdakwa &L, adrTerdakwa &P, adrTerdakwa Prec);
adrTerdakwa findTerdakwa(ListTerdakwa L, string noRegistrasi);
void viewTerdakwa(ListTerdakwa L);
void countTerdakwa(ListTerdakwa L, int &count);



#endif // TERDAKWA_H_INCLUDED
