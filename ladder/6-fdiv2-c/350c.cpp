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

int n,x,y,a,b;
vector<pair<int,int>>v;

int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  rep(i, n) {
    scanf("%d%d",&x,&y);
    v.push_back(make_pair(x,y));
    if(x==0 || y==0) a++;
    else b++;
  }
  auto cmp = [](PII &a, PII &b) {
    return abs(a.X)+abs(a.Y) < abs(b.X)+abs(b.Y);
  };
  sort(v.begin(),v.end(),cmp);
  printf("%d\n",a*4 + b*6);
  for(auto &x:v) {
    if(x.X!=0)
      printf("1 %d %c\n",abs(x.X),x.X<0?'L':'R');
    if(x.Y!=0)
      printf("1 %d %c\n",abs(x.Y),x.Y<0?'D':'U');
    printf("2\n");
    if(x.X!=0)
      printf("1 %d %c\n",abs(x.X),x.X<0?'R':'L');
    if(x.Y!=0)
      printf("1 %d %c\n",abs(x.Y),x.Y<0?'U':'D');
    printf("3\n");
  }
}