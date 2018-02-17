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
array<array<int, N>, N> A;
auto rng = xor128(42);
vector<tuple<int, int, int>> outputs;

void input() { rep(i, N) rep(j, N) cin >> A[i][j]; }
void print() {
    cout << outputs.size() << endl;
    for (auto e : outputs) {
        cout << get<0>(e) << " ";
        cout << get<1>(e) << " ";
        cout << get<2>(e) << endl;
    }
}
int main() {
    input();

    rep(i, 1000) {
        int X = rng() % N;
        int Y = rng() % N;
        int H = rng() % N + 1;
        outputs.push_back(make_tuple(X, Y, H));
    }
    print();

    return 0;
}
