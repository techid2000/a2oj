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
const int N = 2005;
int n,p,q,r,s;
int a[N][N];
LL x[N][N],y[N][N],z[N][N],Max1,Max2;
int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  foru(i,1,n+1) {
    foru(j,1,n+1) {
      scanf("%d",&a[i][j]);
    }
  }
  foru(i,1,n+1) {
    foru(j,1,n+1) {
      x[i][j]=a[i][j]+x[i-1][j-1];
      y[i][j]=a[i][j]+y[i-1][j+1];
    }
  }
  foru(i,1,n+1) {
    foru(j,1,n+1) {
      z[i][j]=x[i-1][j-1]-x[i-min(i,j)][j-min(i,j)]+
              y[i-1][j+1]-y[i-min(i,n-j+1)][j+min(i,n-j+1)]+
              x[i+min(n-i,n-j)][j+min(n-i,n-j)]-x[i][j] +
              y[i+min(n-i,j-1)][j-min(n-i,j-1)]-y[i][j] + a[i][j];
    }
  }
  foru(i,1,n+1) {
    foru(j,1,n+1) {
      if((i+j)%2==0) {
        if(z[i][j]>=Max1) {
          Max1=z[i][j];
          p=i, q=j;
        }
      } else {
        if(z[i][j]>=Max2) {
          Max2=z[i][j];
          r=i, s=j;
        }
      }
    }
  }
  printf("%lld\n",Max1+Max2);
  printf("%d %d %d %d\n",p,q,r,s);
  return 0;
}
