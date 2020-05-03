
/**

Problem : Hackerrank Digit Min Max Scores

A digit is a min-digit in a number if it is less than both its adjacent digits.
Similarly, a digit is a max-digit in a number if it is greater than both its
adjacent digits. The min-max-score of number is the total number of min-digits
and max-digits (ignoring the first and last digit) contained in it.

Given a and b, find the sum of the min-max-scores of all numbers between
a and b( including a and b).

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

LL dp[20][2][2][20][3][2][20];

LL go(int pos,int choto,int boro,int prev,int last_cmp,int non_zero,int score)
{
    if(pos==B.size())
    {
        if(non_zero)
            return score;
        return 0;
    }

    LL &ret = dp[pos][choto][boro][prev][last_cmp][non_zero][score];

    if(ret!=-1)
        return ret;

    ret = 0;

    int lo = 0, hi = 9;

    if(!choto) hi = B[pos] - '0';
    if(!boro) lo = A[pos] - '0';

    for(int j=lo; j<=hi; j++)
    {
        int add = 0 , current_cmp = 0;

        if(non_zero)
        {
            if(j<prev)
                current_cmp = 1;
            else if (j>prev)
                current_cmp = 2;
        }

        if((current_cmp^last_cmp)==3)
            add = 1;

        ret += go(pos+1, choto | (j<hi), boro | (j>lo),j,current_cmp,non_zero|(j>0),score+add);
    }


    return ret;
}

int main()
{
    optimizeIO();

    int tc=1;

    for(int q=1; q<=tc; q++)
    {
        LL a,b;
        cin>>a>>b;

        B = to_str(b);
        A = to_str(a);
        while(A.size()<B.size())
        {
            A.insert(A.begin(),'0');
        }
//        while(A.size()<13)  // this part is needed as the indexing is from last digit
//        {
//            A.insert(A.begin(),'0');
//            B.insert(B.begin(),'0');
//        }
        memset(dp,-1,sizeof dp);
        LL ans = go(0,0,0,0,0,0,0);
        cout<<ans<<endl;

    }


    return 0;
}
