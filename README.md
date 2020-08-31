# Advanced-Data-Structure-and-Algorithm

# Algorithm

<details>
<summary>  
    
```c++
█▀▀ █▀█ ▄▀█ █▀█ █░█   ▀█▀ █░█ █▀▀ █▀█ █▀█ █▄█
█▄█ █▀▄ █▀█ █▀▀ █▀█   ░█░ █▀█ ██▄ █▄█ █▀▄ ░█░
```
</summary>

* ***Graph Traversal***
  * BFS
    * [Single Source BFS](Algorithm/01%20BFS.cpp) 
    * [Multi Source BFS](Algorithm/37%20Multisource%20BFS.cpp)
  * [DFS](Algorithm/02%20DFS.cpp)
* ***Single Source Shortest Path (SSSP)***
  * [Dijkstra](Algorithm/03%20Dijkstra%20%5BSingle%20Source%20Shortest%20Path%5D.cpp)
  * [Bellman Ford](Algorithm/04%20Bellman%20Ford%20%5BSingle%20Source%20Shortest%20Path%5D.cpp)
* ***All Pair Shortest Path (APSP)***
  * [Floyd Warshall](Algorithm/05%20Floyd%20Warshall%20%5BAll%20Pair%20Shortest%20Path%5D.cpp)
  * [Johnson](Algorithm/06%20Johnson%20%5BAll%20Pair%20Shortest%20Path%5D.cpp)
