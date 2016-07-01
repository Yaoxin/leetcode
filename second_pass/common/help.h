#ifndef HELP_H_
#define HELP_H_

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <stack>
#include <limits>
#include <cmath>

#define NULL_INT numeric_limits<int>::min()
#define MAX_INT numeric_limits<int>::max()
#define MIN_INT numeric_limits<int>::min()


using namespace std;


//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

template <typename T>
void leetcode_swap(T &left, T &right) {
    unsigned char *pleft = reinterpret_cast<unsigned char *>(&left);
    unsigned char *pright = reinterpret_cast<unsigned char *>(&right);
    for (unsigned long x = 0; x < sizeof(T); ++x)  
    {  
        pleft[x] ^= pright[x];  
        pright[x] ^= pleft[x];  
        pleft[x] ^= pright[x];  
    }   
}


    
ListNode * create_linklist(std::vector<int>v);
void print_linklist(ListNode * head);
void print_vector(std::vector<int> v);
TreeNode * create_binary_tree(std::vector<int> v);
void print_binary_tree(TreeNode * root); 









#endif