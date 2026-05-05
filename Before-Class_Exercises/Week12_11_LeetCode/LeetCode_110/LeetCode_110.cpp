#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 定義二元樹節點結構
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // check 函式同時負責兩件事：
    // 1. 如果子樹平衡，回傳該子樹的高度。
    // 2. 如果子樹不平衡，回傳 -1。
    int check(TreeNode* x) {
        if (!x) {
            return 0; // 空節點高度為 0
        }

        int l = check(x->left);
        if (l == -1) {
            return -1; // 左子樹已不平衡，直接向上回傳 -1
        }

        int r = check(x->right);
        if (r == -1) {
            return -1; // 右子樹已不平衡，直接向上回傳 -1
        }

        // 檢查當前節點是否平衡
        if (abs(l - r) > 1) {
            return -1;
        };

        // 平衡則回傳當前高度
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return (check(root) != -1);
    }
};

int main() {
    Solution sol;

    // 建立一個平衡二元樹範例: [3, 9, 20, null, null, 15, 7]
    //      3
    //     / \
    //    9  20
    //      /  \
    //     15   7
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    cout << "Example 1 (Balanced): " << (sol.isBalanced(root1) ? "True" : "False") << endl;

    // 建立一個不平衡二元樹範例: [1, 2, 2, 3, 3, null, null, 4, 4]
    //        1
    //       / \
    //      2   2
    //     / \
    //    3   3
    //   / \
    //  4   4
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);

    cout << "Example 2 (Unbalanced): " << (sol.isBalanced(root2) ? "True" : "False") << endl;

    return 0;
}