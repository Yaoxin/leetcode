#include <iostream>

using namespace std;


class Solution {
public:
	int GeneralCount(int num)
	{
		if(num == 0)
		{
			return 0;
		}
		else
		{
			int add = 1;
			for(int i = num; i > 1; i--)
			{
				add *= 10;
			}
			return 10 *GeneralCount(num - 1) + add;
		}
	}

    int countDigitOne(int n) {
    	if(n < 0)
    		return 0;
    	int sum = 0;
    	int count = 0;
    	int x = n;
    	int y = 0;
    	int z = 0;
    	int t = 1; 
    	while(x)
    	{
    		y = x%10;
    		x /=10;
    		t = 1;
    		for(int i = 0; i < count; i++)
    		{
    			t *= 10;	
    		}
    		if(y != 0)
    		{
    			sum = y * GeneralCount(count) + ((y == 1)?(z + 1):t) + sum;
    		}
    		z += t*y;
    		count++; 
    		//cout << "count =" << count << " sum = "<< sum << " t = " << t<< " z = " << z << endl;
    	}

    	return sum;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int out = s.countDigitOne(999);
	cout << out << endl;
	return 0;
}

