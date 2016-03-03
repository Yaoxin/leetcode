#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
    int lengthOfLastWord(const char *s) {
    	string text = s;
    	int pos = text.find_last_not_of(' ');
    	text.erase(pos + 1);
    	pos = text.find_last_of(' ');
    	return text.length() - pos - 1;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int len = s.lengthOfLastWord("hello world");
	cout << len << endl;
	return 0;
}