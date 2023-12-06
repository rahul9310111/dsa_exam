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
        this->next = nullptr;
    }
};

void linkingattail(int data, node *&tail, node* & head)
{
    node *temp = new node(data);
    if (tail == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
}

node * middl(node * & head){
    node * fast = head;
    node * slow = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node * reverse(node * & head){
    node * curr = head; 
    node * prev = nullptr;
    node * forward = nullptr;
    while(curr != nullptr){
        forward = curr->next ;
        curr->next = prev;
        prev = curr ;
        curr = forward;
    }
    return prev;
}



bool pallindrom(node * & head){
    node * curr = head;
    node * mid = middl(head);
    node * last = reverse(mid->next);
    while(last != nullptr){
        if(curr->data != last->data){
            return false;
        }
        last = last->next;
        curr = curr->next;
    }
}

void display(node *&head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    node *head = nullptr;
    node *tail = nullptr;
    linkingattail(56, tail, head);
    linkingattail(85, tail, head);
    linkingattail(15, tail, head);
    linkingattail(15, tail, head);
    linkingattail(85, tail, head);
    linkingattail(56, tail, head);

   
    
    if(pallindrom(head) == true){
        cout<<"it is pallindrome"<<endl;
    }
    else{
        cout<<"it is not pallindrome"<<endl;
    }
     

    return 0;
}