//General tree
#include <iostream>
#include <string> 
#define max 20
using namespace std;
class node{
public:
char name[50];
int noofsub;
node* subsect[max];
};
class Tree{
public:
node* root=NULL;
void createbook(){
    node* newnode=new node;
    root=newnode;
    cout<<"Enter the name of the book: ";
    cin>>newnode->name;
    // cin.get();
    // getline();
    cout<<"Enter the number of chapters in the book: ";
    cin>>newnode->noofsub;
    for(int i=1;i<=newnode->noofsub;i++){
        newnode->subsect[i]=new node;
        cout<<"Enter the name of chapter "<<i<<": ";
        cin>>newnode->subsect[i]->name;
        // cin.get();
        // getline();
        cout<<"Enter the number of subsections in "<<newnode->subsect[i]->name<<": ";
        cin>>newnode->subsect[i]->noofsub;
        for(int j=1;j<=newnode->subsect[i]->noofsub;j++){
            newnode->subsect[i]->subsect[j]=new node;
            cout<<"Enter the name of the subsection "<<j<<": ";
            cin>>newnode->subsect[i]->subsect[j]->name;
            // cin.get();
            // getline();
        }
    }
}
void display(){
    cout<<"------------------------------\n";
    node*temp=root;
    cout<<"NAME OF THE BOOK IS "<<temp->name<<endl;
    cout<<"This book has "<<temp->noofsub<<" chapters "<<endl;
    cout<<"Name of the chapters is         "<<endl;
    for(int i=1;i<=temp->noofsub;i++){
        cout<<"\t\t"<<temp->subsect[i]->name<<endl;
        cout<<temp->subsect[i]->name<<" has "<<temp->subsect[i]->noofsub<<" subsections "<<endl;
        cout<<"Name of the subsections in "<<temp->subsect[i]->name<<" are"<<endl;
        for(int j=1;j<=temp->subsect[i]->noofsub;j++){
            cout<<"\t\t\t"<<temp->subsect[i]->subsect[j]->name<<"\n";
        }
    }
}
};
int main(){
    Tree t;
    t.createbook();
    t.display();
    return 0;
}
