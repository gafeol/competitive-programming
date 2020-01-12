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
int dif[MAXN];
map<int, int> cnt;

int main (){
    for_tests(t, tt){
        cnt.clear();
        scanf("%d", &n);
        vector<tuple<int, int, int>> s(2*n);
        vector<int> l(n);
        for(int a=0;a<n;a++){
            dif[a] = 0;
            int i, j;
            scanf("%d%d", &i, &j);
            l[a] = i;
            cnt[i]++;
            s[a*2] = {i, 0, a};
            s[a*2 + 1] = {j, 1, a};
        }
        sort(s.begin(), s.end());
        multiset<int> lf;
        int ini = 0;
        for(tuple<int, int, int> tp: s){
            int x, id, t; 
            tie(x, t, id)  = tp;
            if(!t){
                if(lf.empty()){
                    ini++;
                    if(cnt[x] == 1){
                        dif[id]--;
                    }
                }
                if(lf.size() == 1 && l[*lf.begin()] != x){
                    int o = *lf.begin();
                    dif[o]++;
                }
                lf.insert(id);
            }
            else
                lf.erase(lf.find(id));
        }
        int ans =0;
        for(int a=0;a<n;a++){
            ans = max(ans, ini + dif[a]); 
            //printf("ini %d dif %d\n", ini, dif[a]);
        }
        printf("%d\n", ans);
    }
}

