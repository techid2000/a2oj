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
int n,p;
string s;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  redirect();
  //Code here
  cin>>n>>p>>s;
  if(p == 1) {
    cout << "NO\n";
    return 0;
  }
  if(p == 2 && n > 2) {
    cout << "NO\n"; return 0;
  }
  ford(i, n-1, 0) {
    foru(f,s[i]+1,'a'+p-1) {
      auto tmp=s[i];
      s[i]=(char)f;
      if((i<=0||s[i]!=s[i-1]) && (i<=1||s[i]!=s[i-2])) {
        foru(j, i+1, n-1) {
          foru(k, 'a','a'+p-1) {
            if((j<=0||k!=s[j-1]) && (j<=1||k!=s[j-2])) {
              s[j] = k;
              break;
            }
          }
        }
        cout << s;
        return 0;
      }
      s[i]=tmp;
    }
  }
  cout << "NO\n";
  return 0;
}