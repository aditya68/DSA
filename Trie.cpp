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
int tre[N][26];
int cnt[N],leaf[N];
int vt=1;
void insrt(string s)
{
    int node=0;
    for(int i=0;i<s.size();i++)
    {
        int k=s[i]-'a';
        if(!tre[node][k])tre[node][k]=vt++;
        node=tre[node][k];
        cnt[node]++;
    }
    leaf[node]++;
    return;
}
void rmv(string s)
{
    int node=0;
    for(int i=0;i<s.size();i++)
    {
        int k=s[i]-'a';
        node=tre[node][k];
        cnt[node]--;
    }
    leaf[node]--;
    return;
}
bool isprs(string s)
{
    int node=0;
    for(int i=0;i<s.size();i++)
    {
        int k=s[i]-'a';
        if(!tre[node][k])return 0;
        node=tre[node][k];
        if(!cnt[node])return 0;
    }
    if(!leaf[node])return 0;
    return 1;
}
void solve()
{
    int q; cin>>q;
    while(q--)
    {
        int ty; cin>>ty;
        string s; cin>>s;
        if(ty==1)insrt(s);
        else if(ty==2)rmv(s);
        else
        {
            if(isprs(s))cout<<"YES";
            else cout<<"NO";
            cout<<endl;
        }
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
