#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(const string &s)
{
    vector<int> f(s.size(), 0);

    int k = 0;
    for (int i = 1; i < (int)s.size(); ++i)
    {
        while (k > 0 && s[i] != s[k]) k = f[k - 1];
        if (s[i] == s[k]) ++k;
        f[i] = k;
    }
    return f;
}
vector<int> search(const string &s, const string &t)
{
// return 0-indexed occurrence of t in s
    vector<int> f = kmp(t), res;
    for (int i = 0, k = 0; i < (int)s.size(); ++i)
    {
        while (k > 0 && (k == (int)t.size() || s[i] != t[k])) k = f
                    [k - 1];
        if (s[i] == t[k]) ++k;
        if (k == (int)t.size()) res.push_back(i - t.size() + 1);
    }
    return res;
}
int main()
{
    string A="abc abcdefgaacdefffcdef";
    string B="cdef";
    vector<int> result=search(A,B);
    for(int i:result){
        cout<<i<<"  ";
    }
    return 0;
}
