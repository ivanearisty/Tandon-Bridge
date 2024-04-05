/*

Note: I didn't know we could use a calculator, so I couldn't really calculate anything since I said i didn't have one in procotor U.

1:

Use mathematical induction to prove that 3 divides n^3 + 2n whenever n is a
positive integer. 

Proof: by induction on n.

Claim: n^3  + 2n mod 3 = 0

Base Case:
n = 1
(1)^3 + 2*(1) = 3
3 mod 3 = 0
So the base case when n = 1 works.

Inductive Step:
Say that for some arbitrary positive integer k
k^3 + 2*k mod 3 = 0 
is true. Then, 
(k+1)^3 + 2*(k+1) mod 3 = 0 
we claim. 

Expanding out the terms for k+1 we get:
k^3 + 3k^2 + 3k + 1 + 2k + 2

We can reorganize as such:
k^3 + 2k + 3k^2 + 3k + 1 + 2
(k^3 + 2k) + (3k^2 + 3k + 3)
(k^3 + 2k) + 3(k^2 + k + 1)

Now, we have two terms in parenthesis both divisble by 3.
The first term, (k^3 + 2k), is our inductive hypothesis, which is true.
The second term, 3(k^2 + k + 1), is (by definition of k) some integer
that is multiplied by 3. Therefore it is divisible by 3.
This concludes our proof by induction.

2:
a) How many bit strings of length seven either begin with two 0s or end with
three 1s? Explain your answer.

First of all, we have to realize that these are not mutually exclusive events.
A bit string of length 7 can begin with two 0s and end with 3 1's.
Therefore, we will have to take this into consideration later.

Total bit strings of length 7 = 2^7

Total bit strings of length 7 that begin with two 0's:
Since they have to begin with two 0's, we are removed choices for pos 1 and 2.
Therefore the answer for this is:	2^5

Total bit strings of length 7 that end with three 1's:
Since they have to end with three 1's, we are removed choices for pos 5, 6 and 7.
Therefore the answer for this is: 2^4

Now, we have to take into account the overlap.
We have to count how many bit strings of length 7 begin with two 0's and end with three 1's.
In this situation, we are removed choices 1 and 2 by the 0's, and 5, 6 and 7 by the 1's.
Therefore the answer for this is: 2^2, or 4.
Here they are separated for simplicity: 00, 00 , 111 - 00, 01 , 111 - 00, 10 , 111 - 00, 11 , 111.

Now that we have all the pieces we can say that:
The total number of bit strings of length seven that either begin with two 0's or end with three 1's
is equal to:
Total bit strings of length 7 that begin with two 0's
+
Total bit strings of length 7 that end with three 1's
- 
the intersection.

Which, for a final answer is: 2^5 + 2^4 - 4

b) How many ways are there for 5 women and 4 men to stand in a line so
that no two men stand next to each other? Explain your answer.

The question is somewhat unclear on order importance, so I assume that Woman1, Woman2 != Woman2, Woman1

Since no two men can stand next to each other, a woman must separate them.
We need at least 3 women for this:
M W M W M W M

However, we have 2 women left over who can go anywhere in the list.
The first women has 8 options on where she is going to go (to whose side).
The second has 9 options since we count the new woman that entered.
Therefore there are 
8 x 9 ways for this to happen.

So the final answer is the ways to choose 3 women to be the separators (they have fixed positions): C(5,3)
Times the ways to permute 4 men in their fixed positions: 4!
Times the ways to distribute the last 2 women not chosen 8 x 9.

C(5,3) x 4! x 9 x 8

3:
Find the probability of at most one success when n independent Bernoulli
trials are carried out with probability of success p? Explain your answer.

I didn't have a calculator for this question :(

For a bernoulli trial we need:
the number of trials: n
the probability of success: p
and the probability of failure: (1-p)
the required successes: l

Probability of all successes = trial of: (n choose n)^(p) (n choose 0)^(1-p)
Bernoulli trial of n - 1 successes = trial of: (n choose n-1)^(p) (n choose 1)^(1-p)
At most one success = Probability of all successes - Bernoulli trial of n - 1 successes

You have seven cards, numbered 3 through 9, and you pick one at
random. If you pick a card with a prime number, you get 1 point; if you pick
a card with a composite number (that is, a number which not prime), you
lose 1 point. Find the expected value of the number of points you get.
Explain your answer.

All cards have the same probability of being picked: 1/7

There are 3 primes from 3 to 9: 3, 5, and 7 
There are 4 composites from 3 to 9: 4, 6, 8 and 9

Therefore E[X] = 1 * 3/7 + -1 * 4/7

4:
Function 1:

For the first loop outer runs in theta log_2(n) 
times the inner loop which runs proportional to n 
so theta log_2(n)*n

The second loop has the exact same functionality as the first loop.
It's just converting the while into for.

The final time complexity is theta log_2(n)*n

Function 2:

For the first loop we run in linear time. 
It doesnt matter that we divide n by half it is still a factor of n.
It also doesnt matter that we linearly skip one step every iteration.
So the time complexity of that first loop is theta n

The second loop is interesting because it is two log_2(n) loops nested.
So the time complexity here is theta log_{2}^2(n).

If my math doesnt fail me log_{2}^{2}(n) < n as n -> infinity. 

So my final answer for overall time complexity is theta(n). 

*/