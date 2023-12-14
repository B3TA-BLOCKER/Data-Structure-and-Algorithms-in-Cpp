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

void Add_at_tail(node *&head, int data)
{
    node *new_node = new node(data);
    node *temp = head;
    if (head == NULL)
    {
        head = new_node;
        new_node->next = NULL;

        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
}
node *Merge(node *&head1, node *&head2)
{

    node *ptr_1 = head1;
    node *ptr_2 = head2;
    node *dummy_node = new node(-1);
    node *ptr3 = dummy_node;

    while (ptr_1 != NULL && ptr_2 != NULL)
    {
        if (ptr_1->data < ptr_2->data)
        {
            ptr3->next = ptr_1;
            ptr_1 = ptr_1->next;
        }
        else
        {
            ptr3->next = ptr_2;
            ptr_2 = ptr_2->next;
        }
        ptr3 = ptr3->next;
    }

    while (ptr_1 != NULL)
    {
        ptr3->next = ptr_1;
        ptr_1 = ptr_1->next;
        ptr3 = ptr3->next;
    }

    while (ptr_2 != NULL)
    {
        ptr3->next = ptr_2;
        ptr_2 = ptr_2->next;
        ptr3 = ptr3->next;
    }

    return dummy_node->next;
}
void Display(node *head)
{
    node *temp = head;
    cout << "{NULL} ==> ";
    while (temp != NULL)
    {
        cout << temp->data << " ==> ";
        temp = temp->next;
    }
    cout << "{NULL}";
}

int main(void)
{
    node *head_1 = NULL;
    node *head_2 = NULL;

    Add_at_tail(head_1, 2);
    Add_at_tail(head_1, 3);
    Add_at_tail(head_1, 5);
    Add_at_tail(head_1, 9);
    Display(head_1);

    cout << endl;

    Add_at_tail(head_2, 1);
    Add_at_tail(head_2, 4);
    Add_at_tail(head_2, 7);
    Add_at_tail(head_2, 8);
    Display(head_2);

    cout << endl
         << "After Merging Both the Lists " << endl;
    node *newhead = Merge(head_1, head_2);
    Display(newhead);
}