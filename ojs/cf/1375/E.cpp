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

const int MAXN = 1003;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN];

int main (){
	scanf("%d", &n);
    int cnt = 0;
    vector<int> x;
	for(int j=0;j<n;j++){
        scanf("%d", s+j);
        x.pb(s[j]);
        for(int i=0;i<j;i++){
            if(s[i] > s[j]){
                cnt++;
                adj[j].pb(i);
            }
        }
	}
    sort(x.begin(), x.end());
    map<int, int> qtd;
    for(int a=0;a<n;a++){
        s[a] = lower_bound(x.begin(), x.end(), s[a]) - x.begin() + qtd[s[a]]++; 
    }
    printf("%d\n", cnt);
    for(int j=n-1;j>=0;j--){
        set<pii> q;
        for(int i: adj[j])
            q.insert({s[i], i}); 
        while(!q.empty()){
            int i = q.begin()->snd;
            q.erase(q.begin());
            swap(s[i], s[j]);
            printf("%d %d\n", i+1, j+1);
        }
    }
}
