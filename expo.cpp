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
// takes O(log(exp)) time.
int pw(int bs,int exp)
{
    if(!exp)return 1;
    int t=pw(bs,exp/2);
    if(exp%2)return (((t*t)%mod)*bs)%mod;
    return (t*t)%mod;
}
void solve()
{
    cout<<pw(2,30);
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
