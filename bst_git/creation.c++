#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node * bst_maker(node * &root , int data){
    //base condition
    if(root == nullptr){
        root = new node(data);
        return root;
    }

    if(root->data < data){
       root->right =  bst_maker(root->right, data);
    }
    else{
        root->left = bst_maker(root->left , data);
    }
    return root;
}

void creation(node * &root){
    int data ;
    cin>>data;
    while(data != -1){
        root = bst_maker(root, data);
        cout<<" ";
        cin>>data;
    }
}

void inorder(node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(node * root , int d){

    //base condtion
    if(root == nullptr){
        return false;
    }
    if(root->data == d){
        return true;
    }

    if(root->data < d){
        return search(root->right , d);
    }
    else{
        return search(root->left, d);
    }

     
}

int min(node * root ){
    node * temp = root;
    while(temp->left != nullptr){
        temp = temp->left;
    }

    return temp->data;
}

node * deletion(node * root , int data){

    //base condtion
    if(root == nullptr){
        return nullptr;
    }

    if(root->data == data){
        //0 child present
        if(root->left == nullptr && root->right == nullptr){
            
            return nullptr;
        }

        //1 child
        //right child
        if(root->left == nullptr && root->right != nullptr){
            node * temp = root->right;
            delete root;
            return temp;
        }
        //left child
        if(root->left != nullptr && root->right == nullptr){
            node * temp = root->left;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != nullptr && root->right != nullptr){
            int mini = min(root->right);
            root->data = mini;
            root->right = deletion(root->right , mini);
            return root;
            
        }
    }

    if(root->data < data){
        root->right = deletion(root->right, data);
        return root;
    }
    else{
        root->left = deletion(root->left , data);
        return root;
    }
}



int main() {
    node * root = nullptr;
    creation(root);
    inorder(root);
    cout<<search(root, 7);
    cout<<endl;
    deletion(root,5);
    inorder(root);
    return 0;
}