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
int n,m,t;
vector <PII> a;
vector <int> b,c;

int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  foru(i,1,n) {
    scanf("%d",&m);
    a.push_back({m,i});
  }
  sort(begin(a),end(a));
  for(auto & [x,y] : a) {
    if(t == 0) b.push_back(y);
    else c.push_back(y);
    t ^= 1;
  }
  printf("%d\n",b.size());
  for(auto x : b) printf("%d ",x);
  printf("\n%d\n",c.size());
  for(auto x : c) printf("%d ",x);
  return 0;
}