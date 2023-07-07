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
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>> adj[n];
  for(int i=0;i<m;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    u--;
    v--;
    adj[u].pb({v,-wt});
  }
  vi shortpath(n,1e17);
  shortpath[0]=0;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n;j++){
      for(auto it:adj[j]){
        int node=it.first;
        int step=it.second;
        if(shortpath[node]>shortpath[j]+step&&shortpath[j]!=1e17){
          shortpath[node]=shortpath[j]+step;
        }
      }
    }
  }
  bool flag=true;
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++){
    for(auto it:adj[j]){
      int node=it.first;
      int step=it.second;
      if(shortpath[node]>shortpath[j]+step&&shortpath[j]!=1e17){
        shortpath[node]=-1e17;
      }
    }
  }
  if(shortpath[n-1]>-1e17&&shortpath[n-1]<1e17){
    cout<<-shortpath[n-1]<<endl;
  }
  else{
    cout<<-1<<endl;
  }
 
}
