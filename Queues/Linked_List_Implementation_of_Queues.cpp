#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int data){
            this->data=data;
            next= NULL;
        }
};

class Queue{
    node *front ;
    node *back;

    public:
        Queue(){
            front =NULL;
            back=NULL;
        }

        void push(int x){
            node * new_node = new node(x);
            if(front==NULL){
                back=new_node;
                front = new_node;

                return;
            }
            back->next = new_node;
            back=new_node;
        }

        void pop(){
            if(front ==NULL){
                cout<<"Queue under Flow !!"<<endl;
                return ;
            }
            node *to_delete = front ;
            front = front->next;
            delete to_delete;
        }

        int peek(){
            if(front == NULL){
                cout<<"Queue is empty !!"<<endl;
                return -1;
            }return front->data;
        }

        bool empty(){
            if(front == NULL ){
                return true;
            }return false;
        }
};

int main(void){

    Queue q;

    int limit;

    cout<<"How many Elements you want to Insert in the Queue"<<endl<<"-> ";
    cin>>limit;

    cout<<endl<<"Enter the Elements "<<endl;
    for(int i=0;i<limit;i++){
        int element;
        cout<<"-> ";
        cin>>element;
        q.push(element);
    }

    cout<<endl<<"The First Element in the Queue is : "<<q.peek()<<endl;

    cout<<endl<<"The Complete Queue is "<<endl;
    while(!q.empty()){
        cout<<"~> "<<q.peek()<<endl;
        q.pop();
    }


}