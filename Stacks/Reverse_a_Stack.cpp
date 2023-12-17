/*
    There are two methods of doing this, i.e.:
        1. Using another stack for storing every pushed element
        2. Recursion method
*/

#include <iostream>
#include <stack>

using namespace std;

void insert_at_bottom(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);

        return;
    }
    int top_element = st.top();
    st.pop();

    insert_at_bottom(st, element);

    st.push(top_element);
}

// Called by reference because we are making changes in the same stack.

void reverse(stack<int> &st)
{

    /*
    This function either removes or stores the top element.
    It then goes through the stack from the second element to the last one,
    and finally adds the removed element back at the end.
    */

    if (st.empty())
    {
        return;
    }
    int element = st.top();
    st.pop();
    reverse(st);
    insert_at_bottom(st, element);
}

int main(void)
{
    stack<int> st;

    int stack_size;
    int element;

    cout << "Enter the number of Elements you want to insert in the stack " << endl
         << "=> ";
    cin >> stack_size;

    cout << endl
         << "Enter the elements in the stack " << endl;
    for (int i = 0; i < stack_size; i++)
    {
        cout << "-> ";
        cin >> element;
        st.push(element);
    }

    cout << endl
         << "Stack After Reversing " << endl;

    reverse(st);

    while (!st.empty())
    {
        cout << "=> " << st.top() << endl;
        st.pop();
    }
    cout << endl;
}
