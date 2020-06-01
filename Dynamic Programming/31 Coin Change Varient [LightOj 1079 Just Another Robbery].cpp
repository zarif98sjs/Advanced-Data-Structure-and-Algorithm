
/**

Problem : LightOJ 1079

Idea
====

DP

- Probability of robbing bank a1 , a2 ... an = (1-p1) * (1-p2) * ... (1-pn)
where pi = the probability of getting caught from robbing bank i

- Use this idea to implement a variation of coin change dp .

**/

/**Which of the favors of your Lord will you deny ?**/

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
const LL LINF = 1e17;

template<class T>
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

double dp[10005]; /** dp[s] = Probability of robbing 's' millions i.e not getting caught robbing 's' millions **/
int money[105];
double p[105];

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    for(int qq=1; qq<=tc; qq++)
    {
        memset(dp,0,sizeof dp);

        int n;
        double thresh;
        cin>>thresh>>n;

        LL sum = 0;

        for(int i=1;i<=n;i++)
            cin>>money[i]>>p[i] , sum += money[i];

        dp[0] = 1.0; /** Probability of robbing 0 million **/

        for(int i=1;i<=n;i++)
            for(int s=sum;s-money[i]>=0;s--)
                dp[s] = max(dp[s],dp[s-money[i]]*(1-p[i])); /** As prob of not getting caught , So, (1-p[i]) is multiplied **/

//        for(int s=sum;s>=0;s--)
//            cout<<s<<" : "<<dp[s]<<endl;

        for(int s=sum;s>=0;s--)
            if(1-dp[s]<thresh) /** Prob of getting caught < threshold value **/
                {cout<<"Case "<<qq<<": "<<s<<endl;break;}

    }

    return 0;
}

/**

1
0.29 4
7 0.04
10 0.69
2 0.78
2 0.78

Ans = 7


**/


