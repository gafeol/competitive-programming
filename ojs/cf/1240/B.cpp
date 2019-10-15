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

const int MAXN = 312345;

int n, m, k;
int s[MAXN];
int L[MAXN], R[MAXN];

int main (){
    for_tests(t, tt){
        vector<int> v;
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            L[a] = INT_MAX;
            R[a] = -1;
            scanf("%d", s+a);
            v.pb(s[a]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        for(int a=0;a<n;a++){
            s[a] = lower_bound(v.begin(), v.end(), s[a]) - v.begin();
            R[s[a]] = max(R[s[a]], a);
            L[s[a]] = min(L[s[a]], a);
        }
        int i = 0, j = 0;
        int ans = 1;
        while(j+1 < v.size()){
            if(L[j+1] < R[j])
                i = j+1;
            j++;
            ans = max(ans, j - i + 1);
        }
        printf("%d\n", (int)v.size() - ans);
        
    }
}


