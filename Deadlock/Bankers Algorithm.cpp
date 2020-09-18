#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int processNo, resourceNo, tvr[100], finishedProcesses=0;
    bool safe=false;
    cout<<"Enter the number of processes: ";
    cin>>processNo;
    cout<<"Enter the number of resources: ";
    cin>>resourceNo;
    struct processes
    {
        int name;
        int max_resource[100];
        int allocated_resource[100];
        int need_matrix[100];
        bool finish=false;
    };
    processes a[processNo];
    queue<int> cp;
    //vector<processes> ucp;

    for(int i=0; i<processNo; i++)
    {
        cout<<"\nProcess "<<i+1<<":";
        a[i].name=i+1;
        for(int j=0; j<resourceNo; j++)
        {
            cout<<"Maximum value for resource "<<j+1<<": ";
            cin>>a[i].max_resource[j];
        }
        for(int j=0; j<resourceNo; j++)
        {
            cout<<"Allocated from resource "<<j+1<<": ";
            cin>>a[i].allocated_resource[j];
        }
    }
    for(int i=0; i<processNo; i++)
    {
        for(int j=0; j<resourceNo; j++)
        {
            a[i].need_matrix[j] = (a[i].max_resource[j] - a[i].allocated_resource[j]);
        }
    }
    /*
    for(int i=0; i<processNo; i++)
    {
        for(int j=0; j<resourceNo; j++)
        {
            cout<<"\n\n"<<a[i].need_matrix[j];
        }
        cout<<"\n\n";
    } */
    for(int i=0; i<resourceNo; i++)
    {
        cout<<"\nEnter Total Value for Resource "<<i+1<<": ";
        cin>>tvr[i];
    }
    /*
    for(int i=0; i<processNo; i++)
    {
        ucp[i].push_back(a[i]);

    } */
    while(true)
    {
        for(int i=0; i<processNo; i++)
        {
            if(a[i].finish==false)
            {
                int flag = 0;
                for(int j=0; j<resourceNo; j++)
                {
                    if(a[i].need_matrix[j] <= tvr[j])
                        flag = 0;
                    else
                        {
                            flag = 1;
                            break;
                        }
                }
                if(flag == 0)
                {
                    for(int j=0; j<resourceNo; j++)
                    {
                        tvr[j]+=a[i].allocated_resource[j];
                    }
                    a[i].finish=true;
                    finishedProcesses++;
                    cp.push(a[i].name);
                    cout<<"\nExecuting process no : "<<a[i].name<<endl;
                    //ucp.erase(a[i]);
                }
            }
        }
        if(finishedProcesses==processNo)
        {
            safe=true;
            break;
        }
    }/*
    if(safe==true)
    {
        cout<<"\nThe System is in safe state!"<<endl;
        while(!cp.empty()){
            cout<<"|---Process"<<cp.front()<<"---|";
            cp.pop();
        }
    }*/

    return 0;
}
