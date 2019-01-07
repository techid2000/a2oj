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

int n, x, y, Max, last, cnt;
vector <PII> a, b;

int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  rep(_, n) {
    scanf("%d %d",&x,&y);
    a.push_back({x, y});
  }
  sort(a.begin(), a.end());
  rep(i, n) {
    if(i>0 && a[i].X!=a[i-1].X)
      last = Max;
    Max = max(Max, a[i].Y);
    if(a[i].Y < last) {
      cnt++;
    }
  }
  printf("%d\n",cnt);
}