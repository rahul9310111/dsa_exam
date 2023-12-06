#include<iostream>
using namespace std;

class queue{
    int * arr;
    int front ; 
    int  rear;
    int cap ;
    public:
    queue(int cap ){
        this->cap = cap ;
        front = -1 ; 
        rear = -1 ;
        arr = new int[cap];
    }

    void push(int data){
        if((rear+1)%cap == front){
            cout<<" full "<<endl;
            return ;
        }
        else if( front == -1){
            front = 0 ; 
            rear = 0; 
            arr[front] = data;
            return;
        }
        rear = (rear+1)%cap;
        arr[rear] = data;
    }

    void pop(){
        if(front == -1){
            return;
        }

        front = (front+ 1)% cap;
    }

    bool is_empty(){
        return front == -1;
    }

    int get_top(){
        return arr[front];
    }
};

int main() {
    queue q1(5);
    

    int i =0 ;
    while(i < 5){
        cout<<q1.get_top()<<" ";
        q1.pop();
        i++;
    }
    
    return 0;
}