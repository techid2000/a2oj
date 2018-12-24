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
char s[200005],t[200005];
int a[200005],b,cnt,len;
int to1[200005],to2[200005];
int back1[200005],back2[200005];
void track(int x,int y) {
  if(x>0) {
    if(y==1){
      track(x-1,back1[x]);
    } else {
      track(x-1,back2[x]);
    }
  }
  if(y==1) putchar(t[x]);
  else printf("%c%c",t[x],t[x]);
}
int main() {
  debugMode();
  //Code here
  scanf(" %s",s);
  len = strlen(s);
  rep(i, len) {
    cnt++;
    if(i==len-1 || s[i+1]!=s[i]) {
      t[b]=s[i];
      a[b++]=cnt;
      cnt=0;
    }
  }
  to1[0]=a[0]-1;
  if(a[0]-2>=0) {
    to2[0]=a[0]-2;
  } else {
    to2[0]=1e9;
  }
  foru(i,1,b) {
    if(a[i]-2>=0) {
      to2[i]=to1[i-1]+a[i]-2;
      back2[i]=1;
    } else {
      to2[i]=1e9;
    }
    if(to1[i-1]<to2[i-1]) {
      to1[i]=to1[i-1]+a[i]-1;
      back1[i]=1;
    } else {
      to1[i]=to2[i-1]+a[i]-1;
      back1[i]=2;
    }
  }
  if(to1[b-1]<to2[b-1]) {
    track(b-1,1);
  } else {
    track(b-1,2);
  }
  return 0;
}