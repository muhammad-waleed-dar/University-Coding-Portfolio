#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isdigit(ch))
        {
            while (i < infix.length() && isdigit(infix[i]))
            {
                postfix += infix[i];
                i++;
            }
            postfix += ' ';
            i--;
        }

        else if (isalpha(ch))
        {
            postfix += ch;
            postfix += ' ';
        }

        else if (ch == '(')
        {
            st.push(ch);
        }

        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        else if (ch != ' ')
        {
            while (!st.empty() && precedence(st.top()) >= precedence(ch))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string tests[] = {
        "3+5",
        "3+5*2",
        "(3+5)*2",
        "3+5*2-8/4",
        "a+b*c",
        "12+34*5"
    };

    for (int i = 0; i < 6; i++)
    {
        cout << "Infix:   " << tests[i] << endl;
        cout << "Postfix: " << infixToPostfix(tests[i]) << endl;
        cout << endl;
    }

    return 0;
}