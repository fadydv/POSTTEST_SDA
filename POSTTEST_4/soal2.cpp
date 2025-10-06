//## SOAL 2
//Buat fungsi yang memeriksa apakah sebuah string yang berisi tanda kurung (), {}, dan \[\] seimbang. Contohnya, "{\[()\]}" seimbang, tetapi "{\[(\])}" tidak. Gunakan implementasi Stack manual.

#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

// fungsi push 
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// fungsi pop 
char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// fungsi untuk memeriksa apakah tanda kurung seimbang
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // 1. loop setiap karakter dalam `expr`.
    for (char c : expr) {
        // 2. jika karakter adalah kurung buka '(', '{', '[', push ke stack.
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // 3. jika karakter adalah kurung tutup ')', '}', ']', cek:
        else if (c == ')' || c == '}' || c == ']') {
            // a. apakah stack kosong? jika ya, berarti ada kurung tutup tanpa kurung buka yang sesuai.
            if (stackTop == nullptr) {
                return false;
            }
            // b. pop stack, lalu cek apakah kurung tutup cocok dengan kurung buka.
            char poppedChar = pop(stackTop);
            if (
                (c == ')' && poppedChar != '(') ||
                (c == '}' && poppedChar != '{') ||
                (c == ']' && poppedChar != '[')
            ) {
                // c. jika tidak cocok, berarti tidak seimbang
                return false;
            }
        }
    }

    // setelah loop selesai, jika stack kosong, return true (semua kurung buka sudah punya pasangan).
    // jika tidak, return false (ada kurung buka yang belum punya pasangan).
    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr3 = "([{}])";
    cout << expr3 << " -> " << (areBracketsBalanced(expr3) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr4 = "(()";
    cout << expr4 << " -> " << (areBracketsBalanced(expr4) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr5 = "}{";
    cout << expr5 << " -> " << (areBracketsBalanced(expr5) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}