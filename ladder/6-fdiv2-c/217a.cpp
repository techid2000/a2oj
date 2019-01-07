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
int n,x,y,p[105];
int lx[1005],ly[1005]; 
set <int> s;

int Find(int x) {
  if(p[x]==x) return x;
  return p[x]=Find(p[x]);
}
void Merge(int a,int b) {
  int u=Find(a),v=Find(b);
  if(u!=v) p[v]=u;
}

int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  iota(p,p+n,0);
  fill(lx,lx+1005,-1);
  fill(ly,ly+1005,-1);
  rep(i, n) {
    scanf("%d %d",&x,&y);
    if(lx[x]!=-1) Merge(i, lx[x]);
    if(ly[y]!=-1) Merge(i, ly[y]);
    lx[x]=i;
    ly[y]=i;
  }
  rep(i, n) s.insert(Find(i));
  printf("%d\n",s.size()-1);
  return 0;
}