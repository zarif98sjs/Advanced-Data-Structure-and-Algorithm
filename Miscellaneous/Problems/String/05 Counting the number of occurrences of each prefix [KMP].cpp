
/**

Algorithm       : Calculating the Number of occurrences of each prefix using Prefix Function (KMP)
Time Complexity : O(N)

Idea:

Consider the value of the prefix function π[i] at a position i.
By definition it means that in position i the prefix of length π[i] of the string s appears and ends at position i,
and there doesn't exists a longer prefix that follows this definition.
At the same time shorter prefixes can end at this position.
It is not difficult to see, that we have the same question that we already answered when we computed the prefix function itself:
    Given a prefix of length j that is a suffix ending at position i, what is the next smaller prefix <j that is also a suffix ending at position i.

Thus at the position i ends the prefix of length π[i], the prefix of length π[π[i]−1], the prefix π[π[π[i]−1]−1], and so on, until the index becomes zero.
Thus we can compute the answer in the following way.

Here for each value of the prefix function we first count how many times it occurs in the array π,
and then compute the final answers: if we know that the length prefix i appears exactly ans[i] times,
then this number must be added to the number of occurrences of its longest suffix that is also a prefix.
At the end we need to add 1 to each result, since we also need to count the original prefixes also.

**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

/**

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> countPrefixOccurence(string s,const vector<int> &pi)
{
    int n = s.size();

    vector<int> ans(n + 1); /// ans[i] = the number of occurrence of prefix of length i

    for (int i = 0; i < n; i++)
        ans[pi[i]]++; /// count the largest prefixes ending at i
    for (int i = n-1; i > 0; i--)
        ans[pi[i-1]] += ans[i]; /// adding smaller prefixes which also end at i
    for (int i = 0; i <= n; i++)
        ans[i]++; /// adding the prefix itself to the count

    return ans;
}

int main()
{
    optimizeIO();

    while(1)
    {
        string s;
        cin>>s;

        vector<int>pi = prefix_function(s);
        cout<<pi<<endl;

        vector<int>cnt = countPrefixOccurence(s,pi);
        cout<<cnt<<endl;
    }

    return 0;
}

/**

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}


