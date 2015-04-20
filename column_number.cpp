#include <iostream>

using namespace std;


class Solution {
public:
    int titleToNumber(string s) {

    	int j = 0;
    	int sum = 0;
    	int temp = 0;
    	for(int i = s.size(); i > 0; i--, j++ )
    	{
    		temp = (s[i - 1] - 'A' + 1);
    		for(int z = j; z > 0; z--)
    		{
    			temp = temp * 26;    		
    		}
    		sum = temp + sum;
    	}
    	return sum;
    }
};

int main(int argc, char const *argv[])
{
	string s = "AAA";
	Solution test;
	int num = test.titleToNumber(s);
	cout << num << endl;
	return 0;
}