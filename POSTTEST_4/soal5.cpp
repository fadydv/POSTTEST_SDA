//## SOAL 5
//Buat sebuah fungsi untuk menukar posisi node head dan node tail dalam sebuah circular doubly linked list tanpa menukar datanya, melainkan dengan memanipulasi pointernya.

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// fungsi untuk menukar posisi node head dan node tail
void exchangeHeadAndTail(Node *&head_ref) {
    // hanya berjalan jika ada 2 node atau lebih
    // jika list kosong, atau hanya 1 node (head->next == head), tidak ada yang perlu ditukar.
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;        
    Node* tail = head_ref->prev;  

    // kasus khusus: Hanya ada 2 node
    // jika head->next adalah tail (dan tail->next adalah head), berarti hanya ada 2 node.
    if (head->next == tail && tail->prev == head) {
        head_ref = tail; 
        return;
    }

    // Simpan neighbor (yaitu head_next dan tail_prev)
    Node* head_next = head->next;
    Node* tail_prev = tail->prev;

    // 1. sambungkan tetangga head dan tetangga tail ke node yang akan menjadi head/tail baru.
    // node setelah head lama (head_next) sekarang akan punya prev menunjuk ke tail (yang jadi head baru)
    head_next->prev = tail;
    // node sebelum tail lama (tail_prev) sekarang akan punya next menunjuk ke head (yang jadi tail baru)
    tail_prev->next = head;

    // 2. perbarui pointer untuk tail 
    tail->next = head_next; 
    tail->prev = head;       

    // 3. perbarui pointer untuk head 
    head->prev = tail_prev;  
    head->next = tail;       

    // 4. update head_ref ke node yang sekarang menjadi head list
    head_ref = tail; 
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

// fungsi untuk menyisipkan node di akhir list
void insertEnd(Node *&head_ref, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};
    if (head_ref == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main()
{
    Node *head = nullptr;
    // list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head);

    // test case dengan 2 node
    Node* head2 = nullptr;
    insertEnd(head2, 10);
    insertEnd(head2, 20);
    cout << "\nList 2 node sebelum exchange: ";
    printList(head2);
    exchangeHeadAndTail(head2);
    cout << "List 2 node setelah exchange: ";
    printList(head2);

    // test case dengan 1 node
    Node* head3 = nullptr;
    insertEnd(head3, 100);
    cout << "\nList 1 node sebelum exchange: ";
    printList(head3);
    exchangeHeadAndTail(head3); 
    cout << "List 1 node setelah exchange: ";
    printList(head3);

    return 0;
}