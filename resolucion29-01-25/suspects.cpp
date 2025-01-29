#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> parent;
vector<int> tamano;

int find(int x) {
    if (parent[x] == -1)
        return x;
    return find(parent[x]);
}

void unir(int a, int b) {
    int A = find(a);
    int B = find(b);
    if (A == B)
        return;
    if (A < B) {
        parent[B] = A;
        tamano[A] += tamano[B];
        tamano[B] = 0;
    } else {
        parent[A] = B;
        tamano[B] += tamano[A];
        tamano[A] = 0;
    }
}

void solve() {
    int k, suspect, prev;
    parent.assign(n + 5, -1);
    tamano.assign(n + 5, 1);
    while (m--) {
        cin >> k;
        prev = -1;
        for (int i = 0; i < k; i++) {
            cin >> suspect;
            if (prev != -1) {
                unir(suspect, prev);
            }
            prev = suspect;
        }
    }
    int c = 0;
    cout << tamano[0] << endl;
}

int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        solve();
    }
    return 0;
}