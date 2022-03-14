#include<iostream>
using namespace std;
class node{  
    public:
    int data; 
    node * next; 
    node(){
        data=0;
        next=NULL;
    }
};
class linkedlist{
node * head=NULL; 
node* lvl1h=NULL;
public:
void insertnode(int a){
    node* newnode=new node(); 
    newnode->data=a;
    newnode->next=NULL;
    if(head==NULL){ 
        head=newnode;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){ 
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void skiplist(){
        node*t,*k;
        k=head;
        node* newn=new node;
        newn->data=head->data;
        newn->next=NULL;
        if(lvl1h==NULL){
            lvl1h=newn;
        }
        else{
            t=lvl1h;

        while(k->next!=NULL){
            // lvl1h->next->data=t->next->next->data;
            // lvl1->next->next=NULL;
            // t=t->next;  
            // cout<<"\n"<<t->data;        
            k=k->next->next;
            cout<<k->data;
            
        }
        
}
}
void display(){
    node* temp=head;
    if(head==NULL){
        cout<<"Linked list is empty";
    }
    else{
        while(temp!=NULL){
            cout<<temp->data<<"-";
            temp=temp->next;
        }
    }
}
void displayskip(){
    node* lvl1=head;
    
    if(head==NULL){
        cout<<"Linked list is empty";
    }
        else{
        while(lvl1!=NULL){
            cout<<lvl1->data<<"-";
            lvl1=lvl1->next->next;

        }
    }
}
};
int main(){
    linkedlist l;
    int n,num;
    cout<<"Enter number of links ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the number ";
        cin>>num;
        l.insertnode(num);
    }
    l.display();
    l.skiplist();
    cout<<"\n";
     l.displayskip();
    return 0;
}
