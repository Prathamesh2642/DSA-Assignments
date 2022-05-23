#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
using namespace std;

void set_data()
{

}

int main()
{

    ofstream o1;
    int num;
    string s1, no, index;

    cout << "\nEnter no of entries: ";
    cin >> num;

    o1.open("Sample.txt");
    cout << "\nWriting the File...\n";

    cout << "\nFollowing format \n\t\t\tSr.No  Name  Roll No";

    // getline(cin, s1);
    // or below
    getchar();
    for (int i = 0; i < num; i++)
    {
        cout << "\nEnter student Detail: ";
        getline(cin, s1);
        o1 << s1 << endl;
    }

    cout << "Enter the index no. of the student: ";
    cin >> no;
    // Reading
    ifstream i1;
    i1.open("Sample.txt");

    cout << "\nReading the File:\n";
    int flag=0;
    while (i1)
    {
        getline(i1, s1);

        index = s1[0];
        if (no == index)
        {
            cout << "Found the record....\n";
            flag++;
            cout << s1 << endl;
            break;
        }

    
    }
    if(flag==0){
    cout << "Not found !\n";    
    }
  return 0;
}
