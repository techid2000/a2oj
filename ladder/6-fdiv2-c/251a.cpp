//Author: techid2000
#include <bits/stdc++.h>
#pragma region Preparation
#define foru(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,a) for(int i=0;i<a;i++)
#define minheap(x) x,vector<x>,greater<x>
#define X first
#define Y second
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
using namespace std;
using PII = pair<int,int>;
using LL = long long;
template<class T,class U>inline bool amin(T& x, U y){return x>y?(x=y,true):false;}
template<class T,class U>inline bool amax(T& x, U y){return x<y?(x=y,true):false;}
ifstream fin("iofiles/in.txt");
ofstream fout("iofiles/out.txt"),ferr("iofiles/err.txt");
inline void redirect() {
#ifndef ONLINE_JUDGE
  cin.rdbuf(fin.rdbuf()); cout.rdbuf(fout.rdbuf());cerr.rdbuf(ferr.rdbuf());
#endif
}
#pragma endregion
int a[100005],n,d;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  redirect();
  //Code here
  cin>>n>>d;
  foru(i,1,n)cin>>a[i];
  int y=3; LL cnt=0; 
  foru(x,1,n-2) {
    if(y-x+1<3) y=x+2;
    while(y+1<=n && a[y+1]-a[x]<=d) y++;
    if(y-x-1>0 && a[y]-a[x]<=d) {
      // cerr<<x<<" "<<y<<"\n";
      cnt+=1ll*(y-x)*(y-x-1)/2;
    }
  }
  cout<<cnt;
  return 0;
}