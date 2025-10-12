//## SOAL 3
//Kebalikan dari soal mencari nilai terkecil, kali ini kamu diminta membuat fungsi untuk menemukan nilai terbesar dalam sebuah Binary Search Tree (BST). Sesuai aturan BST, nilai terbesar selalu berada di ujung paling kanan dari

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

// fungsi untuk mencari nilai terbesar di BST
int findMaxValue(Node* root) {
    //  1. Cek jika tree kosong.
    // kalau tree kosong
    if (root == nullptr) return -1;

    // 2. Selama masih ada anak kanan (right child), terus telusuri ke kanan.
    // terus ke kanan sampai mentok
    while (root->right != nullptr) {
        root = root->right;
    }

    // 3. Node paling kanan adalah node dengan nilai terbesar.
    // node paling kanan = nilai terbesar
    return root->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl;

    return 0;
}