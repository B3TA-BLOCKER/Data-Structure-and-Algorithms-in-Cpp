#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void Insert_at_head(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void Insert_at_the_tail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void Display(node *head)
{
    node *temp = head;
    cout << endl
         << "This is your Linkedlist : " << endl;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}
void Delete_node(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        node *to_delete = head;
        head = head->next;

        delete to_delete;

        return;
    }
    node *temp = head;
    if (temp->data == val)
    {
        node *to_delete = temp;
        head = temp->next;

        delete to_delete;
        return;
    }
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *to_delete = temp->next;
    temp->next = temp->next->next;

    delete to_delete;
}
// searching in a Linked List
bool Search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main(void)
{
    node *head = NULL;
    Insert_at_the_tail(head, 3);
    Insert_at_the_tail(head, 5);
    Insert_at_the_tail(head, 10);

    Insert_at_head(head, 15);
    Display(head);
    // cout<<Search(head,15);
    cout << endl
         << "After Deletion : ";
    Delete_node(head, 15);
    Display(head);
}