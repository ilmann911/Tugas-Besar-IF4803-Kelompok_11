#include <iostream>
#include "main.h"

using namespace std;

int main() {
    ListHakim LH;
    createListHakim(LH);

    int pilihan;

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

        while (pilihan != 0) {
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
    };

    return 0;
}
