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
    while (temp_head->next != NULL)
    {
        ++count;
        temp_head = temp_head->next;
    }

    temp_head = head;
    for (int i = 0; i < count; i++)
    {
        temp_head = head;
        for (int j = 0; j < count - 1; j++)
        {
            if (temp_head->data > temp_head->next->data)
            {
                temp = temp_head->data;
                temp_head->data = temp_head->next->data;
                temp_head->next->data = temp;
            }
            temp_head = temp_head->next;
        }
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