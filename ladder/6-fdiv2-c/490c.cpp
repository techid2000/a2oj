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
char s[1000005];
int ch[1000005],a,b,len;
LL num,ten;
int main() {
  debugMode();
  //Code here
  scanf(" %s",s);
  scanf("%d%d",&a,&b);
  len=strlen(s);
  rep(i,len) {
    num+=s[i]-'0';
    num%=a;
    if(num==0) {
      ch[i]++;
    }
    num*=10;
    num%=a;
  }
  num=0;
  ten=1;
  ford(i,len-1,-1) {
    num+=ten*(s[i]-'0');
    num%=b;
    if(num==0) {
      ch[i-1]++;
      if(ch[i-1]==2 && s[0]!='0' && s[i]!='0') {
        printf("YES\n");
        rep(j, i) {
          putchar(s[j]);
        }
        printf("\n");
        foru(j,i,len) {
          putchar(s[j]);
        }
        return 0;
      }
    }
    ten*=10;
    ten%=b;
    num%=b;
  }
  printf("NO\n");
  return 0;
}