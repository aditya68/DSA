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
vi v[N];
int vis[N];
int st=-1,ed;
void dfs(int t)
{
    vis[t]=1;
    for(int i=0;i<v[t].size();i++)
    {
        int ch=v[t][i];
        if(vis[ch]==2)continue;
        if(!vis[ch])dfs(ch);
        else  // This is a Back edge.
        {
            st=ch+1; ed=t+1;
        }
    }
    vis[t]=2;
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
    }
    for(int i=0;i<n;i++)if(!vis[i])dfs(i);
    if(st==-1)
    {
        cout<<"NO CYCLE in the graph!!";
        return;
    }
    cout<<st<<" "<<ed;
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
