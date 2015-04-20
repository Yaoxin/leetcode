#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


class Solution {
public:
    void rotate_bak(int nums[], int n, int k) {
    	int temp = 0;

    	while(k--)
    	{
    		temp = nums[n - 1];
    		for(int i = n - 1; i > 0; i--)
    		{
    			nums[i] = nums[i - 1];
    		}
    		nums[0] = temp;
    	}
    }

    void rotate(int nums[], int n, int k)
    {
    	if(k == 0)
    	{
    		return;
    	}
    	if(k > n)
    	{
    		k = k - n;
    	}
    	int a = n / k;
    	int b = n % k;
    	int index = n - 1;
    	while(a-- > 1)
    	{
    		for(int i = index; i > index - k; i--)
    		{
    			swap(nums[i], nums[i - k]);
    		}
    		index -= k;
    	}
    	int temp = 0;
    	while(b--)
    	{
    		temp = nums[0];
    		for(int i = 0; i < index; i++)
    		{
    			nums[i] = nums[i+1];
    		}
    		nums[index] = temp;
       	}
    }
};

int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int b[] = {1};
	Solution test;
	test.rotate(a, 7, 3);
	test.rotate(b, 1, 0);
	for (int i = 0; i < 7; ++i)
	{
		cout << a[i] << endl;
	}

	for(int i = 0; i < 1; ++i)
	{
		cout << b[i] << endl;
	}
	return 0;
}