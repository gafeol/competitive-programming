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

const int MAXN = 2123456;

int n, m, k;
char s[MAXN];

int vi[] = {1, 1, 2, 2};
int vj[] = {-1, -2, -1, -2};

int go(int i, int j){
    if(i == j) return 1;
    if(i == j -1) return 2;
    for(int move = 0;move < 4;move++){
        int ii = i + vi[move];
        int jj = j + vj[move];
        if(ii > jj) continue;
        if(s[ii] == s[jj])
            return 2 + go(ii, jj);
    }
    assert(false);
}

queue<char> beg;
stack<char> fim;

void re(int i, int j){
    if(i == j){
        beg.push(s[i]);
        return ;
    }
    beg.push(s[i]);
    fim.push(s[j]);
    if(i == j -1){
        return ;
    }
    for(int move = 0;move < 4;move++){
        int ii = i + vi[move];
        int jj = j + vj[move];
        if(ii > jj) continue;
        if(s[ii] == s[jj]){
            re(ii, jj);
            return ;
        }
    }
    assert(false);
}

int main (){
    scanf(" %s", s);
    n = strlen(s);
    for(char ini = 'a';ini <= 'c';ini++){
        int i = 0, j = n-1;
        while(i < j){
            if(s[i] != ini)
                i++;
            else if(s[j] != ini)
                j--;
            else
                break;
        }
        int sz = go(i, j);
        if(sz >= n/2){
            re(i, j);
            while(!beg.empty()){
                printf("%c", beg.front());
                beg.pop();
            }
            while(!fim.empty()){
                printf("%c", fim.top());
                fim.pop();
            }
            puts("");
            return 0;
        }
    }
    puts("IMPOSSIBLE");
}

