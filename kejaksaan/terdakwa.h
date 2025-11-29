#ifndef TERDAKWA_H_INCLUDED
#define TERDAKWA_H_INCLUDED

#include <iostream>

struct infotypeTerdakwa {
    string noRegistrasi;
    string nama;
    string tuntutan;
};

typedef struct elmTerdakwa *adrTerdakwa;

struct elmTerdakwa {
    infotypeTerdakwa info;
    adrTerdakwa next;
    adrTerdakwa prev;
};

struct ListTerdakwa {
    adrTerdakwa first;
    adrTerdakwa last;
};

using namespace std;


#endif // TERDAKWA_H_INCLUDED
