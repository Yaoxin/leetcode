#include <iostream>
#include <cstdlib>

using namespace std;


int ctoi(char c)
{
	return c - 48;
}

string str_convert(string &source)
{
	char str[8] = {0};
	string out;

	if(source.size() == 0)
	{
		return out;
	}
	int temp =  ctoi(source[0]);
	int count  = 0;
	for(int i = 0; i < source.size(); i++)
	{
		if(ctoi(source[i])  == temp)
		{
			count++;
		}
		else
		{
	    		snprintf(str, 8, "%d%d", count, temp);
			out += str;
			temp = ctoi(source[i]);
			count = 1;
		}
	}

	if(count != 0)
	{
		snprintf(str, 8, "%d%d", count, temp);
		out += str;
	}

	return out;
}

class Solution {
public:
    string countAndSay(int n) {
    	string say;
    	if(n == 0)
    	{
    		return say;
    	}

    	say += "1";

    	for(int i = 1; i < n; i++)
    	{
    		say = str_convert(say);
    	}
		
		return say;    	
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	string test = s.countAndSay(112233);
	cout << test << endl;

	return 0;
}

