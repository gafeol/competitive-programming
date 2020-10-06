#include "bits/stdc++.h"
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


 const int MAXN = 1009;
int n, m, k;
int s, d;

ull h[MAXN];

vector<ull> sh;

unordered_map<ull, int> cnt;

int main (){
    srand(time(NULL));
	scanf("%d%d%d", &n, &s, &d);
    for(int a=0;a<n;a++){
        h[a] = getRand();
    }
    sh.resize(s);
    for(int a=0;a<s;a++){
        vector<int> x;
        int q;
        scanf("%d", &q);
        ull hx = 0;
        while(q--){
            int i;
            scanf("%d", &i);
            i--;
            hx ^= h[i];
            x.pb(i);
        }
        sh[a] = hx;
    }
    int hf = s/2;
    for(int bm=0;bm<(1<<hf);bm++){
        int cus = __builtin_popcount(bm); 
        ull H = 0;
        for(int i=0;i<hf;i++){
            if((bm>>i)&1)
                H ^= sh[i];
        }
        if(cnt.find(H) == cnt.end())
            cnt[H] = cus;
        else
            cnt[H] = min(cus, cnt[H]);
        //printf("cnt[%llu] %d\n", H, cnt[H]);
    }

    for(int a=0;a<d;a++){
        int q;
        scanf("%d", &q);
        ull H = 0;
        while(q--){
            int i;
            scanf("%d", &i);
            i--;
            H ^= h[i];
        }
        int hf = s -  s/2, del = s/2;
        int ans = INT_MAX;
        for(int bm=0;bm<(1<<hf);bm++){
            int cus = __builtin_popcount(bm); 
            ull hx = H;
            for(int i=0;i<hf;i++){
                if((bm>>i)&1)
                    hx ^= sh[i+del];
            }
            if(cnt.find(hx) != cnt.end())
                ans = min(ans, cus + cnt[hx]);
        }
        if(ans == INT_MAX)
            puts("-1");
        else
            printf("%d\n", ans);
    }
}

