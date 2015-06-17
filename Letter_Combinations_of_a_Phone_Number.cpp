#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


class Solution {
public:
	//这个动作非常耗时，涉及到对象的复制、删除。
	void helper(vector<string> &v, string &s)
	{
		string text;
		if(v.size() == 0)
		{
			for (int i = 0; i < s.length(); ++i)
			{
				text = s[i];
				v.push_back(text);
			}
			return;
		}

		vector<string> temp(v);
		v.clear();
		for (int i = 0; i < temp.size(); ++i)
		{
			for(int j = 0; j < s.length(); j++)
			{
				text = temp[i] + s[j];
				v.push_back(text);
			}
		}
	}

    vector<string> letterCombinations(string digits) {
    	vector<string> out;
    	static string table[] = {"", "", "abc", "def", "ghi", "jkl",\
    	"mno", "pqrs", "tuv", "wxyz"};
    	for(int i = 0; i < digits.size(); i++)
    	{
    		helper(out, table[digits[i] - '0']);
    	}

    	return out;
    }


    //采用dfs
    void dfs(vector<string> &out, int level, string cur,string &digits)
    {
    	if(level == digits.size())
    	{
    		out.push_back(cur);
    	}
    	static string table[] = {"", "", "abc", "def", "ghi", "jkl",\
    	"mno", "pqrs", "tuv", "wxyz"};

    	string temp = table[digits[level] - '0'];
    	for (int i = 0; i < temp.size(); ++i)
    	{
    		dfs(out, level + 1, cur + temp[i], digits);
    	}
    }

    vector<string> letterCombinations_dfs(string digits) {
    	vector<string> out;
    	string cur = "";
    	dfs(out, 0, cur,digits);
    	return out;
    }

    //采用top-down
    vector<string> td(int level, string digits)
    {
    	static string table[] = {"", "", "abc", "def", "ghi", "jkl",\
    	"mno", "pqrs", "tuv", "wxyz"};	
    	vector<string> ret;
    	string text = table[digits[level] - '0'];
    	if(level == 0)
    	{
    		for (int i = 0; i < text.length(); ++i)
    		{
    			stringstream stream;
    			stream << text[i];
    			string str = stream.str();
    			ret.push_back(str);
    		}

    		return ret;
    	}
    	else
    	{
    		std::vector<string> v = td(level - 1, digits);
    		for (int i = 0; i < text.length(); ++i)
    		{
    			for (int j = 0; j < v.size(); ++j)
    			{
    				ret.push_back(v[j] + text[i]);
    			}
    		}

    		return ret;
    	}
    }

    vector<string> letterCombinations_td(string digits) {
    	return td(digits.size() - 1, digits);
    }
};







int main(int argc, char const *argv[])
{
	Solution s;
	vector<string> out = s.letterCombinations_td("23");
	for (int i = 0; i < out.size(); ++i)
	{
		cout << out[i] << endl;
	}

	return 0;
}