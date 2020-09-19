#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, left, input, size_of_file, flag=0;
    char name;
    cout<<"Enter the number of blocks: ";
    cin>>n;
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
                for(int i=0; i<size_of_file; i++){
                    while(1){
                        int random = rand() % n;
                        if(disk[random]==' '){
                            disk[random]=name;
                            break;
                        }
                    }
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
            for(int i=0; i<n; i++){
                if(disk[i]==name){
                    flag=1;
                    cout<<"\nFile found in block: "<<i;
                }
            }
            if(flag==0){
                cout<<"\nNot Found";
            }
            flag=0;
        }else{
            cout<<"\nInvalid Number";
            break;
        }
    }
    return 0;
}
