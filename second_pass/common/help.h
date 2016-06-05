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


    
ListNode * create_linklist(std::vector<int>v);
void print_linklist(ListNode * head);
void print_vector(std::vector<int> v); 









#endif