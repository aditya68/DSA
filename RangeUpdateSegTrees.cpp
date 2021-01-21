#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
#define setpr(x) cout<<fixed<<setprecision(x)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pi pair<int,pii>
const int inf=1e9+7;
const int N=1e5+5;
int seg[4*N];
int lazy[4*N];
// point update
void pointupd(int t,int l,int r,int idx,int val)
{
    if(l==r)
    {
        seg[t]+=val;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid)pointupd(2*t+1,l,mid,idx,val);
    else pointupd(2*t+2,mid+1,r,idx,val);
    seg[t]=seg[2*t+1]+seg[2*t+2];
    return;
}
// range update using lazy propagation.
void rangeupd(int t,int l,int r,int c,int d,int val)
{
    if(lazy[t])
    {
        seg[t]+=(r-l+1)*lazy[t];
        if(l!=r)
        {
           lazy[2*t+1]+=lazy[t];
           lazy[2*t+2]+=lazy[t];
        }
        lazy[t]=0;
    }
    if(r<c||d<l)return;
    if(l>=c&&r<=d)
    {
        seg[t]+=(r-l+1)*val;
        if(l!=r)
        {
           lazy[2*t+1]+=val;
           lazy[2*t+2]+=val;
        }
        return;
    }
    int mid=(l+r)/2;
    rangeupd(2*t+1,l,mid,c,d,val);
    rangeupd(2*t+2,mid+1,r,c,d,val);
    seg[t]=seg[2*t+1]+seg[2*t+2];
    return;
}
// range query
int qur(int t,int l,int r,int c,int d)
{
    if(lazy[t])
    {
        seg[t]+=(r-l+1)*lazy[t];
        if(l!=r)
        {
           lazy[2*t+1]+=lazy[t];
           lazy[2*t+2]+=lazy[t];
        }
        lazy[t]=0;
    }
    if(r<c||d<l)return 0;
    if(l>=c&&r<=d)return seg[t];
    int mid=(l+r)/2;
    int q1=qur(2*t+1,l,mid,c,d);
    int q2=qur(2*t+2,mid+1,r,c,d);
    return q1+q2;
}
void solve()
{
    int n,q; cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        pointupd(0,0,n-1,i,x);
    }
    while(q--)
    {
        int ty; cin>>ty;
        if(ty==1)
        {
            int c,d,val; cin>>c>>d>>val;
            c--; d--;
            rangeupd(0,0,n-1,c,d,val);
        }
        else
        {
            int a,b; cin>>a>>b;
            --a; --b;
            cout<<qur(0,0,n-1,a,b)<<endl;
        }
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; t=1;
    while(t--)solve();
    return 0;
}
