#include<bits/stdc++.h>
using namespace std;

struct process
{
    int name;
    int cpu_time;
    int arrival_time;
    int priority;
    bool visited=false;

    bool operator() (process a, process b)
    {
        if(visited==false)
            return (a.priority<b.priority);
    }
}data;

bool compare_priority(process a, process b)
{
    return a.priority < b.priority;
}
bool compare_arrival(process a, process b)
{
    return a.arrival_time < b.arrival_time;
}
bool compare_arrival_vector(vector <process>a, vector <process>b)
{
//    return a.arrival_time < b.arrival_time;
}

int main(void)
{
    int n;
    int startingTime=0;
    int finishTime=0;
    float waitingTime=0;
    float turnAroundTime=0;
    int time=0;
    vector <process> v;
    float total=0;
    float totalwait=0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int rem=n;
    process a[n];
    for(int i=0; i<n; i++)
    {
        printf("\nEnter process name: ");
        cin>>a[i].name;
        printf("\nEnter CPU time: ");
        cin>>a[i].cpu_time;
        printf("\nEnter Arrival time: ");
        cin>>a[i].arrival_time;
        printf("\nEnter Priority: ");
        cin>>a[i].priority;
    }
    sort(a, a+n, compare_arrival);

    for(int i=0;i<n; i++)
        v.push_back(a[i]);


    while(rem!=0)
    {
        int i=0;
        cout<<"\n\nProcess = "<<v[i].name<<", Waiting Time = "<<(time-v[i].arrival_time)<<", Turnaround Time = "<<(time-v[i].arrival_time+v[i].cpu_time);
        v[i].visited = true;
        waitingTime+=(time-v[i].arrival_time);
        turnAroundTime+=(time-v[i].arrival_time+v[i].cpu_time);
        time+=v[i].cpu_time;
        v.erase(v.begin());
        rem--;
        sort(v.begin(), v.end(),data);
    }

    cout<<"\n\nAverage Waiting Time = "<<((float)waitingTime/(float)(n));
    cout<<"\n\nAverage Turn Around Time = "<<((float)turnAroundTime/(float)(n));

    return 0;
}

