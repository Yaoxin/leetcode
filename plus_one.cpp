#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	int len = digits.size();
    	while(len--)
    	{
			if(digits[len] == 9)
    		{
    			digits[len] = 0;
    		}
    		else
    		{
    			digits[len] += 1;
    			break;
    		}
    	}

    	if(len == -1 && digits[len + 1] == 0)
    	{
    		digits.insert(digits.begin(), 1);
    	}

		return digits;        
    }
};



int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v(5, 9);

	s.plusOne(v);

	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;

	return 0;
}