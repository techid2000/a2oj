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
const int N = 1e6 + 5;
int len, num;
int l[N], r[N];
char s[N];

void dfs(int node) {
  if(l[node] > 0 && l[node] <= num)
    dfs(l[node]);
  printf("%d\n",node);
  if(r[node] > 0 && r[node] <= num)
    dfs(r[node]);
}

int main() {
  debugMode();
  //Code here
  scanf(" %s",s+1);
  len = strlen(s+1);
  foru(i, 1, len) {
    num++;
    if(s[i] == 'l') l[num] = num+1;
    else r[num] = num+1;
  }
  dfs(1);
  return 0;
}