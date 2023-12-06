#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *nxt;

    node(int data)
    {
        this->data = data;
        this->nxt = NULL;
    }
};

class que
{
    node *top;

public:
    que()
    {
        this->top = nullptr;
    }

    void push(int data)
    {
        node *temp = new node(data);
        if (isEmpty())
        {
            top = temp;
            return;
        }
        else
        {
            node *curr = top;
            while (curr->nxt != nullptr)
            {
                curr = curr->nxt;
            }
            curr->nxt = temp;
        }
    }

    int pop()
    {

        if (top == nullptr)
        {
            cout << "que is empty" << endl;
            return -1;
        }
        else
        {
            node *temp = top;
            int popped = temp->data;
            top = top->nxt;
            delete temp;
            return popped;
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    int get_top()
    {
        return top->data;
    }

    void display()
    {
        node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->nxt;
        }
    }
};

int main()
{
    que q1;
    q1.push(78);
    q1.push(45);
    q1.push(56);

    // cout<<q1.pop()<<endl;

    q1.display();

    cout << q1.get_top();

    return 0;
}