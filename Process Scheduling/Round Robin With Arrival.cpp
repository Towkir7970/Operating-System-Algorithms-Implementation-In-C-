#include<bits/stdc++.h>
using namespace std;

struct process
{
    int name;
    int arrival_time;
    int cpu_time;
    int rem_time;
    int finish_time;
    int waiting_time;
    int turn_around_time;
    int temp;
};

bool compare_arrival_time(process a, process b)
{
    return a.arrival_time < b.arrival_time;
}

int main(void)
{
    int n, t, time=0, totalWaitingTime=0, totalTurnaroundTime=0;
    queue <process> q;
    queue <int> g;
    vector <int> v2;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter the time slice: ");
    scanf("%d", &t);
    process a[n];
    int rem =n;

    for(int i=0; i<n; i++)
    {
        printf("\nEnter process name: ");
        cin>>a[i].name;
        printf("\nEnter CPU time: ");
        cin>>a[i].cpu_time;
        printf("\nEnter Arrival time: ");
        cin>>a[i].arrival_time;
        a[i].rem_time=a[i].cpu_time;
        a[i].waiting_time=0;
        //a[i].finish_time=0;
        a[i].temp=0;
        a[i].turn_around_time=0;
    }
    sort(a, a+n, compare_arrival_time);
    q.push(a[0]);
    int i=0;
    while(!q.empty())
    {
        process c = q.front();
        g.push(c.name);
        //c.waiting_time = c.waiting_time+(time-c.temp);
        //wt[c.name]=wt[c.name]+(time-c.temp);
        //printf("\n\nprocess %d waiting time %d\n\n", c.name, c.waiting_time);
        q.pop();
        if(c.rem_time>t)
        {
            c.rem_time-=t;
            time+=t;
            c.temp=time;
        }
        else{
            time+=c.rem_time;
            c.rem_time=0;
            c.finish_time=time;
            v2.push_back(c.finish_time);
            //cout<<"\nFinish Time"<<c.finish_time<<endl;
        }
        while(i+1<n)
        {
            if(a[i+1].arrival_time<=time)
            {
                q.push(a[i+1]);
                i++;
                //a[i+1].waiting_time=(time-a[i+1].arrival_time);
                //wt[i+1]=time-a[i+1].arrival_time;
            }
            else
                break;
        }
        if(c.rem_time>0)
        {
            q.push(c);
        }
        //printf("\n\nProcess = %d temp = %d\n\n", c.name, c.temp);
        //c.waiting_time = c.waiting_time+(time-c.temp);

    }
    printf("\n\nTotal Execution Time = %d\n\n", time);
    while(!g.empty()){
		cout<<"|---P"<<g.front()<<"---|";
		g.pop();
	}
	for(int i=0; i<n; i++)
        a[i].finish_time=v2[i];

	for(int i=0; i<n; i++)
        cout<<"\nfinish time "<<a[i].finish_time<<endl;

	for(int i=0; i<n; i++)
    {
        a[i].turn_around_time = a[i].finish_time-a[i].arrival_time;
        totalTurnaroundTime+=a[i].turn_around_time;
        a[i].waiting_time = a[i].turn_around_time-a[i].cpu_time;
        totalWaitingTime+=a[i].waiting_time;
    }
    printf("\n\n");
    for(int i=0; i<n; i++)
    {
        cout<<"Process "<<a[i].name<<" Waiting Time = "<<a[i].waiting_time<<" Turnaround Time = "<<a[i].turn_around_time<<endl;
    }
    cout<<"\nAverage Waiting Time = "<<(float)(totalWaitingTime)/(float)(n);
    cout<<"\nAverage Turnaround Time = "<<(float)(totalTurnaroundTime)/(float)(n);

}

