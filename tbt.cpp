#include <iostream>
using namespace std;
class tree{
public:
int data;
tree* left;
tree* right;
bool rthr;
};
class TBT{

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
                temp->rthr=false;
                temp->left->rthr=true;
                break;
            }
            else if(temp->data>newnode->data){ //traversal
                temp=temp->left;
            }
            else if((temp->data<newnode->data) && (temp->right==NULL)){//insertion right
                temp->right=newnode;
                cout<<"Value inserted on right \n"<<endl;
                break;
                // temp->right->lthr=true;
                temp->rthr=false;
                temp->right->rthr=true;
            }
            // if((temp->data<newnode->data) && (temp->right==NULL) && (temp->left==NULL) && (newnode->data<rootnode->data)){
            //     temp->rthr=true;
            //     // temp->right->rthr=true;
            // }
            else{
                temp=temp->right;
            }
        }
    }
}
tree* maxvaluenode(tree* n) 
{ 
    tree* current = n;
    // tree* temp; 
    while (current && current->right != NULL) {
        current = current->right;
    }
    current->rthr=true;
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

void printinorder(tree * root){
    
    if(root!=NULL){
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
    }

}
void printpreorder(tree * root){
    
    if(root!=NULL){
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
    }

}
void printpostorder(tree * root){
    
    if(root!=NULL){
    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->data<<" ";
    
    }

}
void check_tbt(tree *root)
{
    if(root == nullptr)
        return;

    check_tbt(root->left);

    if(root->rthr)
        cout<<root->data<<" ";

    check_tbt(root->right);
}


};
int main(){
    TBT b1;
    tree *t;
    int choice;
    int val;
    do{
        cout<<"Select from following option \n1.Insert\n2.Search\n3.Delete\n4.Print inorder BST\n5.Print preorder BST\n6.Print postorder BST\nselect 0 to exit \n";
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
        case 4:b1.printinorder(b1.rootnode);
                cout<<"\n";
                break;
        case 5:b1.printpreorder(b1.rootnode);
                cout<<"\n";
                break;
        case 6:b1.printpostorder(b1.rootnode);
                cout<<"\n";
                break;
        case 7:b1.maxvaluenode(b1.rootnode->left);
                b1.check_tbt(b1.rootnode);
                break;
        default:
            break;
        }
    }while(choice!=0);
    return 0;
}
