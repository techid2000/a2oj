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
#define DEBUG_MODE

int main() {
#if defined(DEBUG_MODE) && !defined(ONLINE_JUDGE)
  freopen("iofiles/in.txt","r",stdin);
  freopen("iofiles/out.txt","w",stdout);
#endif
  //Code here
  int n,m,M;
  cin>>n>>m;
  M=m;
  if(m>2*(n+1) || m+1<n) {
    cout<<-1;
  } else {
    string ans="";
    rep(i, n) {
      if(i==n-1) {
        ans+="0";
      } else if(i<M-(n-1)) {
        ans+="011";
        m-=2;
      } else {
        ans+="01";
        m-=1;
      }
    }
    if(m>=3){
      ans="11"+ans;
      rep(i,m-2) ans+="1";
    } else {
      rep(i,m) ans+="1";
    }
    cout << ans;
  }
  return 0;
}