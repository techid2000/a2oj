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
const int Mod = (1e9)+7;
LL ans=1ll;
int n,m;
char c;
set<char>s[105];
int main() {
  debugMode();
  //Code here
  scanf("%d%d",&n,&m);
  rep(i,n) {
    rep(j,m) {
      scanf(" %c",&c);
      s[j].insert(c);
    }
  }
  rep(i,m) {
    ans*=(LL)s[i].size();
    ans%=Mod;
  }
  printf("%lld\n",ans);
  return 0;
}