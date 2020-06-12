# GCD

## Euclid's Algorithm
$$
gcd( a , b ) = gcd( b , a \ mod \ b)
$$
  - ### Lemma  
    If a > 0 and b > 0 :
     - **`gcd( a , b ) = gcd( a - b , b )`** [ a > b ]
     - **`gcd( a , b ) = gcd( a , b - a )`** [ b > a ]
  
## Properties
- _**Commutative**_ : **`gcd ( a , b ) = gcd( b , a )`** 
- _**Associative**_ : **`gcd( a , gcd(b,c) ) = gcd( gcd(a,b) , c)`**  
- _**Distributive**_ :   
  1 . **`gcd( a , lcm(b,c) ) = lcm( gcd(a,b) , gcd(a,c) )`**  
  2 . **`lcm( a , gcd(b,c) ) = gcd( lcm(a,b) , lcm(a,c) )`** 
- _**GCD LCM Formula**_ : **`gcd( a , b ) * lcm( a, b ) = a * b`**
- _**Bézout's identity**_ :  
  The smallest positive integer `d` which can be written in the form  
   **`d = a*p + b*q`**  
   where `p` and `q` are integers is `gcd( a, b )` 
   The expression is called **Bézout's identity**
- _**Lemma :**_  
  1 . **`gcd( lcm(n1,M) , lcm(n2,M) ... lcm(nk,M) ) = lcm( gcd(n1,n2, ... nk) , M )`**  
  2 . **`lcm( gcd(n1,M) , gcd(n2,M) ... gcd(nk,M) ) = gcd( lcm(n1,n2, ... nk) , M )`**
- _**Prime Factorization :**_  
  If $a = {p_{1}}^{e_{1}} *{p_{2}}^{e_{2}} * ... * {p_{n}}^{e_{n}}$  and  $b = {p_{1}}^{f_{1}} *{p_{2}}^{f_{2}} * ... * {p_{n}}^{f_{n}}$
  $$
  gcd(a,b) = {p_{1}}^{min(e_{1},f_{1})} *{p_{2}}^{min(e_{2},f_{2})} * ... * {p_{n}}^{min(e_{n},f_{n})}
  $$
- An identity involving _**Euler Totient**_ :  
  $$
  gcd(a,b) = \sum_{k|a \ and \ k|b} \varphi (k) 
  $$
- _**Miscellaneous**_
  - If `m` is a _non-negative_ integer  
    **`gcd( m*a , m*b ) = m * gcd( a , b )`**
  - If `m` is _any_ integer  
    **`gcd( a+m*b , b ) = gcd( a , b )`**
  - If `m` is a positive common divisor of `a` and `b`  
    **`gcd( a/m , b/m ) = gcd( a , b ) / m `**
  - If `a1` & `a2` are relatively prime   
    **`gcd( a1*a2 , b ) = gcd( a1 , b ) * gcd( a2 , b )`**  

<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config">MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });</script>