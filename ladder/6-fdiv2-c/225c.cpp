//Author: techid2000
#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,a) for(int i=0;i<a;i++)
#define minheap(x) x,vector<x>,greater<x>
#define X first
#define Y second
using namespace std;
using PII = pair<int,int>;
using LL = long long;
template<typename T,typename U>inline void amin(T& x, U y){x=min(x,y);}
template<typename T,typename U>inline void amax(T& x, U y){x=max(x,y);}
inline void debugMode() {
#ifndef ONLINE_JUDGE
  freopen("iofiles/in.txt","r",stdin);
  freopen("iofiles/out.txt","w",stdout);
#endif
}
int n,m,x,y,now,bef,ans,cost;
int col[1005];
int dp[1005][2][1005];
char a;
int main() {
  debugMode();
  //Code here
  scanf("%d %d %d %d",&n,&m,&x,&y);
  foru(i,1,n) {
    foru(j,1,m) {
      scanf(" %c",&a);
      if(a == '#')
        col[j]++;
    }
  }
  fill_n(&dp[0][0][0],1005*2*1005,1e9);
  dp[1][0][1] = col[1];
  dp[1][1][1] = n-col[1];
  foru(i,2,m) {
    foru(t,0,1) {
      cost = (t == 0 ? col[i] : n-col[i]);
      foru(j,1,m) {
        if(j>=x && j<=y)
          amin(dp[i][t][1],dp[i-1][1-t][j]+cost);
        if(j > 1)
          dp[i][t][j] = dp[i-1][t][j-1]+cost;
      }
    }
  } 
  ans = 1e9;
  foru(i,x,y) {
    amin(ans,min(dp[m][0][i],dp[m][1][i]));
  }
  printf("%d\n",ans);
  return 0;
}