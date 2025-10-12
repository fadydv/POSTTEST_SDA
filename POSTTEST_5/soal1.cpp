//## SOAL 1
//Kamu diminta membuat fungsi untuk menghitung jumlah total node yang ada dalam sebuah Binary Search Tree (BST). Logikanya mirip dengan proses traversal, di mana kamu harus mengunjungi setiap node, tetapi alih-alih mencetak datanya, kamu menambah sebuah penghitung.

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

// fungsi untuk menghitung jumlah total node di tree
int countNodes(Node* root) {
    // 1. Base case: Jika root adalah nullptr, tree kosong, kembalikan 0.
    // base case: kalau kosong, jumlah node = 0
    if (root == nullptr) return 0;

    // 2. Recursive step: Jumlah node adalah 1 (untuk node saat ini) + jumlah node di subtree kiri + jumlah node di subtree kanan.
    // hitung 1 node ini + jumlah node di kiri + jumlah node di kanan
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl; 

    return 0;
}