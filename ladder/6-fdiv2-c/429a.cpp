//Author: techid2000
#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,a) for(int i=0;i<a;i++)
#define minheap(x) x,vector<x>,greater<x>
#define X first
#define Y second
#define watch(x) cout<<#x<<" = "<<x<<'\n'
using namespace std;
using PII = pair<int,int>;
using LL = long long;
template<class T,class U>inline void amin(T& x, U y){x=min(x,y);}
template<class T,class U>inline void amax(T& x, U y){x=max(x,y);}
ifstream fin("iofiles/in.txt");
ofstream fout("iofiles/out.txt");
inline void redirect() {
#ifndef ONLINE_JUDGE
  cin.rdbuf(fin.rdbuf()); cout.rdbuf(fout.rdbuf());
#endif
}
const int N = 100005;
int n,u,v,init[N],goal[N],diff[N];
vector <int> g[N],ver;

void dfs(int x,int p,int d,int e,int o) {
  if(d % 2 == 0) {
    if(e^diff[x]) {
      e ^= 1;
      ver.push_back(x);
    }
  } else {
    if(o^diff[x]) {
      o ^= 1;
      ver.push_back(x);
    } 
  }
  for(auto y : g[x]) {
    if(y != p) {
      dfs(y, x, d+1, e, o);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  redirect();
  //Code here
  cin >> n;
  rep(_,n-1) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  foru(i, 1, n) cin >> init[i];
  foru(i, 1, n) {
    cin >> goal[i];
    if(init[i]!=goal[i]) {
      diff[i] = 1;
    }
  }
  dfs(1,0,0,0,0);
  cout << ver.size() << '\n';
  for(auto x:ver) cout << x << '\n';
  return 0;
}