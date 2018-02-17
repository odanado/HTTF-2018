#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

class xor128 {
 public:
    static constexpr unsigned min() { return 0u; }        // 乱数の最小値
    static constexpr unsigned max() { return UINT_MAX; }  // 乱数の最大値
    unsigned operator()() { return random(); }
    xor128() {
        std::random_device rd;
        w = rd();
    }
    xor128(unsigned s) { w = s; }  // 与えられたシードで初期化
 private:
    unsigned x = 123456789u, y = 362436069u, z = 521288629u, w;
    unsigned random() {
        unsigned t;
        t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    };
};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
constexpr int N = 100;
using Board = array<array<int, N>, N>;
Board A;
auto rng = xor128(42);
using Outputs = vector<tuple<int, int, int>>;
Outputs outputs;
using i64 = int64_t;

void input() { rep(i, N) rep(j, N) cin >> A[i][j]; }
void print() {
    cout << outputs.size() << endl;
    for (auto e : outputs) {
        cout << get<0>(e) << " ";
        cout << get<1>(e) << " ";
        cout << get<2>(e) << endl;
    }
}

Board make_board(const Outputs &outputs) {
    Board ret = {};
    for (auto e : outputs) {
        int X = get<0>(e), Y = get<1>(e), H = get<2>(e);
        rep(y, N) rep(x, N) { ret[y][x] += max(0, H - abs(x - X) - abs(y - Y)); }
    }
    return ret;
}

i64 calc_diff(const Board &A, const Board &B) {
    i64 ret = 0;
    rep(i, N) rep(j, N) ret += abs(A[i][j] - B[i][j]);
    return ret;
}

int main() {
    input();
    i64 best = -1;
    rep(_, 100) {
        Outputs cand;
        rep(i, 1000) {
            int X = rng() % N;
            int Y = rng() % N;
            int H = rng() % N + 1;
            cand.push_back(make_tuple(X, Y, H));
        }
        auto B = make_board(cand);
        auto diff = calc_diff(A, B);
        if (best == -1 || best > diff) {
            best = diff;
            outputs = cand;
            // cerr << diff << endl;
        }
    }
    print();
    auto B = make_board(outputs);
    auto diff = calc_diff(A, B);
    cerr << diff << endl;

    return 0;
}
