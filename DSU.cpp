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
#define endl '\n'
const int inf=2e9;
const int N=1e6+5;
int pr[N],sz[N];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        pr[i]=i;
        sz[i]=1;
    }
    return;
}
int root(int a)
{
    if(pr[a]==a)return a;
    return root(pr[a]);
}
bool Union(int a,int b)
{
    int ra=root(a);
    int rb=root(b);
    if(ra==rb)return 0;
    if(sz[rb]>sz[ra])swap(ra,rb);
    pr[rb]=ra;
    sz[ra]+=sz[rb];
    return 1;
}
int comp(n)
{
    int c=0;
    for(int i=0;i<n;i++)if(pr[i]==i)c++;
    return c;
}
void solve()
{
    init();
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
