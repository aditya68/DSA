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
const int inf=2e9;
const int mod=1e9+7;
const int N=1e5+5;
int ncr[65][65];
void init()
{
    ncr[1][0]=ncr[1][1]=1;
    for(int i=2;i<65;i++)for(int j=0;j<=i;j++)
    {
        if(!j)
        {
            ncr[i][j]=1;
            continue;
        }
        ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
    }
    return;
}
void solve()
{
    init();
    cout<<ncr[5][2];
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
