
/**

Backtracking is nothing extra ordinary .
It is just like plain DFS :)

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

// N x N chessboard
#define N 8

int row[N];
char mat[N][N];

bool isSafe(int r,int c)
{
    for(int prev=0; prev<c; prev++)
    {
        if(row[prev]==r || (abs(row[prev]-r)==abs(prev-c))) /// check if shares same row or same diagonal
            return false;
    }

    return true;
}

void printBoard()
{
    /// initialize mat[][] by '-'
	memset(mat, '-', sizeof mat);

    for (int i = 0; i < N; i++)
    {
        mat[i][row[i]] = 'Q';
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int cnt = 0;
void nQueen(int c)
{
    if(c==N)
    {
        cout<<++cnt<<endl;
        printBoard();
        return;
    }

    for(int r=0;r<8;r++)
    {
        if(isSafe(r,c))
        {
            row[c]=r;

            nQueen(c+1);

            /**
            We could have done sth like writing row[c] = -1 to remove the move .
            But that's not necessary here as the previous values gets overwritten in the next call in the line row[c] = r;
            **/
        }
    }
}

int main()
{
    optimizeIO();

	nQueen(0);

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


