
/**

Segmented Sieve
===============

Precalculating primes : O( sqrt(R) log(log(sqrt(R))) )
Later segmented sieve : O( (R-L+1) log(logR) )

So,
Time Complexity : O( (R-L+1) log(logR) + sqrt(R) log(log(sqrt(R))) )

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
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl
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

/**

Segmented Sieve

Range of [L,R] ~ 10^5

**/

const int pnmax = 1e6+10;  /** ~ sqrt(R) **/
const int pnmax2 = 1e5+10; /** diff of R and L **/

LL LIM = 1e6+5; /** ~ sqrt(R) **/
vector<LL>primes;
bool isP[pnmax];
bool isPFinal[pnmax2];

void sieve()
{
    for(LL i=2;i<=LIM;i++)
        isP[i] = true;

    for(LL i=2;i<=LIM;i++) /** If I don't want to know the primes , it is enough to loop upto sqrt(LIM) here **/
    {
        if(isP[i]==true)
        {
            primes.push_back(i);
            for(LL j=i*i;j<=LIM;j+=i)
                isP[j]=false;
        }
    }
}

void segmented_sieve(LL L ,LL R)
{
    for(LL i=0; i<=pnmax2; i++)
        isPFinal[i]=true;

    for(LL i=0;i<primes.size();i++)
    {
        LL p=primes[i];
        LL j=p*p;

        if(j<L)
            j=((L+p-1)/p)*p;

        for(;j<=R;j+=p)
            isPFinal[j-L]=false;

    }

    /** print **/
    for(LL i=L;i<=R;i++)
    {
        if(i==1LL)
            continue;

        if(isPFinal[i-L])
            cout<<i<<endl;
    }
}


int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

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


