#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/** 5.3 Manacher’s Algorithm
 *
 * 用來計算迴文數量，t不可為str中含有字元
 *
 */
int manacher(const string& s)
{
    int z[s.length()*2];
    z[0]=0;
    string t = ".";
    for (int i = 0; i < s.length(); ++i) t += s[i], t += '.';
    int l = 0, r = 0, ans = 0;
    for (int i = 1; i < t.length(); ++i)
    {
        z[i] = (r > i ? min(z[2 * l - i], r - i) : 1);
        while (i - z[i] >= 0 && i + z[i] < t.length() && t[i - z[i]] == t[i + z[i]])
            ++z[i];
        if (i + z[i] > r) r = i + z[i], l = i;
    }
    for (int i = 1; i < t.length(); ++i) ans = max(ans, z[i] - 1);
    return ans;
}

int main()
{
    string str="aefwababa";
    int k=manacher(str);
    cout<<k;
    return 0;
}
