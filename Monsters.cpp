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
    vector<string> vs(n);
    fron(i,n){
        cin>>vs[i];
    }
    vector<vector<bool>>vis2(n,vector<bool>(m,0));
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    int start_x=0;
    int start_y=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vs[i][j]=='A'){
                start_x=i;
                start_y=j;
            }
        }
    }
    char arr[n][m];
    bool flag=false;
    vector<vector<int>> time(n,vector<int>(m,1e18));
    queue<pair<int,pair<int,int>>>q2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vs[i][j]=='M'){
                q2.push({0,{i,j}});
                time[i][j]=0;
            }
            if(vs[i][j]=='#'){
                time[i][j]=0;
            }
        }
    }
    while(!q2.empty()){
        auto i=q2.front();
        q2.pop();
        int timer=i.first;
        int x_cod=i.second.first;
        int y_cod=i.second.second;
        int dx[]={-1,0,+1,0};
        int dy[]={0,-1,0,+1};
        for(int k=0;k<4;k++){
            int n_x_cod=x_cod+dx[k];
            int n_y_cod=y_cod+dy[k];
            if(n_x_cod>=0&&n_y_cod>=0&&n_x_cod<n&&n_y_cod<m&&!vis2[n_x_cod][n_y_cod]&&vs[n_x_cod][n_y_cod]=='.'){
                vis2[n_x_cod][n_y_cod]=1;
                q2.push({timer+1,{n_x_cod,n_y_cod}});
                time[n_x_cod][n_y_cod]=timer+1;
            }
        }
    }
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{start_x,start_y}});
    int endx=0,endy=0;
    while(!q.empty()){
        int timer=q.front().first;
        int i=q.front().second.first;
        int j=q.front().second.second;
        q.pop();
        int dx[]={-1,0,+1,0};
        int dy[]={0,+1,0,-1};
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0&&y>=0&&x<n&&y<m&&!vis[x][y]&&((timer+1)<time[x][y])){
                vis[x][y]=1;
                q.push({timer+1,{x,y}});
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
                if(x==n-1||y==m-1||x==0||y==0){
                    endx=x;
                    endy=y;
                    flag=true;
                    break;
                }
            }
        }
        if(flag) break;
    }
    if(start_x==0||start_x==n-1||start_y==0||start_y==m-1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
    }
    else if(flag){
        cout<<"YES"<<endl;
        vector<char> ans;
        while(endx!=start_x||endy!=start_y){
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
