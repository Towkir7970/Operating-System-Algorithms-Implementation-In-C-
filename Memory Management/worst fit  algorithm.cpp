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
        if(f==0){
            cout<<"\n"<<requests[i]<<" -> ";
            int largest=-1;
            for(int j=0; j<n_holes; j++){
                if(holes[j]>=largest){
                    largest=holes[j];
                }
            }
            cout<<"Largest "<<largest;
            for(int j=0; j<n_holes; j++){
                if((holes[j]==largest) && (holes[j]>=requests[i])){
                    cout<<" Block "<<j+1;
                    holes[j]-=requests[i];
                    break;
                }
                else if((holes[j]==largest) && (holes[j]<requests[i])){
                    f=1;
                }
            }
        }
    }

    cout<<"\n\n";
    for(int i=0; i<n_holes; i++){
        cout<<"Block "<<i+1<<": "<<holes[i]<<"\n";
    }
    int ext_frg=0;
    for(int i=0; i<n_holes; i++){
        ext_frg+=holes[i];
    }
    cout<<"External Fragmentation: "<<ext_frg<<endl;

    return 0;

}

