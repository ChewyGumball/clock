# Clock
A simple, header only library for keeping track of time based on std::chrono.

# Features
## Clock
### Ticking
A `Clock` only advances time when its `tick()` function is called. The time between the previous two `tick()` calls can be retrieved using the `tickedTime()` function.
### Pausing
A `Clock` can be paused by calling its `pause()` function. Calls to `tick()` will not advance time while a `Clock` is paused, and `tickedTime()` will return a duration of zero time. A `Clock` can be resumed by calling its `resume()` function.
### Time Dilation
A `Clock` can be run faster or slower than wall time by using the `timeScaling` parameter in the `Clock` constructor. The returned values from both `tickedTime()` and `totalElapsedTime()` will be scaled by the value of `timeScaling`.
### `Clock::Seconds` vs `std::chrono::seconds`
`Clock::Seconds` can represent fractional seconds while `std::chrono::seconds` can not.
## Timer
A `Timer` keeps track of the elapsed time of a `Clock`. Multiple `Timer`s can be tracking time of the same `Clock`. A `Timer`'s elapsed time is scaled by the same amount of the `Clock` is its tracking.
# Example Output
The output of the example code provided is:
```
Seconds per tick: 1
Time Dilation Factor: 0.333333
Tick 1
         Fast Clock: Tick Time = 1.00172s Elapsed Time = 1.00172s
         Slow Clock: Tick Time = 0.333906s Elapsed Time = 0.333906s
Tick 2
         Fast Clock: Tick Time = 1.00327s Elapsed Time = 2.00499s
         Slow Clock: Tick Time = 0.334424s Elapsed Time = 0.66833s
Tick 3
         Fast Clock: Tick Time = 1.00316s Elapsed Time = 3.00815s
         Slow Clock: Tick Time = 0.334386s Elapsed Time = 1.00272s
Tick 4
         Fast Clock: Tick Time = 1.00284s Elapsed Time = 4.01099s
         Slow Clock: Tick Time = 0.33428s Elapsed Time = 1.337s
Timer Stopped:
         Fast Timer: Elapsed Time = 4.01099s
         Slow Timer: Elapsed Time = 1.337s
Tick 5
         Fast Clock: Tick Time = 1.00425s Elapsed Time = 5.01524s
         Slow Clock: Tick Time = 0.334751s Elapsed Time = 1.67175s
Tick 6
         Fast Clock: Tick Time = 1.00375s Elapsed Time = 6.01899s
         Slow Clock: Tick Time = 0.334583s Elapsed Time = 2.00633s
Timer Started:
         Fast Timer: Elapsed Time = 4.01099s
         Slow Timer: Elapsed Time = 1.337s
Tick 7
         Fast Clock: Tick Time = 1.00498s Elapsed Time = 7.02397s
         Slow Clock: Tick Time = 0.334993s Elapsed Time = 2.34132s
Tick 8
         Fast Clock: Tick Time = 1.00334s Elapsed Time = 8.02731s
         Slow Clock: Tick Time = 0.334448s Elapsed Time = 2.67577s
Timer Resetting:
         Fast Timer: Elapsed Time = 6.01931s
         Slow Timer: Elapsed Time = 2.00644s
Tick 9
         Fast Clock: Tick Time = 1.00467s Elapsed Time = 9.03198s
         Slow Clock: Tick Time = 0.33489s Elapsed Time = 3.01066s
Tick 10
         Fast Clock: Tick Time = 1.003s Elapsed Time = 10.035s
         Slow Clock: Tick Time = 0.334334s Elapsed Time = 3.345s
Final Timer Times:
         Fast Timer: Elapsed Time = 2.00767s
         Slow Timer: Elapsed Time = 0.669224s
```
