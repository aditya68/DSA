#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
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
#define endl '\n'
const int inf=1e18;
const int mod=1e9+7;
const int N=1e5+5;
vii v[N];
void solve()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,wt; cin>>a>>b>>wt;
        --a; --b;
        v[a].pb({b,wt});
    }
    int d[n];
    for(int i=0;i<n;i++)d[i]=inf;
    set <pii> st; d[0]=0;
    st.insert({0,0});
    while(!st.empty())
    {
        pii p=*st.begin();
        st.erase(st.begin());
        int t=p.Y;
        for(int i=0;i<v[t].size();i++)
        {
            int ch=v[t][i].X,wt=v[t][i].Y;
            if(d[t]+wt>=d[ch])continue;
            st.erase({d[ch],ch});
            d[ch]=d[t]+wt;
            st.insert({d[ch],ch});
        }
    }
    for(int i=0;i<n;i++)cout<<d[i]<<" ";
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
