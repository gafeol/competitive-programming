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

int n, m;
ll k;
int s[MAXN];

int bef[MAXN], aft[MAXN];

ll ni;

int qrybef(int i){
    i += 2;
    int ans = 0;
    while(i < MAXN){
        ans += bef[i];
        i += (i&-i);
    }
    return ans;
}


int qryaft(int i){
    i += 2;
    int  ans = 0;
    while(i > 0){
        ans += aft[i];
        i -= (i&-i);
    }
    return ans;
}

void updbef(int i, int val){
    i += 2;
    while(i > 0){
        bef[i] += val;
        i -= (i&-i);
    }
}

void addbef(int x){
    ni += qrybef(x+1);
    ni += qryaft(x-1);
    //printf("add bef %d ni += %d\n", x, qrybef(x+1) + qryaft(x-1));
    updbef(x, 1); 
}

void updaft(int i, int val){
    int ori = i;
    i += 2;
    while(i < MAXN){
        aft[i]+=val;
        i += (i&-i);
    }
}


void rmvaft(int x){
    ni -= qryaft(x-1);
    ni -= qrybef(x+1);
    //printf("rmvaft %d ni -= %d\n", x, qryaft(x-1) + qrybef(x+1));
    updaft(x, -1);
}


int main (){
	scanf("%d%lld", &n, &k);
    vector<int> x;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        x.pb(s[a]);
	}
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for(int a=0;a<n;a++)
        s[a] = lower_bound(x.begin(), x.end(), s[a]) - x.begin();
    ll i = 0, j = -1;
    ni = 0;
    for(int a=n-1;a>=0;a--){
        updaft(s[a], 1);
        ni += qryaft(s[a]-1);
    }
    /*for(int a=0;a<n;a++){
        printf("%d ", s[a]);
    }*/
    //puts("");
    ll ans = 0;
    //printf("total ni %lld\n", ni);
    if(ni <= k)
        ans = (n*(n-1ll))/2;
    else{
        rmvaft(s[0]);
        j = 0;
        addbef(s[0]);
        for(i=1;i<n;i++){
            while(j+1 < n && ni > k)
                rmvaft(s[++j]);
            if(ni > k) break;
            ans += n-j-1;
            //printf("i %lld j %lld ni %lld ans += %d\n", i, j, ni, n-j-1);
            if(i == j && j+1 < n)
                rmvaft(s[++j]);
            addbef(s[i]);
        }
    }
    printf("%lld\n", ans);
}
