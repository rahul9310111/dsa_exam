#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * forward;
    node * backward;

     node(int data)
    {
        this->data = data;
        forward = nullptr;
        backward = nullptr;
    }
};

void linking(node * & head, node * & tail , int data){
    node * temp = new node(data);
    if(head == nullptr && tail == nullptr){
        head = temp ;
        tail = temp;
    }
    tail->forward = temp;
    temp->backward = tail;
    tail = tail->forward;
}

void insertion(node *&head, node *&tail, int data, int pos){
    node * temp = new node(data);
    node * curr = head;
    int cnt  = 1 ;

    if(pos == 1){
        temp->forward = head;
        head->backward = temp;
        head = head->backward;
        return ;
    }
    else{
        while(cnt<pos-1){
            curr = curr->forward;
            cnt++;

        }
        if(curr->forward == nullptr){
            tail->forward = temp;
            temp->backward = tail;
            tail = tail ->forward;
            return ;
        }

        temp->forward = curr->forward;
        curr->forward->backward = temp;
        curr->forward = temp;
        temp->backward = curr;
    }
}

int main() {
    
    return 0;
}