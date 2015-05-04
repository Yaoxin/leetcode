#include <iostream>
#include <cstdlib>

using namespace std;



class Solution {
public:
	//递增
    void merge(int A[], int m, int B[], int n) {
    	int *temp = (int *)new int[m + n];
    	int i = 0;
    	int j = 0;
    	int z = 0;

    	while(i < m && j < n)
    	{
    		if(A[i] < B[j])
    		{
    			temp[z++] = A[i++];
    		}
    		else
    		{
    			temp[z++] = B[j++];
    		}
    	}

    	if(i >= m)
    	{
    		memcpy(temp + z, B + j, (n - j) *sizeof(int));
    	}
    	else
    	{
    		memcpy(temp + z, A + i, (m - i) *sizeof(int));
    	}
    	memcpy(A, temp, (m + n)*sizeof(int));
    }
};



int main(int argc, char const *argv[])
{
	int A[12] = {1, 5, 7, 9, 12, 23, 45};
	int B[5] = {3, 8, 11, 19, 20};
	Solution s;
	s.merge(A, 7, B, 5);
	for (int i = 0; i < 12; ++i)
	{
		cout << A[i] << endl;
	}

	return 0;
}