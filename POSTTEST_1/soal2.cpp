#include <iostream>
using namespace std;

int main() {
    const int n = 3;
    int matriks[n][n];

    cout << "Masukkan elemen matriks 3x3 (boleh dipisah dengan spasi atau Enter):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriks[i][j];
        }
    }

    int jumlah = 0;
    for (int i = 0; i < n; i++) {
        jumlah += matriks[i][i];
        jumlah += matriks[i][n - 1 - i];
    }

    cout << "\nMatriks 3x3:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Jumlah diagonal utama + sekunder = " << jumlah << endl;

    return 0;
}