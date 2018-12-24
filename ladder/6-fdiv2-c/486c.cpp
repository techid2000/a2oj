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
int MinStep(char x, char y) {
  if(x>y)swap(x,y);
  return min(y-x, x-'a'+'z'-y+1);
}
int len,n,p,sum,a,b,ch,Min;
char s[100005];
int main() {
  debugMode();
  //Code here
  scanf("%d%d",&n,&p);
  scanf(" %s",s+1);
  len=strlen(s+1);
  if(p<=len/2) {
    a=len/2, b=1, ch=0;
    foru(i, 1, len/2+1) {
      Min=MinStep(s[i],s[len-i+1]);
      if(Min>0) {
        a=min(a,i);
        b=max(b,i);
        ch=1;
      }
      sum += Min;
    }
  } else {
    a=len, b=len/2+1, ch=0;
    foru(i, len/2+1, len+1) {
      Min = MinStep(s[i],s[len-i+1]);
      if(Min > 0) {
        a=min(a,i);
        b=max(b,i);
        ch=1;
      }
      sum += Min;
    }
  }
  if(ch) {
    if(a<=p && p<=b) {
      sum += min(p-a,b-p)+(b-a);
    } else if(b<=p) {
      sum += p-a;
    } else if(a>=p) {
      sum += b-p;
    }
  }
  printf("%d\n",sum);
  return 0;
}