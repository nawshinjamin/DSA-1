#include <iostream>
#include <fstream>
#include "listBST.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file) {
        cerr << "Unable to open file\n";
        return 2;
    }
    char c, str[5];
    int val;
    BST<int, int> *bst = new ListBST<int, int>();
    if (!bst) {
        cerr << "Memory allocation failed\n";
        return 3;
    }
    while (in_file >> c) {
        
        if (c == 'F') {
            int k; in_file >> k;
            if (bst->find(k)) cout << "Key " << k << " found in BST." << '\n';
            else cout << "Key " << k << " not found in BST." << '\n';
        }
    
        else if (c == 'E') {
            if (bst->empty()) cout << "Empty" << '\n';
            else cout << "Not empty" << '\n';
        }
    
        else if (c == 'I') {
            int k; in_file >> k;
            bool res = bst->insert(k, k);
            if (res) {
                cout << "Key " << k << " inserted into BST, BST (Default): ";
                bst->print('D');
                cout << '\n';
            } else {
                cout << "Insertion failed! Key " << k << " already exists in BST, BST (Default): ";
                bst->print('D');
                cout << '\n';
            }
        }
        
        else if (c == 'M') {
            string s; in_file >> s;
            if (s == "Min") {
                try { cout << "Minimum value: " << bst->find_min() << '\n'; }
                catch (const std::exception &e) { cout << "Empty" << '\n'; }
            } else { 
                try { cout << "Maximum value: " << bst->find_max() << '\n'; }
                catch (const std::exception &e) { cout << "Empty" << '\n'; }
            }
        }
        
        else if (c == 'D') {
            int k; in_file >> k;
            bool res = bst->remove(k);
            if (res) {
                cout << "Key " << k << " removed from BST, BST (Default): ";
                bst->print('D');
                cout << '\n';
            } else {
                cout << "Removal failed! Key " << k << " not found in BST, BST (Default): ";
                bst->print('D');
                cout << '\n';
            }
        }
        
        else if (c == 'T') {
            string s; in_file >> s;
            if (s == "In") { cout << "BST (In-order): "; bst->print('I'); cout << '\n'; }
            else if (s == "Pre") { cout << "BST (Pre-order): "; bst->print('P'); cout << '\n'; }
            else if (s == "Post") { cout << "BST (Post-order): "; bst->print('O'); cout << '\n'; }
        }
        
        else if (c == 'S') {
            cout << "Size: " << bst->size() << '\n';
        }
    }
    in_file.close();
    delete bst;
    return 0;
}