/*
    Write a C++ program to implement a singly linked list using object-oriented programming concepts.
    Your program should support the following operations:

        •Insert a node at the beginning of the list.
        •Insert a node at the end of the list.
        •Delete a node from the beginning of the list.
        •Delete a node from the end of the list.
        •Display the elements of the linked list.

    Additionally, provide a menu-driven interface to allow the user to perform these operations.
    
*/

#include <iostream>
#include <unistd.h>
using namespace std;

class Linked_List
{
public:
    int data;
    Linked_List *next;

    Linked_List(int a)
    {
        data = a;
        next = NULL;
    }
};
void Insert_at_Head(Linked_List *&head, int val)
{
    Linked_List *node = new Linked_List(val);
    node->next = head;
    head = node;
}
void Insert_at_Tail(Linked_List *&head, int val)
{
    Linked_List *node = new Linked_List(val);

    if (head == NULL)
    {
        head = node;
        return;
    }
    Linked_List *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}
void Delete_at_Head(Linked_List *&head)
{
    if (head == NULL)
    {
        return;
    }
    Linked_List *to_delete = head;
    head = head->next;

    delete to_delete;
}
void Delete_at_Tail(Linked_List *&head)
{
    Linked_List *temp = head;
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        delete head;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete (temp->next);

    temp->next = NULL;
}
void Display(Linked_List *head)
{
    Linked_List *temp = head;
    cout << "\t\t\t\t\t   ";
    while (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(void)
{
    Linked_List *head = NULL;
    int choice, val;

    do
    {
    again:
    system("CLS");
        cout << "\t\t\t\t\t\t............. MENU ............. " << endl
             << endl;
        cout << "\t\t\t\t\t1.} Insert a node at the beginning of the list." << endl;
        cout << "\t\t\t\t\t2.} Insert a node at the end of the list." << endl;
        cout << "\t\t\t\t\t3.} Delete a node from the beginning of the list." << endl;
        cout << "\t\t\t\t\t4.} Delete a node from the end of the list." << endl;
        cout << "\t\t\t\t\t5.} Display the elements of the linked list." << endl;
        cout << "\t\t\t\t\t6.} Exit." << endl
             << endl;

        cout << "\t\t\t\t\t   Enter your Choice (1-6) : " << endl
             << "\t\t\t\t\t     -> ";
        cin >> choice;

        cout << endl
             << endl
             << endl
             << endl;
        switch (choice)
        {
        case 1:
        {
            cout << "\t\t\t\t     Enter the value to Insert at the beginning of the list." << endl
                 << "\t\t\t\t\t-> ";
            cin >> val;
            Insert_at_Head(head, val);
        }
        break;
        case 2:
        {
            cout << "\t\t\t\t     Enter the value to Insert at the end of the list." << endl
                 << "\t\t\t\t\t-> ";
            cin >> val;
            Insert_at_Tail(head, val);
        }
        break;
        case 3:
        {
            cout << "\t\t\t\t     Deleteting a node from the beginning of the list.";
            Delete_at_Head(head);
            for (int i = 0; i < 4; i++)
            {
                cout << " . ";
                sleep(1);
            }
            cout<<endl;
        }
        break;
        case 4:
        {
            cout << "\t\t\t\t      Deleteting a node from the end of the list.";
            Delete_at_Tail(head);
            for (int i = 0; i < 4; i++)
            {
                cout << " . ";
                sleep(1);
            }
            cout<<endl;
        }
        break;
        case 5:
        {
            cout << "\t\t\t\t     Displaying the elements of the linked list.";
            for (int i = 0; i < 4; i++)
            {
                cout << " . ";
                sleep(1);
            }
            cout<<endl;
            Display(head);
            sleep(10);
        }
        break;
        case 6:
        {
            cout << "\t\t\t\t\t   Exiting the program.";
            for (int i = 0; i < 4; i++)
            {
                cout << " . ";
                sleep(1);
            }
            cout<<endl;
        }
        break;
        default:
        {
            cout << "\t\t\t\t\t   Wrong Entry ";
            cout << endl
                 << endl
                 << "\t\t\t\t     Redirecting ";
            for (int i = 0; i < 4; i++)
            {
                cout << " . ";
                sleep(1);
            }
            goto again;
        }
        }
    } while (choice != 6);
}