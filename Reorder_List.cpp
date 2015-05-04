#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    void reorderList(ListNode *head) {
    	ListNode *fast = head;
      ListNode *slow = head;

      while(fast != NULL && fast->next != NULL)
      {
          fast = fast->next->next;
          slow = slow->next;
      }

      ListNode * pre = slow;
      if(pre == NULL)
      {
        return;
      }

      cout << pre->val << endl;

      //reserve thr list
      ListNode *rehead = pre->next;
      if(rehead == NULL)
      {
        return; 
      }

      ListNode *Cur = rehead->next;
      ListNode *temp = rehead->next;
      rehead->next = NULL;
      
      while(Cur != NULL)
      {
        Cur = Cur->next;
        temp->next = rehead;
        rehead = temp;
        temp = Cur;
      }

      pre->next = NULL;
      Cur = head;
      ListNode * rehead_temp = NULL;
      while(Cur != NULL && rehead != NULL)
      {
        temp = Cur->next;
        Cur->next = rehead;
        rehead_temp = rehead->next;
        rehead->next = temp;
        rehead = rehead_temp;
        Cur = temp;
      }
    }
};


int main(int argc, char const *argv[])
{
  ListNode a(1);
  ListNode b(2);
  ListNode c(3);
  ListNode d(4);
  ListNode e(5);
  ListNode f(6);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = &f;
  f.next = NULL;

  Solution s;
  s.reorderList(&a);

  ListNode *cur = &a;
  while(cur != NULL)
  {
    cout << " " << cur->val;
    cur = cur->next;
  }
  cout << endl;
  return 0;
}
