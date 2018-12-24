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

int n,m,k,x,y,c;
void Next() {
  if(x%2==1 && y<m) {y++; return;}
  if(x%2==0 && y>1) {y--; return;}
  x++;
}

int main() {
  debugMode();
  //Code here
  scanf("%d %d %d",&n,&m,&k);
  x=y=1;
  rep(t,k) {
    if(t<k-1) {
      printf("2 ");
      printf("%d %d ",x,y);
      Next();
      printf("%d %d\n",x,y);
      Next();
      c+=2;
    } else {
      printf("%d ",n*m-c);
      rep(u,n*m-c) {
        printf("%d %d ",x,y);
        Next();
      }
    }
  }
  return 0;
}