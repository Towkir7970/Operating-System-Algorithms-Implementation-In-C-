#include<bits/stdc++.h>
using namespace std;

int farthest(string arr, int sizeArr, vector<char> a, int sizeA, int pos)
{
    int x[sizeA];
    for(int i=0; i<sizeA; i++){
        x[i]=-1;
    }
    for(int i=0; i<sizeA; i++){
        for(int j=pos; j<sizeArr; j++){
            if(a[i]==arr[j]){
                if(x[i]==-1){
                    x[i]=j;
                }
            }
        }
    }
    if(*min_element(x, x+sizeA)==-1){
        for(int i=0; i<sizeA; i++){
            if(x[i]==-1){
                return i;
            }
        }
    }else{
        for(int i=0; i<sizeA; i++){
            if(x[i]==*max_element(x, x+sizeA)){
                return i;
            }
        }
    }
}


int main(void){
    int pageFrame, pageFault=0;
    string refString;
    vector <char> x;
    printf("\nEnter length of page frame: ");
    cin>>pageFrame;
    int arr[pageFrame];
    printf("\nEnter reference string: ");
    cin>>refString;
    for(int i=0; i<refString.length(); i++){
        cout<<" "<<refString[i];
    }
    for(int i=0; i<refString.length(); i++){
        if(count(x.begin(), x.end(), refString[i])){
           continue;
        }
        else if(x.size()<pageFrame){
            x.push_back(refString[i]);
            pageFault++;
        }
        else if(x.size()==pageFrame){
            int far=farthest(refString, refString.length(), x, x.size(), i+1);
            //cout<<"\n"<<far;
            x[far]=refString[i];
            pageFault++;
        }
    }
    cout<<"\n\nPage Fault: "<<pageFault;
    return 0;
}

