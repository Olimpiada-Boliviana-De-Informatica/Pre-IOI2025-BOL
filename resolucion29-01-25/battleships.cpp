#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> mat(105, vector<char>(105));
int n, t;
int hayBarco = 0;

bool esValido(int x, int y) {
    // if (x >= 0 && x < n && y >= 0 && y < n) {
    //     return true;
    // }
    // return false;
    return x >= 0 && x < n && y >= 0 && y < n;
}

// Return 0 cuando barco es de puro @, devuelvo 1 cuando hay al menos una x
void contarBarco(int x, int y) {
    if (mat[x][y] == 'x') {
        hayBarco = 1;
    }
    mat[x][y] = '.';
    if (esValido(x + 1, y) && (mat[x + 1][y] == '@' or mat[x + 1][y] == 'x')) {
        contarBarco(x + 1, y);
    } else if (esValido(x, y + 1) && (mat[x][y + 1] == '@' or mat[x][y + 1] == 'x')) {
        contarBarco(x, y + 1);
    }
}

int main() {

    cin >> t;
    for (int caso = 1; caso <= t; caso++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        int barcos = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == '@' or mat[i][j] == 'x') {
                    hayBarco = 0;
                    contarBarco(i, j);
                    barcos += hayBarco;
                }
            }
        }
        cout << "Case " << caso << ": " << barcos << endl;
    }
    return 0;
}