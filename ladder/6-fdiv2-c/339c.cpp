//Author: techid2000
#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>b;i--)
#define rep(i,a) for(int i=0;i<a;i++)
#define PII pair<int,int>
#define LL long long
#define minheap(x) x,vector<x>,greater<x>
#define X first
#define Y second
using namespace std;
inline void debugMode() {
#ifndef ONLINE_JUDGE
  freopen("iofiles/in.txt","r",stdin);
  freopen("iofiles/out.txt","w",stdout);
#endif
}

struct A {
  int i,a,d;
};

char s[15];
vector<int>a;
int m,dp[1005][15][15];
A back[1005][15][15];

int Dp(int i,int a,int d) {
  if(i==m-1) {
    return dp[i][a][d]=1;
  }
  if(dp[i][a][d]!=-1)
    return dp[i][a][d];
  int k;
  for(auto j:(::a)) {
    if(j!=a && j-d > 0) {
      k = Dp(i+1, j, j-d);
      if(k==1) {
        back[i][a][d] = A{i+1, j, j-d};
        return dp[i][a][d]=1;
      }
    }
  }
  return dp[i][a][d]=0;
}

void Track(int i, int a,int d) {
  A &go = back[i][a][d];
  printf("%d ",a);
  if(i==m-1) return;
  Track(go.i, go.a, go.d);
}

int main() {
  debugMode();
  //Code here
  scanf(" %s",s);
  rep(i,10) {
    if(s[i]=='1')
      a.push_back(i+1);
  }
  scanf("%d",&m);
  memset(dp,-1,sizeof(dp));
  for(auto i:a) {
    Dp(0,i,i);
    if(dp[0][i][i]==1) {
      printf("YES\n");
      Track(0,i,i);
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}