#include <iostream>

using namespace std;


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */


/*
	算法
	A——>a——B——>b——C——>c——>D——>d
*/

  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };

void print_list(RandomListNode *head)
{
	RandomListNode *temp = head;
	while(temp != NULL)
	{
		cout << " " << temp->label;
		temp = temp->next;
	}
	cout <<endl;
}


class Solution {
public:
	//时间复杂度 O(n) 空间复杂度O(1)
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(head == NULL)
    		return NULL;

    	RandomListNode *Cur = head;
    	RandomListNode *Nex = head->next;
    	RandomListNode *Temp = NULL;
    	while(Cur != NULL)
    	{
    		Temp = new RandomListNode(Cur->label);
    		Temp->next = Nex;
    		Cur->next = Temp;
    		Cur = Nex;
    		if(Nex != NULL)
    		{
    			Nex = Nex->next;
    		}
    	}

    	print_list(head);

    	Cur = head;
    	Nex = head->next;
    	while(Cur != NULL)
    	{
    		if(Cur->random != NULL)
    		{
    			Nex->random = Cur->random->next;
    		}
    		else
    		{
    			Nex->random = NULL;
    		}
    		Cur = Nex->next;
    		if(Cur != NULL)
    		{
    			Nex = Cur->next;
    		}
    	}
    	print_list(head);

    	Cur = head;
    	Nex = head->next;
    	Temp = head->next;
    	while(Cur != NULL)
    	{
    		Cur->next = Nex->next;
    		Cur = Nex->next;
    		if(Cur != NULL)
    		{
    			Nex->next = Cur->next;
    			Nex = Cur->next;
    		} 		
    	}
    	print_list(head);

    	return Temp;
    }
};

int main(int argc, char const *argv[])
{
	RandomListNode *head = new RandomListNode(1);
	int i = 1;
	RandomListNode *temp = NULL;
	RandomListNode *pre = head;
	while(i++ <= 9)
	{
		temp = new RandomListNode(i);
		pre->next = temp;
		pre = temp;
	}
	Solution s;
	RandomListNode *out =  s.copyRandomList(head);
	print_list(out);
	return 0;
}