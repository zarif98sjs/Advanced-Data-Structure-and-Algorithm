
/**

Problem : LightOj 1068
Divisibility check by Digit Sum

An integer is divisible by 3 if the sum of its digits is also divisible by 3.
For example, 3702 is divisible by 3 and 12 (3+7+0+2) is also divisible by 3.
This property also holds for the integer 9.

In this problem, we will investigate this property for other integers.

For each case, output the case number and the number of integers in the range [A, B]
which are divisible by K and the sum of its digits is also divisible by K.

**/


/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e3+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

string A,B;

int k;

LL dp[10][2][2][150][150];

LL go(int pos,int choto,int boro,int sum,int div)
{
    if(pos==B.size())
        return (sum==0) && (div==0);

    LL &ret = dp[pos][choto][boro][sum][div];

    if(ret!=-1)
        return ret;

    ret = 0;

    int lo = 0, hi = 9;

    if(!choto) hi = B[pos] - '0';
    if(!boro) lo = A[pos] - '0';

    for(int j=lo; j<=hi; j++)
        ret += go(pos+1, choto | (j<hi), boro | (j>lo), (sum+j)%k, (((div*10)%k)+j)%k );

    return ret;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {

        //cout<<"----------------------"<<endl;
        cout<<"Case "<<q<<": ";

        LL a,b;
        cin>>a>>b>>k;

        if(k>81)
        {
            cout<<0<<endl;
            continue;
        }

        B = to_str(b);
        A = to_str(a);
        while(A.size()<B.size())
        {
            A.insert(A.begin(),'0');
        }

        //cout<<inp<<endl;
        memset(dp,-1,sizeof dp);
        LL ans = go(0,0,0,0,0);
        cout<<ans<<endl;

    }


    return 0;
}
