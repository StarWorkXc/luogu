#include<bits/stdc++.h>
using namespace std;
int a[1000011],d[1000011],l[1000011],r[1000011];
long long modify[1000011];
int n,m;
bool pd(int x)
{
    memset(modify,0,sizeof(modify));
    for(int i=1;i<=x;i++)
    {
        modify[l[i]]+=d[i];
        modify[r[i]+1]-=d[i];
    }
    long long p=0;
    for(int i=1;i<=n;i++)
    {
        p+=modify[i];
        if(p>a[i]) return 0;
    }
    return 1;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>d[i]>>l[i]>>r[i];
    }
    if(pd(m))
    {
        cout<<0;
        return 0;
    }
    else cout<<-1<<endl;
    int begin=1,end=m;
    while(begin<end)
    {
        int mid=(begin+end)/2;
        if(pd(mid))
        {
            begin=mid+1;
        }
        else
        {
            end=mid;
        }
    }
    cout<<begin;
}