# Assignments

## Race Condition: Hailstone Sequence

Simulate a race condition with the hailstone sequence.

```
Here's a little game to play. Starting with any positive whole number $n$ form a sequence in 
the following way:

If n is even, divide it by 2 to give n = n/2.
If n is odd, multiply it by 3 and add 1 to give n = 3n + 1
Then take n as the new starting number and repeat the process. 

For example, n = 5 gives the sequence

 	[ 5, 16, 8, 4, 2, 1, 4, 2, 1,...]	 	 

and n = 11 gives the sequence

 	[ 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1, 4, 2, 1,...]	 	 

Sequences formed in this way are sometimes called hailstone sequences because they go up and down 
just like a hailstone in a cloud before crashing to Earth. However, it seems that all 
hailstone sequences eventually end in the endless cycle

 	[ 4, 2, 1, 4, 2, 1]	
```

You will need to create two or more threads that build the sequence in parallel, and the
sequence itself is a shared data structure. A specific thread will look at the current number
and figure out the next number in the sequence, and add it. All threads will attempt to 
do this resulting in a race condition. You can detect a race condition by observing that the
sequence has invariants violated.

Now once you create a race condition, you can write a second program to resolve the race
condition. The sequence should have no variants violated.

## Deadlock: Currency Trading

Create two Country objects C1 and C2 that have money in different currencies.
Both C1 and C2 hold money in dollars and pounds.

You are supposed to simulate currency trading between these two accounts.
Note that C1 is owned by thread T1 and C2 is owned by thread T2.

Here is the sequence of events that transpire:

1. C1 sends a request to C2 to buy/sell pounds in exchange for dollars. The request should contain
at the minimum {exchangeRate, amount, currencyType, buy/sell}.

2. C2 can refuse the request or accept it.

3. If C2 refuses request, then C1 will delete the request.

4. If C2 accepts request, then C1 initiates the transfer. At the end of the transfer,
C1/C2 should update their foreign currency reserves.

5. C1 will then close the resolved request.

In above sequence, it could happen in any order. So C2 could send a request while C1 is sending
a request. And C1 and C2 could both be waiting for each other to accept/reject the request.
So they could get in a potential deadlock.

First part of your assignment is to simulate a deadlock between T1 and T2, based on currency
trading activity between C1 and C2.

Second part of your assignment is to resolve the deadlock. 

Create two separate programs one that creates a deadlock and other one that resolves the deadlock.
In order to test if there is a deadlock, create a continuous stream of currency trading activity
between the two countries for a period of time t, and make sure they do not deadlock.

Explain how you concluded there was no deadlock anymore? What method did you use to diagnose the
deadlock. What symptoms did you look for, and how were these symptoms resolved with your fix.
