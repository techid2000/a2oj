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
LL q,t,x,a,n,sum;
vector <int> p = {0,0};
vector <int> r = {0,0};
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  redirect();
  //Code here
  cin >> q;
  n = 1;
  rep(_, q) {
    cin >> t;
    if(t == 1) {
      cin >> x >> a;
      p[x] += a;
      sum += a*x;
    } else if(t == 2) {
      cin >> x;
      p.push_back(0);
      r.push_back(x);
      sum += x;
      n++;
    } else {
      p[n-1]+=p[n];
      sum -= p[n];
      sum -= r[n];
      p.pop_back();
      r.pop_back();
      n--;
    }
    cout << fixed << setprecision(6) << 1.0*sum/n << '\n';
  }
  return 0;
}