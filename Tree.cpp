#include <iostream>
using namespace std;

// Node pohon biner
struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

// Membuat node baru secara dinamis
Node* buatNode(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->kiri = nullptr;
    baru->kanan = nullptr;
    return baru;
}

// Menyisipkan nilai: lebih kecil -> kiri, lebih besar -> kanan
Node* sisip(Node *root, int nilai) {
    if (root == nullptr) {
        return buatNode(nilai);   // angka pertama otomatis jadi root
    }
    if (nilai < root->data) {
        root->kiri = sisip(root->kiri, nilai);
    } else if (nilai > root->data) {
        root->kanan = sisip(root->kanan, nilai);
    }
    // nilai yang sama dengan node yang ada diabaikan (tidak ada duplikat)
    return root;
}

// Pre-order: Root -> Kiri -> Kanan
void preOrder(Node *root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->kiri);
    preOrder(root->kanan);
}

// In-order: Kiri -> Root -> Kanan
void inOrder(Node *root) {
    if (root == nullptr) return;
    inOrder(root->kiri);
    cout << root->data << " ";
    inOrder(root->kanan);
}

// Post-order: Kiri -> Kanan -> Root
void postOrder(Node *root) {
    if (root == nullptr) return;
    postOrder(root->kiri);
    postOrder(root->kanan);
    cout << root->data << " ";
}

// Menghapus seluruh tree agar tidak terjadi memory leak
void hapusTree(Node *root) {
    if (root == nullptr) return;
    hapusTree(root->kiri);
    hapusTree(root->kanan);
    delete root;
}

int main() {
    Node *root = nullptr;
    int angka;

    cout << "Masukkan angka (input 0 untuk berhenti):" << endl;
    while (true) {
        cout << "> ";
        cin >> angka;
        if (angka == 0) break;
        root = sisip(root, angka);
    }

    if (root == nullptr) {
        cout << "Tree kosong." << endl;
        return 0;
    }

    cout << "\nPre-order  : ";
    preOrder(root);
    cout << "\nIn-order   : ";
    inOrder(root);
    cout << "\nPost-order : ";
    postOrder(root);
    cout << endl;

    hapusTree(root);
    return 0;
}
