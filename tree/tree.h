struct Node {
    int key;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
    Node(int key) {
        this->key = key;
        color = Color::Red;
        left = right = nullptr;
    }
    Node* grandfather();
    Node* uncle();
};

enum Color {Black, Red};

class Tree {
    Node* root;
    Node* search(Node* current, int key);
public:
    Tree() {
        root = nullptr;
    }
    void rotateLeft(Node* node);
    void rotateRight(Node* node); 
    void recolor(Node* node);

    void insert(int key);      
    Node* search(int key); 

};