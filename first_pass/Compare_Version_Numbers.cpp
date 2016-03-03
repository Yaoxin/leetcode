#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int compareVersion(string version1, string version2) {
    	int num1 = 0, num2 = 0;

    	while(version1 != "" || version2 != "")
    	{
    		string::size_type pos = version1.find_first_of(".");
	    	if(pos != string::npos)
	    	{
	    		num1 = atoi(version1.substr(0, pos).c_str());
	    		version1 = version1.substr(pos + 1);
	    	}
	    	else
	    	{
	    		num1 = atoi(version1.c_str());
	    		version1 = "";

	    	}
	        
	        pos = version2.find_first_of(".");
	        if(pos != string::npos)
	        {
	        	num2 = atoi(version2.substr(0, pos).c_str());
	        	version2 = version2.substr(pos + 1);
	        }
	        else
	        {
	        	num2 = atoi(version2.c_str());
	        	version2 = "";
	        }

	        if(num1 != num2)
	        {
	        	break;
	        }
    	}

    	if(num1 == num2)
    	{
    		return 0;
    	}

    	return (num1 > num2)?1:-1;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int out = s.compareVersion("1.0", "1.0.1");
	cout << out << endl;
	return 0;
}