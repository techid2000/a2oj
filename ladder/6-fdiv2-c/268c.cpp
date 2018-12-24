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
int main() {
  debugMode();
  //Code here
  int n,m,j=0;
  scanf("%d%d",&n,&m);
  printf("%d\n",min(n,m)+1);
  ford(i, m, -1) {
    if(j>n) break;
    printf("%d %d\n",j,i);
    j++;
  }
  return 0;
}