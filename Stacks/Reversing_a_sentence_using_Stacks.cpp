#include <iostream>
#include <stack>
#include <strings.h>
using namespace std;

void reverse_string(string str)
{
    stack<string> st;

    for (int i = 0; i < str.length(); i++)
    {
        string word = "";
        while (str[i] != ' ' && i < str.length())
        {
            word += str[i];
            i++;
        }
        st.push(word);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    string str;

    cout << "Enter a Sentence " << endl
         << "=> ";
    getline(cin, str);

    reverse_string(str);
}