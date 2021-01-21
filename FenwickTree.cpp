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
int bit[N];
int n;
// update at index k.
void upd(int k,int val)
{
    k++;
    for(;k<=n;k+=k&-k)
        bit[k]+=val;
    return;
}
// prefix sum up to index k.
int qur(int k)
{
    k++;
    int c=0;
    for(;k>0;k-=k&-k)
        c+=bit[k];
    return c;
}
void solve()
{
    int q; cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        upd(i,a[i]);
    }
    while(q--)
    {
        int ty; cin>>ty;
        if(ty==1)
        {
            int idx,val; cin>>idx>>val;
            idx--;
            upd(idx,val-a[idx]);
            a[idx]=val;
        }
        else
        {
            int a,b; cin>>a>>b;
            --a; --b;
            int c=qur(b);
            if(a)c-=qur(a-1);
            cout<<c<<endl;
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
