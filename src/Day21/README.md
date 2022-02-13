# Assignment

## Multi-threaded N-body problem

Upgrade your assignment from previous day to support threads. Don't replace the original code,
but commit new directory/files to git with a multi-threaded version of the N-body problem.

However, this multi-threaded version is a trivial version, meaning you simply consider your
entire current experiment as one of the threads. So all the code you had written in the previous
assignment will run in a single thread. However, now you can launch M threads that all do the
same thing. This means, that the function that you launch from main() to simulate your N body
problem will simply be the starting function for a new thread.

So as you notice this is a trivial multi-threaded experiment for the N bodies, as all of the
N bodies are being updated sequentially in a single thread. But this is fine for now, as this
will simplify your parallel threading application as you do not need to have data shared
between the threads.

However the significance of running the trivial experiment is to see if you can eke out more
horsepower from your CPU by adding more threads. So it simply helps you to understand threads
and how compute can affect your application.

So each of the M threads will run it's own N body experiment, and they are all independent
experiments that run within each thread. These M experiments do not communicate with each other.
However, you must wait until all threads are completed, and then compute the aggregate result
from all the M experiments and output that to the same JSON file we talked, except you can 
add one more column to the JSON file which is the numThreads column.

So in effect you vary M, which is the numThreads from 1, 2, .... 8. From the JSON file and
the final aggregate numbers you should be able to tell if you were better off with more threads
and if it was linear, less than linear or more than linear. You should be able to tell if 
increasing the number of threads has helped you, and at what time you have diminishing returns.
Compare this to the number of hardware threads your container has access to, and see if 
you see a strong correlation between the number of hardware threads and the number of threads
that are the right number to get an optimum amount of work done. Write your analysis to your
README.md file.

So the question is what exactly are you measuring? Note that you will measure the total 
number of interactions per second across M threads, to know how many interactions you have
been able to simulate. Really what you are measuring is how much total work you can do,
and most of this work is just all the calculations for force, acceleration, velocity and
position.

Also, because you are running M threads, each thread should ideally run on a different core.
And you may not have so many cores. So eventually as you increase the number of threads,
you will notice that the threads are competing for cores, and this contention in turn will
slow down each thread. When we say slow down, we just mean, that a thread is waiting for a
CPU to be available. This will mean that the number of interactions per sec for each 
thread will start to reduce as you increase the number of threads above the number of cores.
If you had 2 cores, then you can run 2 threads comfortably and you would not see any
contention. However, if you had 2 cores and were running 4 threads, you would have the 4 threads
competing for 2 cores.

So it is important that you also calculate the number of interactions per second for each
thread as you increase the value of M, and not just the total number of interactions per second
across all the threads.

You may have realized this from the last 2 assignments, but here it is:

The number of interactions per second for our purposes, is simply the number of times you compute the 
force between two bodies (out of N bodies) in one second.

Now we also talk about one more enhancement related to time slices and sleeping.

Since you are simulating time slices, in your previous single threaded assignment, we assume
that you are not sleeping in between time steps. Even though we call them time steps, we are
not really sleeping in between the calculations. You can upgrade this logic to be able to
introduce a sleep in between the timesteps as an option. So you would have the timestep/sleep
as your option. So if the timestep was 0.001, then you sleep for 0.001 seconds in between your
iterations. And you can recalculate your numbers with this modification before you move
on to the M thread assignment.

We add a sleep (in addition to a timestep) in order to show that a thread will relinquish the CPU
for a brief period of time, to give a chance to other threads. You should compare the
calculations with the old timestep and the new sleep to see if you get better results
with the sleep or the timestep. You may need to create two JSON files with M thread numbers
for interactions per sec, one with the the timestep, and other with the sleep.

In case of the sleep scenario, the value of k will simply be the number of times you call
sleep().

Now off to our previous assignment just copied here, and it is identical:

So in this assignment you should still compute half-pairs instead of full-pairs. 
Your half-pairs solution should use Newton's third law 

```
fij = -fji
```

to halve the number of force calculations needed compared to the all-pairs solution.

What do we mean by half-pair?

If Body A exerts force on Body B, then Body B exerts the opposite force on Body A.
So you only need to calculate the force in one-direction, and the force in the other direction
would be the negative of that based on Newton's third law above.

You will need to modify some Lambda functions to solve this.

The rest of the description below is the same, but keep in mind the getForce computations would
be more efficient with half-pairs.

Simulate the N-body problem in 2 dimensions using several lambda functions.
Make sure all your lambda functions have appropriate capture, parameter, mutable,
return value, body and exception clauses.

Consider the following constants:

```
/* N bodies */
int N = 5; // this will be varied in loop (read below).
/* Gravitational constant */
double G = 6.673e-11;
/* timestep */
double timestep = 0.001;  // experiment with this!
/* small mass */
double initial_mass = 1.0; // experiment with this!
/* num timesteps */
double k = 100; // you can experiment with this! it can be fairly large.
```

Your single body in N-body will look like this:

```
typedef struct body {
    int ind; // index of body
    double mass;
    R position;
    V velocity;
    F *forceVector; // computed {f-i1,fi2...fiN}
    F totalForce; // computed
    A acceleration;  // computed from f = ma
};
```

The magnitude of gravitation force between two objects can be described as

<img src="formula.png" alt="Gravitation Force Equation"/>

You need to create a single-threaded C++ algorithm to compute force exerted on each body
with respect to other N-1 bodies at each (of k) timesteps. As the bodies collide you will need to
update the force, acceleration, velocity and position at each time step.

For example the force on one body due to another body can be computed as:

<img src="formula1.jpg" alt="Gravitation Force Equation"/>

Make sure you set the initial position, velocity, acceleration, mass, and force vectors
of a body before you begin the iteration timesteps. Mass of each body will be constant.

Use some lambda equations to:

- Update the force exerted on a body
- Update the acceleration on a body
- Update velocity of a body
- Update position of a body
- Compute distance between bodies (x, y) space

There will be more lambda functions you will write besides above.

You already know how to compute Force for each body using the gravitional equation above
with respect to each of the other N-1 bodies. Where m1 is the mass of this body, and m2 is the
mass of the other bodies from the N-1 bodies. So you will need a for loop to update the
force for each of the N bodies at each timestep.

And from Newton's law, write a lambda for following too:

```
F = m * a
```

Since you know the mass, you can compute the acceleration of each body.

Now that you know the acceleration of each body, the velocity and position of a body at 
ith timestep can be computed as:

```
New Velocity = Current Velocity + timestep*acceleration
```

```
New Position = Current Position + timestep*velocity
```

So you will need additional loop to compute the velocity and position of each body above
at each time step.

Once you compute the force exerted on each body from each of the other N-1 bodies, you will
need to compute the total force exerted on each body by summing the force from each of the N-1
bodies, and you will need to update the total force this way for each of the N bodies in each
time step. This summation also should use a lambda function.

Assuming you run this test for duration D, and with k timesteps for N bodies, you should write
a final lambda function that computes the number of interactions per second using the following
formula:

```
Interactions/sec = k * N * N / D
```

You should run the above test by varying the number of bodies (N):

```
    int numBodies[] = {10, 20, 50, 100, 200, 500, 1000, 2000};
```

So you can then compute interactions per sec lambda for each value of N in above array.

Optionally print a graph with X axis (N) and Y axis (interactions/sec). If you cannot plot a 
graph using matplotlib or something similar, save the data as a JSON file with two elements per
record. First element should be value of N, and second element should be interactions/sec.
