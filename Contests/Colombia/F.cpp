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

int n;
string s;
char ss[MAXN];
int nxt[MAXN];

int mrk[MAXN];
ll base = 2ll*2*2*2
            *3*3
            *5
            *7
            *11
            *13
            *17
            *19;

ll read(int &i){
    ll A = 0;
    while(s[i] != '/'){
        A *= 10;
        A += s[i]-'0';
        i++;
    }
    ll B = 0;
    while(i+1 < s.size() && s[i+1] >= '0' && s[i+1] <= '9'){
        i++;
        B *= 10;
        B += s[i]-'0';
    }

    assert(base%B == 0);
    return A*(base/B);
}

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main (){
    while(scanf(" %s", ss) != EOF){
        s.clear();
        s.push_back('+');
        s = s + ss;
        s.push_back('+');
        n = s.size();
        stack<int> q;
        for(int a=0;a<n;a++){
            if(s[a] == '(')
                q.push(a);
            else if(s[a] == ')'){
                nxt[q.top()] = a;                  
                q.pop();
            }
        }
        int sig = 1;
        int lstsig = 1;
        ll ans = 0;
        for(int i=0;i<s.size();i++){
            //printf("s[%d] %c\n", i, s[i]);
            if(s[i] == '('){
                mrk[nxt[i]] = lstsig;
                sig *= lstsig;
                lstsig = 1;
            }
            else if(s[i] == ')'){
                sig *= mrk[i];
            }
            else if(s[i] == '+'){
                lstsig = 1;
            }
            else if(s[i] == '-'){
                lstsig = -1;
            }
            else{
                ll val = read(i);
                ans += sig*lstsig*val;
            }
        }
        if(ans == 0){
            puts("0/1");
        }
        else{
            ll gc = gcd(abs(ans), base);
            printf("%lld/%lld\n", ans/gc, base/gc);
        }
    }
}

