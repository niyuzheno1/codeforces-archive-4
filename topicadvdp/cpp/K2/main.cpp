#include <bits/stdc++.h>
using namespace std;

/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
// mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

ll p[100005];

const ll is_query = -(1LL<<62);
struct line {
    ll m, b;
    mutable function<const line*()> succ;
    bool operator<(const line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct dynamic_hull : public multiset<line> { // will maintain upper hull for maximum
    const ll inf = LLONG_MAX;
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

		/* compare two lines by slope, make sure denominator is not 0 */
        ll v1 = (x->b - y->b);
        if (y->m == x->m) v1 = x->b > y->b ? inf : -inf;
        else v1 /= (y->m - x->m);
        ll v2 = (y->b - z->b);
        if (z->m == y->m) v2 = y->b > z->b ? inf : -inf;
        else v2 /= (z->m - y->m);
        return v1 >= v2;
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
      line tmp;
      tmp.m = x;
      tmp.b = is_query;
        auto l = *lower_bound( tmp);
        return ((ll) l.m) * x + l.b;
    }
};

struct segtree {
  int n, depth;
  vector<dynamic_hull> tree;

  void init(int s) {
    n = s;
    tree = vector<dynamic_hull>(4 * s);
    init(0, 0, n - 1);
  }

  void init(int i, int l, int r) {
	for (ll j = l; j <= r; j++) {
		tree[i].insert_line(-a[j], -(j * a[j] - p[j]));
	}
    if (l == r) return;

    int mid = (l + r) / 2;
    init(2 * i + 1, l, mid),
    init(2 * i + 2, mid + 1, r);
  }

  ll query(int l, int r, ll x) {
    return query(0, 0, n-1, l, r, x);
  }

  ll query(int i, int tl, int tr, int ql, int qr, ll x) {
    if (ql <= tl && tr <= qr) return -tree[i].eval(x);
    if (tl > tr || tr < ql || qr < tl) return 1e18;

    int mid = (tl + tr) / 2;
    ll a = query(2 * i + 1, tl, mid, ql, qr, x),
       b = query(2 * i + 2, mid + 1, tr, ql, qr, x);
    return min(a, b);
  }
};

segtree st;

void solve(int tc = 0) {
	cin >> n;
	
	ll r = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		r += a[i];
		p[i] = r;
	}
	
	st.init(n);
	
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll x, y;
		cin >> x >> y;
		--y;
		cout << p[y]<< '\n';
	}
}

// two pointers? maybe
// xor tricks (or general bitwise)

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("code");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc.cpp", "w", stdout);
 		
	cout << setprecision(12) << fixed;
					
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
} 