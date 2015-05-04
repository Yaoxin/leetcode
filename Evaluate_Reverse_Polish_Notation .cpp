#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cstdlib>


using namespace std;

int my_calc(int num1, int num2, string operator_str)
{
	if(operator_str == "+")
	{
		return num1 + num2;
	}
	else if(operator_str == "-")
	{
		return num1 - num2;
	}
	else if(operator_str == "*")
	{
		return num1 * num2;
	}
	else if(operator_str == "/")
	{
		return num1 / num2;
	}

	return 0;
}


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	if(tokens.size() == 0)
    	{
    		return 0;
    	}

    	int num1 = 0;
    	int num2 = 0;
    	stack<int> st;
    	
    	for(int i = 0; i < tokens.size(); i++)
    	{
    		if(tokens[i] == "*" || tokens[i] == "-" ||\
    			tokens[i] == "/" || tokens[i] == "+")
    		{
    			num1 = st.top();
    			st.pop();
    			num2 = st.top(); 
    			st.pop();
    			st.push(my_calc(num2, num1, tokens[i]));
    		}
    		else
    		{
    			st.push(atoi(tokens[i].c_str()));
    		}
    	}
        return st.top();
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<string> v;
	v.push_back("3");
	v.push_back("6");
	v.push_back("*");

	cout << s.evalRPN(v) << endl;
	return 0;
}