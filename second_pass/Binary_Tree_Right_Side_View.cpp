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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> v;
        if(root == NULL) {
            return v;
        }
        rightSideViewImpl(root, v, 0);
        return v;
    }

    //深度优先搜索，递归
    //也可以采用广度优先搜索，不过暂时没有递归的思路
    void rightSideViewImpl(TreeNode * root, std::vector<int> &v, int level ) {
        if(v.size() == level) {
            v.push_back(root->val);
        } else {
            v[level] = root->val;
        }
        if(root->left) {
            rightSideViewImpl(root->left, v, level + 1);
        }
        if(root->right) {
            rightSideViewImpl(root->right, v, level + 1);
        }
        return;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {
        3, 7, 2,
        NULL_INT,
        8, 23,
        NULL_INT,
        NULL_INT,
        14 
    };
    std::vector<int> v(a, a +9);
    TreeNode * root = create_binary_tree(v);
    Solution s = Solution();
    s.rightSideView(root);
    print_vector(s.rightSideView(root));
    return 0;
}
