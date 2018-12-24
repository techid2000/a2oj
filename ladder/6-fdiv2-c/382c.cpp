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
int n;
int a[100005];
map<int,int>Map;
set<int>s;
PII p,q;
int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  rep(i, n) {
    scanf("%d",&a[i]);
  }
  sort(a,a+n);
  if(n==1) {
    printf("-1\n");
  } else if(n==2) {
    if((a[0]+a[1])%2==0) {
      s.insert((a[1]+a[0])/2);
    }
    s.insert(a[0]-(a[1]-a[0]));
    s.insert(a[1]+(a[1]-a[0]));
    printf("%d\n",s.size());
    for(auto k:s) {
      printf("%d ",k);
    }
  } else {
    foru(i,1,n) {
      Map[a[i]-a[i-1]]++;
    }
    if(Map.size()>2) {
      printf("0\n");
    } else if(Map.size()==1) {
      s.insert(a[0]-(a[1]-a[0]));
      s.insert(a[n-1]+(a[1]-a[0]));
      printf("%d\n",s.size());
      for(auto x:s) {
        printf("%d ",x);
      }
    } else {
      auto it = Map.begin();
      p=*it;
      it++;
      q=*it;
      if(q.Y==1) swap(p,q);
      if(p.Y==1) {
        if(p.X==q.X*2) {
          printf("1\n");
          foru(i,1,n) {
            if(a[i]-a[i-1]==p.X) {
              printf("%d\n",(a[i-1]+a[i])/2);
            }
          }
        } else {
          printf("0\n");
        }
      } else {
        printf("0\n");
      }
    }
  }
  return 0;
}