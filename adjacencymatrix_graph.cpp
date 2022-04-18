#include<iostream>
using namespace std;
class graph{
public:
int data;
int matrix[5][5];
void initialize(int num){
    for(int i=0;i<=num;i++){
        for(int j=0;j<=num;j++){
            matrix[i][j]=0;
        }
    }
}
void newlink(int a,int b){
    matrix[a][b]=1;

}
void displayadj(int num){
    cout<<"  ";
    for(int k=0;k<=num;k++){
        cout<<k<<" ";
    }
    cout<<"\n";
    for(int i=0;i<=5;i++){
        cout<<i<<" ";
        for(int j=0;j<=5;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}
};
int main(){
    graph g;
    int numnodes,choice,start,end;
    cout<<"Enter number of nodes ";
    cin>>numnodes;
    g.initialize(numnodes);
    do{
        cout<<"Select operation to be performed \n1.Insert node\n2.Display Adjacency matrix\n3.exit\n" ;
        cin>>choice;
        switch (choice)
        {
        case 1:cout<<"Enter nodes ";
            cin>>start>>end;
            g.newlink(start,end);
            break;
        
        case 2:cout<<"-------------"<<endl;
                g.displayadj(numnodes);
        }
    }while(choice!=3);
    

    return 0;
}
