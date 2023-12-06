#include<iostream>
using namespace std;

class node{
    public:
    int data ;
    node *next;

    node(int data){
        this->data = data;
        next = nullptr;
    } 

};

    void linking(node * & head , node * & tail , int data){
        node * temp = new node(data);

        if(head == nullptr && tail == nullptr){
            head = temp ;
            tail = temp ;
        } 

        tail->next = temp ;
        tail = tail->next ;
    }

  void duplicate(node * & head){
    node * temp =  head;
    
    while(temp != NULL){
        if(temp->next !=NULL  &&  temp->data == temp->next->data ){
            node* duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        }
        else{
            temp= temp->next;
        }
    }
    
}

   void display(node * head){
        node * temp =  head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }


int main() {

    node * head = nullptr;
    node * tail = head;
     linking(head, tail, 34);
    linking(head, tail, 57);
    linking(head, tail, 57);
    linking(head, tail, 14);

    duplicate(head);

    display(head);

   


   
    
    return 0;
}