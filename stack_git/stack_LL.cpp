#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class stack
{
    node *head;

public:
    stack()
    {
        head = nullptr;
    }

    void push(int data)
     {   node *temp = new node(data);
     
        temp->next = head;
        head = temp;
    }

    int pop()
    {
        if (head == nullptr)
        {
            cout << " stack is underflow" << endl;
            return -1;
        }
        int popped_data = head->data;
        node *prev_head = head;
        head = head->next;
        delete prev_head;
        return popped_data;
    }

    int top()
    {
        if (head == nullptr)
        {
            cout << "stack is empty " << endl;
            return -1;
        }
        return head->data;
    }

    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    stack s1;
    s1.push(56);
    s1.push(556);
    s1.push(567);

    cout << s1.pop() << endl;
    cout << s1.isEmpty() << endl;

    return 0;
}