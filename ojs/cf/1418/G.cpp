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

random_device rd;     //Get a random seed from the OS entropy device, or whatever
mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator and seed it with entropy.
//Define the distribution, by default it goes from 0 to MAX(unsigned long long)
uniform_int_distribution<unsigned long long> distr;
unsigned long long getRand() { return distr(eng); }

const int MAXN = 500005;

int n, m, k;
int s[MAXN];

int cnt[MAXN];
int ate[MAXN];
ull hx[MAXN][3];

map<ull, queue<int>> pos;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        hx[a+1][0] = 0;
        for(int i=1;i<3;i++){
            hx[a+1][i] = getRand();
        }
	}

    int j = 0;
    for(int i=0;i<n;i++){
        //printf("i %d j %d cnt[s[j]] %d\n", i, j, cnt[s[j]]);
        while(j < n && cnt[s[j]] <= 2){
            cnt[s[j]]++;
            j++;
        }
        //printf("ate %d\n", j-1);
        ate[i] = j-1;
        cnt[s[i]]--;
    }
    ull h = 0;
    for(int a=0;a<=n;a++)
        cnt[a] = 0;
    pos[h].push(n);
    ll ans = 0;
    for(int a=n-1;a>=0;a--){
        h ^= hx[s[a]][cnt[s[a]]];
        cnt[s[a]] = (cnt[s[a]] + 1)%3;
        h ^= hx[s[a]][cnt[s[a]]];
        //printf("a %d ate %d h %llu ans += %d\n", a, ate[a], h, upper_bound(pos[h].begin(), pos[h].end(), ate[a] + 1) - pos[h].begin());

        while(!pos[h].empty() && pos[h].front() > ate[a] + 1)
            pos[h].pop();
        ans += pos[h].size();
        pos[h].push(a);
    }
    printf("%lld\n", ans);
}

