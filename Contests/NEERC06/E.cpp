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

#define qtd snd
#define prc fst
#define id fst

const int MAXN = 11234;

int n, m, k;
int s[MAXN];

set<pii, greater<pii>> buy;
map<int, deque<pii>> buybook;
set<pii> sell;
map<int, deque<pii>> sellbook;

int cancelou[MAXN];

pii bstbuy(){
    if(buy.empty())
        return {0, 0};
    return *buy.begin();
}

pii bstsell(){
    if(sell.empty())
        return {99999, 0}; // CUIDADO PRA NAO CONFUNDIR COM VALOR REAL
    return *sell.begin();
}

inline void qry(){
    printf("QUOTE ");
    printf("%d %d - ", bstbuy().qtd, bstbuy().prc);
    printf("%d %d\n", bstsell().qtd, bstsell().prc);
}

inline void addSell(int q, int p, int id){
    if(!sellbook[p].empty() && sell.lower_bound({p, -1})->prc == p){
        int prvq = sell.lower_bound({p, -1})->qtd;
        sell.erase({p, prvq});
        sell.insert({p, prvq + q});
    }
    else{
        sell.insert({p, q});
    }
    sellbook[p].emplace_back(id, q);
}

inline void rmvSell(int q, int p){
    while(q){
        pii &fstSell = sellbook[p].front();
        int qtd = min(q, fstSell.qtd);
        q -= qtd;
        fstSell.qtd -= qtd;
        if(!fstSell.qtd)
            sellbook[p].pop_front();
        auto it =  *sell.begin();
        sell.erase(it);
        it.qtd -= qtd;
        if(it.qtd)
            sell.insert(it);
    }
}

inline void addBuy(int q, int p, int id){
    if(!buybook[p].empty() && buy.lower_bound({p, INT_MAX})->prc == p){
        int prvq = buy.lower_bound({p, INT_MAX})->qtd;
        buy.erase({p, prvq});
        buy.insert({p, prvq + q});
    }
    else{
        buy.insert({p, q});
    }
    buybook[p].emplace_back(id, q);
}

inline void rmvBuy(int q, int p){
    while(q){
        pii &fstBuy = buybook[p].front();
        int qtd = min(q, fstBuy.qtd);
        q -= qtd;
        fstBuy.qtd -= qtd;
        if(!fstBuy.qtd)
            buybook[p].pop_front();
        auto it =  *buy.begin();
        buy.erase(it);
        it.qtd -= qtd;
        if(it.qtd)
            buy.insert(it);
    }
}

inline void print(){
        printf("SELL:\n");
        for(auto it: sell){
            printf("(%d %d) ", it.fst, it.snd);
        }
        puts("");
        for(auto it: sellbook){
            printf("(%d: ", it.fst);
            for(auto itt: it.snd){
                printf("(%d %d) ", itt.fst, itt.snd);
            }
            puts(")");
        }
        printf("BUY:\n");
        for(auto it: buy){
            printf("(%d %d) ", it.fst, it.snd);
        }
        puts("");
        for(auto it: buybook){
            printf("(%d: ", it.fst);
            for(auto itt: it.snd){
                printf("(%d %d) ", itt.fst, itt.snd);
            }
            puts(")");
        }
}

inline bool trade(){
    if(buy.empty() || sell.empty())
        return false;

    pii bstb = bstbuy();
    pii bsts = bstsell();
    if(bstb.prc < bsts.prc)
        return false; 
    int qtd = min(bstb.qtd, bsts.qtd);
    if(!qtd) return false;
    printf("TRADE %d %d\n", qtd, bsts.prc);
    rmvSell(qtd, bsts.prc);
    rmvBuy(qtd, bstb.prc);
    puts("AFT TRADE:");
    print();
    return true;
}

int t[MAXN], price[MAXN];

int main (){
    freopen("exchange.in", "r", stdin);
    freopen("exchange.out", "w", stdout);
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        char com[20];
        scanf(" %s", com);
        int q, p;
        if(com[0] == 'B'){
            t[a+1] = 0;
            scanf("%d%d", &q, &p);
            price[a+1] = p;
            addBuy(q, p, a+1);

        }
        else if(com[0] == 'S'){
            t[a+1] = 1;
            scanf("%d%d", &q, &p);
            price[a+1] = p;
            addSell(q, p, a+1);
        }
        else{
            int id;
            scanf("%d", &id);
            deque<pii> newDeq;
            if(t[id] == 0){
                for(pii p: buybook[price[id]]){
                    if(p.id != id)
                        newDeq.pb(p);
                    else{
                        int q = p.qtd;
                        auto it =  *buy.lower_bound({price[id], INT_MAX});
                        buy.erase(it);
                        it.qtd -= q;
                        if(it.qtd)
                            buy.insert(it);
                    }
                }
                buybook[price[id]] = newDeq;
            }
            else{
                for(pii p: sellbook[price[id]]){
                    if(p.id != id)
                        newDeq.pb(p);
                    else{
                        int q = p.qtd;
                        auto it =  *sell.lower_bound({price[id], -1});
                        sell.erase(it);
                        it.qtd -= q;
                        if(it.qtd)
                            sell.insert(it);
                    }
                }
                sellbook[price[id]] = newDeq;
            }
        }
        while(trade());
        qry();
	}
}
