#include<iostream>
#define max 100
using namespace std;
class graph{
public:
int data;
int matrix[max][max];
int values[max];
static int numnodes;
// int adjlistarr[num];
void initialize(int num){
    for(int i=0;i<=num;i++){
        for(int j=0;j<=num;j++){
            matrix[i][j]=0;
        }
    }
    for(int i=0;i<max;i++){
        values[i]=0;
    }
}
int checknodepresence(int a){
    int flag=0;
    for(int i=0;i<numnodes;i++){
        if(a==values[i]){
            return 1;
        }
    }
    if(flag==0){
        return 0;
    }
}
int indexreturn(int number){
    for(int i=0;i<numnodes;i++){
        if(number==values[i]){
            return i;
        }
    }
}
void newlink(int a,int b){
    int firstindex=indexreturn(a);
    int secondindex=indexreturn(b);
    matrix[firstindex][secondindex]=1;
    matrix[secondindex][firstindex]=1;
}


void displayadj(int num){
    cout<<"  ";
    for(int k=0;k<num;k++){
        cout<<values[k]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<num;i++){
        cout<<values[i]<<" ";
        for(int j=0;j<num;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}
};
int graph::numnodes=0;
int main(){
    graph g;
    int numnodes,nodes,choice,first,last,flag;
    cout<<"Enter number of nodes ";
    cin>>numnodes;
    g.numnodes=numnodes;
    g.matrix[numnodes][numnodes];
    g.values[numnodes];
    g.initialize(numnodes);
    int i=0;
    while(i<numnodes){
        cout<<"Enter the node value in the graph ";
        cin>>nodes;
        g.values[i]=nodes;
        i++;
    }
    
    for(int i=0;i<numnodes;i++){
        cout<<g.values[i]<<" ";
    }
    do{
        cout<<"Select operation to be performed \n1.Insert node\n2.Display Adjacency matrix\n3.exit\n" ;
        cin>>choice;
        switch (choice)
        {
        case 1:cout<<"Enter nodes ";
            cin>>first;
            if(g.checknodepresence(first)==0){
                cout<<"Enter valid value "<<endl;
                break;
            }
            cin>>last;
            if(g.checknodepresence(last)==0){
                cout<<"Enter valid value "<<endl;
                break;
            }
            g.newlink(first,last);
            break;
        
        case 2:cout<<"-------------"<<endl;
                g.displayadj(numnodes);
                break;
        }
    }while(choice!=3);
    

    return 0;
}
