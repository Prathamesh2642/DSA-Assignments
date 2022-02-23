#include<iostream>
using namespace std;
class node{
  public:
  int data;
  node* next;
};
class linkedlist{
  node* head=NULL;
  public:
  void insertnlink(int k){
      node* newnode=new node;
      newnode->data=k;
      newnode->next=NULL;
      if(head==NULL){
          head=newnode;
      }
      else{
          node*temp=head;
          while(temp->next!=NULL){
              temp=temp->next;
        
          }
          temp->next=newnode;
      }
      
  }
  void display(){
      node* tmp=head;
      while(tmp!=NULL){
          cout<<tmp->data<<"-";
          tmp=tmp->next;
      }
  }
  void insertatfirst(int k){
      node* t=new node;
      t->data=k;
      t->next=head;
      head=t;
  }
  int countnodes(){
      node* temp=head;
      int i=0;
      while(temp!=NULL){
          i++;
          temp=temp->next;
      }
      return i;
  }
  void insertatposition(int pos,int k){
      node* e=new node;
      node* temp=head;
      e->data=k;
      for(int i=0;i<pos-1;i++){
          temp=temp->next;
      }
      e->next=temp->next;
      temp->next=e;
      }
    void deletenode(int k){
        node* temp;
        node* t=head;
        int flag=0;
        while(t->next!=NULL){
            if(t->next->data==k){
                temp=t;
                temp->next=t->next->next;
                flag++;
            }
            t=t->next;
        }
        if (flag==0){
            cout<<"Number is not present in the list "<<endl;
        }
    }
    void searchnumber(int n){
        node* temp;
        temp=head;
        int flag=0;
        int j=0;
        while(temp->next!=NULL){
            if(temp->data==n){
                flag++;
                cout<<"Number is found at position "<<j+1<<endl;
                
            }
            temp=temp->next;
            j++;
        }
        if(flag==0){
            cout<<"Number is not present in the list"<<endl;
        }
    }
  
};
int main(){
    int a,b;
    linkedlist l;
    do{
        cout<<"\nchoose among the following \n1.Insert\n2.Display\n3.add node at first\n4.Insert at position \n5.Count number of nodes\n6.delete node\n7.Search\n8.Exit\n";
        cin>>a;
        switch(a){
            
            case 1:cout<<"Enter number to be inserted ";
                   cin>>b;
                   l.insertnlink(b);
                   break;
           
            case 2:l.display();
                    break;
            
            case 3:int q;
                    cout<<"Enter the number to be inserted ";
                    cin>>q;
                    l.insertatfirst(q);
                    break;
           
            case 4:int pos,num1;
                    cout<<"Enter the position ";
                    cin>>pos;
                    cout<<"Enter the number to be inserted ";
                    cin>>num1;
                    l.insertatposition(pos,num1);
                    break;
            
            case 5:int p;
                    p=l.countnodes();
                    cout<<"The number of nodes are "<<p;
                    break;
            
            case 6:int num2;
                    cout<<"Enter the number to be deleted ";
                    cin>>num2;
                    l.deletenode(num2);
            case 7:int num3;
                    cout<<"Enter the number to be searched ";
                    cin>>num3;
                    l.searchnumber(num3);
                    break;
        }
        
    }while(a!=8);
    return 0;
}
