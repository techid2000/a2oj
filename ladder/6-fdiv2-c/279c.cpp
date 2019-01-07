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
inline void debugMode() {
#ifndef ONLINE_JUDGE
  freopen("iofiles/in.txt","r",stdin);
  freopen("iofiles/out.txt","w",stdout);
#endif
}
const int N = 100005;
int n,m,a[N],incr[N],decr[N];
int lo,hi,mid,l,r,aux;
int main() {
  debugMode();
  //Code here
  scanf("%d %d",&n, &m);
  foru(i, 1, n) {
    scanf("%d",&a[i]);
    if(i > 1) {
      if(a[i] > a[i-1]) {
        incr[i] = 1;
      } else if(a[i] < a[i-1]) {
        decr[i] = 1;
      }
    }
    incr[i] += incr[i-1];
    decr[i] += decr[i-1];
  }
  rep(_, m) {
    scanf("%d %d",&l,&r);
    if(r-l<=1) {printf("Yes\n"); continue;}
    lo = l, hi = r;
    aux = 0;
    while(lo <= hi) {
      mid = (lo + hi) >> 1;
      if(decr[mid]-decr[l] == 0 && incr[r]-incr[mid] == 0) {
        aux = 1;
        printf("Yes\n");
        break;
      }
      if(decr[mid]-decr[l]>0) hi = mid-1;
      else {
        if(incr[r]-incr[mid]>0) lo = mid+1;
        else hi = mid-1;
      }
    }
    if(aux == 0) printf("No\n");
  }
  return 0;
}