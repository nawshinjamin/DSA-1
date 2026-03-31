#include <iostream>
#include <fstream>
#include <string>
#include "listBST.hpp"
using namespace std;

// Auction class encapsulates item storage and auction logic. Uses only provided headers and dynamic allocation.
class Auction {
public:
    struct Item {
        string name;
        int cur_bid;
        int total_bids;
        int succBids;
        int rejBids;
        Item(const string &n, int b) : name(n), cur_bid(b), total_bids(0), succBids(0), rejBids(0) {}
    };

    struct ItemNode {
        Item* item;
        ItemNode* next;
        ItemNode(Item* it) : item(it), next(nullptr) {}
    };

private:
    ItemNode* head;
    ListBST<string,int>* bst;

    // Sorted singly-linked list (alphabetical order) to print REPORT without STL
    struct SortedNode {
        Item* item;
        SortedNode* next;
        SortedNode(Item* it) : item(it), next(nullptr) {}
    };
    SortedNode* sorted_head;

public:
    Auction() : head(nullptr), bst(new ListBST<string,int>()), sorted_head(nullptr) { }

    ~Auction() {
        // delete all items and item nodes (these own Item*)
        for (ItemNode* p = head; p; ) {
            ItemNode* nxt = p->next;
            delete p->item;
            delete p;
            p = nxt;
        }
        head = nullptr;
        // delete sorted list nodes (do not delete items again)
        for (SortedNode* s = sorted_head; s; ) {
            SortedNode* nxt = s->next;
            delete s;
            s = nxt;
        }
        sorted_head = nullptr;
        delete bst;
    }

    void append_item(Item* it) {
        ItemNode* node = new ItemNode(it);
        if (!head) head = node;
        else {
            ItemNode* p = head;
            while (p->next) p = p->next;
            p->next = node;
        }
        // insert into sorted list as well
        insert_sorted(it);
    }

    // insert item into sorted linked list in lexicographical order
    void insert_sorted(Item* it) {
        SortedNode* node = new SortedNode(it);
        if (!sorted_head || it->name < sorted_head->item->name) {
            node->next = sorted_head;
            sorted_head = node;
            return;
        }
        SortedNode* p = sorted_head;
        while (p->next && p->next->item->name < it->name) p = p->next;
        node->next = p->next;
        p->next = node;
    }

    Item* find_item(const string &name) const {
        for (ItemNode* p = head; p; p = p->next) {
            if (p->item->name == name) return p->item;
        }
        return nullptr;
    }

    void load_initial(ifstream &in) {
        int n; in >> n;
        for (int i = 0; i < n; ++i) {
            string name; int bid; in >> name >> bid;
            Item* it = new Item(name, bid);
            append_item(it);
            bst->insert(name, bid);
        }
    }

    void print_initial() const {
        cout << "Initial auction items:\n";
        cout << "BST (In-order): ";
        bst->print('I');
        cout << "\n\n";
        cout << "Auction starts!\n\n";
        cout << "==============================\n";
    }

    void run(ifstream &in) {
        string cmd;
        while (in >> cmd) {
            if (cmd == "BID") {
                string name; int amount; in >> name >> amount;
                Item* itm = find_item(name);
                if (itm) {
                    itm->total_bids++;
                    if (amount > itm->cur_bid) {
                        itm->cur_bid = amount;
                        itm->succBids++;
                        bst->update(name, amount);
                        cout << "Bid of " << amount << " on " << name << " accepted. Current bid: " << amount << "\n";
                    } else {
                        itm->rejBids++;
                        cout << "Bid of " << amount << " on " << name << " rejected. Current bid: " << itm->cur_bid << "\n";
                    }
                    cout << "BST (In-order): ";
                    bst->print('I');
                    cout << "\n";
                }
            } else if (cmd == "CHECK") {
                string name; in >> name; Item* itm = find_item(name);
                if (itm) {
                    cout << "Current bid for " << name << ": " << itm->cur_bid << "\n";
                    cout << "BST (In-order): ";
                    bst->print('I');
                    cout << "\n";
                }
            } else if (cmd == "STATS") {
                string name; in >> name; Item* itm = find_item(name);
                if (itm) {
                    cout << "Statistics for " << name << ":\n";
                    cout << "  Current highest bid: " << itm->cur_bid << "\n";
                    cout << "  Total bids placed: " << itm->total_bids << "\n";
                    cout << "  Successful bids: " << itm->succBids << "\n";
                    cout << "  Rejected bids: " << itm->rejBids << "\n";
                }
            } else if (cmd == "ADD") {
                string name; int start; in >> name >> start;
                if (!find_item(name)) {
                    Item* it = new Item(name, start);
                    append_item(it);
                    bst->insert(name, start);
                    cout << "Item " << name << " added with starting bid " << start << "\n";
                    cout << "BST (In-order): ";
                    bst->print('I');
                    cout << "\n";
                }
            } else if (cmd == "REPORT") {
                cout << "Auction Report:\n";
                int total_items = 0; int total_bids = 0, total_succ = 0, total_rej = 0;
                for (ItemNode* p = head; p; p = p->next) {
                    total_items++;
                    total_bids += p->item->total_bids;
                    total_succ += p->item->succBids;
                    total_rej += p->item->rejBids;
                }
                cout << "Total items: " << total_items << "\n";
                cout << "Total bids placed: " << total_bids << "\n";
                cout << "Total successful bids: " << total_succ << "\n";
                cout << "Total rejected bids: " << total_rej << "\n\n";
                cout << "Item Statistics:\n";
                // print items in alphabetical order using the sorted linked list
                for (SortedNode* s = sorted_head; s; s = s->next) {
                    Item* itm = s->item;
                    cout << "  " << itm->name << ": Current bid: " << itm->cur_bid << ", Total bids: " << itm->total_bids << ", Successful: " << itm->succBids << ", Rejected: " << itm->rejBids << "\n";
                }
            }
            cout << "==============================\n";
        }
    }
};

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file) {
        cerr << "Unable to open file\n";
        return 1;
    }

    Auction auction;
    auction.load_initial(in_file);
    auction.print_initial();
    auction.run(in_file);

    in_file.close();
    return 0;
}