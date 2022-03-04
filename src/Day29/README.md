# Assignment

## Memory Order

Thread A stores value in int x.
Thread B stores values in int y.
Thread C tries to read x and then read y.
Thread D tries to read y and then read x.

Apply the following ordering schemes and demonstrate the order in each thread:

### sequence consistent
Show single total order evidence in each thread.

### relaxed
Show different concurrency access orders in each thread.

### release acquire
Show pairwise synchronization.

### consume
Use data dependency to control outcome.
