#include <iostream>
#include <vector>

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
    int countNodes(TreeNode* root) {
        return dfs(root);
    }

private:
    int dfs(TreeNode* root) {
        // Base Case: 如果是空節點，數量為 0
        if (root == nullptr)
            return 0;

        // 遞迴公式：當前節點 (1) + 左子樹數量 + 右子樹數量
        return 1 + dfs(root->left) + dfs(root->right);
    }
};

int main() {
    Solution sol;

    // 建立一個二元樹範例: [1, 2, 3, 4, 5, 6]
    //        1
    //       / \
    //      2   3
    //     / \ /
    //    4  5 6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3, new TreeNode(6), nullptr);

    cout << "Total Nodes: " << sol.countNodes(root) << endl;
    // 預期輸出: 6

    // 測試範例 2: 空樹
    cout << "Empty Tree Nodes: " << sol.countNodes(nullptr) << endl;
    // 預期輸出: 0

    return 0;
}