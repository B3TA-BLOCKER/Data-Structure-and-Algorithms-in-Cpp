#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void insert_at_head(node *&head, int data)
{
    node *n = new node(data);
    node *temp = head;

    if (head == NULL)
    {
        n->next = n;
        head = n;

        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void insert_at_tail(node *&head, int data)
{
    node *n = new node(data);
    node *temp = head;

    if (head == NULL)
    {
        insert_at_head(head, data);
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void display(node *head)
{
    node *temp = head;
    cout << endl
         << "[NULL] -> ";
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "[NULL]";
}
int main(void)
{

    node *head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    display(head);
}