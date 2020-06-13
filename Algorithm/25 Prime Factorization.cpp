
/**

Prime Factorization by finding all primes
-----------------------------------------

There are roughly N/log(N) primes <= N

As we need only prime factors upto sqrt(N) to prime factorize ,
Complexity of prime factorization will be O( (sqrt(N)/log(sqrt(N)) * log(N) )

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

/** Bit Sieve **/

const int pnmax = 1e8+7;
LL LIM;
bitset<pnmax> bs;   /// can sieve upto 1e8 in ~ 1 sec
vector<LL> primes;

void bit_sieve(LL upperbound)
{
    LIM = upperbound + 1;
    bs.set();                                     /// set all bits to 1
    bs[0] = bs[1] = 0;
    for (LL i = 2; i <= LIM; i++) /** If I don't want to know the primes , it is enough to loop upto sqrt(LIM) here **/
        if (bs[i])
        {
            for (LL j = i * i; j <= LIM; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
}

bool isPrime(LL N)
{
    if (N <= LIM)
        return bs[N];                   /// O(1) for small primes

    /** note: only work for N <= (last prime in "primes" vector)^2 . So, if Sieve is done upto 10^6 , can know isPrime upto 10^12 **/
    for (LL x:primes)
        if (N % x == 0)
            return false;
    return true;                    /// it takes longer time if N is a large prime!
}



/** Prime Factorization **/

vector<LL> primeFactors(LL N)
{
    vector<LL>factors;
    LL PF_idx = 0, PF = primes[PF_idx];
    while (N != 1 && (PF * PF <= N))     /// stop at sqrt(N), but N can get smaller
    {
        while (N % PF == 0)
        {
            N /= PF;    /// remove this PF
            factors.push_back(PF);
        }
        PF = primes[++PF_idx];                              /// only consider primes!
    }
    if (N != 1)
        factors.push_back(N);     /// special case if N is actually a prime

    return factors;
}

LL number_of_different_PF(LL N)
{
    LL PF_idx = 0, PF = primes[PF_idx], ans = 0;
    while (N != 1 && (PF * PF <= N))
    {
        if (N % PF == 0)
            ans++;                           /// count this pf only once
        while (N % PF == 0)
            N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans++;
    return ans;
}

int main()
{
    optimizeIO();

    bit_sieve(1e6);

    while(1)
    {
        LL x;
        cin>>x;
        vector<LL>pf = primeFactors(x);
        cout<<pf<<endl;
        cout<<number_of_different_PF(x)<<endl;
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


