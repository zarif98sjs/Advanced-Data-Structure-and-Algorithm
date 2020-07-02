
/**

If we use Radix Sort , sorting complexity will be O(N)

Time Complexity : O( N (logN) )

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

void radix_sort(vector<pair<PII,int>> &v)
{
    int n = v.size();

    {
        vector<int>cnt(n); /// for counting sort

        for(auto el:v)
            cnt[el.F.S]++; /// first sort according to second element

        vector<pair<PII,int>> nv(n);
        vector<int>pos(n); /// pos[i] = first empty position in bucket i

        pos[0] = 0;
        for(int i=1; i<n; i++)
            pos[i] = pos[i-1] + cnt[i-1];

        for(auto el:v)
        {
            int i = el.F.S; /// bucket
            nv[pos[i]] = el; /// putting element in bucket
            pos[i]++; /// empty position in bucket i increased
        }

        v = nv;
    }

    {
        vector<int>cnt(n); /// for counting sort

        for(auto el:v)
            cnt[el.F.F]++; /// first sort according to second element

        vector<pair<PII,int>> nv(n);
        vector<int>pos(n); /// pos[i] = first empty position in bucket i

        pos[0] = 0;
        for(int i=1; i<n; i++)
            pos[i] = pos[i-1] + cnt[i-1];

        for(auto el:v)
        {
            int i = el.F.F; /// bucket
            nv[pos[i]] = el; /// putting element in bucket
            pos[i]++; /// empty position in bucket i increased
        }

        v = nv;
    }
}

vector<int> buildSuffixArray(string s)
{
    s += "$";

    int n = s.size();

    /// init p , c

    vector<PII>v(n);

    for(int i=0; i<n; i++)
        v[i] = {s[i],i};
    sort(ALL(v));

    vector<int>p(n), c(n);
    for(int i=0; i<n; i++)
        p[i] = v[i].S;

    c[p[0]] = 0;
    for(int i=1; i<n; i++)
    {
        if(v[i].F!=v[i-1].F)
            c[p[i]] = c[p[i-1]] + 1;
        else
            c[p[i]] = c[p[i-1]];
    }

    /// logN times

    int k = 0;

    while((1<<k) < n)
    {
        vector<pair<PII,int>>v(n);

        for(int i=0; i<n; i++)
            v[i] = {{ c[i],c[(i+(1<<k))%n] }, i};

        radix_sort(v);

        for(int i=0; i<n; i++)
            p[i] = v[i].S;

        c[p[0]] = 0;
        for(int i=1; i<n; i++)
        {
            if(v[i].F!=v[i-1].F)
                c[p[i]] = c[p[i-1]] + 1;
            else
                c[p[i]] = c[p[i-1]];
        }

        k++;
    }

    return p;
}

bool binarySearch(int lo,int hi,string s,string key,vector<int> &ara)
{
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;

        string chk = s.substr(ara[mid],key.size());

        if(chk<key) lo = mid + 1;
        else if (chk>key) hi = mid - 1;
        else return true;
    }

    return false;
}

int main()
{
    optimizeIO();

    string s;
    cin>>s;

    int n = s.size();

    vector<int>p = buildSuffixArray(s);

//    for(int i=0; i<(int)p.size(); i++)
//        cout<<p[i]<<" ";

    int q;
    cin>>q;

    while(q--)
    {
        string sub;
        cin>>sub;

        if(binarySearch(0,n,s,sub,p)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
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


