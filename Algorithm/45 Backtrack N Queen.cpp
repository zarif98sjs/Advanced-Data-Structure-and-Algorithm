
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

/// Function to check if two queens threaten each other or not
bool isSafe(char mat[][N], int r, int c)
{
    /// return false if two queens share the same column
    for (int i = 0; i < r; i++)
        if (mat[i][c] == 'Q')
            return false;

    /// return false if two queens share the same \ diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j] == 'Q')
            return false;

    /// return false if two queens share the same / diagonal
    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
        if (mat[i][j] == 'Q')
            return false;

    return true;
}

void printBoard(char mat[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int cnt = 0;
void nQueen(char mat[][N], int r)
{
    /// if N queens are placed successfully, print the solution
    if (r == N)
    {
        cout<<++cnt<<endl;
        printBoard(mat);
        return;
    }

    /// place Queen at every square in current row r and recur for each valid movement
    for (int i = 0; i < N; i++)
    {
        /// if no two queens threaten each other
        if (isSafe(mat, r, i))
        {
            /// place queen on current square
            mat[r][i] = 'Q';

            /// recur for next row
            nQueen(mat, r + 1);

            /// backtrack and remove queen from current square
            mat[r][i] = '-';
        }
    }
}

int main()
{
    optimizeIO();

    /// mat[][] keeps track of position of Queens in current configuration
	char mat[N][N];

	/// initialize mat[][] by '-'
	memset(mat, '-', sizeof mat);

	nQueen(mat, 0);

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


