#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123456;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll expo(ll base, ll e){
    if(e == 0) return 1ll;
    ll ans = expo(base, e/2ll);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

ll inv(ll x){
    return expo(x, modn-2);
}

vector<pii> pos;

int M[1009][1009];
int nxt[MAXN];

ll sumsq[MAXN], sumi[MAXN], sumj[MAXN], sump[MAXN];
ll sumr[MAXN];

bool cmp(pii a, pii b){
    return  M[a.fst][a.snd] > M[b.fst][b.snd];
}

ll sq(ll i, ll j){
    return mod(i*i + j*j);
}

int main (){
	scanf("%d%d", &n, &m);
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            int x;
            scanf("%d",  &x);
            M[a][b] = x;
            pos.pb(pii(a, b));
        }
    }
    int l, r;
    scanf("%d%d", &l, &r);
    l--;r--;
    int ini = 0;
    sort(pos.begin(), pos.end(), cmp);
    int i = 0;
    for(int a=0;a<pos.size();a++){
        if(pos[a].fst == l && pos[a].snd == r)
            ini = a;
        if(i < a) i = a;
        while(i < pos.size() && M[pos[i].fst][pos[i].snd] == M[pos[a].fst][pos[a].snd])
            i++;
        nxt[a] = i;
    }
    ll ans = 0;
    for(int a=ini;a<pos.size();a++){
        printf("a %d pos %d %d\n", a, pos[a].fst, pos[a].snd);
        if(a > 0){
            sump[a] = mod(sump[a] + sump[a-1]);
            sumi[a] = mod(sumi[a] + sumi[a-1]);
            sumj[a] = mod(sumj[a] + sumj[a-1]);
            sumsq[a] = mod(sumsq[a] + sumsq[a-1]);
            sumr[a] = mod(sumr[a] + sumr[a-1]);
        }
        printf("%lld %lld %lld %lld %lld\n", sump[a], sumi[a], sumj[a], sumsq[a], sumr[a]);

        ll sz = pos.size() - nxt[a];
        printf("nx %d sz %lld\n", nxt[a], sz);
        ll p = inv(sz); 
        printf("inv %lld\n", p);


        ll i = pos[a].fst, j = pos[a].snd;
        ll res = mod(modn + mod(sumsq[a] - mod(2ll*i*sumi[a]) - mod(2ll*j*sumj[a]) + mod(sq(i, j)*sump[a]) + sumr[a]));
        printf("res %lld\n", res);

        int nx = nxt[a];

        if(nx == pos.size())
            ans = mod(ans + res);
        sumsq[nx] = mod(sumsq[nx] + mod(p*mod(sq(i, j))));
        sumi[nx] = mod(sumi[nx] + mod(p*i));
        sumj[nx] = mod(sumj[nx] + mod(p*j));
        sump[nx] = mod(sump[nx] + p);
        sumr[nx] = mod(sumr[nx] + res);
    }
    printf("%lld\n", ans);
}
