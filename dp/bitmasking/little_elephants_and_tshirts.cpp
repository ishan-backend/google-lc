/*
https://www.codechef.com/problems/TSHIRTS

Kinds of tshirts: T1, T2 .... T100
N persons. Each person can own some of these tshirts. Every person has max one tshirt of an ID.
Multiple persons can have same tshirt ids.

No of ways - in which people can wear tshirts they own. Such that no two person in the party are wearing tshirt with same ID.

N = 2
p1 = 3 5
p2 = 8 50

Ans = 4 ways i.e. (3, 8), (3, 50), (5, 8), (5, 50)

dp(i, mask): no of ways for person from Pi till Pn to wear tshirts to a party such that Pi till Pn only wear tshirts mentioned by mask
Mask will have 100 bits. jth bit of this mask will tell if it is available to wear if set, if unset that means it has been wore by person from P1 to Pi-1.

that will be dp(1, (1111..100 times)base2) and 2^100 is very large hence the SC is very bad.
Let's try to optimize further

So let's reverse the dp state
Tshirts <= 100 count
Person <= 10 count
dp(i, mask): ways to assign  to ith t-shirt to mask i.e. people left to wear/be assigned a t-shirt.
*/

