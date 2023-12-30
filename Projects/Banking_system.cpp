#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Structure for Customer information
struct user
{
    int account_number;
    string user_name;
    string user_address;
    string phone_number;
};

// Node structure for the Linked list
struct node
{
    user user_data;
    node *next;
};

// Linked list class for managing user information
class user_list
{
private:
    node *head;

public:
    user_list()
    {
        head = NULL;
    }

    void add_user(user &new_user)
    {
        node *newnode = new node{new_user, head};
        head = newnode;
    }

    // Displaying all the customers in the linked list
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << "Account Number : " << temp->user_data.account_number << endl;
            cout << "Name : " << temp->user_data.user_name << endl;
            cout << "Address : " << temp->user_data.user_address << endl;
            cout << "Contact Info : " << temp->user_data.phone_number << endl;
            temp = temp->next;
            cout << endl;
        }
    }
};

// Hash table class for efficent data management of the uers
class hashed
{
private:
    unordered_map<int, user> user_data_map;

public:
    // Adding new user to the hash table
    void adduser(user &new_user)
    {
        user_data_map[new_user.account_number] = new_user;
    }

    // Retriving user data by account number
    user get_user(int account_number)
    {
        return user_data_map[account_number];
    }
};

// BST class for efficent account verification

class account_verification
{
private:
    struct tree_node
    {
        int accountNumber;
        tree_node *left;
        tree_node *right;
    };

    tree_node *root;

    // Inserting an account in the BST
    tree_node *insert(tree_node *node, int account_number)
    {
        if (node == nullptr)
        {
            node = new tree_node{account_number, nullptr, nullptr};
        }
        else if (account_number < node->accountNumber)
        {
            node->left = insert(node->left, account_number);
        }
        else if (account_number > node->accountNumber)
        {
            node->right = insert(node->right, account_number);
        }
        return node;
    }

public:
    account_verification()
    {
        root = NULL;
    }
    void add_account(int account_number)
    {
        root = insert(root, account_number);
    }

    bool verification(int account_number)
    {
        tree_node *temp = root;
        while (temp != NULL)
        {
            if (account_number == temp->accountNumber)
            {
                return true;
            }
            else if (account_number < temp->accountNumber)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return false;
    }
};

int main(void)
{
    system("cls");
    user_list userlist;
    hashed account_hash;
    account_verification account;

    // Adding users
    user user1{101, "Ali", "Pashawar DHA Phase#2", "12345678910"};
    user user2{102, "Ahmad", "Karachi Gulshan-e-Iqbal Black B", "97598307897"};

    // Adding users to the linkedlist
    userlist.add_user(user1);
    userlist.add_user(user2);

    // Adding the user in the hash table
    account_hash.adduser(user1);
    account_hash.adduser(user2);

    // Adding account numbers to the BST
    account.add_account(user1.account_number);
    account.add_account(user2.account_number);

    // Displaying user detaiLs
    cout << "User Info (Linked_List)" << endl;
    userlist.display();

    // Verifying accoun t number
    int to_verify = 101;
    if (account.verification(to_verify))
    {
        user verified_user = account_hash.get_user(to_verify);
        cout << "Verified Customer Information:" << endl;
        cout << "Name: " << verified_user.user_name << endl;
        cout << "Address: " << verified_user.user_address << endl;
        cout << "Contact Info: " << verified_user.phone_number << endl;
    }
    else
    {
        cout << "Account : " << to_verify << " Not FOUND !! " << endl;
    }
}
