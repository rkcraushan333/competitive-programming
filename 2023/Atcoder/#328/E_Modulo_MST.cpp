#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <ranges>
#include <numeric>

int main() {
    using namespace std;

    unsigned N, M;
    unsigned long K;
    cin >> N >> M >> K;
    vector<tuple<unsigned, unsigned, unsigned long>> edges(M);
    for (auto&&[u, v, cost] : edges){
        cin >> u >> v >> cost;
        --u;
        --v;
    }

    basic_string<bool> use_edges(M, false); // Among M edges
    ranges::fill(use_edges | views::take(N - 1), true); // Use (N - 1) edges
    ranges::reverse(use_edges);

    // Use disjoint set union (DSU) (or Union-Find) to determine if they form a spanning tree
    vector<unsigned> uf(N), sz(N, 1);
    const auto find{[&uf](auto i) {
        while (i != uf[i])i = uf[i] = uf[uf[i]];
        return i;
    }};
    const auto unite{[&uf, &sz, find](auto i, auto j) -> bool {
        i = find(i);
        j = find(j);
        if (i == j)return false;
        if (sz[i] < sz[j])swap(i, j);
        sz[i] += sz[j];
        uf[j] = i;
        return true;
    }};

    unsigned long ans{K};
    const auto chmin{[](auto &&x, const auto &y) {
        if (x > y)x = y;
        return x;
    }};

    do
        chmin(ans, [&] {
            // 
            iota(begin(uf), end(uf), 0U);
            ranges::fill(sz, 1U);

            unsigned long cost_sum{};
            for (const auto i : views::iota(0U, M))
                if (use_edges[i]) {
                    const auto&[u, v, cost]{edges[i]};
                    if (!unite(u, v)) // Once a cycle is found
                        return K; // return a sufficiently large value
                    cost_sum += cost;
                }
            // If they form a spanning tree
            return cost_sum % K; // return its cost
        }());
    while (ranges::next_permutation(use_edges).found);

    cout << ans << endl;

    return 0;
}
