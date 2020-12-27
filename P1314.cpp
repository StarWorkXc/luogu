//
// Created by StarWork on 2020/12/27.
//

#include<bits/stdc++.h>
using namespace std;
int w[200200],v[200200];
int l[200200],r[200200];
int n,m;
long long s;
long long item_sum[200200],value_sum[200200];
int max_w=-1;
long long min(long long x,long long y)
{
    if(x>y) return y;
    else return x;
}
void modify(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(w[i]>=x)
        {
            value_sum[i]=value_sum[i-1]+1;
            item_sum[i]=item_sum[i-1]+v[i];
        }
        else
        {
            value_sum[i]=value_sum[i-1];
            item_sum[i]=item_sum[i-1];
        }
    }
}
long long cal()
{
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        ans+=(item_sum[r[i]]-item_sum[l[i]-1])*(value_sum[r[i]]-value_sum[l[i]-1]);
    }
    return ans;
}
int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
        max_w=max(max_w,w[i]);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i];
    }
    int begin=1,end=max_w+1,mid;
    long long anss=9999999999999999;
    while(begin<=end)
    {
        mid=begin+end>>1;
        modify(mid);
        long long ans=cal();
        if(ans>=s)
        {
            begin=mid+1;
        }
        else
        {
            end=mid-1;
        }
        anss=min(anss,fabs(s-ans));
    }
    cout<<anss;
}