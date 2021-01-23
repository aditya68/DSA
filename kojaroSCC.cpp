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
const int inf=2e9;
const int mod=1e9+7;
const int N=1e5+5;
vi v[N],gp[N];
bool vis[N];
vi odr,cmp;
void dfs1(int t)
{
    vis[t]=1;
    for(int i=0;i<v[t].size();i++)
    {
        int ch=v[t][i];
        if(vis[ch])continue;
        dfs1(ch);
    }
    odr.pb(t);
    return;
}
void dfs2(int t)
{
    vis[t]=1; cmp.pb(t+1);
    for(int i=0;i<gp[t].size();i++)
    {
        int ch=gp[t][i];
        if(vis[ch])continue;
        dfs2(ch);
    }
    return;
}
void solve()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        --a; --b;
        v[a].pb(b);
        gp[b].pb(a);
    }
    for(int i=0;i<n;i++)if(!vis[i])dfs1(i);
    memset(vis,0,sizeof(vis));
    for(int i=odr.size()-1;i>=0;i--)
    {
        int t=odr[i];
        if(vis[t])continue;
        dfs2(t);
        for(int j=0;j<cmp.size();j++)cout<<cmp[j]<<" ";
        cout<<endl;
        cmp.clear();
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
