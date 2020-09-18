#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int noHeads, current, noReq, a, left, index, minimum, value, total=0;
    vector<int> requests;
    cout<<"\nEnter Current Head point: ";
    cin>>current;
    cout<<"\nEnter Number of requests: ";
    cin>>noReq;
    left=noReq+1;
    cout<<"\nEnter the requests: ";
    for(int i=0; i<noReq; i++){
        cin>>a;
        requests.push_back(a);
    }
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
    cout<<"\nTotal Cylinder Movement: "<<total;
    return 0;
}
