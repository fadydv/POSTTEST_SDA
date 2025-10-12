//## SOAL 2
//Binary Search Tree (BST), semua nilai yang lebih kecil dari root berada di subtree kiri. Dengan properti ini, kita dapat dengan mudah menemukan nilai terkecil dalam tree. Buatlah fungsi untuk mencari nilai minimum tersebut.

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

// fungsi untuk mencari nilai terkecil di BST
int findMinValue(Node* root) {
    // 1. Cek jika tree kosong.
    // kalau tree kosong
    if (root == nullptr) return -1;

    // 2. Selama masih ada anak kiri (left child), terus telusuri ke kiri.
    // terus bergerak ke kiri sampai mentok
    while (root->left != nullptr) {
        root = root->left;
    }

    // 3. Node paling kiri adalah node dengan nilai terkecil.
    // node paling kiri = nilai terkecil
    return root->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl;

    return 0;
}