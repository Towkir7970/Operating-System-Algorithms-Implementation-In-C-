#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, current, left, input, size_of_file, flag=0;
    char name;
    cout<<"Enter the number of blocks: ";
    cin>>n;
    current=0;
    left=n;
    char disk[n];
    for(int i=0; i<n; i++){
        disk[i]=' ';
    }
    while(1){
        cout<<"\n\n1.Create File \n2.Search File";
        cout<<"Enter 1 or 2: ";
        cin>>input;
        if(input==1){
            cout<<"\nEnter Filename: ";
            cin>>name;
            cout<<"\nEnter File Size: ";
            cin>>size_of_file;
            if(size_of_file<=left){
                for(int i=0; i<=size_of_file; i++){
                    disk[current]=name;
                    current++;
                }
                left-=size_of_file;
                cout<<"\nFile Created";
            }else{
                cout<<"\nFile can not be created. Not enough space";
            }
        }else if(input==2){
            cout<<"\nEnter Filename: ";
            cin>>name;
            cout<<endl;
            if(current!=0){
                for(int i=0; i<current; i++){
                    if(disk[i]==name){
                        flag=1;
                        cout<<"\nFile found in block: "<<i;
                    }
                }
            }else{
                cout<<"\nNot Found";
            }
            if(flag==0){
                cout<<"\nNot Found";
            }
            flag=0;
        }else{
            cout<<"\nInvalid Number";
        }
    }
    return 0;
}
