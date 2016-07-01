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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return balanced(root, depth);
    }

    bool balanced(TreeNode * node, int & depth) {
        if (!node)
        {
            return true;
        }
        int left = 0, right = 0;
        if(balanced(node->left, left) && balanced(node->right, right))
        {
            if(abs(left - right) <= 1) {
                depth = 1 + std::max(left, right);
                return true;
            }
        }
        return false; 
    }
 };

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, NULL_INT, 3};
    std::vector<int> v(a, a + 4);
    TreeNode * root = create_binary_tree(v);
    Solution s = Solution();
    cout << s.isBalanced(root) << endl;
    return 0;
}