//## SOAL 4
//Anda memiliki sebuah circular doubly linked list yang datanya sudah terurut (ascending). Buatlah fungsi untuk menyisipkan sebuah node baru ke dalam list tersebut sehingga urutannya tetap terjaga.

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// fungsi untuk menyisipkan node baru ke dalam list yang terurut
void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr}; 

    // kasus 1: list masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode; 
        newNode->prev = newNode; 
        head_ref = newNode;      
        return;
    }

    // kasus 2: data baru lebih kecil dari head (sisipkan di awal)
    // jika data baru lebih kecil dari data head_ref saat ini
    if (data < head_ref->data) {
        Node* tail = head_ref->prev; 

        // sambungkan newNode ke tail dan head
        newNode->next = head_ref;
        newNode->prev = tail;
        head_ref->prev = newNode;
        tail->next = newNode;
        head_ref = newNode; 
        return;
    }

    // kasus 3: cari posisi yang tepat (tengah/akhir)
    Node* current = head_ref; 

    // loop while 
    // lanjutkan selama belum kembali ke head_ref DAN data node berikutnya lebih kecil dari data yang akan disisipkan
    // (ini untuk menemukan posisi dimana data baru harus disisipkan setelah 'current')
    while (current->next != head_ref && current->next->data < data) {
        current = current->next; 
    }

    // setelah loop, sisipkan newNode setelah current
    newNode->next = current->next; 
    newNode->prev = current;      
    current->next->prev = newNode; 
    current->next = newNode;       
}

// fungsi untuk mencetak list
void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }
    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref); 
    cout << endl;
}

int main()
{
    Node *head = nullptr; 

    // test sorted insert
    sortedInsert(head, 30);
    cout << "Setelah insert 30: "; printList(head);
    sortedInsert(head, 10);
    cout << "Setelah insert 10: "; printList(head);
    sortedInsert(head, 40);
    cout << "Setelah insert 40: "; printList(head);
    sortedInsert(head, 20);
    cout << "Setelah insert 20: "; printList(head);
    sortedInsert(head, 5);
    cout << "Setelah insert 5: "; printList(head);
    sortedInsert(head, 45);
    cout << "Setelah insert 45: "; printList(head);

    cout << "Circular Doubly Linked List (sorted final): ";
    printList(head);

    return 0;
}