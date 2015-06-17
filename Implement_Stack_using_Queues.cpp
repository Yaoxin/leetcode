#include <iostream>
#include <queue>


using namespace std;

//这道题目还是蛮有意思的。
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        my_stack.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (!empty())
        {
            int size = my_stack.size() - 1;
            while(size--)
            {
                my_stack.push(my_stack.front());
                my_stack.pop();
            }
            my_stack.pop();
        }
        
    }

    // Get the top element.
    int top() {
        if(!empty())
        {
            return my_stack.back();
        }

        return -1;
    }

    // Return whether the stack is empty.
    bool empty() {
        return my_stack.empty();
    }

private:
    queue<int> my_stack;
};


int main(int argc, char const *argv[])
{
    Stack s;
    s.push(3);
    s.push(2);
    s.push(1);
    cout << s.top()<< endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}