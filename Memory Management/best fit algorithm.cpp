#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n_holes, n_reqs, f=0;
    vector <int> holes;
    vector <int> requests;
    cout<<"Enter number of holes: ";
    cin>>n_holes;
    cout<<"\nEnter hole values: ";
    for(int i=0; i<n_holes; i++){
        int a;
        cin>>a;
        holes.push_back(a);
    }
    cout<<"\nEnter number of requests: ";
    cin>>n_reqs;
    cout<<"\nEnter request values: ";
    for(int i=0; i<n_reqs; i++){
        int a;
        cin>>a;
        requests.push_back(a);
    }

    for(int i=0; i<n_reqs; i++){
        cout<<"\n"<<requests[i]<<" -> ";
        int index, a, b=9999;
        for(int j=0; j<n_holes; j++){
            if(holes[j]>=requests[i]){
                a=holes[j]-requests[i];
                if(a<=b){
                    index=j;
                    b=a;
                }
            }
        }
        cout<<"Block "<<index+1;
        holes[index]-=requests[i];
        f++;
    }
    cout<<"\n\n";
    for(int i=0; i<n_holes; i++){
        cout<<"Block "<<i+1<<": "<<holes[i]<<"\n";
    }
    if(f!=n_reqs){
        int ext_frg=0;
        for(int i=0; i<n_holes; i++){
            ext_frg+=holes[i];
        }
        cout<<"External Fragmentation: "<<ext_frg<<endl;
    }else{
        cout<<"\nNo External Fragmentation.\n";
    }
    return 0;

}


