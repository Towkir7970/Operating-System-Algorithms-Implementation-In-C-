#include<bits/stdc++.h>
using namespace std;
int main()
{
   int cap;
   printf("enter size:");
   scanf("%d",&cap);
   int x;
   printf("enter request size:");
   scanf("%d",&x);
   int arr[x];

   for(int i=0;i<x;i++)
   {
       scanf("%d",&arr[i]);
   }

   set<int> s;
   set <int> :: iterator it;
   int page=0;

   for(int i=0;i<x;i++)
   {
       if(s.size()<cap)
       {
           if(s.find(arr[i])==s.end())
           {
               s.insert(arr[i]);
               page++;
           }
       }
       else
       {
           int lar=0,val=0;
           if(s.find(arr[i])==s.end())
           {
                 for (it=s.begin(); it != s.end(); ++it)
                 {
                     for(int j=i+1;j<x;j++)
                     {
                         if(*it==arr[j])
                         {
                             if(j>lar)
                             {
                                 val=*it;
                                 lar=j;
                             }
                             break;
                         }
                         else
                         {

                                 val=*it;
                                 lar=100;

                                break;
                         }

                     }
                 }
                 printf("\n %d %d",val,i);
                 s.erase(val);
                 s.insert(arr[i]);
                 page++;

           }

       }
   }

   printf("\n%d",page-1);

}
