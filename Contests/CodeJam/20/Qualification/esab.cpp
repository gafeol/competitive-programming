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
#define debug(args...) ////fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212;

int n, m, k;
int s[MAXN];
int res[MAXN];

#define REV  0
#define NOT  1
#define COMP 2
#define CREV 3

int i, j;

void apply(int t){
    if(t == COMP || t == CREV){
        for(int a=1;a<=n;a++)
            res[a] = !res[a];
    }
    if(t == REV || t == CREV){
        for(int a=1;a<=n/2;a++)    
            swap(res[a], res[n+1-a]);
        int aux = i;
        i = n - j + 1;
        j = n - aux + 1;
    }
}

bool eq, dif;

int geteq(){
    for(int a=1;a<=i && n-a+1 >= j;a++){
        if(res[a] == res[n-a+1]){
            return a;
        }
    }
    return -1;
}

int getdif(){
    for(int a=1;a<=i && n-a+1 >= j;a++){
        if(res[a] != res[n-a+1]){
            return a;
        }
    }
    return -1;
}

int cnt;

int query(int i){
    cnt++;
    cout << i << endl;
    fflush(stdout);
    //fprintf(stderr, "query %d\n", i);
    char x;
    scanf(" %c", &x);
    //fprintf(stderr, "leu %c\n", x); 
    if(x == 'N') exit(0);
    return (x-'0');
}

void correct(){
    int e = geteq();
    int d = getdif();
    int t = 0;

    if(e != -1){
        int x = query(e);
        if(x != res[e])
            t+=2;
    }
    if(d != -1){
        int y = query(d);
        if(y == res[d])
            t++;
    }

    if(d == -1 || e == -1){
        i = min(i, n+1-j);
        j = max(j, n+1-i);
    }
    
    apply(t);
}

int main (){
    int t;
    scanf("%d%d", &t, &n);
    //fprintf(stderr, "leu t %d n %d\n", t, n);
    for(int tt=1;tt<=t;tt++){
        i = 0; 
        j = n+1; 
        cnt = 1;
        while(i+1 < j){
            if(cnt > 1 && cnt%10 == 1)
                correct();
            if(i + j <= n+1){
                i++; 
                res[i] = query(i);
            }
            else{
                j--;
                res[j] = query(j);
            }
        }
        for(int a=1;a<=n;a++){
            //fprintf(stderr, "%d", res[a]);
            cout << res[a];
            fflush(stdout);
        }
        //fprintf(stderr, "\n");
        cout << endl;
        fflush(stdout);

        char c;
        scanf(" %c", &c);
        if(c == 'N')
            return 0;
    }
}

