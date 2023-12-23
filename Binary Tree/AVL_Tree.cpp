#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void pre_order(struct node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void inorder(struct node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void post_order(struct node *root)
{
    if (root == nullptr)
    {
        return;
    }

    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}

bool Is_Balanced(node *root){
    
}

int main(void)
{
    node *root = new node(10);
    root->left = new node(6);
    root->right = new node(12);
    root->left->left = new node(5);
    root->left->right = new node(7);
    root->right->left = new node(11);
    root->right->right = new node(15);

    cout << endl
         << "Preorder Traversals of the Tree " << endl;
    pre_order(root);
    cout << endl
         << "Inodrder Traversals of the Tree " << endl;
    inorder(root);
    cout << endl
         << "Post order Traversals of the Tree " << endl;
    post_order(root);
}