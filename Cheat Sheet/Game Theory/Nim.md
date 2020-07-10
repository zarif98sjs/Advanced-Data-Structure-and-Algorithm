# Nim

## Optimal Strategy

> “If both A and B play optimally (i.e- they don’t make any mistakes), then the player starting first is guaranteed to win if the Nim-Sum at the beginning of the game is non-zero. Otherwise, if the Nim-Sum evaluates to zero, then player A will lose definitely.”

### Reasoning 
Couple of deductions about bitwise XOR necessary for understanding the Optimal Strategy :
- If the XOR sum of ‘n’ numbers is already zero then there is no possibility to make the XOR sum zero by single reduction of a number. 
- If the XOR sum of ‘n’ numbers is non-zero then there is at least a single approach by which if you reduce a number, the XOR sum is zero.

