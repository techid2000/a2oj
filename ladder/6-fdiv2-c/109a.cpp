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
int n;
int a[1000006];
int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  a[0]=0;
  foru(i,1,n+1){
    a[i]=-1e9;
    if(i-4>=0) a[i]=a[i-4];
    if(i-7>=0) a[i]=max(a[i],a[i-7]+1);
  }
  if(a[n]<0) {
    printf("-1\n");
  } else {
    rep(i,(n-7*a[n])/4) {
      putchar('4');
    }
    rep(i,a[n]) {
      putchar('7');
    }
  }
  return 0;
}