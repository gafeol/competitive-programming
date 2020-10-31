#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

vector<tuple<int, int, int, int>> ans;
int sx, sy;
//////        |
//////    -----     
//////    |

//         VERTICALLLL  HORIZONTALLLL
void add(int x, int y, int xx, int yy){
    //printf("add %d %d %d %d\n",x, y, xx, yy);
    x *= sx;
    xx *= sx;

    y *= sy;
    yy *= sy;
    ans.eb(x, y, xx, yy);
}

void add(int x, int y){
    return add(x, y, x+k, y+k);
}

/*
 *     |
 *   --. 
 */

void add2(int x, int y){
    return add(x+k, y+k, x, y);
}

int main (){
    for_tests(t,tt){
        ans.clear();
        scanf("%d%d%d", &n, &m, &k);
        k--;
        sx = sy = 1;
        if(n < 0){
            n *= -1;
            sx = -1;
        }
        if(m < 0){
            m *= -1;
            sy = -1;
        }

        int x = 0, y = 0;

        int lstMove = -1;
        while(max(abs(x - n), abs(y - m)) > k){
            // x e y posicao livre
            //printf("X %d y %d\n", x, y);
            if(abs(x - n) <= k){ // sobe
                add(x, y);
                y += k + 1;
                lstMove = 0;
            }
            else if(abs(y - m) <= k){ // direita
                add2(x, y);
                x += k + 1;
                lstMove = 1;
            }
            else{
                add(x, y);
                x += k; y += k;
                if(abs(x - n) > abs(y - m)){
                    x++;
                    lstMove = 1;
                }
                else{
                    y++;
                    lstMove = 0;
                }
            }
        }
        assert(x <= n && y <= m);
        // se lstMove eh -1 ta tudo liberado
        //printf("lstmove %d\n", lstMove);
        if(lstMove != 1){
            // essa linha y ta livre
            int difX = n - x;
            add2(x - (k - difX), y);
        }
        else if(lstMove != 0){
            // essa coluna x ta livre
            int difY = m - y;
            add(x, y-(k - difY));
        }
        printf("%d\n", (int)ans.size());
        for(auto [x, y, xx, yy]: ans){
            printf("%d %d %d %d\n", x, y, xx, yy);
        }
    }
    return 0;
}

