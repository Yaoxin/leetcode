#include "common/help.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int sum = 0;
        int val = root->val; 
        dfs(root, val, sum);
        return sum;
    }

    void dfs(TreeNode *root, int val, int &sum) {
        if(!root->left && !root->right) {
            sum += val;
        } else {
            if(root->left) {
            dfs(root->left, 10 * val + root->left->val, sum);
            }
            if(root->right) {
                dfs(root->right, 10 * val + root->right->val, sum);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3};
    std::vector<int> v(a, a + 3);
    TreeNode * node = create_binary_tree(v);
    Solution s = Solution();
    cout << s.sumNumbers(node) << endl;
    return 0;
}