#include <iostream>
#include "main.h"

using namespace std;

int main() {
    ListHakim LH;
    createListHakim(LH);

    loadDataDummy(LH);

    int pilihan = -99;

    while (pilihan != 0)
    {
        system("cls");
        cout << "========================================" << endl;
        cout << "    APLIKASI DATA HAKIM & TERDAKWA      " << endl;
        cout << "========================================" << endl;
        cout << "1. Test Case" << endl;
        cout << "2. Study Case" << endl;
        cout << "0. Keluar" << endl;
        cout << "========================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan)
        {
            case 1:
                //cout << "Kamu masuk ke Menu Test Case." << endl;
                menuAdmin(LH);
                break;
            case 2:
                //cout << "Kamu masuk ke Menu Study Case." << endl;
                menuUser(LH);
                break;
            default:
                if (pilihan != 0)
                {
                    cout << "Pilihan tidak valid." << endl;
                    system("pause");
                }
                else
                {
                   cout << "Terima kasih telah menggunakan aplikasi."<< endl;
                }
                break;
        }
    }

    /* do {
        cout << "========================================" << endl;
        cout << "    APLIKASI DATA HAKIM & TERDAKWA      " << endl;
        cout << "========================================" << endl;
        cout << "1. Menu Admin (Kelola Data)" << endl;
        cout << "2. Menu User (Lihat Data)" << endl;
        cout << "0. Keluar" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                menuAdmin(LH);
                break;
            case 2:
                menuUser(LH);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan aplikasi." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
        cout << endl;
    } while (pilihan != 0); */


    return 0;
}

