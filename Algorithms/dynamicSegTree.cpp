// Min val dynamic segtree
//
const int INF = INT_MAX;
struct arv{
    int mn;
    arv *L, *R;
    arv() : mn(INF), L(NULL), R(NULL) {}
    arv* left() { // create if unexistent
        if(L == NULL){
            L = new arv();
        }
        return L;
    }
    arv* right() { // create if unexistent
        if(R == NULL)
            R = new arv();
        return R;
    }
};

int val(arv* u){
    if(u == NULL)
        return INF;
    return u->mn;
}

vector<arv*> root;

void upd(arv* u, int i, int j, int l, int x){
    if(i == j){
        u->mn = x;
        return ;
    }
    int m = (i+j)/2;
    if(l <= m)
        upd(u->left(), i, m, l, x);
    else
        upd(u->right(), m+1, j, l, x);
    u->mn = min(val(u->L), val(u->R));
}

int qry(arv *u, int i, int j, int l, int r){
    if(u == NULL || l > j || r < i) 
        return INF;
    if(i >= l && j <= r)
        return u->mn; 
    int m = (i + j)/2;
    return min(qry(u->L, i, m, l, r),
                qry(u->R, m+1, j, l, r));
}

void init(int n){
    root.clear();
    root.resize(n+1);
    for(int a=1;a<=n;a++){
        root[a] = new arv();
    }
}

void clean(arv* u){
    if(u == NULL) return;
    clean(u->L);
    clean(u->R);
    free(u);
}

