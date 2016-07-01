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

typedef struct _Node{
    bool vister;
    TreeNode * node;
} Node; 

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> v;
        if(!root) {
            return v;
        }
        std::stack<Node *> s;
        push_stack(root, s);
        while(!s.empty()) {
            Node * t = s.top();
            if(t->vister) {
                v.push_back(t->node->val);
                s.pop();
                continue;
            }
            if(!t->node->left && !t->node->right) {
                v.push_back(t->node->val);
                s.pop();
                continue;
            }
            if(t->node->right) {
                push_stack(t->node->right, s);
            }
            if(t->node->left) {
                push_stack(t->node->left, s);
            }
            t->vister = true;

        }
        return v;        
    }

    void push_stack(TreeNode * node, stack<Node *> &s) {
        Node * n = new Node;
        n->node = node;
        n->vister = false;
        s.push(n);
    }

};

int main(int argc, char const *argv[])
{
    int a[] = {1, NULL_INT, 2, 3};
    std::vector<int> v(a, a + 4);
    Solution s = Solution();
    TreeNode * root = create_binary_tree(v);
    print_vector(s.postorderTraversal(root));
    return 0;
}