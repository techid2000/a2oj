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
LL r,g,b;
int main() {
  debugMode();
  //Code here
  scanf("%lld%lld%lld",&r,&g,&b);
  if(r > g) swap(r,g);
  if(g > b) swap(g,b);
  if(r > g) swap(r,g);
  if(2*(r+g) <= b) {
    printf("%lld\n", r+g);
  } else {
    printf("%lld\n",(r+g+b)/3);
  }
  return 0;
}