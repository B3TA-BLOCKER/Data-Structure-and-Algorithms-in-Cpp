// This Linked List is Reversed through Recursion

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
     cout<<"{NULL} -> ";
    while (temp != NULL)
    {
        cout << temp->data;
        cout<<" -> ";
        temp = temp->next;
    }
    cout<<"{NULL}";
    cout << endl;
}
node* recursive_reverse (node* &head){

    if(head==NULL || head->next==NULL){
        return head;
    }
   node* new_Head = recursive_reverse(head->next);
   head->next->next=head;
   head->next=NULL;

   return new_Head;

}
int main(void)
{
    node *head = NULL;
    Insert_at_the_tail(head, 3);
    Insert_at_the_tail(head, 5);
    Insert_at_the_tail(head, 10);

    Insert_at_head(head, 15);

    cout<<"The Actual Linked List : "<<endl;
    Display(head);

    node* new_Head = recursive_reverse(head);
    cout<<endl<<"After Recursively Reversing the list : "<<endl;
    Display(new_Head);
    
}