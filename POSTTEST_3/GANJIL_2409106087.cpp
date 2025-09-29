#include <iostream>
#include <limits>

using namespace std;

const int NIM_NUMBER = 87;
const int NIM_LAST_DIGIT = 7;

// struct untuk menyimpan data item
struct Item {
    string namaItem;
    int jumlah;
    string tipe;
};

// node untuk double linked list
struct Node {
    Item data;
    Node *prev; 
    Node *next; 
};

// prototipe fungsi
// create
void CF(Node *&head, Node *&tail, const string& nama, const string& tipe);
void CL(Node *&head, Node *&tail, const string& nama, const string& tipe);
void CP(Node *&head, Node *&tail);

// read (traversal)
void tampilkanInventory(Node *head);
void tampilkanInventoryReverse(Node *tail);
void tampilkanDetailItem(Node *head);

// delete & update
void DL(Node *&head, Node *&tail);
void DF(Node *&head, Node *&tail);
void DP(Node *&head, Node *&tail, Node* temp);
void gunakanItem(Node *&head, Node *&tail);

// utility
void errorInput(int &input);
void setWarnaBiru() { cout << "\033[34m"; }
void resetWarna() { cout << "\033[0m"; }

void displayMenu() {
    setWarnaBiru();
    cout << "+---------------------------------------------------+" << endl;
    cout << "|              GAME INVENTORY MANAGEMENT            |" << endl;
    cout << "|               [ Dilla - 2409106087 ]              |" << endl;
    cout << "+---------------------------------------------------+" << endl;
    cout << "| 1. Tambah Item Baru di Awal                       |" << endl;
    cout << "| 2. Tambah Item Baru di Akhir                      |" << endl; 
    cout << "| 3. Sisipkan Item                                  |" << endl;
    cout << "| 4. Hapus Item Terakhir                            |" << endl;
    cout << "| 5. Gunakan Item                                   |" << endl;
    cout << "| 6. Tampilkan Inventory dari Depan ke Belakang     |" << endl;
    cout << "| 7. Tampilkan Inventory dari Belakang ke Depan     |" << endl;
    cout << "| 8. Tampilkan Detail Item                          |" << endl;
    cout << "| 0. Keluar                                         |" << endl;
    cout << "+---------------------------------------------------+" << endl;
    resetWarna();
    cout << "Masukan pilihan Anda: ";
}

int main() {
    Node *head = nullptr;
    Node *tail = nullptr;
    int pilihan;

    do {
        displayMenu();
        cin >> pilihan;
        errorInput(pilihan);

        switch (pilihan) {
            case 1:
                {
                    string nama, tipe;
                    cout << "Masukan nama item: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, nama);
                    cout << "Masukan tipe item (contoh: Potion, Sword): ";
                    getline(cin, tipe);
                    CF(head, tail, nama, tipe);
                }
                break;
            case 2:
                {
                    string nama, tipe;
                    cout << "Masukan nama item: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, nama);
                    cout << "Masukan tipe item (contoh: Potion, Sword): ";
                    getline(cin, tipe);
                    CL(head, tail, nama, tipe);
                }
                break;
            case 3: 
                CP(head, tail);
                break;
            case 4:
                DL(head, tail);
                break;
            case 5:
                gunakanItem(head, tail);
                break;
            case 6:
                tampilkanInventory(head);
                break;
            case 7:
                tampilkanInventoryReverse(tail);
                break;
            case 8: 
                tampilkanDetailItem(head);
                break;
            case 0:
                cout << "Keluar dari program. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
        cout << endl;
    } while (pilihan != 0);

    Node *current = head;
    while(current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}

void errorInput(int &input) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Mohon masukan angka: ";
        cin >> input;
    }
}

Node* createNode(const string& nama, const string& tipe) {
    Node *nodeBaru = new Node;
    nodeBaru->data.namaItem = nama;
    nodeBaru->data.tipe = tipe;
    nodeBaru->data.jumlah = NIM_NUMBER;
    nodeBaru->prev = nullptr;
    nodeBaru->next = nullptr;
    return nodeBaru;
}

// create first
void CF(Node *&head, Node *&tail, const string& nama, const string& tipe) {
    Node *nodeBaru = createNode(nama, tipe);
    if (head == nullptr) {
        head = tail = nodeBaru;
    } else {
        nodeBaru->next = head;
        head->prev = nodeBaru;
        head = nodeBaru;
    }
    cout << "Item '" << nodeBaru->data.namaItem << "' berhasil ditambahkan di awal." << endl;
}

// create last 
void CL(Node *&head, Node *&tail, const string& nama, const string& tipe) {
    Node *nodeBaru = createNode(nama, tipe);

    if (head == nullptr) {
        head = tail = nodeBaru;
    } else {
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;
    }
    cout << "Item '" << nodeBaru->data.namaItem << "' berhasil ditambahkan di akhir dengan jumlah " << NIM_NUMBER << "." << endl;
}

