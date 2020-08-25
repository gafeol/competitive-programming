#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
 
vector<double> pos;
vector<double> spd;
vector<int> res;
 
vector<int> result(double m, int n) {
    vector<int> r(n);
    for (int i = 0; i < n; i++)
        r[i] = i;
    sort(r.begin(), r.end(), [&m](const int& a, const int& b) -> bool {return pos[a] + spd[a] * m > pos[b] + spd[b] * m; });
    return r;
}
 
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        pos.resize(n);
        spd.resize(n);
        for (int i = 0; i < n; i++) {
            double p, s;
            scanf("%lf %lf", &p, &s);
            pos[i]=(p);
            spd[i]=(s);
        }
        res = result(100001, n);
        for (auto a: res) {
            printf("%d ", a+1);
        } printf("\n");
        double l = 0;
        for(int ii=0;ii+1<res.size();ii++){
            int i = res[ii];
            int j = res[ii+1];
            pair<double, double> bef = {pos[i], spd[i]}, aft = {pos[j], spd[j]}; 
            if(bef.fst > aft.fst)
                swap(bef, aft);
            if(bef.snd <= aft.snd)
                continue;
            l = max(l, (aft.fst - bef.fst)/(bef.snd - aft.snd));
            //printf("i %d inters %.3f\n", i,  (aft.fst - bef.fst)/(bef.snd - aft.snd));
        }
        printf("%.6lf\n", l);
    }
}
