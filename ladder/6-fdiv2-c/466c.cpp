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

int n, b;
int a[500005];
LL s, t, ans;
vector <int> x, y;

int main() {
#if defined(DEBUG_MODE) && !defined(ONLINE_JUDGE)
  freopen("iofiles/in.txt","r",stdin);
  freopen("iofiles/out.txt","w",stdout);
#endif
  //Code here
  scanf("%d",&n);
  foru(i, 1, n+1) {
    scanf("%d",&a[i]);
    s += a[i];
  }
  if(s % 3 != 0) {
    printf("0\n");
  } else {
    t = s / 3;
    s = 0;
    foru(i, 1, n+1) {
      s += a[i]; 
      if(s == t) {
        x.push_back(i);
      }
    }
    s = 0;
    ford(i, n, 0) {
      s += a[i];
      if(s == t) {
        y.push_back(i);
      }
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(auto k : x) {
      b = y.end()-upper_bound(y.begin(),y.end(),k+1);
      ans += b;
    }
    printf("%lld\n", ans);
  }
  return 0;
}