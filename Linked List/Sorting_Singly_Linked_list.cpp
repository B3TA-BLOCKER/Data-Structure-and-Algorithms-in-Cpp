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

void Add(node *&head, int data)
{
    node *new_node = new node(data);

    new_node->next = head;
    head = new_node;
}

void display(node *head)
{
    node *temp = head;
    cout << endl
         << "[NULL] -> ";
    while (temp->next != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "[NULL]";
}

void Sorting(node *&head)
{
    int temp;
    int count = 0;
    node *temp_head = head;
    node *temp_ = head;

    while (temp_head->next != NULL)
    {
        temp_ = head;
        while (temp_->next != NULL)
        {
            if (temp_->data > temp_->next->data)
            {
                temp = temp_->data;
                temp_->data = temp_->next->data;
                temp_->next->data = temp;
            }
            temp_ = temp_->next;
        }
        temp_head = temp_head->next;
    }
}

int main(void)
{
    node *head = NULL;

    Add(head, 60);
    Add(head, 6);
    Add(head, 17);
    Add(head, 7);
    Add(head, 27);
    Add(head, 16);
    Add(head, 4);

    display(head);
    Sorting(head);
    display(head);
}
