#include<bits/stdc++.h>
using namespace std;

int farthestLRU(string arr, int sizeArr, vector<char> a, int sizeA, int pos)
{
    int x[sizeA];
    int y=0, f=0;
    for(int i=0; i<sizeA; i++){
        x[i]=-1;
    }
    for(int i=pos; i>=0; i--){
        for(int j=0; j<sizeA; j++){
            if(a[j]==arr[i]){
                if(x[j]==-1){
                    y++;
                    x[j]=1000;
                }
                if(y==sizeA){
                    return j;
                }
            }
        }
    }
}

int main(void){
    int pageFrame, pageFault=0;
    int y, f=0;
    string refString;
    vector <char> x;
    printf("\nEnter length of page frame: ");
    cin>>pageFrame;
    printf("\nEnter reference string: ");
    cin>>refString;
    for(int i=0; i<refString.length(); i++){
        if(count(x.begin(), x.end(), refString[i])){
           continue;
        }
        else if(x.size()<pageFrame){
            x.push_back(refString[i]);
            pageFault++;
        }
        else if(x.size()==pageFrame){
            int far=farthestLRU(refString, refString.length(), x, x.size(), i-1);
            //cout<<"\n"<<far;
            x[far]=refString[i];
            pageFault++;
        }
    }
    cout<<"\n\nPage Fault: "<<pageFault;
    return 0;
}

