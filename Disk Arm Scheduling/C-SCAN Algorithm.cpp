#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int noHeads, current, noReq, a, last, index, minimum, value, total=0;
    vector<int> requests;
    vector<int> requestsLarge;
    vector<int> requestsSmall;
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
    for(int i=0; i<noReq; i++){
        if(requests[i]>current){
            requestsLarge.push_back(requests[i]);
        }else{
            requestsSmall.push_back(requests[i]);
        }
    }
    sort(requestsLarge.rbegin(), requestsLarge.rend());
    sort(requestsSmall.rbegin(), requestsSmall.rend());
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
    cout<<"\nTotal Cylinder Movement: "<<total;
    return 0;
}

