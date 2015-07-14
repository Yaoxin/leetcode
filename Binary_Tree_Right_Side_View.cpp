#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

struct AssistNode
{
	TreeNode *node;
	int level;
};

class Solution {
public:
	//层序遍历
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> out;
    	if(root == NULL)
    		return out;
    	struct AssistNode Assist;
    	Assist.node = root;
    	Assist.level = 1;
    	queue<struct AssistNode> q;
    	q.push(Assist);

    	struct AssistNode cur;
    	int curlevel = 0;

    	while(!q.empty())
    	{
    		Assist = q.front();
    		if(Assist.level != curlevel)
    		{
    			out.push_back(Assist.node->val);
    			curlevel = Assist.level;
    		}
    			
    		if(Assist.node->right)
    		{
    			cur.node = Assist.node->right;
    			cur.level = Assist.level + 1;
    			q.push(cur);
    		}
    		if(Assist.node->left)
    		{
    			cur.node = Assist.node->left;
    			cur.level = Assist.level + 1;
    			q.push(cur);
    		}
    		q.pop();
    	}

    	return out;        
    }

    //bfs
    void bfs(TreeNode *root, vector<int> &right, int level)
    {
    	if(level = right.size())
    		right.push_back(root->val);
    	if(root->right)
    		bfs(root->right, right, level + 1);
    	if(root->left) 
    		bfs(root->left, right, level + 1);
    }
    vector<int> rightSideView(TreeNode* root)
    {
    	vector<int> right;
    	if(!root) return right;

    	bfs(root, right, 0);

    	return right;
    }

    //dfs
    void dfs(TreeNode *root, vector<int> &right, int level)
    {
    	if(right.size() < level + 1)
    		right.resize(level + 1);
    	right[level] = root->val;
    	if(right->left)
    		dfs(root->left, right, level + 1);
    	if(right->right)
    		dfs(root->right, right, level + 1);
    }

    vector<int> rightSideView(TreeNode* root)
    {
    	vector<int> right;
    	if(!root) return right;
    	dfs(root, right, 0);
    	return right;
    }
};