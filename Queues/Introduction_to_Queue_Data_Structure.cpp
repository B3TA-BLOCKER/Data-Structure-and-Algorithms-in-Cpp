/*
    Store the list of items in which an otem can be inserted at one end and remoed from the other end only
*/


#include<iostream>
using namespace std;

#define n 20

class queue{
    int * arr;
    int front, back;

    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x){
        if(back==n-1){
            cout<<"Queue Overflow"<<endl;

            return;
        }
        back++;
        arr[back] = x;

        if(front =-1){
            front ++;
        }
    }

    void pop(){
        if(front==-1 || front >back){
            cout<<"No Element in the Queue "<<endl;
        }

        front ++;
    }

    int peek(){
        if(front == -1 || front > back){
            cout<<"No element in the Queue"<<endl;
            return -1;
        }

        return arr[front];
    }

    bool empty(){
        if(front == -1 || front > back ) {
            return true;
        }return false;
    }
};

int main(void){

    queue obj1;

    int limit;
    cout<<"Enter the size of the queue "<<endl<<"-> ";
    cin >> limit;

    cout<<endl<<endl<<"Enter the elements "<<endl;
    for(int i=0;i<limit;i++){
        cout<<"=> ";
        int element ;
        cin>>element;
        obj1.push(element);
    }

    cout<<endl<<"The First elements in the Queue is : "<<obj1.peek()<<endl;

    cout<<endl<<"The complete Queue is  "<<endl;
    while(!obj1.empty()){
        cout<<"~> "<<obj1.peek()<<endl;
        obj1.pop();
    }

}