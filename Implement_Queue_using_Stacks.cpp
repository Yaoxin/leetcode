#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        if(empty())
        {
            value = x;
        }
        my_queue.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(empty())
            return;
        stack<int> temp;
        int n = my_queue.size();
        for(int i = 0; i < n - 1; i++)
        {
            temp.push(my_queue.top());
            my_queue.pop();
        }
        my_queue.pop();
        n = temp.size();
        for(int i = 0; i < n; i++)
        {
            push(temp.top());
            temp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if(!empty())
        {
            return value;
        }
        return -1;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return my_queue.empty();
    }
private:
    int value;
    stack<int> my_queue;
};

int main(int argc, char const *argv[])
{
    Queue test;
    test.push(1);
    test.push(2);
    test.pop();
    test.push(3);
    test.push(4);
    test.pop();
    cout << test.peek() <<endl;

/*
    int out = test.peek();
    cout << out << endl;
    test.pop();
    if(!test.empty())
        cout << "not empty" << endl;
    out = test.peek();
    cout << out << endl;
    test.pop();
     if(!test.empty())
        cout << "not empty" << endl;
     else
        cout << "empty" << endl;
*/
    return 0;
}


