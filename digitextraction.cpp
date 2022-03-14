#include<iostream>
#include<string>
#define max 10
using namespace std;

class hashvalues{
    public:

    long int number;
    hashvalues *next;
};
class hashtable{
    hashvalues *data[max];
    int index;
    public:
    void initialize(){
        for(int i=0;i<max;i++){
            data[i]=NULL;
        }
    }
    hashvalues *createnode(int value)
    {
        hashvalues *temp = new hashvalues;
        temp->next = NULL;
        temp->number = value;
        return temp;
    }
    int hashfunction(string v){
        return stoi(v.substr(1,1));//v%max

    }
    void insertval(int k,string v){
        int index = hashfunction(v);
        hashvalues *temp = new hashvalues;
        hashvalues *head = new hashvalues;
        head = createnode(k);
        temp = data[index];
        if (temp == NULL)
        {
            data[index] = head;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = head;
        }
    }
    void display(){
        for(int i=0;i<max;i++){
            cout<<i<<"]";
            hashvalues *temp=new hashvalues;
            temp=data[i];
            while(temp!=NULL){
                cout<<temp->number<<"-->";
                temp=temp->next;
            }
            cout<<"\n";
        }
    }
    void search(int n,string q){
        int index = hashfunction(q);
        hashvalues *temp = new hashvalues;
        hashvalues *head = new hashvalues;
        
    }

};
int main(){
    int num,k,c;
    string v,j;
    hashtable a;
    a.initialize();
    do
    {
        cout << "\n1.Insert \n2.Display\n3.Exit" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter a 3 digit number :";
            cin >>v;
            num=stoi(v);
            a.insertval(num,v);
            break;
        case 2:
            a.display();
            break;
        case 3:;
        }
        

    } while (c != 4);
    
    
    
    return 0;
}
