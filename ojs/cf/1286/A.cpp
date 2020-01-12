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
int cnt[2];

int go(){
    int o[2];
    o[0] = cnt[0];
    o[1] = cnt[1];
    multiset<int> q[2];

    int res = 0;
    int prv = -1;
    for(int a=0;a<n;a++){
        if(s[a] == -1) continue;
        if(prv != -1){
            int dx = a - prv - 1;
            res += (s[prv] != s[a]); 
            if(s[prv] == s[a])
               q[s[a]].insert(dx); 
        }
        prv = a;
    }
    for(int t=0;t<=1;t++){
        while(!q[t].empty()){
            if(cnt[t] >=*q[t].begin())
                cnt[t] -= *q[t].begin();
            else
                res+=2;
            q[t].erase(q[t].begin());
        }
    }

    cnt[0] = o[0];
    cnt[1] = o[1];
    return res;
}

int main (){
	scanf("%d", &n);
    cnt[0] = n/2;
    cnt[1] = (n+1)/2;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        if(s[a] != 0){
            s[a] &= 1;
            cnt[s[a]]--;
        }
        else
            s[a] = -1;
	}
    if(n == 1){
        puts("0");
        return 0;
    }
    int res = INT_MAX;
    if(s[0] == -1 && s[n-1] == -1){
        for(int ini=0;ini<=1;ini++){
            if(cnt[ini] == 0) continue;
            cnt[ini]--;
            s[0] = ini;
            for(int fim=0;fim<=1;fim++){
                if(cnt[fim] == 0) continue;
                cnt[fim]--;
                s[n-1] = fim;
                res = min(res, go());
                cnt[fim]++;
            }
            cnt[ini]++;
        }
    }
    else if(s[0] == -1){
        for(int ini=0;ini<=1;ini++){
            if(cnt[ini] == 0) continue;
            cnt[ini]--;
            s[0] = ini;
            res = min(res, go());
            cnt[ini]++;
        }
    }
    else if(s[n-1] == -1){
        for(int fim=0;fim<=1;fim++){
            if(cnt[fim] == 0) continue;
            cnt[fim]--;
            s[n-1] = fim;
            res = min(res, go());
            cnt[fim]++;
        }
    }
    else
        res = go();
    printf("%d\n", res);
}

