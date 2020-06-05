
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

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e6+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

const double eps = 1e-9;

/// Number of digits in N factorial
int factorialDigitExtended ( int n, int base ) {
    double x = 0;
    for ( int i = 1; i <= n; i++ ) {
        x += log10 ( i ) / log10(base); // Base Conversion
    }
    int res = x + 1 + eps;
    return res;
}

/// Prime Factorization of N Factorial O(N*log(N))
void factFactorize ( int n ) {
    for ( int i = 0; i < primes.size() && primes[i] <= n; i++ ) {
        int x = n;
        int freq = 0;

        while ( x / primes[i] ) {
            freq += x / primes[i];
            x = x / primes[i];
        }

        printf ( "%d^%d\n", primes[i], freq );
    }
}

/// Find the first K digits of N!
int leadingDigitFact ( int n, int k ) {
    double fact = 0;

    // Find log(N!)
    for ( int i = 1; i <= n; i++ ) {
        fact += log10 ( i );
    }

    // Find the value of q
    double q = fact - floor ( fact+eps );

    double B = pow ( 10, q );

    // Shift decimal point k-1 \times
    for ( int i = 0; i < k - 1; i++ ) {
        B *= 10;
    }

    // Don't forget to floor it
    return floor(B+eps);

}

int main()
{
    optimizeIO();

}


