#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Binary_Tree
{
private:
    node *root;

    node *Insert(node *Node, int data)
    {
        if (Node == NULL)
        {
            return new node(data);
        }

        if (data < Node->data)
        {
            Node->left = Insert(Node->left, data);
        }
        else if (data > Node->data)
        {
            Node->right = Insert(Node->right, data);
        }

        return Node;
    }

    void inorder(node *Node)
    {
        if (Node == NULL)
        {
            return;
        }
        inorder(Node->left);
        cout << Node->data << " ";
        inorder(Node->right);
    }

public:
    Binary_Tree()
    {
        root = NULL;
    }

    void insert_node(int data)
    {
        root = Insert(root, data);
    }

    void Print_Tree()
    {
        inorder(root);
        cout << endl;
    }
};

int main(void)
{
    Binary_Tree tree;

    int num, node;

    cout << "Enter How Many Number You Want To Enter : " << endl
         << " -> ";
    cin >> num;

    cout << endl
         << "Enter The Numbers" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> node;
        tree.insert_node(node);
    }

    cout << endl
         << "This Is The Tree Formed " << endl;
    tree.Print_Tree();
}