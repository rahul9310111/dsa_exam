#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int data)
    {
        this->data = data;
        right = nullptr;
        left = nullptr;
    }
};

node *entry(node *root)
{
    cout << "enter the value of data :";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "Enter data for left node of " << data << ": ";
    root->left = entry(root->left);
    cout << "Enter data for right node of " << data << ": ";
    root->right = entry(root->right);
    return root;
}

int no(node * root , int &cnt){

    //base condition
    if(root == nullptr){
        return cnt;
    }

    int left = no(root->left , cnt);
    int right = no(root->right , cnt);

    if(root->left == nullptr && root->right == nullptr){
        cnt = cnt+1;
    }

    return cnt;
}

int height(node * root){
    //base condition 
    if(root == nullptr){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) +1;

}

int diameter(node * root){
    
    //base condition
    if(root == nullptr){
        return 0;
    }

    int l = diameter(root->left);
    int r = diameter(root->right);
    int h = height(root->left) + height(root->right) +1;

    return max(l , max(r,h));
}

// class Solution {
// public:
//     // Function to check if two trees are identical.
//     bool isIdentical(Node *r1, Node *r2) {
//         // Base condition
//         if (r1 == nullptr && r2 == nullptr) {
//             return true;
//         }

//         if (r1 == nullptr || r2 == nullptr) {
//             return false;
//         }

//         // Check if the current nodes have the same value, and recursively check their left and right subtrees.
//         return (r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
//     }
// };

int main()
{
    node *root = nullptr;
    root = entry(root);
    // int cnt = 0;
    // cnt = no(root,cnt);
   
    // cout<<cnt<<endl;

   // int hght = height(root);

    //cout<<hght;

    cout<<diameter(root);
    

    return 0;
}