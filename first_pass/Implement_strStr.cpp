#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define 	TABLE_LEN	26

class Solution {
public:
	//字符串匹配
	int strStr_horspool(string haystack, string needle) {
		int n = haystack.size();
		int m = needle.size();
		if(n < m || n == 0 || m == 0)
		{
			return -1;
		}
		//预排序，也可以以字母表的字符为索引
		std::vector<int> v(TABLE_LEN, m);
		for(int i = 0; i <= m - 2; i++)
		{
			v[needle[i] - 'a'] = m - i - 1;
			cout << needle[i] << " "<<v[needle[i] - 'a'] << endl;
		}

		int i = m - 1;//移到模式最右端的位置
		int k = 0;
		while(i <= n - 1)
		{
			k = 0;
			while(k <= m - 1)
			{
				if(haystack[i - k] == needle[m - 1 - k])
				{
					k++;
					continue;
				}
				break;
			}

			if(k == m)
			{
				return i - m + 1;
			}
			else
			{
				i += v[haystack[i] - 'a'];
			}
		}

		return -1;    
	}
};

int main(int argc, char const *argv[])
{
	//string a = "abbbbbaabbaabaabbbaaaaabbabbbabbbbb \
	//aababaabbaabbbbbababaababbbbaaabbbbabaabaaaabbbbabbbaabbbaabbaaabaabaaaaaaaa";
	//string b = "abbbaababbbabbbabbbbbabaaaaaaabaabaabbbbaabab";

	string a = "mississippi";
	string b = "issi";

	Solution s;
	int index = s.strStr_horspool(a, b);

	cout << index << endl;
	return 0;
}