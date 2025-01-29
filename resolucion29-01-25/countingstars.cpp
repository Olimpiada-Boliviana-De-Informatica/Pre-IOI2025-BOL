#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> mat(105, vector<char>(105));
int n, m;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool esValido(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void floodfill(int x, int y) {
    mat[x][y] = '#';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (esValido(nx, ny) && mat[nx][ny] == '-') {
            floodfill(nx, ny);
        }
    }
}

int main() {
    int caso = 1;
    while (cin >> m >> n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        int estrellas = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == '-' or mat[i][j] == 'x') {
                    floodfill(i, j);
                    estrellas++;
                }
            }
        }
        cout << "Case " << caso++ << ": " << estrellas << endl;
    }
    return 0;
}