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
bool flag=true;;
void dfs(int i,int p,vi& vis,vi adj[],vi & ans){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
            ans[it]=1-ans[i];
            dfs(it,i,vis,adj,ans);
        }
        else if(it!=p){
            if(ans[i]==ans[it]){
                flag=false;
            }
        }
    }
}
int32_t main(){
    fastIO
    int n,m;
    cin>>n>>m;
    vi ans(n);
    vi adj[n];
    fron(i,m){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi vis(n);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans[i]=0;
            dfs(i,-1,vis,adj,ans);
        }
    }
    if(flag){
        for(auto it:ans){
            cout<<it+1<<" ";
        }
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
 
}
