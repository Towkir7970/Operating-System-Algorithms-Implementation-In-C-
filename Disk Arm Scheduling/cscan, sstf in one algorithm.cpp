#include<bits/stdc++.h>
using namespace std;

void cscan(int noHeads, int current, int noReq, vector<int> requests)
{
    cout<<"\n\nUsing CSCAN::"<<endl;
    int a, last, index, minimum, value, total=0;
    vector<int> requestsLarge;
    vector<int> requestsSmall;
    for(int i=0; i<noReq; i++){
        if(requests[i]>current){
            requestsLarge.push_back(requests[i]);
        }else{
            requestsSmall.push_back(requests[i]);
        }
    }
    sort(requestsLarge.rbegin(), requestsLarge.rend());
    sort(requestsSmall.rbegin(), requestsSmall.rend());
    cout<<"\nCylinder Serving Order: ";
    cout<<current<<"-> ";
    while(requestsLarge.size()!=0){
        cout<<requestsLarge.back()<<" ";
        last=requestsLarge.back();
        requestsLarge.pop_back();
        total+=abs(current-last);
        current=last;
    }
    total+=abs(current-(noHeads-1));
    current=0;
    while(requestsSmall.size()!=0){
        cout<<requestsSmall.back()<<" ";
        last=requestsSmall.back();
        requestsSmall.pop_back();
        total+=abs(current-last);
        current=last;
    }
    cout<<"\nTotal Cylinder Movement Using CSCAN: "<<total;
}

void sstf(int noHeads, int current, int noReq, vector<int> requests)
{
    cout<<"\n\nUsing SSTF::"<<endl;
    int a, left, index, minimum, value, total=0;
    cout<<"\nCylinder Serving Order: ";
    left=noReq;
    while(left!=0){
        minimum=9999;
        cout<<current<<"-> ";
        for(int i=0; i<requests.size(); i++){
            value=abs(current-requests[i]);
            if(value<minimum){
                minimum=value;
                index=i;
            }
        }
        total+=value;
        current=requests[index];
        left--;
        requests.erase(requests.begin()+index);
    }
    cout<<"\nTotal Cylinder Movement Using SSTF: "<<total;
}

int main(void)
{
    int noHeads, current, noReq, a, last, index, minimum, value, total=0;
    vector<int> requests;
    cout<<"Enter No of Head points: ";
    cin>>noHeads;
    cout<<"\nEnter Current Head point: ";
    cin>>current;
    cout<<"\nEnter Number of requests: ";
    cin>>noReq;
    cout<<"\nEnter the requests: ";
    for(int i=0; i<noReq; i++){
        cin>>a;
        requests.push_back(a);
    }
    cscan(noHeads, current, noReq, requests);
    sstf(noHeads, current, noReq, requests);
    cout<<endl;
    return 0;
}

