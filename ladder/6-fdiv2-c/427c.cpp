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
const int Mod = 1000000007;
const int N = 100005;
int n, m, u, v, c[N],ch[N],cmp,Min,num;
LL sum, ans;
vector <int> g[N], h[N];
vector <int> cat[N];
stack <int> s;

void dfs(int x) {
  ch[x] = 1;
  for(auto y : g[x])
    if(!ch[y])
      dfs(y);
  s.push(x);
}

void dfs2(int x) {
  ch[x] = 0;
  cat[cmp].push_back(c[x]);
  for(auto y : h[x])
    if(ch[y])
      dfs2(y);
}

int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  foru(i, 1, n+1) scanf("%d",c+i);
  scanf("%d",&m);
  rep(_, m) {
    scanf("%d %d",&u,&v);
    g[u].push_back(v);
    h[v].push_back(u);
  }
  foru(i, 1, n+1) if(!ch[i]) dfs(i);
  while(!s.empty()) {
    while(!s.empty() && !ch[s.top()]) s.pop();
    if(!s.empty()) {
      dfs2(s.top());
      cmp++;
    }
  }
  sum = 0, ans = 1ll;
  rep(i, cmp) {
    Min = *min_element(cat[i].begin(),cat[i].end());
    num = count_if(cat[i].begin(),cat[i].end(),
          [](int x)->bool{return x==Min;});
    sum += Min, ans *= num, ans %= Mod;
  }
  printf("%lld %lld\n",sum,ans);
  return 0;
}