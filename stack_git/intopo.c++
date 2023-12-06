#include<bits/stdc++.h>

using namespace std;


int precendence(char ch){
    if(ch == '/' || ch == '*'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return -1;
    }
}


string intopo(string str , stack<char> st){
    string ans;
    reverse(str.begin(), str.end());

    for(int i = 0; i < str.length() ; i++){
        char ch = str[i];

        //if ch is operand
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ){
            ans += ch;
        }

        //if ch is closing bracket
        else if(ch == ')'){
            st.push(ch);
        }

        //if ch is opening braket
        else if(ch == '('){
            while(!st.empty() && st.top() != ')'){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()){

            st.pop();
            }
        }

        //if ch is operator
        else{

            while(!st.empty() && precendence(st.top()) >= precendence(ch)){
                ans += st.top();
                st.pop();

            }
            st.push(ch);

        }

        
    }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

         reverse(ans.begin() , ans.end());
         return ans;
}

int main() {
    stack<char > st;
    string str = "(a+b)*d";

    cout<<intopo(str,st);
    
    return 0;
}