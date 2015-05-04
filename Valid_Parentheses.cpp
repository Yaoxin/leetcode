#include <iostream>
#include <stack>

using namespace std;

bool isMatch(char c1, char c2)
{
	if((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') \
		|| (c1 == '{' && c2 == '}') )
		return true;
	return false;
}


class Solution {
public:
    bool isValid(string s) {
    	if(s.empty())
    		return false;
    	stack<char> st;
    	for (int i = 0; i < s.size(); ++i)
    	{
    		if(!st.empty())
    		{
    			if(isMatch(st.top(), s[i]))
    			{
    				st.pop();
    			}
    			else
    			{
    				st.push(s[i]);
    			}
    		}
    		else
    		{
    			st.push(s[i]);
    		}
    	}

    	return st.empty()?true:false;
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	string test1 = "(){}[]";
	string test2 = "({]";
	cout << s.isValid(test1) << endl;
	cout << s.isValid(test2) << endl;
	return 0;
}
