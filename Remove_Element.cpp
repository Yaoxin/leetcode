#include <iostream>


using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
    	int pos = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		if(A[i] != elem)
    		{
    			if(pos != i)
    			{
    				A[pos] = A[i];
    			}
    			pos++;
    		}
    	}

    	return pos;
    }
};