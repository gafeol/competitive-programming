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
int s[MAXN];
int cnt[MAXN];
set<pii> q;

void add(int x){
    auto it = q.find({-cnt[x], x});
    if(it != q.end())
        q.erase(it);
    cnt[x]++;
    q.insert({-cnt[x], x});
}

void rmv(int x){
    auto it = q.find({-cnt[x], x});
    if(it != q.end())
        q.erase(it);
    cnt[x]--;
    q.insert({-cnt[x], x});
}

bool qry(){
    if(q.empty()) return false;
    auto big = *q.begin();
    if(-big.fst < 4) return false;
    int npar = 0;
    if(-big.fst >= 8)
        return true;
    if(-big.fst >= 6)
        npar++;
    q.erase(big);
    if(!q.empty()){
        auto big2 = *q.begin();    
        if(-big2.fst >= 4)
            npar++;
        if(-big2.fst >= 2)
            npar++;
        q.erase(big2);

        if(!q.empty()){
            auto big3 = *q.begin();
            if(-big3.fst >= 4)
                npar++;
            if(-big3.fst >= 2)
                npar++;
        }

        q.insert(big2);
    }
    q.insert(big);
    return (npar >= 2);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        add(s[a]);
	}
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        char t;
        int x;
        scanf(" %c %d", &t, &x);
        if(t == '-')
            rmv(x);
        else
            add(x);
        if(qry())
            puts("YES");
        else
            puts("NO");
    }
}

