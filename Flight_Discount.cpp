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
    vector<pair<int,int>>adj[n];
    vector<pair<int,int>>adj2[n];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        u--;
        v--;
        adj[u].pb({v,wt});
        adj2[v].pb({u,wt});
    }
    vi shortpath(n,1e18);
    shortpath[0]=0;
    vi shortpathrev(n,1e18);
    set<pair<int,int>> st;
    st.insert({0,0});
    while(!st.empty()){
        auto i=st.begin();
        int steps=i->first;
        int node=i->second;
        st.erase(i);
        for(auto it:adj[node]){
            if(shortpath[it.first]>steps+it.second){
                st.erase({shortpath[it.first],it.first});
                shortpath[it.first]=steps+it.second;
                st.insert({shortpath[it.first],it.first});
            }
        }
    }
    st.insert({0,n-1});
    shortpathrev[n-1]=0;
    while(!st.empty()){
        auto i=st.begin();
        int steps=i->first;
        int node=i->second;
        st.erase(i);
        for(auto it:adj2[node]){
            if(shortpathrev[it.first]>steps+it.second){
                st.erase({shortpathrev[it.first],it.first});
                shortpathrev[it.first]=steps+it.second;
                st.insert({shortpathrev[it.first],it.first});
            }
        }
    }
    int ans=1e18;
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            int node=it.first;
            int wt=it.second;
            ans=min(ans,shortpath[i]+shortpathrev[node]+wt/2);
        }
    }
    cout<<ans<<endl;
}
