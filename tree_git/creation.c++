#include <iostream>
#include <queue>
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

void display(node *root)
{
    queue<node *> q1;
    q1.push(root);
    q1.push(nullptr);

    while (!q1.empty())
    {

        node *temp = q1.front();

        q1.pop();
        if (temp == nullptr)
        {
            cout << endl;
            if (!q1.empty())
            {
                q1.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != nullptr)
            {
                q1.push(temp->left);
            }

            if (temp->right != nullptr)
            {
                q1.push(temp->right);
            }
        }
    }
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
    root = entry(root);
    cout << "printing the data" << endl;
    display(root);
    cout<<endl;
    cout<<validate(root);
    return 0;
}

// Online C++ compiler to run C++ program online
