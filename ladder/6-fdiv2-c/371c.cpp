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

char s[105];
LL ib,is,ic;
LL nb,ns,nc;
LL pb,ps,pc;
LL r,len;
LL lo,hi,mid,ans;
int main() {
  debugMode();
  //Code here
  scanf(" %s",s);
  len=strlen(s);
  scanf("%I64d %I64d %I64d",&nb,&ns,&nc);
  scanf("%I64d %I64d %I64d",&pb,&ps,&pc);
  scanf("%I64d",&r);
  rep(i, len) {
    if(s[i]=='B') ib++;
    if(s[i]=='S') is++;
    if(s[i]=='C') ic++;
  }
  lo=0, hi=1e15;
  while(lo<=hi) {
    mid=(lo+hi)>>1;
    if(max(0ll,mid*ib-nb)*pb+
      max(0ll,mid*is-ns)*ps+
      max(0ll,mid*ic-nc)*pc <= r) {
      ans=mid;
      lo=mid+1;
    } else {
      hi=mid-1;
    }
  }
  printf("%I64d\n",ans);
  return 0;
}