// create at position 
void CP(Node *&head, Node *&tail) {
    int posisi;
    posisi = NIM_LAST_DIGIT == 0 ? 2 : NIM_LAST_DIGIT + 1;

    string nama, tipe;
    cout << "Masukan nama item yang akan disisipkan: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nama);
    cout << "Masukan tipe item (contoh: Potion, Sword): ";
    getline(cin, tipe);
    
    if (posisi <= 1 || head == nullptr) {
        cout << "Karena posisi kurang dari 2 atau inventory kosong, item akan ditambahkan di awal." << endl;
        CF(head, tail, nama, tipe);
        return;
    }

    Node *nodeBaru = createNode(nama, tipe);
    
    Node *temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr) {
        cout << "Posisi tidak valid/melebihi panjang list. Item ditambahkan di akhir." << endl;
        delete nodeBaru; 
        CL(head, tail, nama, tipe);
        return;
    }

    nodeBaru->next = temp->next;
    nodeBaru->prev = temp;
    
    if (temp->next != nullptr) {
        temp->next->prev = nodeBaru;
    } else {
        tail = nodeBaru;
    }
    temp->next = nodeBaru;

    cout << "Item '" << nodeBaru->data.namaItem << "' berhasil disisipkan pada posisi ke-" << posisi << "." << endl;
}

// traversal depan 
void tampilkanInventory(Node *head) {
    if (head == nullptr) {
        cout << "Inventory kosong." << endl;
        return;
    }
    cout << "\n---------- Daftar Item dari Depan ke Belakang ----------" << endl;
    int i = 1;
    Node *current = head;
    while (current != nullptr) {
        cout << i++ << ". Nama: " << current->data.namaItem
             << ", Tipe: " << current->data.tipe
             << ", Jumlah: " << current->data.jumlah << endl;
        current = current->next;
    }
    cout << "-----------------------------------------------------" << endl;
}

// traversal belakang
void tampilkanInventoryReverse(Node *tail) {
    if (tail == nullptr) {
        cout << "Inventory kosong." << endl;
        return;
    }
    cout << "\n---------- Daftar Item dari Belakang ke Depan ----------" << endl;
    int i = 1;
    Node *current = tail;
    while (current != nullptr) {
        cout << i++ << ". Nama: " << current->data.namaItem
             << ", Tipe: " << current->data.tipe
             << ", Jumlah: " << current->data.jumlah << endl;
        current = current->prev;
    }
    cout << "-----------------------------------------------------" << endl;
}

// tampilkan detail item 
void tampilkanDetailItem(Node *head) {
    if (head == nullptr) {
        cout << "Inventory kosong. Tidak ada item yang bisa dicari." << endl;
        return;
    }

    string namaCari;
    cout << "Masukan nama item yang ingin dicari: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, namaCari);

    Node *temp = head;
    bool ditemukan = false;
    int posisi = 1;
    while (temp != nullptr) {
        if (temp->data.namaItem == namaCari) {
            cout << "\n--------------- Detail Item Ditemukan ---------------" << endl;
            cout << "Posisi dalam List: " << posisi << endl;
            cout << "Nama Item: " << temp->data.namaItem << endl;
            cout << "Tipe Item: " << temp->data.tipe << endl;
            cout << "Jumlah Item: " << temp->data.jumlah << endl;
            cout << "-----------------------------------------------------" << endl;
            ditemukan = true;
            break;
        }
        temp = temp->next;
        posisi++;
    }
    if (!ditemukan) {
        cout << "Item '" << namaCari << "' tidak ditemukan dalam inventory." << endl;
    }
}

// delete first
void DF(Node *&head, Node *&tail) {
    if (head == nullptr) {
        cout << "Inventory kosong. Tidak ada item yang bisa dihapus." << endl;
        return;
    }
    Node* temp = head;
    if (head == tail) { 
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr; 
    }
    cout << "Item '" << temp->data.namaItem << "' berhasil dihapus dari awal." << endl;
    delete temp;
}

// delete last
void DL(Node *&head, Node *&tail) {
    if (tail == nullptr) {
        cout << "Inventory kosong. Tidak ada item yang bisa dihapus." << endl;
        return;
    }
    Node *temp = tail;
    if (head == tail) { 
        head = tail = nullptr;
    } else {
        tail = tail->prev; 
        tail->next = nullptr; 
    }
    cout << "Item '" << temp->data.namaItem << "' berhasil dihapus dari akhir." << endl;
    delete temp;
}

// delete at position
void DP(Node *&head, Node *&tail, Node* temp) {
    if (temp == head) {
        DF(head, tail);
        return;
    }
    if (temp == tail) {
        DL(head, tail);
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    
    cout << "Item '" << temp->data.namaItem << "' habis dan berhasil dihapus." << endl;
    delete temp;
}

// gunakan item
void gunakanItem(Node *&head, Node *&tail) {
    if (head == nullptr) {
        cout << "Inventory kosong. Tidak ada item yang bisa digunakan." << endl;
        return;
    }

    string nama;
    cout << "Masukan nama item yang ingin digunakan: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nama);

    Node *temp = head;
    while (temp != nullptr && temp->data.namaItem != nama) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item tidak ditemukan." << endl;
        return;
    }
    
    if (temp->data.jumlah > 1) {
        temp->data.jumlah--;
        cout << "Item '" << temp->data.namaItem << "' berhasil digunakan. Jumlah sekarang: " << temp->data.jumlah << "." << endl;
    } else {
        DP(head, tail, temp);
    }
}