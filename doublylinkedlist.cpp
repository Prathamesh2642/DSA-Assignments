#include<iostream>
using namespace std;
class node{
public:
int data;
node* next;
node* prev;
};

class dlinkedlist{
node* head=NULL;
node* tail=NULL;
public:

void insertval(int k){
    node * newnode=new node;
    newnode->data=k;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
        tail=head;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void display(){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-";
        temp=temp->next;
    }
}
void revdisplay(){
    node* temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<"-";
        temp=temp->prev;
        // cout<<"\n"<<temp->data;
    }
}
};

int main(){
dlinkedlist l;
int c,a,b;
do{
cout<<"\nEnter the choice \n1.Insert\n2.Display\n3.Display reverse\n4.Exit\n ";
cin>>c;
switch(c){
    case 1:
            cout<<"Enter the number to be inserted ";
            cin>>a;
            l.insertval(a);
            break;
    case 2: 
            cout<<"\n Doubly linked list looks like \n ";
            l.display();
            break;
            
    case 3: 
            cout<<"\n Reverse printing this linked list \n";
            l.revdisplay();
            break;
}
}while(c!=4);
    return 0;
}
