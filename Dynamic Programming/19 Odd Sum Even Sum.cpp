
/**

Problem : Spoj Ra-one

Any number is Ra-one if the Difference between Sum of digits at even location and Sum of digits at odd location is One (1)
.. For eg... for 234563 is Ra-One number

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

LL go(int pos,int choto,int boro,int odd_sum,int even_sum)
{
    if(pos==B.size())
        return ((odd_sum-even_sum)==1);

    LL &ret = dp[pos][choto][boro][odd_sum][even_sum];

    if(ret!=-1)
        return ret;

    ret = 0;

    int lo = 0, hi = 9;

    if(!choto) hi = B[pos] - '0';
    if(!boro) lo = A[pos] - '0';

    for(int j=lo; j<=hi; j++)
        ret += go(pos+1, choto | (j<hi), boro | (j>lo), ((pos%2)==1 ? j:0) + odd_sum , ((pos%2)==0 ? j:0) +even_sum);

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
        //cout<<"Case "<<q<<": ";

        LL a,b;
        cin>>a>>b;

        B = to_str(b);
        A = to_str(a);
        while(A.size()<B.size())
        {
            A.insert(A.begin(),'0');
        }
        while(A.size()<9)
        {
            A.insert(A.begin(),'0');
            B.insert(B.begin(),'0');
        }
        //cout<<inp<<endl;
        memset(dp,-1,sizeof dp);
        LL ans = go(0,0,0,0,0);
        cout<<ans<<endl;

    }


    return 0;
}
