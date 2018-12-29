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
int n,a[100005],far,ch;
int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  foru(i, 1, n+1) scanf("%d",a+i);
  far = 1;
  a[0] = INT_MIN;
  a[n+1] = INT_MAX;
  foru(i, 1, n+1) {
    if(i>1 && a[i]!=a[i-1]) {
      far = i;
    }
    if(i<n && a[i+1]<a[i]) {
      ford(j, n, i) {
        if(a[j] < a[i]) {
          swap(a[far],a[j]);
          ch=1;
          foru(k, 1, n+1) {
            if(k<n && a[k+1]<a[k]) {
              ch=0;
              break;
            }
          }
          if(ch) {
            printf("YES\n");
            return 0;
          }
          swap(a[far],a[j]);
          printf("NO\n");
          return 0;
        }
      }
    }
  }
  printf("YES\n");
  return 0;
}