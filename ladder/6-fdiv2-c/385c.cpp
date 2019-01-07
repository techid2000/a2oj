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
const int MAX = (1e7)+5;
int u,v,m,n,r;
int cnt[MAX];
int sieve[MAX];
int qs[MAX];
int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  rep(i, n) {
    scanf("%d",&u);
    cnt[u]++;
  }
  scanf("%d",&m);
  for(int i=2; i<MAX; i++) {
    if(!sieve[i]) {
      for(int j=i; j<MAX; j+=i) {
        qs[i]+=cnt[j];
        sieve[j]=1;
      }
    }
  }
  foru(i,1,MAX) {
    qs[i]+=qs[i-1];
  }
  while(m--) {
    scanf("%d %d",&u,&v);
    if(u > 1e7) printf("0\n");
    else {
      if(v >= MAX) v=MAX-1;
      printf("%d\n",qs[v]-qs[u-1]);
    }
  }
  return 0;
}