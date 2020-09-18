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

void LRU(int pageFrame, string refString, vector<char> x){
    int pageFault=0;
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
            x[far]=refString[i];
            pageFault++;
        }
    }
    cout<<"\n\nNumber Of Page Fault Using LRU Page Replacement Algorithm: "<<pageFault;
    cout<<"\nPage Fault Rate Using LRU Page Replacement Algorithm: "<<(double)(((double)pageFault/(double)refString.length())*100)<<"%";
}

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

void optimal(int pageFrame, string refString, vector<char> x){
    int pageFault=0;
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
    cout<<"\n\nNumber of Page Fault Using Optimal Page Replacement Algorithm: "<<pageFault;
    cout<<"\nPage Fault Rate using Optimal Page Replacement Algorithm: "<<(double)(((double)pageFault/(double)refString.length())*100)<<"%";
}

int main(void){
    int pageFrame;
    string refString;
    vector <char> x;
    printf("\nEnter length of page frame: ");
    cin>>pageFrame;
    printf("\nEnter reference string: ");
    cin>>refString;
    LRU(pageFrame, refString, x);
    optimal(pageFrame, refString, x);
    cout<<endl;
    return 0;
}

