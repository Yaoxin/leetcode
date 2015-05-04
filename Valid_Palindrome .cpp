#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
    	int beg = 0;
    	int end = s.size() - 1;

    	while(beg < end)
    	{
    		while(!(isalpha(s[beg]) || isdigit(s[beg])))
    		{
    			beg++;
    		}
    		while(!(isalpha(s[end]) || isdigit(s[end])))
    		{
    			end--;
    		}

    		if(toupper(s[beg]) == toupper(s[end]))
    		{
    			beg++;
    			end--;
    			continue;
    		}
    		break;
    	}

    	return (beg < end)?false:true;
        
    }
};


int main(int argc, char const *argv[])
{
	string s = "1a2";
	Solution test;
	bool a = test.isPalindrome(s);
	cout << a << endl;
	cout << s << endl;
	return 0;
}

