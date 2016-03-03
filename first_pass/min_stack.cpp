#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
    	s.push(x);
    	if(m.empty())
    	{
    		m.push(x);
    	}
    	else
    	{
    		if(m.top() >= x)
    		{
    			m.push(x);
    		}
    	}
    }

    void pop() {
    	if(!s.empty())
    	{
    		int c = s.top();
    		s.pop();
    		if(!m.empty() && c == m.top())
    		{
    			m.pop();
    		}
    	}
        
    }

    int top() {
    	int c = 0;
    	if(!s.empty())
    	{
    		c = s.top();
    	}
    	return c;
        
    }

    int getMin() {
    	int c = 0;
    	if(!m.empty())
    	{
    		c = m.top();
    	}
    	return c;
    }
 private:
 	stack<int> s;
 	stack<int> m;
};

int main(int argc, char const *argv[])
{
	MinStack s;
	s.push(2147483646);
	s.push(2147483646);
	s.push(2147483647),
	s.top();
	s.pop();
	cout << s.getMin() << endl;
	s.pop();
	cout <<s.getMin()<< endl;
	s.pop();
	s.push(2147483647);
	s.top();
	cout << s.getMin() << endl;
	s.push(-2147483648);
	s.top();
	s.getMin();
	s.pop();
	cout << s.getMin() << endl;

	return 0;
}