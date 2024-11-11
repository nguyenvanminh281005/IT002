#include<bits/stdc++.h>

using namespace std;

int main () {
    long double x, y, u, v; cin >> x >> y >> u >> v;
    cout << "Khoang cach: " << sqrtl((x - u) * (x - u) + (y - v) * (y - v));
}
