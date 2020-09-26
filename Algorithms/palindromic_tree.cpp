struct node{
    int sz;
    node *link;
    map<char, node*> to;
    node() {}
    node(int sz, node* l): sz(sz), link(l) {}
};


node *imp, *par;

struct pal_tree{  
    void init(){
        imp = new node(-1, NULL);
        imp->link = imp;
        par = new node(0, imp);
    }


    pal_tree(string s){
        init();
        node* u = par;
        for(int i=0;i<s.size();i++){
            u = add(u, i, s);
        }
    }

    node* add(node*u, int i, string &s){
        while(1){
            if(i - u->sz > 0 && s[i- u->sz - 1] == s[i])
                break;
            u = u->link;
        }
        if(u->to.find(s[i]) != u->to.end()){
            debug("aresta de u %d com char %c ja existe\n", u->sz, s[i]);
            return u->to[s[i]];
        }
        else{
            debug("novo no sz %d\n", u->sz+2);
            node *l = u->link;
            while(s[i-l->sz-1] != s[i])
                l = l->link;
            debug("to no l %d\n", l->sz);
            if(l->sz > -1)
                assert(l->to.find(s[i]) != l->to.end());
            l = (l->to.find(s[i]) != l->to.end() ? l->to[s[i]] : par);

            node *newNode = new node(u->sz + 2, l);
            u->to[s[i]] = newNode;
            debug("retorna newnode\n");
            return newNode;
        }
    }

};



int main (){
    auto t = pal_tree(s);
}

