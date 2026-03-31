#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>

/**
 * Binary Search Tree implementation using linked list structure
 *
 * @tparam Key - The type of keys stored in the BST
 * @tparam Value - The type of values associated with keys
 */
template <typename Key, typename Value>
class ListBST : public BST<Key, Value>
{
private:
    /**
     * Node class for the binary search tree
     */
    class Node
    {
    public:
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node *root;
    size_t node_count;

    // TODO: Implement private helper functions as needed
    // Start your private helper functions here
    Node *insertNode(Node *node, Key key, Value value, bool &inserted)
    {
        if (node == nullptr)
        {
            inserted = true;
            
            return new Node(key, value);
        }

        if (key == node->key)
        {
            inserted = false;
            return node;
        }
        else if (key < node->key)
            node->left = insertNode(node->left, key, value, inserted);
        else
            node->right = insertNode(node->right, key, value, inserted);
        return node;
    }

    Node *findNode(Node *node, Key key) const
    {
        if (!node)
        {
            return nullptr;
        }
        if (key == node->key)
            return node;
        else if (key < node->key)
            return findNode(node->left, key);
            else
        return findNode(node->right, key);
    }
   

    Node *removeNode(Node *node, Key key, bool &removed)
    {
        if (!node)
        {
            return nullptr;
        }

        if (key < node->key)
        {
            node->left = removeNode(node->left, key, removed);
        }
        else if (key > node->key)
        {
            node->right = removeNode(node->right, key, removed);
        }
        else
        {
            removed = true;
            

            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node* s = node->right;
            while (s->left)
                s = s->left;
            node->key = s->key;
            node->value = s->value;
            bool r = false;
            node->right = removeNode(node->right, s->key, r);
            }
        }
        return node;
    }
    void clearNode(Node *node)
    {
        if (!node)
        {
            return;
        }
        clearNode(node->left);
        clearNode(node->right);
        delete node;
    }
void printDefault(std::ostream &os, Node *node) const
{
    if (!node)
    {
        os << "()";
        return;
    }

    if (!node->left && !node->right)
    {
        os << "(" << node->key << ":" << node->value << ")";
        return;
    }

    os << "(" << node->key << ":" << node->value;

    
    if (node->left)
    {
        os << " ";
        printDefault(os, node->left);
    }
    else if (node->right)
    {
        
        os << " ()";
    }

    
    if (node->right)
    {
        os << " ";
        printDefault(os, node->right);
    }

    os << ")";
}

   void printIn(Node *node) const {
    if (!node) return;
    printIn(node->left);
    std::cout << "(" << node->key << ":" << node->value << ") ";
    printIn(node->right);
}

void printPre(Node* node) const {
    if (!node) return;
    std::cout << "(" << node->key << ":" << node->value << ") ";
    printPre(node->left);
    printPre(node->right);
}

void printPost(Node* node) const {
    if (!node) return;
    printPost(node->left);
    printPost(node->right);
    std::cout << "(" << node->key << ":" << node->value << ") ";
}



    // End your private helper functions here

public:
    /**
     * Constructor
     */
    ListBST() : root(nullptr), node_count(0) {}

    /**
     * Destructor
     */
    ~ListBST()
    {
        // TODO: Implement destructor to free memory
        clear();
    }

    /**
     * Insert a key-value pair into the BST
     */
    bool insert(Key key, Value value) override
    {
        // TODO: Implement insertion logic
        
        bool inserted = false;
        root = insertNode(root, key, value, inserted);
        if(inserted == true){
            node_count++;
        }
        return inserted;
    }



    /**
     * Remove a key-value pair from the BST
     */
    bool remove(Key key) override
    {
        // TODO: Implement removal logic
        
        bool removed = false;
        root = removeNode(root, key, removed);
         if(removed == true){
            node_count--;
        }
        return removed;
    }

    /**
     * Find if a key exists in the BST
     */
    bool find(Key key) const override
    {
        // TODO: Implement find logic
        return findNode(root, key) != nullptr;
    }

    /**
     * Find a value associated with a given key
     */
    Value get(Key key) const override
    {
        Node* n = findNode(root, key);
        if (!n) throw std::runtime_error("Key not found");
        return n->value;
    }

    /**
     * Update the value associated with a given key
     */
    void update(Key key, Value value) override
    {
        // TODO: Implement update logic
         Node* n = findNode(root, key);
    if (!n) throw std::runtime_error("Key not found");
    n->value = value;
    }

    /**
     * Clear all elements from the BST
     */
    void clear() override
    {
        // TODO: Implement clear logic
         clearNode(root);
    root = nullptr;
    node_count = 0;
    }

    /**
     * Get the number of keys in the BST
     */
    size_t size() const override
    {
        // TODO: Implement size logic
        return node_count;
    }

    /**
     * Check if the BST is empty
     */
    bool empty() const override
    {
        // TODO: Implement empty check logic
         return node_count == 0;
    }

    /**
     * Find the minimum key in the BST
     */
    Key find_min() const override
    {
        // TODO: Implement find_min logic
         if (!root) throw std::runtime_error("BST is empty");
    Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur->key;
    }

    /**
     * Find the maximum key in the BST
     */
    Key find_max() const override
    {
        // TODO: Implement find_max logic
        
if (!root) throw std::runtime_error("BST is empty");
    Node* cur = root;
    while (cur->right) cur = cur->right;
    return cur->key;
    }

    /**
     * Print the BST using specified traversal method
     */
    void print(char traversal_type = 'D') const override
    {
        // TODO: Implement print logic
          switch (traversal_type) {
        case 'D': case 'd':
            if (!root) { std::cout << "Empty"; return; }
            printDefault(std::cout, root);
            return;
        case 'I': case 'i':{
        
            printIn(root);
            return;
        }
        case 'P': case 'p':{
        
            printPre(root);
            return;
        }
        case 'O': case 'o':{
            
            printPost(root);
            return;
        }
        default:
            throw std::invalid_argument("Invalid traversal type");
    }
    }
};

#endif // LISTBST_H