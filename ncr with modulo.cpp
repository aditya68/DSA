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
int fac[N],invfac[N];
int pw(int bs,int exp)
{
    if(!exp)return 1;
    int t=pw(bs,exp/2);
    if(exp%2)return (((t*t)%mod)*bs)%mod;
    return (t*t)%mod;
}
void init()
{
    fac[0]=1;
    for(int i=1;i<N;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
    }
    // inverse modulo using Fermat's theorem
    invfac[N-1]=pw(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--)
    {
        invfac[i]=(i+1)*invfac[i+1];
        invfac[i]%=mod;
    }
    return;
}
int ncr(int n,int r)
{
    if(n<=0||r<0||r>n)return 0;
    return fac[n]*invfac[r]%mod*invfac[n-r]%mod;
}
void solve()
{
    init();
    cout<<ncr(5,2);
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
