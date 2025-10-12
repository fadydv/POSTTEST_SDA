//## SOAL 5
//Kami sudah menyediakan sebuah tree silahkan lengkapi kode berikut untuk dapat melakukan traversal dengan metode pre-order (root, left, right).

#include <iostream>

using namespace std;

// struktur node untuk binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // constructor untuk mengisi data node baru yang dibuat
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// fungsi untuk menambahkan node baru ke dalam tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); // jika root kosong, buat node baru
    }
    if (val < root->data) {
        root->left = insert(root->left, val); // masuk ke kiri jika lebih kecil
    } else if (val > root->data) {
        root->right = insert(root->right, val); // masuk ke kanan jika lebih besar
    }
    return root;
}

// fungsi untuk traversal pre-order
void preOrderTraversal(Node* root) {
    //  1. Jika node saat ini adalah nullptr, kembalikan (base case).
    // base case: kalau kosong, keluar
    if (root == nullptr) return;

    // 2. Cetak data node saat ini.
    // cetak node sekarang
    cout << root->data << " ";

    // 3. Rekursif ke subtree kiri.
    // lanjut ke anak kiri
    preOrderTraversal(root->left);
    
    // 4. Rekursif ke subtree kanan.
    // lanjut ke anak kanan
    preOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root);

    cout << endl;
    return 0;
}