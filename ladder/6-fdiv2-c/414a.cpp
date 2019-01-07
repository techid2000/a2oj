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
const int Lim = 1e8;
int n,k,x;
vector <LL> v;

bool valid(int k) {
  if(k==x||k==2*x||k+1==x||k+1==2*x) return false;
  return true;
}

//Super Constructive!
int main() {
  debugMode();
  //Code here
  scanf("%d %d",&n,&k);
  if(n == 1 && k == 0) {
    printf("1\n");
    return 0;
  }
  if(k<n/2) {
    printf("-1\n");
    return 0;
  }
  x = k-(n-2)/2;
  if(x > 0) {
    if(n < 2) {
      printf("-1\n");
      return 0;
    }
    printf("%d %d ",x,2*x);
    int x = 1;
    rep(_, (n-2)/2) {
      while(!valid(x)) x++;
      printf("%d %d ",x,x+1);
      x += 2;
    }
    if(n % 2 == 1) {
      while(!valid(x)) x++;
      printf("%d ",x);
    }
  }
  return 0;
}