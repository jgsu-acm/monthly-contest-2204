#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

const int N = 1e6 + 1;

bool vis[N];
int k_cnt[N], exact_k_cnt[N];

void init_prime() {
    vector<int> prime;
    prime.reserve(8e4);
    for (int i = 2; i < N; ++i) {
        if (!vis[i]) {
            prime.push_back(i);
            k_cnt[i] = 1;
        }
        for (auto j = prime.begin(); j != prime.end() && i * *j < N; ++j) {
            vis[i * *j] = true;
            k_cnt[i * *j] = k_cnt[i] + 1;
            if (i % *j == 0) break;
        }
    }
}

int main() {
    init_prime();
    int kase;
    cin >> kase;
    while (kase--) {
        i64 l, r, k;
        cin >> l >> r >> k;
        if (k == 0) {
            cout << (l == 1 ? "1\n" : "0\n");
            continue;
        }
        if (k > log2(r)) {
            cout << "0\n";
            continue;
        }

        if (l == 1) l = 2;
        if (k == 1) {
            for (int i = 0; i <= r - l; ++i) vis[i] = 1;
        } else {
            memset(vis, 0, sizeof(vis[0]) * (r - l + 1));
            for (int i = 2; i < N; ++i)
                if (k_cnt[i] == k - 1)
                    for (i64 j = max((i64)ceil(1.0 * l / i) * i, (i64)2 * i); j <= r; j += i) vis[j - l] = 1;
        }
        for (int i = 2; i < N; ++i)
            if (k_cnt[i] == k)
                for (i64 j = max((i64)ceil(1.0 * l / i) * i, (i64)2 * i); j <= r; j += i) vis[j - l] = 0;

        int k_tot = 0;
        for (int i = 0; i <= r - l; ++i) k_tot += vis[i];

        cout << k_tot << '\n';
    }
    return 0;
}