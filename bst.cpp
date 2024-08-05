#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node* insertIntoBST(Node* root, int d) {
    if (root == nullptr) {
        root = new Node(d);
        return root;
    }
    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else if (d < root->data) {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
void takeInput(Node* &root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}
void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current == nullptr) {
            cout << endl;
            if (!q.empty()) {
                q.push(nullptr);
            }
        } else {
            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
}

int main() {
    Node* root = nullptr;
    cout << "Enter data to create BST (enter -1 to stop):" << endl;
    takeInput(root);
    cout << "Level order Traversal:" << endl;
    levelOrderTraversal(root);

    return 0;
}
