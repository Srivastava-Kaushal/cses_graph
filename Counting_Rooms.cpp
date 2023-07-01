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
 
//--------------------------------CODE STARTS HERE----------------------------------------
vector<vector<bool>>v;
int n,m;
void dfs(int i,int j,vector<vector<bool>>&visited,int dx[],int dy[]){
    visited[i][j]=1;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 and x<n and y>=0 and y<m and !visited[x][y] and v[x][y]){
            dfs(x,y,visited,dx,dy);
        }
    }
 
}
 
 
 
int32_t main(){
    fastIO
    cin>>n>>m;
    for(int i=0;i<n;i++){
        vector<bool>v1;
        for(int i=0;i<m;i++){
            char a;
            cin>>a;
            if(a=='#')
            v1.pb(0);
            else
            v1.pb(1);
        }
        v.pb(v1);
    }
    int dx[]={-1,0,+1,0};
    int dy[]={0,+1,0,-1};
    int cnt=0;
    vector<vector<bool>>visited(n,vector<bool>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&v[i][j]==1){
                dfs(i,j,visited,dx,dy);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
 
    
}
