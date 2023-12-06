#include<iostream>
using namespace std;


// implementing stack using dynamic array 


class stack{
    int * arr;
    int cap; 
    int top;
    public:

    stack(int cap){
        this->cap = cap;
        top = -1;
        arr = new int[cap];
    }

    void push(int value){
        if(top == cap -1){
            cout<<"stack is full "<<endl;
            return ;
        }
        top++;
        arr[top] = value;
    }

    void pop(){
        if(top == -1){
            return ;
        }

        top--;
    }

    bool is_empty(){
        return top ==-1;
    }

    int get_top(){
        if(top ==-1){
            return -1;
        }
        return arr[top];
    }

    void print(){
        int i = 0 ; 

        if(top == -1){
            cout<<"empty hai bhai ";
           return  ;
        }
        while(i <= top){
            cout<<arr[i]<<" ";
            i++;
        }
        cout<<endl;
}

};

int main() {
    cout<<"enter cap "<<endl;
    int cap = 4;

    stack s(cap);

    int i = 0;
    while(i < cap){
        int b ;
        cout<<"enter value "<<endl;
        cin>>b;
        s.push(b);
        i++;

    }

    s.print();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.print();
    
    return 0;
}