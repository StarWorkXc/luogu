//
// Created by StarWork on 2020/12/27.
//

//
// Created by StarWork_Mobile on 2020/12/24.
//

#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    double x,y;
}s[200200],tmp_s[200200];
double min(double x,double y)
{
    if(x>y) return y;
    else return x;
}
double dist(node x,node y)
{
    //cout<<sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y))<<endl;
    return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
bool cmp_1(node x,node y)
{
    if(x.x==y.x) return x.y<y.y;
    return x.x<y.x;
}
bool cmp_2(node x,node y)
{
    return x.y<y.y;
}
double merge(int l,int r)
{
    if(l==r) return 10000000000;
    if(l+1==r) return dist(s[l],s[r]);
    int mid=l+r>>1;
    double d=min(merge(l,mid),merge(mid+1,r));
    int k=0;
    for(int i=l;i<=r;i++)
    {
        if(fabs(s[i].x-s[mid].x)<d)
        {
            tmp_s[++k].x=s[i].x;
            tmp_s[k].y=s[i].y;
        }
    }
    sort(tmp_s+1,tmp_s+k+1,cmp_2);
    for(int i=1;i<=k;i++)
    {
        for(int j=i+1;j<=k&&fabs(tmp_s[j].y-tmp_s[i].y)<d;j++)
        {
            d=min(dist(tmp_s[i],tmp_s[j]),d);
        }
    }
    return d;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i].x>>s[i].y;
    sort(s+1,s+n+1,cmp_1);
    printf("%.4f",merge(1,n));
}