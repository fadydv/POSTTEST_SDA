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

// node untuk single linked list
struct Node {
    Item data;
    Node *next;
};

// prototype fungsi
// create
void CF(Node *&head, const string& nama, const string& tipe);
void CL(Node *&head, const string& nama, const string& tipe);
void CP(Node *&head);

// read
void tampilkanInventory(Node *head);
void cariItem(Node *head);

// update & delete
void gunakanItem(Node *&head);
void DL(Node *&head);
void DF(Node *&head);
void DP(Node *&head, Node* prev, Node* temp);

void errorInput(int &input);

// fungsi untuk mengatur warna teks menjadi biru
void setWarnaBiru() {
    cout << "\033[34m";
}

// fungsi untuk mengembalikan warna teks ke default
void resetWarna() {
    cout << "\033[0m";
}

void displayMenu() {
    setWarnaBiru();
    cout << "+---------------------------------------------------+" << endl;
    cout << "|             GAME INVENTORY MANAGEMENT             |" << endl;
    cout << "|              [ Dilla - 2409106087 ]               |" << endl;
    cout << "+---------------------------------------------------+" << endl;
    cout << "| 1. Tambah Item Baru                               |" << endl;
    cout << "| 2. Sisipkan Item                                  |" << endl;
    cout << "| 3. Hapus Item Terakhir                            |" << endl;
    cout << "| 4. Gunakan Item                                   |" << endl;
    cout << "| 5. Tampilkan Inventory                            |" << endl;
    cout << "| 6. Cari Item Berdasarkan Nama                     |" << endl;
    cout << "| 0. Keluar                                         |" << endl;
    cout << "+---------------------------------------------------+" << endl;
    resetWarna();
    cout << "Masukan pilihan Anda: ";
}

int main() {
    Node *head = nullptr;
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
                    CL(head, nama, tipe);
                }
                break;
            case 2:
                CP(head);
                break;
            case 3:
                DL(head);
                break;
            case 4:
                gunakanItem(head);
                break;
            case 5:
                tampilkanInventory(head);
                break;
            case 6:
                cariItem(head);
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

// create first
void CF(Node *&head, const string& nama, const string& tipe) {
    Node *nodeBaru = new Node;
    nodeBaru->data.namaItem = nama;
    nodeBaru->data.tipe = tipe;
    nodeBaru->data.jumlah = NIM_NUMBER;
    nodeBaru->next = head;
    head = nodeBaru;
    cout << "Item '" << nodeBaru->data.namaItem << "' berhasil ditambahkan di awal dengan jumlah " << nodeBaru->data.jumlah << "." << endl;
}

// create last
void CL(Node *&head, const string& nama, const string& tipe) {
    Node *nodeBaru = new Node;
    nodeBaru->data.namaItem = nama;
    nodeBaru->data.tipe = tipe;
    nodeBaru->data.jumlah = NIM_NUMBER;
    nodeBaru->next = nullptr;

    if (head == nullptr) {
        head = nodeBaru;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
    cout << "Item '" << nodeBaru->data.namaItem << "' berhasil ditambahkan di akhir dengan jumlah " << nodeBaru->data.jumlah << "." << endl;
}

// create at position
void CP(Node *&head) {
    int posisi;
    if (NIM_LAST_DIGIT == 0) {
        posisi = 2;
    } else {
        posisi = NIM_LAST_DIGIT + 1;
    }

    if (posisi <= 1 || head == nullptr) {
        cout << "Karena posisi kurang dari 2 atau inventory kosong, item akan ditambahkan di awal." << endl;
        string nama, tipe;
        cout << "Masukan nama item yang akan disisipkan: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, nama);
        cout << "Masukan tipe item (contoh: Potion, Sword): ";
        getline(cin, tipe);
        CF(head, nama, tipe);
        return;
    }

    Node *nodeBaru = new Node;
    cout << "Masukan nama item yang akan disisipkan: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nodeBaru->data.namaItem);
    cout << "Masukan tipe item (contoh: Potion, Sword): ";
    getline(cin, nodeBaru->data.tipe);
    nodeBaru->data.jumlah = NIM_NUMBER;
    
    Node *temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr) {
        cout << "Posisi tidak valid. Linked list terlalu pendek." << endl;
        delete nodeBaru;
        return;
    }

    nodeBaru->next = temp->next;
    temp->next = nodeBaru;
    cout << "Item '" << nodeBaru->data.namaItem << "' berhasil disisipkan pada posisi ke-" << posisi << "." << endl;
}

// delete first
void DF(Node *&head) {
    Node* temp = head;
    head = head->next;
    cout << "Item '" << temp->data.namaItem << "' berhasil dihapus dari awal." << endl;
    delete temp;
}

// delete last
void DL(Node *&head) {
    if (head == nullptr) {
        cout << "Inventory kosong. Tidak ada item yang bisa dihapus." << endl;
        return;
    }
    if (head->next == nullptr) {
        cout << "Item '" << head->data.namaItem << "' berhasil dihapus." << endl;
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    cout << "Item '" << temp->next->data.namaItem << "' berhasil dihapus." << endl;
    delete temp->next;
    temp->next = nullptr;
}

// delete at position
void DP(Node *&head, Node* prev, Node* temp) {
    if (prev == nullptr) {
        DF(head);
    } else {
        prev->next = temp->next;
        cout << "Item '" << temp->data.namaItem << "' berhasil dihapus dari posisi." << endl;
        delete temp;
    }
}

void gunakanItem(Node *&head) {
    if (head == nullptr) {
        cout << "Inventory kosong. Tidak ada item yang bisa digunakan." << endl;
        return;
    }

    string nama;
    cout << "Masukan nama item yang ingin digunakan: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nama);

    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr && temp->data.namaItem != nama) {
        prev = temp;
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
        DP(head, prev, temp);
    }
}

void tampilkanInventory(Node *head) {
    if (head == nullptr) {
        cout << "Inventory kosong." << endl;
        return;
    }
    cout << "---- Daftar Item dalam Inventory ----" << endl;
    int i = 1;
    while (head != nullptr) {
        cout << i++ << ". Nama: " << head->data.namaItem
             << ", Tipe: " << head->data.tipe
             << ", Jumlah: " << head->data.jumlah << endl;
        head = head->next;
    }
    cout << "-------------------------------------" << endl;
}

void cariItem(Node *head) {
    if (head == nullptr) {
        cout << "Inventory kosong. Tidak ada item yang bisa dicari." << endl;
        return;
    }

    string nama;
    cout << "Masukan nama item yang ingin dicari: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nama);

    Node *temp = head;
    bool ditemukan = false;
    while (temp != nullptr) {
        if (temp->data.namaItem == nama) {
            cout << "Item ditemukan!" << endl;
            cout << "Nama: " << temp->data.namaItem
                 << ", Tipe: " << temp->data.tipe
                 << ", Jumlah: " << temp->data.jumlah << endl;
            ditemukan = true;
            break;
        }
        temp = temp->next;
    }
    if (!ditemukan) {
        cout << "Item tidak ditemukan." << endl;
    }
}

void errorInput(int &input) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Mohon masukan angka: ";
        cin >> input;
    }
}