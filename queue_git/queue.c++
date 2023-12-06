#include<bits/stdc++.h>
using namespace std;

class queue{
    int * arr;
    int front;
    int rear;
    int cap;
    public:

    queue(int cap){
        this->cap = cap;
        front = -1;
        rear = -1 ;
        arr = new int[cap];
    }

    void enque(int value){
        if(front == -1){
            front++;
            rear++;
            arr[rear] = value;
            return;
        }
        else if(rear == cap -1){
            cout<<"queue is full "<<endl;
            return ;
        }

        rear++;
        arr[rear] = value;
    }

    void deque(){
        if(front == -1 || front > rear){
            return ;
        }
        front++;
    }

    int top(){
        return front;
    }

    bool isEmpty(){
        return front == -1;
    }


};

int main() {
    
    return 0;
}