#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> palabras;
    string palabra;
    while (cin >> palabra) {
        palabras.push_back(palabra);
    }
    set<string> respuesta;
    for (int i = 0; i < palabras.size(); i++) {
        for (int j = i + 1; j < palabras.size(); j++) {
            respuesta.insert(palabras[i] + palabras[j]);
            respuesta.insert(palabras[j] + palabras[i]);
        }
    }
    for (auto palabra : respuesta) {
        cout << palabra << '\n';
    }
}
