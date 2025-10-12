//## SOAL 4
//Kami sudah menyediakan sebuah tree silahkan lengkapi kode berikut untuk dapat melakukan traversal dengan metode post-order (left, right, root).

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

// fungsi untuk traversal post-order
void postOrderTraversal(Node* root) {
    // 1. Jika node saat ini adalah nullptr, kembalikan (base case).
    // kalau kosong, tidak perlu diproses
    if (root == nullptr) return;

    // 2. Rekursif ke subtree kiri.
    // kunjungi subtree kiri
    postOrderTraversal(root->left);

    // 3. Rekursif ke subtree kanan.
    // kunjungi subtree kanan
    postOrderTraversal(root->right);

    // 4. Cetak data node saat ini.
    // cetak data node sekarang
    cout << root->data << " ";
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

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root);

    cout << endl;
    return 0;
}