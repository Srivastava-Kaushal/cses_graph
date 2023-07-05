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
int32_t main(){
    fastIO
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> dist(n,vector<int>(n,1e18));
    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        u--;
        v--;
        dist[u][v]=min(dist[u][v],wt);
        dist[v][u]=min(dist[v][u],wt);
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        if(min(dist[u][v],dist[v][u])==1e18) cout<<-1<<endl;
        else{
            cout<<min(dist[u][v],dist[v][u])<<endl;
        }
    }
}

