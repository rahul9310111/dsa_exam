#include <iostream>
#include <string>
using namespace std;

class stack
{
    char *arr;
    int cap;
    int top;

public:
    stack(int cap)
    {
        this->cap = cap;
        this->top = -1;
        arr = new char[cap];
    }

    void push(char data)
    {
        if (this->top == this->cap - 1)
        {
            cout << "overflow" << endl;
            return;
        }
        this->top++;
        this->arr[top] = data;
    }

    char pop()
    {
        if (this->top == -1)
        {
            return -1;
        }
        char poppedelement = arr[top];
        top--;

        return poppedelement;
    }

    int gettop()
    {
        if (this->top == -1)
        {
            cout << " stack is empty " << endl;
            return -1;
        }

        return arr[top];
    }

    bool isEmpty()
    {
        if (this->top == -1)
        {
            return true;
        }
        return false;
    }
};

bool isBalanced(string str, stack st)
{
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }

        // opening bracket chalegi
        else
        {
            if (!str.empty())
            {
                int top = st.gettop();
                if (top == '[' && ch == ']' ||
                    top == '{' && ch == '}' ||
                    top == '(' && ch == ')')
                {
                    st.pop();
                }
            }
        }
    }

    if (st.isEmpty())
    {
        cout << "balanced ";
        return true;
    }
    else
    {
        cout << "unbalanced ";
        return false;
    }
}

int main()
{
    string str = "(()";
    int size = str.length();
    stack st(size);

    cout << isBalanced(str, st);

    return 0;
}