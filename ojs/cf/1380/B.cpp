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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
char s[MAXN];

int main (){
    map<char, char> op;
    op['R'] = 'P';
    op['P'] = 'S';
    op['S'] = 'R';

	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf(" %s", s);
        int tam = strlen(s);
        map<char, int> cnt;
        for(int a=0;a<tam;a++){
            cnt[s[a]]++;
        }
        int mx = max(cnt['R'], max(cnt['S'], cnt['P']));
        if(mx == cnt['R']){
            for(int a=0;a<tam;a++){
                printf("%c", op['R']);
            }
        }
        else if(mx == cnt['P']){
            for(int a=0;a<tam;a++){
                printf("%c", op['P']);
            }
        }
        else{
            for(int a=0;a<tam;a++){
                printf("%c", op['S']);
            }
        }
        puts("");
	}
}

