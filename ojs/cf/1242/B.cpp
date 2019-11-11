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

const int MAXN = 112345;

int n, m, k;
int s[MAXN];
set<int> want;
vector<int> cant[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        cant[i].pb(j);
        cant[j].pb(i);
	}
    for(int a=1;a<=n;a++){
        cant[a].pb(n+1);
        sort(cant[a].begin(), cant[a].end());
        want.insert(a);
    }
    want.erase(1);
    queue<int> q;
    q.push(1);
    int cst = 0;
    while(!want.empty()){
        if(q.empty()){
            q.push(*want.begin());
            want.erase(want.begin());
            cst++;
        }
        int u = q.front();
        q.pop();
        //printf("u %d\n", u);
        int i = 0;
        int rmv = -1;
        for(int val: want){
            if(rmv != -1){
                want.erase(rmv);
                q.push(rmv);
                rmv = -1;
            }
            while(val > cant[u][i])
                i++;
            if(val != cant[u][i])
                rmv = val; 
        }
        if(rmv != -1){
            //printf("rmv %d\n", rmv);
            want.erase(rmv);
            q.push(rmv);
            rmv = -1;
        }
    }
    printf("%d\n", cst);
}

