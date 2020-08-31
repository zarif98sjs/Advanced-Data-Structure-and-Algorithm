
/**

Range Prime Factorization (OPTIMIZED)
===============================

Bruteforce Range Factorization
------------------------------
Segmented Sieve        + Bruteforce prime factorization
O( (R-L+1) log(logR) ) + O( (R-L) * (sqrt(N)/log(sqrt(N)) * log(N)) )

For larger N value (like 1e12) it will get TLE

Optimization Idea 1 (will eventually fail) :
--------------------------------------------
using SPF (smallest prime factors) we could do prime factorization in logN , but we can't find all spf in [1,1e12] in memory limit
will optimize for lower values of N

Optimization Idea 2 :
--------------------
modifying segmented sieve to get all the prime factors of a number without the powers
and later use this information to Factorize in logN
As we don't need to iterate upto logN for every Number , the factorization complexity will reduce to logN

**/


/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif

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

#define int long long

/**
Segmented Sieve
Range of [L,R] ~ 1e7 and R ~ 1e12
**/

const int pnmax = 1e6+10;  /** ~ sqrt(R) **/
const int pnmax2 = 5e5+10; /** diff of R and L **/

LL LIM = 1e6+5; /** ~ sqrt(R) **/
vector<LL>primes;
bool isP[pnmax];
bool isPFinal[pnmax2];

void sieve()
{
    for(LL i=2; i<=LIM; i++)
        isP[i] = true;

    for(LL i=2; i<=LIM; i++) /** If I don't want to know the primes , it is enough to loop upto sqrt(LIM) here **/
    {
        if(isP[i]==true)
        {
            primes.push_back(i);
            for(LL j=i*i; j<=LIM; j+=i)
                isP[j]=false;
        }
    }
}

/** Prime Factorization **/
vector<vector<LL>>factorization(pnmax2);

vector<LL> primeFactors(LL N,vector<LL>&factors_init)
{
    vector<LL>factors;
    for(auto PF:factors_init)     /// stop at sqrt(N), but N can get smaller
    {
        while (N % PF == 0)
        {
            N /= PF;    /// remove this PF
            factors.push_back(PF);
        }
    }
    if (N != 1) factors.push_back(N);     /// special case if N is actually a prime

    return factors;
}

/** Number of Divisors **/
LL NOD[pnmax2];

LL number_of_Divisors(LL N,vector<LL>&factors_init)
{
    LL ans = 1;

    for(auto PF:factors_init)
    {
        LL power = 0;     /// count the power
        while (N % PF == 0)
        {
            N /= PF;
            power++;
        }
        ans *= (power + 1);  /// according to the formula
    }

    if (N != 1) ans *= 2;  /// (last factor has pow = 1, we add 1 to it)

    return ans;
}

void segmented_sieve(LL L,LL R)
{
    vector<vector<int>>factors_init(pnmax2);

    /// Step 1: we will identify all the prime factors of Numbers in the range [l,r] . But we will not know the powers . That we will do in Step 2
    for(auto p:primes)
    {
        if(p*p > R)
            break;

        LL j=p*p;

        if(j<L)
            j=((L+p-1)/p)*p;

        for(; j<=R; j+=p)
            factors_init[j-L].push_back(p);

    }

    /// Step 2 : Find the powers
    for(LL i=L; i<=R; i++)
    {
        NOD[i-L] = number_of_Divisors(i,factors_init[i-L]);
        factorization[i-L] = primeFactors(i,factors_init[i-L]);
    }
}

int32_t main()
{
    optimizeIO();

    sieve();

    int tc;
    cin>>tc;

    while(tc--)
    {
        LL l,r;
        cin>>l>>r;

        segmented_sieve(l,r);

        for(int i=l;i<=r;i++)
        {
            cout<<"Number : "<<i<<endl;
            cout<<"NOD : "<<NOD[i-l]<<endl;
            cout<<"Factorization : "<<endl;
            DBG(factorization[i-l]);
        }
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
    for(T i:v)
    {
        os<<i<<" " ;
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
