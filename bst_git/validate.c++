#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node *creation(node *&root, int data)
{
    if (root == nullptr)
    {
        root = new node(data);
        return root;
    }

    if (root->data < data)
    {
        root->right = creation(root->right, data);
    }
    else
    {
        root->left = creation(root->left, data);
    }
    return root;
}

void generator(node *&root)
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    cout << endl;
    while (data != -1)
    {
        root = creation(root, data);
        cout << "Enter data: ";
        cin >> data;
        cout << endl;
    }
}

void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool validate(node *root) {
    if (root == nullptr) {
        return true;
    }

    // Check the left subtree
    if (root->left != nullptr && root->data < root->left->data) {
        return false;
    }

    // Check the right subtree
    if (root->right != nullptr && root->data >= root->right->data) {
        return false;
    }

    // Recursively check children nodes
    return (validate(root->left) && validate(root->right));
}


int main()
{
    node *root = nullptr;
    generator(root);
    inorder(root);
    cout<<validate(root);

    return 0;
}
