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

int n,k,in;
vector <LL> a={0},qs={0};
LL err;
int lo,hi,mid,ava,ans,ans2;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  redirect();
  //Code here
  cin >> n >> k;
  foru(i, 1, n) {
    cin >> in;
    a.push_back(in);
  }
  sort(begin(a)+1,end(a));
  foru(i, 1, n) {
    qs.push_back(qs.back() + a[i]);
    lo = 1, hi = i;
    while(lo <= hi) {
      mid = (lo + hi) >> 1;
      err = (i-mid+1)*a[i]-(qs[i]-qs[mid-1]);
      if(err <= k) ava = mid, hi = mid-1;
      else lo = mid+1;
    }
    if(i-ava+1 > ans)
      ans = i-ava+1, ans2 = a[i];
  }
  cout << ans << ' ' << ans2;
  return 0;
}