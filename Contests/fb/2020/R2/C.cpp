#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

#define int long long 

const int MAXN = 5123456;

ll n, m, k, ne;
int x[MAXN], y[MAXN];
int i[MAXN];
ll w[MAXN], we[MAXN];

void apg(multiset<ll> &q, ll x){
    assert(q.find(x) != q.end());
    q.erase(q.find(x));
}

main (){
    for_tests(t, tt){
        ll A, B, C;
        scanf("%lld%lld%lld%lld", &n, &m, &ne, &k);
        for(int a=0;a<k;a++)
            scanf("%lld", x+a);

        scanf("%lld%lld%lld", &A, &B, &C);
        for(int a=k;a<n;a++)
            x[a] = (x[a-2]*A + x[a-1]*B  + C)%m;

        for(int a=0;a<k;a++)
            scanf("%lld", y+a);
        scanf("%lld%lld%lld", &A, &B, &C);
        for(int a=k;a<n;a++)
            y[a] = (y[a-2]*A + y[a-1]*B + C)%m;

        ll nar = (n*m + n);
        for(int a=0;a<k;a++)
            scanf("%lld", i+a);
        scanf("%lld%lld%lld", &A, &B, &C);
        for(int a=k;a<ne;a++)
            i[a] = (i[a-2]*A + i[a-1]*B + C)%nar;

        for(int a=0;a<k;a++)
            scanf("%lld", we+a);
        scanf("%lld%lld%lld", &A, &B, &C);
        for(int a=k;a<ne;a++)
            we[a] = (we[a-2]*A + we[a-1]*B + C)%((ll)1e9);

        for(int a=0;a<nar;a++)
            w[a] = 1;

        vector<pii> endp(n);
        vector<bool> hasSegOp(n, false);
        multiset<ll> segOp;
        multiset<ll> bigAr;
        vector<vector<ll>> cost(n, vector<ll>(2, 0)); // NAO TO MANTENDO
        // arestas[comp][0/1] - multiset de custos das arestasno caminho de fst a snd da comp
        vector<vector<multiset<ll>>> arestas(n, vector<multiset<ll>>(2));
        vector<multiset<ll>> totArestas(n);
        vector<int> incomp(nar);
        vector<int> inpath(nar);


        ll solBig = 0;
        ll solSm = 0;
        ll ans = 1;
        for(int a=0;a<n;a++){
            endp[a] = { a*m + x[a], a*m + y[a] };
            //printf("c %lld enp %lld %lld\n", a, endp[a].fst, endp[a].snd);
            hasSegOp[a] = (x[a] != y[a]);
            cost[a][0] = cost[a][1] = 0;
            for(int ar=a*m;ar<(a+1)*m;ar++){
                //printf("analisa aresta %lld \n", ar);
                incomp[ar] = a;
                if(endp[a].fst <= endp[a].snd)
                    inpath[ar] = (ar >= endp[a].fst && ar < endp[a].snd);
                else
                    inpath[ar] = (ar >= endp[a].fst || ar < endp[a].snd);
                cost[a][inpath[ar]] += w[ar];
                arestas[a][inpath[ar]].insert(w[ar]);
                //printf("    c %lld inp %lld w %lld\n", a, inpath[ar], w[ar]);
                totArestas[a].insert(w[ar]);
            }
            solBig += cost[a][0] + cost[a][1];
            solSm += cost[a][0] + cost[a][1];
            ll mx = *totArestas[a].rbegin();
            solBig -= mx;
            solSm -= mx;
            // get seg opt
            if(hasSegOp[a]){
                //printf("tem seg OPt\n");
                ll mx1 = *arestas[a][0].rbegin();
                ll mx2 = *arestas[a][1].rbegin();
                if(mx == mx1)
                    segOp.insert(mx2);
                else
                    segOp.insert(mx1);
                //printf("pegando segOpt %lld %lld %lld\n", mx, mx1, mx2);
            }
            //printf("c %lld endp %lld %lld cost %lld %lld\n", a, endp[a].fst, endp[a].snd, cost[a][0], cost[a][1]);
        }
        if(!segOp.empty())
            solSm -= *segOp.rbegin();

        for(int ar=n*m;ar<n*m+n;ar++){
            bigAr.insert(w[ar]); 
            solSm += w[ar];
            solBig += w[ar];
        }
        solBig -= *bigAr.rbegin();

        for(int ev=0;ev<ne;ev++){
            int ar = i[ev];
            //printf("analisando ar %lld\n", ar);
            if(ar < n*m){ // small
                int c = incomp[ar];
                int p = inpath[ar];

                //desfaz desconto
                ll mx = *totArestas[c].rbegin();
                solBig += mx;
                solSm += mx;
                if(hasSegOp[c])
                    solSm += *segOp.rbegin();

                //retira ar
                solBig -= w[ar];
                solSm -= w[ar];

                if(hasSegOp[c]){
                    ll mx1 = *arestas[c][0].rbegin();
                    ll mx2 = *arestas[c][1].rbegin();
                    if(mx == mx1)
                        apg(segOp, mx2);
                    else
                        apg(segOp, mx1);
                }

                apg(arestas[c][p], w[ar]);
                apg(totArestas[c], w[ar]);

                w[ar] = we[ev];

                totArestas[c].insert(w[ar]);
                arestas[c][p].insert(w[ar]);
                //colocar novo ar
                solBig += w[ar];
                solSm += w[ar];
                mx = *totArestas[c].rbegin();
                solBig -= mx;
                solSm -= mx;
                if(hasSegOp[c]){
                    ll mx1 = *arestas[c][0].rbegin();
                    ll mx2 = *arestas[c][1].rbegin();
                    if(mx == mx1)
                        segOp.insert(mx2);
                    else
                        segOp.insert(mx1);

                    solSm -= *segOp.rbegin();
                }

            }
            else{
                solSm -= w[ar]; 

                solBig += *bigAr.rbegin();
                apg(bigAr, w[ar]);
                solBig -= w[ar];

                w[ar] = we[ev];

                solSm += w[ar];

                solBig += w[ar];
                bigAr.insert(w[ar]);
                solBig -= *bigAr.rbegin();
            }
            //printf("ev %lld solSm %lld solBig %lld\n", ev, solSm, solBig);
            ans = mod(ans*mod(min(solSm, solBig)));
        }
        printf("Case #%lld: %lld\n", tt, ans);
    }
}

