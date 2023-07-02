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
    vector<vector<char>>a(n,vector<char>(m));
    pair<int,int> start;
    vector<string> vs(n);
    for(int i=0;i<n;i++){
        cin>>vs[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vs[i][j]=='A'){
                start={i,j};
            }
        }
    }
    string v2;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    string s="";
    queue<pair<int,int>> q;
    q.push({start.first,start.second});
    vis[start.first][start.second]=1;
    bool flag=false;
    char arr[n][m];
    int endx=0,endy=0;
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        int dx[]={-1,0,+1,0};
        int dy[]={0,+1,0,-1};
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0&&y>=0&&x<n&&y<m&&!vis[x][y]&&vs[x][y]!='#'){
                vis[x][y]=1;
                q.push({x,y});
                if(k==0){
                    arr[x][y]='U';
                }
                else if(k==1){
                    arr[x][y]='R';
                }
                else if(k==2){
                    arr[x][y]='D';
                }
                else if(k==3){
                    arr[x][y]='L';
                }
                if(vs[x][y]=='B'){
                    endx=x;
                    endy=y;
                    flag=true;
                    break;
                }
            }
        }
        if(flag) break;
    }
    if(flag){
        cout<<"YES"<<endl;
        vector<char> ans;
        while(endx!=start.first||endy!=start.second){
            if(arr[endx][endy]=='U'){
                endx++;
                ans.pb('U');
            }
            else if(arr[endx][endy]=='R'){
                endy--;
                ans.pb('R');
            }
            else if(arr[endx][endy]=='D'){
                endx--;
                ans.pb('D');
            }
            else if(arr[endx][endy]=='L'){
                endy++;
                ans.pb('L');
            }
        }
        reverse(all(ans));
        cout<<sz(ans)<<endl;
        for(auto it:ans){
            cout<<it;
        }
        cout<<endl;
    }
    else cout<<"NO"<<endl;
}
