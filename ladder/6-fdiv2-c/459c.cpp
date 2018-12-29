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
int n,k,d,t,o,a,b,s,e;
int ar[1005];
queue <pair<int,pair<int,int>>> q;
vector<vector<int>>v;
int main() {
  debugMode();  
  //Code here
  scanf("%d%d%d",&n,&k,&d);
  if(k==1 && n>1) {
    printf("-1\n");
    return 0;
  }
  if(k>=n) {
    rep(D,d) {
      rep(i, n) {
        printf("%d ",i+1);
      }
      printf("\n");
    }
    return 0;
  }
  q.push(make_pair(0,make_pair(0,n-1)));
  fill(ar,ar+n,k-1);
  while(!q.empty()) {
    o=q.front().X;
    a=q.front().Y.X;
    b=q.front().Y.Y;
    q.pop();
    if(a==b) continue;
    if(o>t) {
      vector<int> w(ar,ar+n);
      v.push_back(w);
      t++;
    }
    foru(i,1,k+1) {
      if(i==1) s=a;
      e=a+i*(b-a)/k;
      if(s>e)continue;
      foru(j,s,e+1) {
        ar[j]+=i;
        ar[j]%=k;
      }
      q.push(make_pair(o+1,make_pair(s,e)));
      s=e+1;
    }
  }
  vector<int> w(ar,ar+n);
  v.push_back(w);
  if(d>=v.size()) {
    for(auto &in:v) {
      for(auto i:in) {
        printf("%d ",i+1);
      }
      d--;
      printf("\n");
    }
    while(d--) {
      for(auto i:v.back()) {
        printf("%d ",i+1);
      }
      printf("\n");
    }
  } else {
    printf("-1\n");
  }
  return 0;
}