/*
    Stack (LIFO):
        Stores a list of items in which an item can be added to or removeed from the list only at one end.

        Operations:
            push() ==> To insert any element at the top of the stack.
            pop()   ==> Removes the top most element from the stack.
            top()   ==> It return the top most element in the stack.It always points to the top most element.
            empty() ==> It will tell if the stack is empty or not.
*/

#include <iostream>
using namespace std;

#define n 100

class stack
{
private:
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow " << endl;
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No Element to pop " << endl;
            return;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "No Element to pop " << endl;
            return 0;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
} st;

int main(void)
{

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty();
}