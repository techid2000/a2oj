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

int n,m,s,p;
int x[105],ch[105];

int main() {
  debugMode();
  //Code here
  scanf("%d", &n);
  rep(i, n) {
    scanf("%d",&x[i]);
  }
  sort(x,x+n);
  rep(i, n) {
    m = 0;
    rep(j, n) {
      if(!ch[j] && x[j]>=m) {
        ch[j]=1;
        m++;
        s++;
      }
    }
    p++;
    if(s==n) break;
  }
  printf("%d\n",p);
  return 0;
}