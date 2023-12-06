#include<iostream>
using namespace std;

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

    stack s(9);
    s.push(5);
    s.push(2);
    s.push(7);
    s.push(16);
    s.push(1);
    s.push(21);
    s.push(135);
    

    stack temp(100);


    while(!s.is_empty()){
        int t = s.get_top();

        s.pop();
        if(temp.get_top() != -1){
            while(!temp.is_empty() && temp.get_top() > t){
                s.push(temp.get_top());
                temp.pop();
            }
            temp.push(t);
        }
        else{
            temp.push(t);
        }
    }

    temp.print();

    
    return 0;
}