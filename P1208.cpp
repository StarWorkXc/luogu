//
// Created by StarWork on 2020/12/28.
//

#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int price,amount;
}milk[10000];
bool cmp(node x,node y)
{
    return x.price<y.price;
}
int main()
{
    cin>>n>>m;
    if(n==0&&m==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>milk[i].price>>milk[i].amount;
    }
    sort(milk+1,milk+m+1,cmp);
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        n-=milk[i].amount;
        if(n>0)
        {
            ans+=milk[i].amount*milk[i].price;
        }
        else
        {
            milk[i].amount+=n;
            ans+=milk[i].amount*milk[i].price;
            cout<<ans;
            return 0;
        }
    }
}