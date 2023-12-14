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
    cout << "This is your Linkedlist : " << endl;
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
node* reverse_K(node* &head, int k){
    node* prev_ptr=NULL;
    node* current_ptr = head;
    node* next_ptr;

    int count=0;
    while(current_ptr!=NULL && count<k){
        next_ptr=current_ptr->next;
        current_ptr->next=prev_ptr;
        prev_ptr=current_ptr;
        current_ptr=next_ptr;
        count++;
    }

    if(next_ptr!=NULL){
        head->next = reverse_K(next_ptr,k);
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
    cout<<"Before Reversing the Linked List "<<endl;
    Display(head);
    cout<<endl<<"After reversing 'K' node in the list : "<<endl;
    int k=2;
    node* new_head= reverse_K(head,k);
    Display(new_head);
}