/*
Kartik Arora Playlist:

N persons, N Jobs
Assign 1 Job to exactly 1 person, and do that in least amount of cost.
Cost varies according to matrix of Job-Person.
N = 4
J - H
P - V
[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

N <= 20
Answer = 13; P1-J2: 2, P2-J1: 6, P3-J3: 1, P4-J4: 4


J1,J2,J3 ... Jn Jobs
P1,P2,p3.... Pn People

Assign Job to P1 in N ways
Assign Job to P2 in N - 1 ways
Assign Job to P3 in N - 2 ways
.. so on

Time Complexity = N * (N - 1) * (N - 2)...* 1 = O(N!)

1. Idea - Recursion

(CurJobToAssigned,PeopleSet) = ({1..N},{P1,P2..PN})

                        (1,{P1,P2..PN})
                            /       \
                (2,{P2,P3..PN}) ... (2,{P1,P3...PN})
    
    -> Obviously This recursion would have overlapping states.
    -> Considering Each permutation as a state and storing it would be heavy storage intensive task
    -> Seeing the constraints what if we represent each permutation of set through a integer.

2. Defining DP

    DP[i][mask] = where mask is integer representation of a permutation of a subset given.
                = Min cost of assigned given people by mask to i to N jobs remaining.
                = Minm cost of assigning jobs to people from Pi to PN with distribution of jobs = mask

3. Recurrence

    dp(i,mask) = MIN { for all valid j | { C(j,i) + dp(i + 1,mask with jth bit off) } }
    where, C(j,i) = cost of assigning jth person ith job from given input matrix
    for all valid j = person is available to me, i.e. jth bit is on

    Time -> O(N^2 * 2^N); try out all people, assign them each job :- can handle N=21/22 easily
    Space -> O(N * 2^N); i = N, mask = 2^N representing combinations/subsets
*/
int N;
int cost[21][21];
int dp[21][(1<<21)]; // 2^21

// recurrence in top-down way
int solve(int i, int mask) {

  if(i == N+1) // if all jobs have been assigned
      return 0;
  if(dp[i][mask] != -1) return dp[i][mask];

  int ans = INT_MAX;
  // try out every person and assign them this ith job
  for(int j=0; j<=N-1; j++) {
    // jth person must not be already assigned a job - check from current available mask, if its set he is available
    if(mask & (1<<j)) { // anything but 0
      // take current cost and mark this person i.e.j unavailable for further recursion
      ans = min(ans, cost[i][j] + solve(i+1, (mask ^ (1<<j)));
    }
  }

  return dp[i][mask] = ans;
}
