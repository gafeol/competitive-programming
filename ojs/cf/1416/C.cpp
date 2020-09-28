#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const int MAXN = 300005;

int n, m, k;
int bit[MAXN];

void upd(int i){
    i += 2;
    while(i > 0){
        bit[i]++;
        i -= (i&-i);
    }
}

ll qry(int i){
    i += 2;
    ll ans = 0;
    while(i < MAXN){
        ans += bit[i];
        i += (i&-i);
    }
    return ans;
}

ll countInv(vector<ll> s){
    vector<ll> cop = s;
    sort(cop.begin(), cop.end());
    for(int a=0;a<MAXN;a++)
        bit[a] = 0;
    ll ans = 0;
    for(int a=0;a<s.size();a++){
        s[a] = lower_bound(cop.begin(), cop.end(), s[a]) - cop.begin();
        ans += qry(s[a]+1);
        upd(s[a]);
    }
    return ans;
}


vector<ll> niv;
ll aux[MAXN];
ll merge(int l, int r){
    //fprintf(stderr,"%d %d\n",l,r);
    if(l==r) return 0;
    ll res;
    ll mid=(l+r)/2;
    res=merge(l,mid)+merge(mid+1,r);
    int i=l, j=mid+1, pos=0;
    while(i<mid+1 && j<r+1){
        if(niv[i]<=niv[j])
            aux[pos++]=niv[i++];
        else{
            aux[pos++]=niv[j++];
            res+=mid-i+1;
        }
    }
    while(i<mid+1)
        aux[pos++]=niv[i++];
    while(j<r+1)
        aux[pos++]=niv[j++];
    for(int b=0;b<pos;b++)
        niv[l+b]=aux[b];
    return res;
}

ll inv(vector<ll> s){
    niv = s;
    return merge(0, s.size()-1);
}

int main (){
	scanf("%d", &n);
    vector<ll> s(n);
	for(int a=0;a<n;a++){
        scanf("%lld", &s[a]);
	}
    ll ans = inv(s);
    ll vans = 0;
    for(int b=0;b<30;b++){
        for(int a=0;a<n;a++)
            s[a] ^= (1<<b);
        ll chg = inv(s);
        //debug("chg %lld inv %lld\n", countInv(s), inv(s));
        //assert(chg == inv(s));
        if(chg < ans){
            ans = chg;
            vans += (1<<b);
        }
        else{
            for(int a=0;a<n;a++)
                s[a] ^= (1<<b);
        }
    }
    printf("%lld %lld\n", ans, vans);
}

