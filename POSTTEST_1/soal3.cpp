#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    const int n = 5;
    Mahasiswa mhs[n];

    cout << "Input data 5 mahasiswa:\n";
    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : "; cin >> mhs[i].nama;
        cout << "NIM  : "; cin >> mhs[i].nim;
        cout << "IPK  : "; cin >> mhs[i].ipk;
    }

    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (mhs[i].ipk > mhs[idx].ipk) {
            idx = i;
        }
    }

    cout << "\nMahasiswa dengan IPK tertinggi:\n";
    cout << "Nama : " << mhs[idx].nama << endl;
    cout << "NIM  : " << mhs[idx].nim << endl;
    cout << "IPK  : " << mhs[idx].ipk << endl;

    return 0;
}