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

  

    void display(node * head){
        node * temp =  head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }


    node * merge(node * & head1 , node * & head2,node * & head3,node * & tail3){
        node * curr1 = head1 ;
         node * curr2 = head2;
         

        while(curr1 != nullptr && curr2 != nullptr){
            if(curr1->data <= curr2->data){
                   linking(head3,tail3,curr1->data);
                    curr1 = curr1->next;
            }
            else if(curr1->data > curr2->data){
               linking(head3,tail3,curr2->data);
                    curr2 = curr2->next;
            }
        }

        while(curr1 != nullptr){
            linking(head3,tail3,curr1->data);
                    curr1 = curr1->next;
        }

        while(curr2 != nullptr){
            linking(head3,tail3,curr2->data);
                    curr2 = curr2->next;
        }
        

        return head3;

    }

    
int main() {

    node * head1 = nullptr;
    node * tail1 = head1;
     linking(head1, tail1, 34);
    linking(head1, tail1, 45);
    linking(head1, tail1, 55);
    linking(head1, tail1, 65);


    node * head2 = nullptr;
    node * tail2 = head2;
     linking(head2, tail2, 37);
    linking(head2, tail2, 57);
    linking(head2, tail2, 91);

     node * head3 = nullptr;
         node * tail3 = head3;
   

    head3 = merge(head1,head2,head3,tail3);

    display(head3);

   


    


   
    
    return 0;
}