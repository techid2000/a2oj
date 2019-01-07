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
const int Max = 1000000;
LL n,isp[Max+5],LCM;
vector <int> p;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  redirect();
  //Code here
  cin >> n;
  if(n==1) {cout << 1; return 0;}
  if(n==2) {cout << 2; return 0;}
  for(int i=2; i<=Max; ++i) {
    if(!isp[i]) {
      p.push_back(i);
      for(int j=2*i; j<=Max; j+=i) {
        isp[j]=1;
      }
    }
  }
  ford(i,p.size()-1,0) {
    if(p[i] <= n) {
      int j = max(0,i-2);
      foru(k,p[j],n) {
        foru(l,k,n) {
          foru(m,l,n) {
            amax(LCM,lcm(1ll*k,lcm(1ll*l,1ll*m)));
          }
        }
      }
      cout << LCM;
      return 0;
    }
  }
  return 0;
}