// Deletion in a Doubly Linked List

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
void insert_at_head(node *&head, int data)
{
    node *newnode = new node(data);
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
}

void Insert_at_tail(node *&head, int data)
{

    if (head == NULL)
    {
        insert_at_head(head, data);
        return ; 
    }
    node *newnode = new node(data);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}

void Display(node *head)
{
    node *temp = head;

    cout << endl;
    cout << "{NULL} <==> ";
    while (temp != NULL)
    {
        cout << temp->data << " <==> ";
        temp = temp->next;
    }
    cout << "{NULL}  "<<endl;
}
void delete_at_head(node*&head){
    node * todelete = head;
    head = head->next;
    head->prev=NULL;

    delete todelete;
}
void Deletion(node*& head,int position){
    if(position==1){
        delete_at_head(head);
    }
    node* temp= head;
    int count = 1;

    while (temp->next != NULL && count!=position){
        temp=temp->next;
        count++;
    }

    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }

    delete temp;

}
int main(void)
{
    node *head = NULL;

    Insert_at_tail(head, 1);
    Insert_at_tail(head, 2);
    Insert_at_tail(head, 3);
    Insert_at_tail(head, 4);
    insert_at_head(head, 5);
    Display(head);
    Deletion(head,5);
    Display(head);
}