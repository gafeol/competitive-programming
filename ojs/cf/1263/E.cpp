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

const int MAXN = 1000006, DEZ = 1000000;

int n, m, k;
struct arv{
    int mn;
    int mx;
    int lz;

    arv operator + (arv o){
        arv res;
        res.mn = min(mn, o.mn);
        res.mx = max(mx, o.mx);
        res.lz = 0;
        return res;
    }
} tree[4*MAXN];

char s[MAXN];

void unlaze(int idx, int i, int j){
    int aux = tree[idx].lz;
    tree[idx].lz = 0;
    if(i != j){
        tree[idx*2].lz += aux;
        tree[idx*2].mn += aux;
        tree[idx*2].mx += aux;
        tree[idx*2+1].lz += aux;
        tree[idx*2+1].mn += aux;
        tree[idx*2+1].mx += aux;
    }
}

void upd(int idx, int i, int j, int l, int r, int val){
    if(i > r || j < l) return;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        tree[idx].lz += val;  
        tree[idx].mn += val;
        tree[idx].mx += val;
        return;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, r, val);
    upd(idx*2+1, m+1, j, l, r, val);
    tree[idx].mn = min(tree[idx*2].mn, tree[idx*2+1].mn);
    tree[idx].mx = max(tree[idx*2].mx, tree[idx*2+1].mx);
}

arv qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l) return {0, 0, 0};
    unlaze(idx, i, j);
    if(i >= l && j <= r)
        return tree[idx];
    int m = (i + j)/2;
    return qry(idx*2, i, m, l, r) + qry(idx*2+1, m+1, j, l, r);
}

int main (){
	scanf("%d", &n);
    int pos = 0;
	for(int a=0;a<n;a++){
        char c;
        scanf(" %c", &c);
        if(c == 'L'){
            if(pos > 0)
                pos--;
        }
        else if(c == 'R')
            pos++;
        else{
            int val = 0;
            if(s[pos] == '(')
                val--;
            if(s[pos] == ')')
                val++;
            if(c == '(')
                val++;
            if(c == ')')
                val--;
            upd(1, 0, DEZ, pos, DEZ, val);
            s[pos] = c;
            //printf("upd %d - %d val %d\n", pos, DEZ, val);
        }
        arv tot = qry(1, 0, DEZ, 0, DEZ);
        arv lst = qry(1, 0, DEZ, DEZ, DEZ);
        //printf("mx tot %d mn tot %d lst mx %d lst mn %d\n", tot.mx, tot.mn, lst.mx, lst.mn);
        if(lst.mx == 0 && tot.mn >= 0){
            printf("%d ", tot.mx);
        }
        else
            printf("-1 ");
	}
}

