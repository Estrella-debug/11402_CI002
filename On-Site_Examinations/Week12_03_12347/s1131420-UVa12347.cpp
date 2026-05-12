#include <iostream>
#include <vector>

using namespace std;

// 定義二元樹結構
struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// 插入節點至BST
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// 後序走訪：左 -> 右 -> 根
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << endl;
}

int main() {
    int val;
    Node* root = NULL;
    // 讀取直到 EOF
    while (cin >> val) {
        root = insert(root, val);
    }
    
    // 輸出後序序列
    postorder(root);
    
    return 0;
}
