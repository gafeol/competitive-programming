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
int cnt[MAXN][30];

vector<int> getFreq(int i, int j){
    vector<int> f(26);
    for(int c=0;c<26;c++){
        f[c] = cnt[j][c] - (i > 0 ? cnt[i-1][c] : 0);
    }
    return f;
}

int main (){
    scanf(" %s", s);
    int tam = strlen(s);
    for(int i=0;i<tam;i++){
        cnt[i][s[i]-'a'] = 1;
        if(i == 0) continue;
        for(int c=0;c<26;c++)
            cnt[i][c] += cnt[i-1][c];
    }
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        vector<int> f = getFreq(i, j);
        int mx = *max_element(f.begin(), f.end());
        //printf("mx %d f[%d] %d \n", mx, s[i]-'a', f[s[i]-'a']);
        if(i == j || s[j] != s[i]){
            puts("Yes");
            continue;
        }
        
        int cnt = 0;
        for(int c=0;c<26;c++){
            cnt += (f[c] != 0);
        }
        if(cnt >= 3){
            puts("Yes");
            continue;
        }



        puts("No");
	}
}

