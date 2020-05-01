#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class key, class value, class cmp = less<key>>
using treemap = tree<key, value, less<int>, rb_tree_tag, tree_order_statistics_node_update>; // key, val, comp, implements, 노드 불변 규칙
template<class key, class cmp = less<key>>
using treeset = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef LOCAL_BOOKNU
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// ........................macro.......................... //
#define FOR(i, f, n) for(int (i) = (f); (i) < (int)(n); ++(i))
#define RFOR(i, f, n) for(int (i) = (f); (i) >= (int)(n); --(i))
#define pb push_back
#define emb emplace_back
#define fi first
#define se second
#define ENDL '\n'
#define sz(A) (int)(A).size()
#define ALL(A) A.begin(), A.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define next next9876
#define prev prev1234
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long i64;
typedef unsigned long long ui64;
// inline i64 GCD(i64 a, i64 b) { if(b == 0) return a; return GCD(b, a % b); }
inline int getidx(const vi& ar, int x) { return lower_bound(ALL(ar), x) - ar.begin(); } // 좌표 압축에 사용: 정렬된 ar에서 x의 idx를 찾음
inline i64 GCD(i64 a, i64 b) { i64 n; if(a < b) swap(a, b); while(b != 0) { n = a % b; a = b; b = n; } return a; }
inline i64 LCM(i64 a, i64 b) { if(a == 0 || b == 0) return GCD(a, b); return a / GCD(a, b) * b; }
inline i64 CEIL(i64 n, i64 d) { return n / d + (i64)(n % d != 0); } // 음수일 때 이상하게 작동할 수 있음.
inline i64 ROUND(i64 n, i64 d) { return n / d + (i64)((n % d) * 2 >= d); }
const i64 MOD = 1e9+7;
inline i64 POW(i64 a, i64 n) {
    assert(0 <= n);
    i64 ret;
    for(ret = 1; n; a = a*a%MOD, n /= 2) { if(n%2) ret = ret*a%MOD; }
    return ret;
}
template <class T> ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    int cnt = 0;
    for(auto vv : v) { os << vv; if(++cnt < v.size()) os << ","; }
    return os << "]";
}
template <class T> ostream& operator<<(ostream& os, set<T> v) {
    os << "[";
    int cnt = 0;
    for(auto vv : v) { os << vv; if(++cnt < v.size()) os << ","; }
    return os << "]";
}
template <class L, class R> ostream& operator<<(ostream& os, pair<L, R> p) { return os << "(" << p.fi << "," << p.se << ")"; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H, debug_out(T...); }
// ....................................................... //
const int MAXN = 110;
int nn;
int g[MAXN][MAXN][2];
set<vi> st; // 구조물 정보들
void input() {
    // ----- Local Test Input ----- //

    // ----- Execute solution ----- //
    // debug(solution());
}

// 일단 짓고 보자 (이미 있으면 false)
void build(int x, int y, int t) {
    st.insert({ x, y, t });
    g[x][y][t] = 1;
}

void destroy(int x, int y, int t) {
    st.erase({ x, y, t });
    g[x][y][t] = 0;
}

bool chkpos(int x, int y) {
    return 0 <= x && x <= nn && 0 <= y && y <= nn;
}

// 현재 상태로 가능한가?
bool cando() {
    for(vi u : st) {
        int x = u[0], y = u[1], t = u[2];
        if(t == 0) {
            if(y == 0) continue; // 바닥에 있으면 무조건 가능!
            if(g[x][y-1][0]) continue; // 아래에 기둥 있으면 가능!
            if((x && g[x-1][y][1]) || g[x][y][1]) continue; // 기둥 왼 혹은 오에 들보 있으면 가능! --> 여기서 x overflow 발생했었음 ㅅㅂ
            return false;
        } else {
            if(y == 0)return false; // 바닥에 설치하려고 함
            if(g[x][y-1][0] || g[x+1][y-1][0]) continue; // 들보 아래에 기둥 있으면 OK
            if(x == 0) return false; // 오른쪽에 들보가 무조건 없으
            if(g[x-1][y][1] && g[x+1][y][1]) continue; // 양 옆에 들보가 있다.
            return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> query) {
    nn = n;
    memset(g, 0, sizeof(g));
    st.clear();
    for(vi& q : query) {
        int x = q[0], y = q[1], t = q[2], h = q[3];
        if(h == 0) {
            // 삭제
            destroy(x, y, t); // 삭제해보고
            if(!cando()) build(x, y, t); // 삭제했는데 이상해지면 복구하고
        } else {
            // 설치
            build(x, y, t); // 설치해보고
            if(!cando()) destroy(x, y, t); // 설치했는데 이상하면 복구하고 
        }
    }
    vvi ret(0);
    for(vi x : st) ret.pb(x);
    sort(ALL(ret));
    return ret;
}

// ................. main .................. //
#ifdef LOCAL_BOOKNU
int main(void) {
    freopen("__IO/input.txt", "r", stdin);
    // freopen("__IO/out.txt", "w", stdout);
    cin.tie(0), ios_base::sync_with_stdio(false);
    input();
    return 0;
}
#endif
