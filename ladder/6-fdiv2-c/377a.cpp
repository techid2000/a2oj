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

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m,k,dot,cnt,ai,aj,bi,bj;
char a[505][505];
queue<PII>q;

int main() {
  debugMode();
  //Code here
  scanf("%d%d%d",&n,&m,&k);
  foru(i, 1, n+1) {
    foru(j, 1, m+1) {
      scanf(" %c",&a[i][j]);
      if(a[i][j]=='.')
        a[i][j]='X',dot++;
    }
  }
  foru(i, 1, n+1) {
    foru(j, 1, m+1) {
      if(a[i][j]=='X') {
        q.push(make_pair(i,j));
        while(!q.empty()) {
          ai=q.front().X;
          aj=q.front().Y;
          q.pop();
          if(a[ai][aj]=='X') {
            a[ai][aj]='.';
            cnt++;
            if(cnt >= dot-k) {
              foru(ii, 1, n+1) {
                foru(jj, 1, m+1) {
                  printf("%c",a[ii][jj]);
                }
                printf("\n");
              }
              return 0;
            }
            rep(k, 4) {
              bi=ai+dx[k];
              bj=aj+dy[k];
              if(a[bi][bj]=='X') {
                q.push(make_pair(bi,bj));
              }
            }
          }
        }
        return 0;
      }
    }
    printf("\n");
  }
  return 0;
}