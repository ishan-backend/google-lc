/*
NP Hard Problem: (With bitmasking we will be able to relax the TC by some measure)

Given cities and distances between each pair of cities (two-way costs).
Shortest possible route that visits each city and returns to origin city.

Starts from city 1.
Visit each city from 2..N exactly once, and then he'll be coming back home i.e. city 1

Design a tour, such that overall cost is minimised.

Brute force:
City 1 to other cities
N-1 * N-2 (from that city to other city options) * ... 1 = (N-1)! factorial
O(N!) for small N also this would not work

Let's try to build a solution which would work atleast for N=30
        {1, (2,3,4...N)}
        Min of :: dist(1, 2) + recurse{2, (3,4...N)}, dist(1, 3) + recurse{3, (2,4....N)}, etc.
 

        dp(i, Set) = minm distance needed to travel given that you are city i and you need to visit cities (represented by set bits) in set S and get back to 1

Final ans = dp(1, {2,3...N})

SC: O(N * 2^N)
TC: O(N^2 * 2^N) - transition time of dist(i, j) is O(N) - rest is space complexity multiplied.
*/





