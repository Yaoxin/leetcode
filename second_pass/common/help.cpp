#include "help.h"
#include <sys/time.h>

struct timeval start_tv;

ListNode * create_linklist(std::vector<int>v) {
    ListNode * head = new ListNode(-1);
    ListNode * cur = head;
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cur->next = new ListNode(*i);
        cur = cur->next;
    }
    return head->next;
}

void print_linklist(ListNode * head) {
    cout << "LinkList : ";
    while(head){
        cout << head->val<< " ";
        head = head->next;
    }
    cout << endl;
}

void print_vector(std::vector<int> v)
{
    cout << "Vector : ";
    for(std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}

TreeNode * create_binary_tree(std::vector<int> v) 
{
    if(v.size() == 0 || v[0] == NULL_INT) {
        return NULL;
    }
    int i = 0;
    int len = v.size();
    TreeNode * head = new TreeNode(v[i]);
    deque<TreeNode *> queue;
    queue.push_back(head);
    while(!queue.empty()) {
        TreeNode* node = queue.front();
        if(++i < len && v[i] != NULL_INT) {
            node->left = new TreeNode(v[i]);
            queue.push_back(node->left);
        }
        if(++i < len && v[i] != NULL_INT) {
            node->right = new TreeNode(v[i]);
            queue.push_back(node->right);
        }
        queue.pop_front();
    }
    return head;
}


void print_binary_tree(TreeNode * root)
{
    cout << "Binary Tree: ";
    if(root == NULL) {
        return; 
    }
    deque<TreeNode *> queue;
    queue.push_back(root);
    cout << " " << root->val;
    while(!queue.empty()) {
        TreeNode * node = queue.front();
        if(node->left || node->right) {
            if(node->left) {
                queue.push_back(node->left);
                cout << " " << node->left->val;
            } else {
                cout << " #"; 
            }
            if(node->right) {
                queue.push_back(node->right);
                cout << " " << node->right->val;
            } else {
                cout << " #";
            }
        }
        queue.pop_front();
    }
    cout << endl;
}

void profile_begin()
{
    gettimeofday(&start_tv, NULL);
}

void profile_end()
{
    struct timeval end_tv;
    gettimeofday(&end_tv, NULL);
    int interval = (end_tv.tv_sec - start_tv.tv_sec) * 1000 + (end_tv.tv_usec - start_tv.tv_usec) / 1000;
    cout << "COST " << interval << " MSEC.";
}



