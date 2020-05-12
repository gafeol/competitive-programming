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

const int MAXN = 1000011;

int n, m, k;
int s[MAXN];

int prv[MAXN];
int res[MAXN];

int go(int t){
    int val = t;
    vector<int> qry(n, 0);
    while(t > 0){
        qry[prv[t]]++;
        t -= s[prv[t]];
    }
    puts("1");
    for(int x: qry)
        printf("%d ", x);
    puts("");
    fflush(stdout);

    char st[10];
    scanf(" %s", st);
    if(st[0] == 'g')
        res[val] =  0;
    else if(st[0] == 'y')
        res[val] =  1;
    else
        res[val] = 2;
    return res[val];
}

int main (){
    memset(prv, -1, sizeof(prv));
	scanf("%d", &n);
	for(int a=0;a<n;a++)
        scanf("%d", s+a);
    prv[0] = n;
    for(int a=0;a<n;a++){
        for(int i=0;i+s[a] < MAXN;i++){
            if(prv[i] == -1)
                continue;
            prv[i+s[a]] = a;
        }
    }
    vector<int> s;
    for(int a=1;a<=1000000;a++){
        if(prv[a] == -1)
            continue;
        s.pb(a);
    }
    int i = 0, j = s.size();
    int lstR = 1000001, lstG = 0;
    while(i < j){
        int m = (i + j)/2;
        int c = go(s[m]);
        if(c == 0){
            i = m + 1;
            lstG = s[m];
        }
        else if(c == 1){
            i = m;
            j = m;
        }
        else{
            j = m-1;
            lstR = s[m];
        }
    }
    if(i == j){
        int c = go(s[i]);
        if(c == 0){
            lstG = s[i];
        }
        else if(c == 2){
            lstR = s[i];
        }
    }
    //printf("lstR %d lstG %d\n", lstR, lstG);
    if(res[s[i]] == 1){
        puts("2");
        printf("%d\n", s[i]);
    }
    else if (lstR == lstG + 2){
        puts("2");
        printf("%d\n", lstG+1);
    }
    else{
        puts("2");
        puts("-1");
    }
    fflush(stdout);
}

