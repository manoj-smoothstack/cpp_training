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

Create two Country objects C1 and C2 that both have money in two currencies.
Both C1 and C2 hold part of their reserves in dollars and part in pounds.

You are supposed to simulate currency trading between these two accounts.
Note that C1 is owned by thread T1 and C2 is owned by thread T2.

Here is the sequence of events that transpire:

1. C1 sends a request to C2 to buy/sell pounds in exchange for dollars. The request should contain
at the minimum {exchangeRate, amount, currencyType, buy/sell}.

2. C2 can refuse the request or accept it. Either because it did not like the rate, or it did not
have enough of the balance to fulfill that request.

3. If C2 refuses request, then C1 will delete the request.

4. If C2 accepts request, then C1 initiates the transfer. At the end of the transfer,
C1/C2 should update their foreign currency reserves. So if the request was:
{1.55, 200000, "Dollars", "Buy"} from C1 to C2, and if C2 accepted the request, then
at the end of the transaction, 
- C1's dollar reserves should increase by 200000
- C1's pound reserves should decrease by approximately 129032.
- C2's dollar reserves should decrease by 200000
- C2's pound reserves should increase by approximately 129032.

5. C1 will then close the resolved request.

In above sequence, it could happen in any order. So C2 could send a request while C1 is sending
a request. And C1 and C2 could both be waiting for each other to accept/reject the request.
So they could get in a potential deadlock.

A request can be designed by you as any form of shared data that both T1 and T2 have access to.
It could be a struct or a class.

Please note that there is no queue between T1 and T2. This means that all currency transactions
are synchronous and cannot be sent to a queue. In other words, C1 cannot send back-to-back 
requests in a queue to C2 and vice-versa.

First part of your assignment is to simulate a deadlock between T1 and T2, based on currency
trading activity between C1 and C2.

Second part of your assignment is to resolve the deadlock. In order to resolve the deadlock, you
should make appropriate use of one or more of std::mutex, std::lock_guard, std::lock or other
similar utilities. Do not attempt to use a queue to resolve this issue, even if it does help you
resolve the deadlock.

You could also decide to use an std::swap to swap two prepared objects as part of the request 
struct. These prepared objects can be A1 and A2.

A1 = {200000, "Dollars", "Add"}
A2 = {129032, "Pounds", "Subtract"}

friend void swap(Amount& A1, Amount& S2);

where A1, and A2 are instances of Amount.

Note that both threads T1 and T2 will have access to A1 and A2, except that will also mean, they
both try to access A1 and A2 at the same time. And it could also mean that only one of them needs
to initiate the swap. As if you swap twice, you have undone the transaction. So you may need to
decide on the "protocol" for who initiates the swap, and keep the order of operations always
predictable to avoid any deadlocks.

Note that using the swap technique is a potential option, but you do not need to use that method.

The request struct is the minimum amount of information that you will need to send. However, feel
free to add other fields such as timestamp etc, if it helps you.

Create two separate programs one that creates a deadlock and other one that resolves the deadlock.
In order to test if there is a deadlock, create a continuous stream of currency trading activity
between the two countries for a period of time t, and make sure they do not deadlock.

Explain how you concluded there was no deadlock anymore? What method did you use to diagnose the
deadlock. What symptoms did you look for, and how were these symptoms resolved with your fix.
