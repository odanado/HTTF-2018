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
using Output = tuple<int, int, int>;
using Outputs = vector<Output>;
Outputs outputs;
using i64 = int64_t;

void put(Board &board, const Output &e) {
    int X = get<0>(e), Y = get<1>(e), H = get<2>(e);
    rep(y, N) rep(x, N) { board[y][x] += max(0, H - abs(x - X) - abs(y - Y)); }
}

Board make_board(const Outputs &outputs) {
    Board ret = {};
    for (auto e : outputs) {
        put(ret, e);
    }
    return ret;
}
xor128 rng;
Output gen_output() { return Output(rng() % N, rng() % N, rng() % N + 1); }
int main(int argc, char const *argv[]) {
    int seed = stoi(argv[1]);
    rng = xor128(seed);
    rep(i, 1000) {
        auto out = gen_output();
        outputs.push_back(out);
    }
    auto board = make_board(outputs);

    rep(i, N) {
        rep(j, N) cout << board[i][j] << (j + 1 != N ? " " : "");
        cout << endl;
    }

    return 0;
}
