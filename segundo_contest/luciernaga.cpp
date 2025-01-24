#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h, altura;
    cin >> n >> h;
    vector<long long> techo(h, 0);
    vector<long long> techo_acum(h, 0);
    vector<long long> piso(h, 0);
    vector<long long> piso_acum(h, 0);
    for (int i = 0; i < n; i++) {
        cin >> altura;
        if (i % 2 == 0) {
            piso[altura - 1]++;
        } else {
            techo[h - altura]++;
        }
    }
    for (int alt = h - 2; alt >= 0; alt--) {
        piso_acum[alt] = piso_acum[alt + 1] + piso[alt];
    }
    for (int alt = 1; alt < h; alt++) {
        techo_acum[alt] = techo_acum[alt - 1] + techo[alt];
    }
    int best = n;
    int count = 0;
    for (int i = 0; i < h; ++i) {
        if (techo_acum[i] + piso_acum[i] < best) {
            best = techo_acum[i] + piso_acum[i];
            count = 1;
        } else if (techo_acum[i] + piso_acum[i] == best) {
            count++;
        }
    }
    cout << best << " " << count;
}