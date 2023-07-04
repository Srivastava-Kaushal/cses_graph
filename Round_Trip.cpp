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
vi ans;
bool dfs(int i,int p, vi &vis,vi adj[]){
    vis[i]=1;
    ans.pb(i);
    for(auto it:adj[i]){
        if(!vis[it]){
            if(dfs(it,i,vis,adj)) return true;
        }
        else if(it!=p){
            ans.pb(it);
            return true;
        }
    }
    ans.pop_back();
    return false;
}
int32_t main(){
    fastIO
    int n,m;
    cin>>n>>m;
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
    bool flag=false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,adj)){
                flag=true;
                break;
            }
        }
    }
    if(flag){
        vi sol;
        sol.pb(ans[sz(ans)-1]);
        for(int i=sz(ans)-2;i>=0;i--){
            sol.pb(ans[i]);
            if(ans[i]==ans[sz(ans)-1]){
                break;
            }
        }
        cout<<sz(sol)<<endl;
        for(auto it:sol){
            cout<<it+1<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}
