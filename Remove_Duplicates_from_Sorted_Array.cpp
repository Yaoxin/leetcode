#include <iostream>

using namespace std;


class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n < 2)
    		return n;
    	int pos = 0;
    	int i = 1;
    	for(i = 1; i < n; i++)
    	{
    		if(A[i - 1] != A[i])
    		{
    			A[pos++] = A[i - 1];
    		}
    	}
    	A[pos] = A[i - 1];

    	return pos + 1;
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {1, 3, 3, 2};
	int ret = s.removeDuplicates(a, 4);
	for (int i = 0; i < ret; ++i)
	{
		cout << " " << a[i];
	}
	cout << endl;
	return 0;
}








