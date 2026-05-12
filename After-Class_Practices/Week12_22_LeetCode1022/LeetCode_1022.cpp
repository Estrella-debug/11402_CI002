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
    int sum = 0;

    // 遞迴函式：now 代表從根節點到當前節點所組成的二進位數值
    void count(TreeNode* root, int now) {
        // 如果是葉節點（左右皆為空），則將累積的數值加入總和
        if (!(root->left) && !(root->right)) {
            sum += now;
            return;
        } else {
            // 往左走：目前的數值 * 2（左移） + 左子節點的值
            if (root->left) {
                count(root->left, now * 2 + (root->left)->val);
            }
            // 往右走：目前的數值 * 2（左移） + 右子節點的值
            if (root->right) {
                count(root->right, now * 2 + (root->right)->val);
            }
        }
    }

    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        sum = 0; // 重置總和，確保多次呼叫不會出錯
        count(root, root->val);
        return sum;
    }
};

int main() {
    Solution sol;

    // 建立二元樹範例: [1, 0, 1, 0, 1, 0, 1]
    //        1
    //       / \
    //      0   1
    //     / \ / \
    //    0  1 0  1
    // 路徑分別為: 100(4), 101(5), 110(6), 111(7)
    // 總和應為: 4 + 5 + 6 + 7 = 22
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0, new TreeNode(0), new TreeNode(1));
    root->right = new TreeNode(1, new TreeNode(0), new TreeNode(1));

    cout << "Total Sum (Root to Leaf): " << sol.sumRootToLeaf(root) << endl;
    // 預期輸出: 22

    return 0;
}