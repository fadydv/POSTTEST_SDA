#include <iostream>
using namespace std;

void swapNilai(int **x, int **y) {
    int temp = **x;
    **x = **y;
    **y = temp;
}

int main() {
    int a, b;
    cout << "Masukkan nilai a: "; cin >> a;
    cout << "Masukkan nilai b: "; cin >> b;

    cout << "\nSebelum swap: a = " << a << ", b = " << b << endl;

    int *pa = &a;
    int *pb = &b;

    swapNilai(&pa, &pb);

    cout << "Sesudah swap: a = " << a << ", b = " << b << endl;

    return 0;
}