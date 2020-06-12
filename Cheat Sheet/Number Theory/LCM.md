# LCM
$$
lcm(a,b) = \frac{a*b}{gcd(a,b)}
$$
## Properties
- _**Commutative**_ : **`lcm ( a , b ) = lcm( b , a )`** 
- _**Associative**_ : **`lcm( a , lcm(b,c) ) = lcm( lcm(a,b) , c)`**  
- _**Distributive**_ :   
  1 . **`gcd( a , lcm(b,c) ) = lcm( gcd(a,b) , gcd(a,c) )`**  
  2 . **`lcm( a , gcd(b,c) ) = gcd( lcm(a,b) , lcm(a,c) )`** 
- _**GCD LCM Formula**_ : **`gcd( a , b ) * lcm( a, b ) = a * b`**
- _**Lemma :**_  
  1 . **`gcd( lcm(n1,M) , lcm(n2,M) ... lcm(nk,M) ) = lcm( gcd(n1,n2, ... nk) , M )`**  
  2 . **`lcm( gcd(n1,M) , gcd(n2,M) ... gcd(nk,M) ) = gcd( lcm(n1,n2, ... nk) , M )`**
- _**Prime Factorization :**_  
  If $a = {p_{1}}^{e_{1}} *{p_{2}}^{e_{2}} * ... * {p_{n}}^{e_{n}}$  and  $b = {p_{1}}^{f_{1}} *{p_{2}}^{f_{2}} * ... * {p_{n}}^{f_{n}}$
  $$
  gcd(a,b) = {p_{1}}^{max(e_{1},f_{1})} *{p_{2}}^{max(e_{2},f_{2})} * ... * {p_{n}}^{max(e_{n},f_{n})}
  $$
- _**Miscellaneous**_
    - `lcm(a, b, c) * gcd(a, b) * gcd(b, c) * gcd(c, a) = abc * gcd(a, b, c)` 