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
void delete_head(node*&head){
    node* temp=head;
    while(temp->next!= head){
        temp=temp->next;
    }
    node* todelete = head;
    temp->next=head->next;
    head=head->next;

    delete todelete;


}
void Deletion(node*& head,int position){
    node* temp = head;
    if(position ==1){
        delete_head(head);
        return ;
    }
    int count  = 1 ;
    while (count != position-1){
        temp= temp->next;
        count++;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
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
    Deletion(head,5);
    display(head);
}