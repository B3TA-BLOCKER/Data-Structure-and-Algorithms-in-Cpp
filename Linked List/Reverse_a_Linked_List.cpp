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
node* reverse (node* &head){
    node* prev_ptr = NULL;
    node* current = head;
    node* nextptr;

    while (current!=NULL){
        nextptr=current->next;
        current->next=prev_ptr;

        prev_ptr=current;
        current=nextptr;
    }

    return prev_ptr;
}
int main(void)
{
    node *head = NULL;
    Insert_at_the_tail(head, 3);
    Insert_at_the_tail(head, 5);
    Insert_at_the_tail(head, 10);

    Insert_at_head(head, 15);
    Display(head);

    node *newhead = reverse(head);
    cout<<endl<<"After reversing the list : "<<endl;
    Display(newhead);

}