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

    void insertion(node * & head , node * & tail , int data, int pos){

        node * temp = new node(data);
        node * curr = head;
        int cnt = 1 ;

        //for pos = 1;
        if(pos == 1){
            temp->next = head;
            head = temp;
            return;
        }
        else{
            while(cnt < pos -1){
                curr = curr->next;
                cnt++;
            }
            if(curr->next == nullptr){
                tail->next = temp;
                tail = temp;
                return;
            }

            temp->next = curr->next;
            curr->next = temp;

        }


    }

    void deletion(node *&head, node *&tail, int pos){
        node * prev = nullptr;
        node * curr = head;
        int cnt = 1;
        

        //pos == 1
        if(pos == 1){
            head = head->next;
            delete curr;
            return;
        }
        else{
            while(cnt<pos){
                prev = curr;
                curr = curr->next;
                cnt++;
            }

            if(curr->next == nullptr){
                prev->next = nullptr;
                tail = prev;
                return;
            }
            prev->next = curr->next;
            delete curr;
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
    linking(head, tail, 96);
    linking(head, tail, 14);

    deletion(head,tail,2);

    cout << head->data << " " << tail->data << endl;


    display(head);


   
    
    return 0;
}