#include<bits/stdc++.h>
using namespace std;

struct process
{
    char name;
    int cpu_time;
};

bool compareCPUtime(process a, process b)
{
    return a.cpu_time < b.cpu_time;
}

int main(void)
{
    int n;
    int startingTime=0;
    int finishTime=0;
    int waitingTime=0;
    int turnAroundTime=0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    process a[n];
    for(int i=0; i<n; i++)
    {
        printf("\nEnter process name: ");
        cin>>a[i].name;
        printf("\nEnter CPU time: ");
        cin>>a[i].cpu_time;
    }
    sort(a, a+n, compareCPUtime);

    for(int i=0; i<n; i++)
    {
        finishTime=finishTime+a[i].cpu_time;
        cout<<a[i].name<<" Starting = "<<startingTime<<", Finishing Time = "<<finishTime<<", Waiting Time = "<<waitingTime<<", Turn Around Time = "<<turnAroundTime<<"\n";
        waitingTime=waitingTime+a[i].cpu_time;
        //startingTime=startingTime+waitingTime;
        startingTime=finishTime;
        turnAroundTime=waitingTime+a[i].cpu_time;
    }

    cout<<"\nAverage Waiting Time = "<<float(waitingTime/n);
    cout<<"\nAverage Turn Around Time = "<<float(turnAroundTime/n);

    return 0;
}
