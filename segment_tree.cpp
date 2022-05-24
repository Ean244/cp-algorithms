struct node {
  int s, e, m;
  int val;
  node *l, *r;

  node(int S, int E) {
    s = S;
    e = E;
    m = (s + e) / 2;
    val = 0;

    if (s != e) {
      l = new node(s, m);
      r = new node(m + 1, e);
    }
  }

  void update(int u, int v) {
    if (s == e) {
      val = v;
      return;
    }

    if (u <= m) {
      l->update(u, v);
    } else {
      r->update(u, v);
    }

    val = min(l->val, r->val);
  }

  int query(int S, int E) {
    if (s == S and E == e) return val;
    else if (S > m) return r->query(S, E);
    else if (E <= m) return l->query(S, E);
    else return min(l->query(S, m), r->query(m + 1, E));
  }

};