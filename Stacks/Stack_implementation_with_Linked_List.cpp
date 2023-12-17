#include <bits/stdc++.h>
using namespace std;

#define maxsize 5

struct node
{
    int data;
    node *next;
};
class mystack
{
    node *head;
    int stacksize;

public:
    mystack()
    {
        head = NULL;
        stacksize = 0;
    }
    void push(int value)
    {
        if (stacksize == maxsize - 1)
        {
            cout << "Stack overflow !!" << endl;

            return;
        }
        node *temp = new node();
        temp->data = value;
        temp->next = head;
        head = temp;

        cout << "Element " << value << " Pushed in the stack " << endl;
        stacksize++;
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty !!" << endl;

            return;
        }
        node *temp = head;
        head = temp->next;
        delete temp;

        cout << "Element poped !!" << endl;
        stacksize--;
    }

    int top()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty !!" << endl;
            return -1;
        }
        cout << "Top element is " << head->data << endl;
        return head->data;
    }

    int size()
    {
        cout << "The size of the stack is " << stacksize << endl;
        return stacksize;
    }

    int empty()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty " << endl;
            return 1;
        }
        else
        {
            cout << "Stack is NOT Empty !!" << endl;
            return 0;
        }
    }
} st;

int main(void)
{
    node *head = NULL;
    st.empty();
    st.push(7);
    st.push(9);
    st.pop();
    st.push(10);
    st.push(4);
    st.push(0);
    st.push(6);
    st.pop();
    st.top();
    st.size();
    st.empty();
}