#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123;

int n, m, k;
int s[MAXN];
int M[MAXN][MAXN];

bool valid(int i, int j){
    return (i>= 0 && j>=0 && i<n && j<m);
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &m, &n);
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                char c;
                scanf(" %c", &c);
                M[a][b] = (c=='1');
            }
        }
        int ans = 0;
        for(int a=0;a<n;a++){
            int cnt = 0;
            for(int b=0;b<m;b++){
                if(M[a][b])
                    cnt++;
                else
                    cnt = 0;
                ans = max(cnt, ans);
            }
        }
        for(int b=0;b<m;b++){
            int cnt = 0;
            for(int a=0;a<n;a++){
                if(M[a][b])
                    cnt++;
                else
                    cnt = 0;
                ans = max(cnt, ans);
            }
        }
        for(int a=0;a<n;a++){
            int i = a, j = 0;
            int cnt = 0;
            while(valid(i, j)){
                if(M[i][j])
                    cnt++;
                else
                    cnt = 0;
                ans = max(cnt, ans);
                i++;
                j++;
            }
        }
        for(int b=0;b<m;b++){
            int i = 0, j = b;
            int cnt = 0;
            while(valid(i, j)){
                if(M[i][j])
                    cnt++;
                else
                    cnt = 0;
                ans = max(cnt, ans);
                i++;
                j++;
            }
        }
        for(int a=0;a<n;a++){
            int i = a, j = m-1;
            int cnt = 0;
            while(valid(i, j)){
                if(M[i][j])
                    cnt++;
                else
                    cnt = 0;
                ans = max(cnt, ans);
                i++;
                j--;
            }
        }
        for(int b=0;b<m;b++){
            int i = 0, j = b;
            int cnt = 0;
            while(valid(i, j)){
                if(M[i][j])
                    cnt++;
                else
                    cnt = 0;
                ans = max(cnt, ans);
                i++;
                j--;
            }
        }
        printf("Image #%d: %d\n", tt, ans);    
    }
}

