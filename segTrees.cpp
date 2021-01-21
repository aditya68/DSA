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
const int N=2e5+5;
int seg[2*N];
int n;
void upd(int k,int val)
{
    k+=n;
    seg[k]=val; k>>=1;
    while(k)
    {
        seg[k]=seg[2*k]+seg[2*k+1];
        k>>=1;
    }
    return;
}
int qur(int a,int b)
{
    a+=n; b+=n;
    int c=0;
    while(a<=b)
    {
        if(a&1)c+=seg[a++]; // a is right child.
        if(~b&1)c+=seg[b--]; // b is left child.
        a>>=1; b>>=1;
    }
    return c;
}
void solve()
{
    int q; cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        upd(i,x);
    }
    while(q--)
    {
        int ty; cin>>ty;
        if(ty==1)
        {
            int idx,val; cin>>idx>>val;
            idx--;
            upd(idx,val);
        }
        else
        {
            int a,b; cin>>a>>b;
            --a; --b;
            cout<<qur(a,b)<<endl;
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