* ***Minimum Spanning Tree***
  * [Prim-Jarnik](Algorithm/07%20Prim's%20MST.cpp)
  * [Kruskal](Algorithm/08%20Kruskal's%20MST.cpp)
* ***Cycle***
  * Cycle Check
    * [**Unirected Graph**](Algorithm/40%20Cycle%20Check.cpp)
    * **Directed graph**
      1. [Colouring](Algorithm/41%20Cycle%20Check%20Directed.cpp)
      2. [Top Sort](Algorithm/41.2%20Cycle%20Check%20Directed%202.cpp)
  * [Odd Cycle existence / Bipartite / Bicolorable check](Algorithm/39%20Bipartite%20check.cpp)
* ***Articulation***
  * [Articulation Point](Algorithm/10%20Articulation%20Point.cpp)
  * [Articulation Bridge](Algorithm/11%20Articulation%20Bridge.cpp)
  * [Biconnected Components](Algorithm/14%20Biconnected%20Components.cpp)
  * [Bridge Tree](Algorithm/15%20Bridge%20Tree.cpp)
* [***Euler Tour***](Algorithm/48%20Euler%20Tour.cpp)
* ***DP***
  * [Subtree Size](Algorithm/38%20Subtree%20Size.cpp)
* [***Binary Lifting***](https://github.com/zarif98sjs/Writeup/blob/master/Algorithms%20%26%20Data%20Structure/Binary%20Lifting.md)
* ***Miscellaneous***
  * [Topological Sort](Algorithm/12%20Topological%20Sort.cpp)
  * [Strongly Connected Component (SCC)](Algorithm/13%20Strongly%20Connected%20Component.cpp)
  * [Lowest Common Ancestor (LCA)](Algorithm/09%20Lowest%20Common%20Ancestor.cpp)

</details>

<details>
<summary>  
    
```c++
█▄░█ █░█ █▀▄▀█ █▄▄ █▀▀ █▀█   ▀█▀ █░█ █▀▀ █▀█ █▀█ █▄█
█░▀█ █▄█ █░▀░█ █▄█ ██▄ █▀▄   ░█░ █▀█ ██▄ █▄█ █▀▄ ░█░
```
</summary>

* ***Power & Modulus***
  * [Power](Algorithm/18%20Power.cpp)
  * [Big Mod](Algorithm/19%20BigMod.cpp)
  * [Inverse Mod](Algorithm/20%20InvMod.cpp)
* [***Extended Euclidean Algorithm***](Algorithm/28%20Extended%20Euclid.cpp)
* [***nCr***](Algorithm/21%20nCr.cpp)
* ***Sieve of Eratosthenes***
  * [General Sieve](Algorithm/22%20Sieve%20of%20Eratosthenes.cpp) : **O( N log(logN) )** , *Memory* : **O(N)**
  * [Bit Sieve](Algorithm/23%20Bit%20Sieve.cpp) : **O( N log(logN) )** , *Memory* : **N bit**
  * [Segmented Sieve](Algorithm/24%20Segmented%20Sieve.cpp) : **O( (R-L+1) log(logR) + sqrt(R) log(log(sqrt(R))) )** , *Memory* : **O(R-L+1)**
* ***Prime Factorization***
  * [Using all primes](Algorithm/25%20Prime%20Factorization.cpp) : **O( (sqrt(N)/log(sqrt(N)) * logN )**
  * [Using only smallest prime factor](Algorithm/35%20Prime%20Factorization%20using%20SPF.cpp) : **O(logN)**
  * [Prime Factorization in a range **[L,R]** ](/Algorithm/53%20Prime%20Factorization%20in%20a%20Range.cpp) **O( (R-L) * logN )  _[Optimized]_**
* ***Divisors***
  * [Number of Divisors](Algorithm/26%20Divisors.cpp)
  * [Cumulative Sum of Number of Divisors](Algorithm/26%20Divisors.cpp)
  * [Sum of Divisors](Algorithm/26%20Divisors.cpp)
  * [Cumulative Sum of Sum of Divisors](Algorithm/26%20Divisors.cpp)
* [***Euler Totient***](Algorithm/27%20Euler%20Totient.cpp)
* ***Linear Diophantine***
  * [2 Variable](Algorithm/29%20Linear_Diophantine.cpp)
  * [3 Variable](Algorithm/31%20Linear%20Diophantine%20(3%20variable).cpp)
  * [Number of solutions in a range](Algorithm/30%20Linear%20Diophantine%20(Number%20of%20solution%20in%20a%20range).cpp)
* [***Highest Composite Number***](Algorithm/32%20Highest%20Composite%20Number.cpp)
* [***Factorials***](Algorithm/33%20Factorials.cpp)
  * Number of digits in N factorial
  * Prime Factorization of N Factorial O(N*log(N))
  * Find the first K digits of N!
* [***Chinese Remainder Theorem***](Algorithm/34%20Chinese%20Remainder%20Theorem.cpp)

</details>

 
<details>
<summary>  
    
```c++
█▀ ▀█▀ █▀█ █ █▄░█ █▀▀
▄█ ░█░ █▀▄ █ █░▀█ █▄█
```
</summary>
    
 * [***Suffix Array***](Data%20Structure/23%20Suffix%20Array%204.cpp) : **O( NlogN )**
 * [***Longest Common Prefix (LCP) Array Construction***](Algorithm/43%20Longest%20Common%20Prefix.cpp) : **O(N)**
 * [***Prefix Function (KMP ALgorithm)***](Algorithm/44%20Prefix%20Function%20KMP.cpp) : **O(N)**
</details>

<details>
<summary>  
    
```c++

█▀█ █▀▀ █▀▀ █░█ █▀█ █▀ █ █▀█ █▄░█   ▄▀█ █▄░█ █▀▄
█▀▄ ██▄ █▄▄ █▄█ █▀▄ ▄█ █ █▄█ █░▀█   █▀█ █░▀█ █▄▀

█▄▄ ▄▀█ █▀▀ █▄▀ ▀█▀ █▀█ ▄▀█ █▀▀ █▄▀ █ █▄░█ █▀▀
█▄█ █▀█ █▄▄ █░█ ░█░ █▀▄ █▀█ █▄▄ █░█ █ █░▀█ █▄█
```
</summary>

  * [Generate all **subsets**](Algorithm/49%20Generate%20all%20subset.cpp)
  * [Generate all **permutations**](Algorithm/50%20Generate%20all%20permutation.cpp)
  * ***N Queen***
    * [Easy to Understand](Algorithm/45%20Backtrack%20N%20Queen.cpp)
    * [Optimized](Algorithm/46%20Backtrack%20N%20Queen%20Optimized.cpp)
  * [***Knight's Tour***](Algorithm/47%20Backtrack%20Knight's%20Tour.cpp)
 
</details>

<details>
<summary>
    
```c++
█▄▄ █ ▀█▀
█▄█ █ ░█░
```
</summary>

* [Bit Manipulation](Algorithm/51%20Bit%20Manipulation.cpp)
* [***Builtin*** Functions](Algorithm/52%20Bit%20Builtin%20Functions.cpp)

</details>    

<details>
<summary>  
    
```c++
█▀ █▀▀ ▄▀█ █▀█ █▀▀ █░█  
▄█ ██▄ █▀█ █▀▄ █▄▄ █▀█  

▀█▀ █▀▀ █▀▀ █░█ █▄░█ █ █▀█ █░█ █▀▀
░█░ ██▄ █▄▄ █▀█ █░▀█ █ ▀▀█ █▄█ ██▄
```
</summary>
 
  * ***Binary Search*** 
    * [***lower_bound*** , ***upper_bound*** implementation](Algorithm/42%20Binary%20Search.cpp)
    * [Solve Equation](Algorithm/16%20Binary%20Search%20(Eqn%20Solve).cpp)
    * [Meet In The Middle](Algorithm/17%20Binary%20Search%20(Meet%20In%20The%20Middle).cpp)
   
</details>
  

# Data Structure

* [***Disjoint Set***](Data%20Structure/12%20Disjoint%20Set.cpp)

* ***Binary Indexed Tree / Fenwick Tree***
  * *1D BIT*
    * [Point Update , Range Query , ***lower_bound*** , ***upper_bound*** ](Data%20Structure/01%20BIT%20(POINT%20update%20%2C%20RANGE%20query).cpp)  
    *update* , *query* : **O(logN)**   
    ***lower_bound*** , ***upper_bound*** : *binary search* - **O( (logN)^2 )**  , *binary lifting* - **O(logN)**
    * [Range Update , Point Query](Data%20Structure/02%20BIT%20(RANGE%20update%20%2C%20POINT%20query).cpp)  
    *update* , *query* : **O(logN)**   
  * *2D BIT*
    * [Point Update , Range Query](Data%20Structure/10%202D%20BIT%20(POINT%20update%2C%20RANGE%20query).cpp)
    
* ***Recursive Segment Tree***
  * *Non Lazy (Point Update , Range Query)*
     ```ruby
     build : O(N) 
     update , query : O(logN)
     ```
    * [Range **Sum**](Data%20Structure/03%20Segment%20Tree%20(POINT%20update%20%2C%20RANGE%20query).cpp) *( Possible Variations : Range [ **Multiplication , Min , Max , GCD , LCM , and , or , xor** ] )*
    * [Maximum **Prefix Sum** & Maximum **Suffix Sum** & Maximum Contiguous **SubArray Sum**](Data%20Structure/13%20Segment%20Tree%20Max%20Prefix_Suffix_SubArray%20Sum.cpp)
  * *Lazy (Range Update , Range Query)* 
     ```ruby
     build : O(N) 
     update , query : O(logN)
     ```
    * [Range **Assignment** Update , Range **Sum** Query](Data%20Structure/24%20SegmentTreeLazy%20(Range%20Assignment%20Update%20%2C%20Range%20Sum%20Query).cpp)
    * [Range **Increment** Update , Range **Sum** Query](Data%20Structure/25%20SegmentTreeLazy%20(Range%20Increment%20Update%20%2C%20Range%20Sum%20Query).cpp)
    * [Range **Increment** Update , **RMQ**](Data%20Structure/26%20SegmentTreeLazy%20(Range%20Increment%20Update%20%2C%20RMQ).cpp)
    * [Range **Flip** Update , Range **Sum** Query](Data%20Structure/27%20SegmentTreeLazy%20(Range%20Flip%20Update%20%2C%20Range%20Sum%20Query).cpp)
  * *Merge Sort Tree*
    * [Range Query](Data%20Structure/05%20Merge%20Sort%20Tree.cpp)  
      ```ruby
      build  : O( NlogN )
      query  : O( (logN)^2 )
      memory : O( NlogN )
      ```
    * [Point Update , Range Query](Data%20Structure/19%20Merge%20Sort%20Tree%202.cpp)  
      ```ruby
      build  : O( N (logN)^2 )
      update , query : O( (logN)^2 )
      memory :   O( NlogN )
      ```
      
* ***Iterative Segment Tree***
  * *Non Lazy*
     ```ruby
     build : O(N) 
     update , query : O(logN)
     ```
    * [Point Update , Range Query](Data%20Structure/28%20Iterative%20Segment%20Tree%20(Point%20Update%2CRange%20Query).cpp)  
    *( Possible Variations : Range [ **Multiplication , Min , Max , GCD , LCM , and , or , xor** ] )*
    * [Range Update , Point Query](Data%20Structure/29%20Iterative%20Segment%20Tree%20(Range%20Update%2CPoint%20Query).cpp)
    
* ***Sparse Table***
  * [Range Sum Query](Data%20Structure/31%20Sparse%20Table%20(Range%20Sum%20Query).cpp) : **O(logN)**
  * [RMQ](Data%20Structure/32%20Sparse%20Table%20(RMQ).cpp) : **O(1)**
* [***Sweep Line Algorithm***](Data%20Structure/06%20Sweep%20Line%20Algorithm.cpp)
* ***Mo's Algorithm (Square Root Decomposition)***
    ```ruby
    Total Complexity : O ( (N+Q)F * sqrt(N) )
    where O(F) is the complexity of add and remove function
    ```
  * [Range **Sum** Query](Data%20Structure/07%20Mo's%20Algo%20(RANGE%20sum%20query).cpp)
  * [Range **Mode** (Highest Frequency) Query](Data%20Structure/09%20Mo's%20Algo%20(RANGE%20mode%20query%20Optimized).cpp)
  * [Range **Number of Distinct Elements** Query](Data%20Structure/30%20Range%20Distinct%20Elements.cpp)
* ***Suffix Array***
  * [**O( N^2 logN )**](Data%20Structure/20%20Suffix%20Array%201.cpp)
  * [**O( N (logN)^2 )**](Data%20Structure/21%20Suffix%20Array%202.cpp)
  * [**O( NlogN )**](Data%20Structure/22%20Suffix%20Array%203.cpp)
  * [**O( NlogN )** *optimized*](Data%20Structure/23%20Suffix%20Array%204.cpp)
* [***Priority Queue***](Data%20Structure/11%20Priority%20Queue%20Implementation.cpp)
* ***STL***
  * [Set](Data%20Structure/14%20STL%20Set.cpp)
  * [Map](Data%20Structure/15%20STL%20Map.cpp)
* ***Policy Based Data Structure***
  * [Set](Data%20Structure/16%20PBDS%20Set.cpp)
  * Multiset
    * [Implementation 1](Data%20Structure/17%20PBDS%20Multiset.cpp) (*erase* doesn't work)
    * [Implementation 2](Data%20Structure/18%20PBDS%20Multiset%202.cpp)

  
# Dynamic Programming

* ***LCS Variant***
  * [Longest Common Subsequence](Dynamic%20Programming/01%20LCS.cpp)
  * [Longest Palindromic Subsequence](Dynamic%20Programming/02%20LPS.cpp)
  * [Longest Repeated Subsequence](Dynamic%20Programming/03%20LRS.cpp)
  * [Levenshtein / Edit Distance](Dynamic%20Programming/04%20Levenshtein%20or%20Edit%20Distance.cpp)
  * [Shortest Common Supersequence](Dynamic%20Programming/08%20Shortest%20Common%20Supersequence.cpp)
* ***LIS Variant***
  * Longest Increasing Subsequence
    - [O(N^2)](Dynamic%20Programming/05%20LIS.cpp)
    - [O( NlogN )](Dynamic%20Programming/05.2%20LIS%20(Binary%20Search).cpp) **Binary Search**
    - [O( NlogN )]() **Segment Tree** //code not added
  * [Longest Bitonic Subsequence](Dynamic%20Programming/09%20Longest%20Bitonic%20Subsequence.cpp)
  * [Increasing Subsequence with Maximum Sum](Dynamic%20Programming/10%20Increasing%20Subsequence%20with%20Maximum%20Sum.cpp)
  * [Longest Increasing Index-Dividing Subsequence](Dynamic%20Programming/32%20Longest%20increasing%20index%20dividing%20subsequence.cpp)
  * **Longest Common Increasing Subsequence**
    - [O( N^3 )](Dynamic%20Programming/33%20Longest%20Common%20Increasing%20Subsequence.cpp)
    - [O( N^2 )](/Dynamic%20Programming/34%20Longest%20Common%20Increasing%20Subsequence%20(Optimized).cpp) 
* ***Coin Change*** 
  * [Coin Change (Minimum number of coins to make a sum)](Dynamic%20Programming/06%20Coin%20Change(Min%20Coin).cpp)
  * [Coin Change (Number of ways to make a sum)](Dynamic%20Programming/07%20Coin%20Change(Num.%20of%20Ways).cpp)
  * [LightOj 1079 (Just Another Robbery)](Dynamic%20Programming/31%20Coin%20Change%20Varient%20%5BLightOj%201079%20Just%20Another%20Robbery%5D.cpp)
* ***Matrix Variant***
  * [Largest Square Matrix with all 1's](Dynamic%20Programming/11%20Largest%20Square%20Matrix%20with%20all%201.cpp)
  * [Minimum Cost Matrix Path (Top Left cell to Bottom Right cell)](Dynamic%20Programming/12%20Minimum%20Cost%20Matrix%20Path.cpp)
  * [Number of paths in a matrix with certain cost (Top Left cell to Bottom Right cell)](Dynamic%20Programming/14%20Number%20of%20Paths%20with%20certain%20cost.cpp)
  * [Longest Sequence formed by adjacent numbers in a matrix](Dynamic%20Programming/13%20Longest%20Sequence%20by%20Adjacent%20Numbers.cpp)
  * [2 Way Prefix Sum (LightOj)](Dynamic%20Programming/26%202%20Way%20Prefix%20Sum.cpp)
* ***Knapsack Variant***
  * [0-1 Knapsack](Dynamic%20Programming/15%200-1%20Knapsack.cpp)
  * [Partition Problem](Dynamic%20Programming/16%20Partition%20Problem.cpp)
  * [Minimum Sum Partition Problem](Dynamic%20Programming/17%20Minimum%20Sum%20Partition%20Problem.cpp)
* ***Digit DP Variant***
  * [Number of zeros (LightOj)](Dynamic%20Programming/19%20Number%20of%20zeros.cpp)
  * [Odd Sum Even Sum (SPOJ)](Dynamic%20Programming/20%20Odd%20Sum%20Even%20Sum.cpp)
  * [Digit Min Max Scores (HackerRank)](Dynamic%20Programming/21%20Digit%20Min%20Max%20Scores.cpp)
  * [Adjacent 1 Scores in binary (LightOj)](Dynamic%20Programming/22%20Adjacent%201%20Scores%20in%20binary.cpp)
  * [Divisibility check by Digit Sum (LightOj)](Dynamic%20Programming/23%20Divisibility%20check%20by%20Digit%20Sum.cpp)
  * [Digit Sum (SPOJ)](Dynamic%20Programming/24%20Digit%20Sum.cpp)
  * [Encoding (CodeChef)](Dynamic%20Programming/25%20CHEF_LONG%20ENCODING.cpp)
* ***Bitmask DP***
  * [Bitmask DP 1 [ LightOj 1011 (Marriage Ceremonies) ]](Dynamic%20Programming/27%20Bitmask%20DP%201%20%5BLightOj%201011%20Marriage%20Ceremonies%5D.cpp)
  * [Bitmask DP 2 [ LightOj 1018 (Brush IV) ]](Dynamic%20Programming/28%20Bitmask%20DP%202%20%5BLightOj%201018%20Brush%20IV%5D.cpp)
  * [Bitmask DP 3 [ LightOj 1037 (Agent 47) ]](Dynamic%20Programming/29%20Bitmask%20DP%203%20%5BLightOj%201037%20Agent%2047%5D.cpp)
  * [Bitmask DP 4 [ LightOj 1057 (Collecting Gold) ]](Dynamic%20Programming/30%20Bitmask%20DP%204%20%5BLightOj%201057%20Collecting%20Gold%5D.cpp)
* ***Miscellaneous***
  * [N-digit binary strings without any consecutive 1’s](Dynamic%20Programming/18%20Count%20N%20digit%20binary%20string%20without%20consecutive%201's.cpp)
  
# Miscellaneous
 - ***Operator Overloading for sorting / STL Data Structure***
   - [Using Comparator ***functions / structure***](Miscellaneous/01%20Operator%20Overloading%20for%20Sorting%20(Part%201).cpp)
   - [Overloading **<** operator](Miscellaneous/01%20Operator%20Overloading%20for%20Sorting%20(Part%202).cpp)
   - [Overloading **>** operator](Miscellaneous/01%20Operator%20Overloading%20for%20Sorting%20(Part%203).cpp)
   
- [_**Coordinate Compression**_](/Miscellaneous/07%20Coordinate%20Compression.cpp)

 - [***BIG Integer Library***](Miscellaneous/06%20Big_Integer.cpp)
   
 - ***Integer Root***
   - [Square Root *(Binary Search)*](Miscellaneous/04%20Square%20Root%20Binary%20Search.cpp) **(Modifiable to nth Root)**
   - [Fast Square & Cube Root](Miscellaneous/05%20Fast%20Integer%20Cube%20and%20Square%20Root.cpp)
 
 - ***Geometry Template***
   - [Point & Line](Miscellaneous/02%20Geometry%20Template%20(Point%20%26%20Line).cpp)
   - [Rectangle](Miscellaneous/03%20Geometry%20Template%20(Rectangle).cpp)
  


### Md. Zarif Ul Alam
Computer Science & Engineering Department , BUET
