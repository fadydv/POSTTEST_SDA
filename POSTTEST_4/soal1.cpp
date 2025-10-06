//## SOAL 1
//Buat sebuah fungsi yang menerima string dan mengembalikannya dalam keadaan terbalik. Anda harus menggunakan struktur data Stack yang diimplementasikan secara manual menggunakan singly linked list.

#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

// fungsi push untuk menambahkan elemen ke puncak stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top}; 
    top = newNode;
}

// fungsi pop untuk mengambil elemen dari puncak stack
char pop(Node*& top) {
    if (top == nullptr) return '\0'; 
    Node* temp = top; 
    char poppedValue = temp->data; 
    top = top->next; 
    delete temp; 
    return poppedValue; 
}

// fungsi untuk membalikkan string menggunakan stack
string reverseString(string s) {
    Node* stackTop = nullptr; 
    string reversed = "";      

    // 1. push setiap karakter dari string s ke dalam stack.
    // loop melalui setiap karakter dalam string input
    for (char c : s) {
        push(stackTop, c); 
    }

    // 2. pop setiap karakter dari stack dan tambahkan ke string `reversed`.
    // loop selama stack tidak kosong
    while (stackTop != nullptr) {
        reversed += pop(stackTop); 
    }

    return reversed; // mengembalikan string yang sudah terbalik
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; 
    return 0;
}