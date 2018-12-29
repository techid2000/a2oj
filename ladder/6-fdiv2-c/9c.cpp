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
int n,m;
int a[20];
int x[20][2], y[20][2];

void f(int k) {
  if(k==0) return;
  f(k/10);
  a[m++]=k%10;
}

int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  f(n);
  if(a[0]>1) {
    y[0][0]=y[0][1]=1;
  } else {
    x[0][1]=y[0][0]=1;
  }
  foru(i, 1, m) {
    y[i][0]=y[i][1]=y[i-1][0]+y[i-1][1];
    if(a[i]==0) {
      x[i][0]+=x[i-1][1]+x[i-1][0];
    } else if(a[i]==1) {
      x[i][1]+=x[i-1][0]+x[i-1][1];
      y[i][0]+=x[i-1][0]+x[i-1][1];
    } else {
      y[i][1]+=x[i-1][0]+x[i-1][1];
      y[i][0]+=x[i-1][0]+x[i-1][1];
    }
  }
  printf("%d\n",(x[m-1][0]+x[m-1][1])+(y[m-1][0]+y[m-1][1]-1));
  return 0;
}