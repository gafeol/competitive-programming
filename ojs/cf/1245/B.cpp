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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

char inv(int i){
    if(i == 0)
        return 'R';
    if(i == 1)
        return 'P';
    return 'S';
}

int win(char c){
    if(c == 'R')
        return 1;
    else if(c == 'P')
        return 2;
    else
        return 0;
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        scanf("%d%d%d", s, s+1, s+2);
        char str[110];
        char ans[110];
        for(int a=0;a<n;a++){
            ans[a] = ' ';
        }
        ans[n] = '\0';
        scanf(" %s", str);
        int cnt = 0;
        for(int a=0;a<n;a++){
            if(s[win(str[a])] > 0){
                ans[a] = inv(win(str[a]));
                s[win(str[a])]--;
                cnt++;
            }
        }
        for(int a=0;a<n;a++){
            if(ans[a] == ' '){
                for(int i=0;i<3;i++){
                    if(s[i] > 0){
                        ans[a] = inv(i);
                        s[i]--;
                        break;
                    }
                }

            }
        }
        if(cnt >= (n+1)/2){
            puts("YES");
            printf("%s\n", ans);
        }
        else
            puts("NO");
    }
}

