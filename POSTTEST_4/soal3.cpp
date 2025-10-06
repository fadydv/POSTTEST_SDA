//## SOAL 3
//Buat implementasi Queue manual menggunakan linked list untuk simulasi antrian printer yang memproses dokumen berdasarkan urutan kedatangan (FIFO). Struktur Data:

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string document; 
    Node* next;      
};

// fungsi enqueue untuk menambahkan dokumen ke belakang antrian
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr}; 

    // 1. jika queue kosong (front == nullptr)
    if (front == nullptr) {
        front = newNode; 
        rear = newNode;
    }
    // 2. jika tidak kosong
    else {
        rear->next = newNode; 
        rear = newNode;       
    }
}

// fungsi dequeue untuk mengambil dokumen dari depan antrian
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return "";

    // 1. simpan data dari front node
    string dequeuedDocument = front->document;
    Node* temp = front; 

    // 2. geser front ke front->next
    front = front->next;

    // 3. jika front menjadi nullptr (artinya antrian menjadi kosong setelah dequeue), set rear juga ke nullptr
    if (front == nullptr) {
        rear = nullptr;
    }

    // 4. delete node lama dan return data
    delete temp; 
    return dequeuedDocument; 
}

// fungsi untuk memproses semua dokumen dalam antrian
void processAllDocuments(Node*& front, Node*& rear) {
    // Loop hingga queue kosong
    while (front != nullptr) {
        // dequeue dan print setiap dokumen
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl; 
    }
}

int main() {
    Node* front = nullptr; 
    Node* rear = nullptr;  

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    cout << "\nMenambahkan dokumen baru setelah antrian sebelumnya kosong:" << endl;
    enqueue(front, rear, "Invoice.pdf");
    enqueue(front, rear, "Memo.txt");
    processAllDocuments(front, rear);

    return 0;
}