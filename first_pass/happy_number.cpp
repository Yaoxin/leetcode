#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int help(int n)
{
	int sum = 0;
	while(n != 0)
	{
		sum += (n % 10) * (n % 10);
		n = n /10;
	}

	return sum;
}


class Solution {
public:
    bool isHappy(int n) {
    	std::vector<int> v;
    	bool status = true;
    	int temp = n;
    	int i = 0;
    	while(temp != 1)
    	{
    		v.push_back(temp);
    		temp = help(temp);
    		for (i = 0; i < v.size(); ++i)
    		{
    			if(temp == v[i])
    			{
    				break;
    			}
    		}
    		if(i != v.size())
    		{
    			status = false;
    			break;
    		}
    	}

    	return status; 
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	bool test = s.isHappy(19);
	cout << test << endl;
	return 0;
}