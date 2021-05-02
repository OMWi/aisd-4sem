#include "tree.h"

Node* Node::grandfather() {
    if ((this != nullptr) && (this->parent != nullptr)) 
        return this->parent->parent;
    else
        return nullptr;
}

Node* Node::uncle() {
    Node* grand = grandfather();
    if (grand == nullptr) 
        return nullptr;
    if (this->parent == grand->left) 
        return grand->right;
    else 
        return grand->left;
}


void Tree::rotateLeft(Node* node) {
    Node* pivot = node->right;

    pivot->parent = node->parent;

    if (node->parent != nullptr) {
        if (node->parent->left == node)
            node->parent->left = pivot;
        else 
            node->parent->right = pivot;
    }

    node->right = pivot->left;
    if (pivot->left != nullptr)
        pivot->left->parent = node;

    node->parent = pivot;
    pivot->left = node;
}

void Tree::rotateRight(Node* node) {
    Node* pivot = node->left;

    pivot->parent = node->parent;

    if (node->parent != nullptr) {
        if (node->parent->left == pivot)
            node->parent->left = pivot;
        else
            node->parent->right = pivot;
    }

    node->left = pivot->right;
    if (pivot->right != nullptr) 
        pivot->right->parent = node;
    
    node->parent = pivot;
    pivot->right = node;
}

void Tree::recolor(Node* node) {
    if (node->color == Color::Black) 
        node->color = Color::Red;
    else
        node->color = Color::Black;
}


void Tree::insert(int key) {
    Node* newNode = new Node(key);
    if (!root) {
        newNode->color = Color::Black;
        root = newNode;
        return;
    }

    Node* current = root;
    while (!current) {
        if (newNode->key > current->key) {
            current = current->right;
        }
        else if (newNode->key < current->key) {
            current = current->left;
        }
    }

    current = newNode;
    if (current->parent->color == Color::Red) {
        if (!current->uncle() || current->uncle()->color == Color::Black) {
            Node* p = current->parent;
            Node* g = current->grandfather();
            if (p == g->right && current == p->right) {
                rotateLeft(g);
                recolor(p->left);
                recolor(p);
            }
            else if (p == g->right && current == p->left) {
                rotateRight(p);
                rotateLeft(g);
                recolor(p->left);
                recolor(p);
            }
            else if (p == g->left && current == p->left) {
                
            }
        }
        else if (current->uncle()->color == Color::Red) {
            recolor(current->parent);
            recolor(current->uncle());
            if (current->grandfather() != root)
                recolor(current->grandfather());
        }
    } 
           
}






Node* Tree::search(int key) {
    return search(root, key);
}

Node* Tree::search(Node* current, int key) {
    if (!current || current->key == key) return current;
    if (key > current->key) return search(current->right, key);
    else if (key < current->key) return search(current->left, key);
}

