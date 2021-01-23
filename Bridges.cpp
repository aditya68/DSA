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
int tin[N],mn[N];
bool vis[N];
vii bdg;
int timer=1;
void dfs(int t,int p)
{
    vis[t]=1; tin[t]=mn[t]=timer++;
    for(int i=0;i<v[t].size();i++)
    {
        int ch=v[t][i];
        if(ch==p)continue;
        if(!vis[ch])
        {
            dfs(ch,t);
            mn[t]=min(mn[t],mn[ch]);
            if(mn[ch]>tin[t])bdg.pb({t+1,ch+1});
        }
        else mn[t]=min(mn[t],mn[ch]);
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
        v[b].pb(a);
    }
    for(int i=0;i<n;i++)if(!vis[i])dfs(i,-1);
    for(int i=0;i<bdg.size();i++)cout<<bdg[i].X<<" "<<bdg[i].Y<<endl;
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
