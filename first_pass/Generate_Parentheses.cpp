#include <iostream>
#include <vector>
#include <string>

using namespace std;

//求卡特兰数的解集
//左括号的个数必须满足右括号的个数
//假设在位置k我们还剩余left个左括号和right个右括号，如果left>0，则我们可以直接打印左括号，而不违背规则。
//能否打印右括号，我们还必须验证left和right的值是否满足规则，如果left>=right，则我们不能打印右括号，
//因为打印会违背合法排列的规则，否则可以打印右括号。
class Solution {
public:
	void generate(int left, int right, string s, vector<string> &out)
	{
		cout << s << endl;
		if(left == 0 && right == 0)
		{
			out.push_back(s);
			return;
		}

		if(right > 0 && left < right)
		{
			generate(left, right - 1, s + ')', out);
		}

		if(left > 0)
		{
			generate(left - 1, right, s + '(', out);
		}
		
	}

    vector<string> generateParenthesis(int n) {
    	vector<string> out;
    	string s;
    	generate(n, n, s, out);

    	return out;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<string> out = s.generateParenthesis(3);
	for (int i = 0; i < out.size(); ++i)
	{
		cout << out[i] << endl;
	}
	return 0;
}