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
bool ispr[N];
void solve()
{
    // Sieve of Eratosthenes.
    // takes O(Nloglog(N)) time
    for(int i=1;i<N;i++)ispr[i]=1;
    for(int i=2;i<N;i++)
    {
        if(!ispr[i])continue;
        for(int j=2*i;j<N;j+=i)ispr[j]=0;
    }
    cout<<ispr[23]<<" "<<ispr[31]<<" "<<ispr[32];
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
