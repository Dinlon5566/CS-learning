#include <bits/stdc++.h>
using namespace std;

template <typename T> tuple<T, T, T> extgcd(T a, T b) {
if (!b) return make_tuple(a, 1, 0);
T d, x, y;
tie(d, x, y) = extgcd(b, a % b);
return make_tuple(d, y, x - (a / b) * y);
}


long long crt(vector<int> mod, vector<int> a) {
long long mult = mod[0];
int n = (int)mod.size();
long long res = a[0];
for (int i = 1; i < n; ++i) {
long long d, x, y;
tie(d, x, y) = extgcd(mult, mod[i] * 1ll);
if ((a[i] - res) % d) return -1;
long long new_mult = mult / __gcd(mult, 1ll * mod[i]) * mod
[i];
res += x * ((a[i] - res) / d) % new_mult * mult % new_mult;
mult = new_mult;
((res %= mult) += mult) %= mult;
}
return res;
}

int main()
{
    vector<int> mod={3,5,7};
    vector<int> a={2,3,2};
    cout<<crt(mod,a);

    return 0;
}
