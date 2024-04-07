/*
Bitmasks:
- We have a set consisting of integers from {1, 2, 3 ... N}
- There can be a total of 2^N subsets of above Set S like, e.g. {}, {1}, {2}, {1, 2} for N=2

Design a technique, to store the subset of the set and use less memory.
Thought process to store a subset:
  1. set<int>
  2. vector<int>
  3. In a subset, of set S containing integers 1...N
      Integer i can either be present or not in this subset.
      bool subset[N+1];
      if i = 5 present, subset[i] = true; // cheaper than vector<int>
      -> All you need is N bits to store if N elements are present or not
      -> where N is universal set
      
      Integers in-memory are represented as binary numbers.
      5 = (0000000000000....101)base2
      8 = (0000000000000...1000)base2
      We are going to have an integer called subset, we will use this integer to represent any subset we want
      Given, it has enough bits in it.
      If N=32, we know Integer has 32 bits so it can represent a subset.

      e.g. for subset s1 = {2, 3, 5} and if our original set had [1, N] range where N <= 32
      int subset1 = (0000000000000...10110)base2
*/

