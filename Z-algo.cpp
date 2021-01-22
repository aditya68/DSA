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
    vector <int> z(n,0);
    int x=0,y=0;
    cout<<z[0]<<" ";
    for(int i=1;i<n;i++)
    {
        z[i]=max(0,min(z[i-x],y-i+1));
        while(i+z[i]<n&&s[i+z[i]]==s[z[i]])
        {
            x=i; y=i+z[i]; z[i]++;
        }
        cout<<z[i]<<" ";
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
