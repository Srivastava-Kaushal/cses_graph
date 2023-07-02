#include<bits/stdc++.h>
#define endl "\n"
#define fron(i,n) for(int i=0;i<n;i++)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define sz(s) s.size()
#define rep(i,x,y) for(int i=x; i<y; i++)
#define mod 1000000007ll //998244353ll
#define pb push_back 
#define eb emplace_back
#define vi vector<int>
#define fill(a,b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
#define mii map<int , int>
#define uniq(s) s.resize(unique(s.begin(), s.end()) - s.begin())
#define hi int t;cin>>t;while(t--)
using namespace std;
int bpow(int a, int b)
{
 a %= mod;
 int res = 1;
  while (b > 0)
  {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
 
//--------------------------------CODE STARTS HERE----------------------------------------
void dfs(int i,vi & vis, vi adj[]){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it,vis,adj);
        }
    }
}
int32_t main(){
    fastIO
    int n,m;
    cin>>n>>m;
    vi adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi vis(n);
    vi ans;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans.pb(i);
            dfs(i,vis,adj);
        }
    }
    cout<<sz(ans)-1<<endl;
    for(int i=1;i<sz(ans);i++){
        cout<<ans[0]+1<<" "<<ans[i]+1<<endl;
    }
}
