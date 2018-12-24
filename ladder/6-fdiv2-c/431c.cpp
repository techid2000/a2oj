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

const int mod = (1e9) + 7;
LL a[105],b[105];

int main() {
  debugMode();
  //Code here
  int n,k,d;
  scanf("%d%d%d",&n,&k,&d);
  a[0] = 1;
  foru(i, 1, n+1) {
    foru(j, 1, k+1) {
      if(i-j>=0) {
        if(j >= d) {
          b[i] += b[i-j];
          b[i] += a[i-j];
        } else {
          b[i] += b[i-j];
          a[i] += a[i-j];
        }
        a[i]%=mod, b[i]%=mod;
      }
    }
  }
  printf("%d\n",b[n]);
  return 0;
}