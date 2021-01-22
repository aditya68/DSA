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
const int N=1e5+5;
void solve()
{
    string s; cin>>s;
    int n=s.size();
    vector <int> phi(n,0);
    cout<<0<<" ";
    for(int i=1;i<n;i++)
    {
        int j=phi[i-1];
        while(j>0&&s[i]!=s[j])j=phi[j-1];
        if(s[i]==s[j])j++;
        phi[i]=j;
        cout<<phi[i]<<" ";
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
