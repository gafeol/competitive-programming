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

const int MAXN = 24*61;

int n, m, k;

vector<int> s[MAXN], e[MAXN];

char res[1123];
int task[2];

bool assign(int x){
    if(task[0] == -1){
        task[0] = x;
        res[x] = 'C';
    }
    else if(task[1] == -1){
        task[1] = x;
        res[x] = 'J';
    }
    else
        return false;
    return true;
}

void deassign(int x){
    if(task[0] == x)
        task[0] = -1;
    else
        task[1] = -1;
}

int main (){
    for_tests(t, tt){
        for(int a=0;a<MAXN;a++){
            s[a].clear();
            e[a].clear();
        }
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            int i, j;
            scanf("%d %d", &i, &j);
            j--;
            s[i].pb(a);
            e[j].pb(a);
        }
        printf("Case #%d: ", tt);
        task[0] = task[1] = -1;
        for(int a=0;a<MAXN;a++){
            for(int x: s[a]){
                if(!assign(x))
                    goto fail;
            }
            for(int x: e[a]){
                deassign(x);
            }
        }

        for(int a=0;a<n;a++)
            printf("%c", res[a]);
        puts("");
        continue;
fail:   puts("IMPOSSIBLE");
    }
}
