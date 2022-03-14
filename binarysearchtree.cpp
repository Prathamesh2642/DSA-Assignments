#include <iostream>
using namespace std;
class tree{
public:
int data;
tree* left;
tree* right;
};
class BST{

public:
tree* rootnode=NULL;
void insertnode(int k){
    tree* newnode=new tree;
    newnode->data=k;
    newnode->left=NULL;
    newnode->right=NULL;
    if(rootnode==NULL){
        rootnode=newnode;
        cout<<"Rootnode created \n";
    }
    else{
        tree* temp=rootnode;
        while(temp!=NULL){
            if(newnode->data==temp->data){
                cout<<"No duplicate values \n";
                return;
                }
            else if((temp->data>newnode->data) && (temp->left==NULL)){//insertion left
                temp->left=newnode;
                cout<<"Value inserted on left \n"<<endl;
                break;
            }
            else if(temp->data>newnode->data){ //traversal
                temp=temp->left;
            }
            else if((temp->data<newnode->data) && (temp->right==NULL)){//insertion right
                temp->right=newnode;
                cout<<"Value inserted on right \n"<<endl;
                break;
            }
            else{
                temp=temp->right;
            }
        }
    }
}
void searchinbst(int val){
    tree *temp=rootnode;
    if(rootnode==NULL){
        cout<<"BST is empty ";
        return;
    }
    else{
        while(temp!=NULL){
            if (temp->data==val){
                cout<<val<<" is present in the tree "<<endl;
                return;
            }
            else if(temp->data>val){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        cout<<val<<" is not present "<<endl;
    }
}


};
int main(){
    BST b1;
    int choice;
    int val;
    do{
        cout<<"Select from following option \n1.Insert\n2.Search\n3.Delete\n4.Print BST\nselect 0 to exit \n";
        cin>>choice;
        switch (choice)
        {

        case 1:cout<<"INSERT NEW NODE "<<endl;
                cout<<"Enter Value to be inserted ";
                cin>>val;
                b1.insertnode(val);
                break;
        case 2:int sear;
                cout<<"\n Enter the value to be searched ";
                cin>>sear;
                b1.searchinbst(sear);
                break;
        case 3://delete
                break;
        case 4://print
                break;
        default:
            break;
        }
    }while(choice!=0);
    return 0;
}
