# clock
A simple, header only library for keeping track of time based on std::chrono.

#Features
##Clock
###Ticking
A `Clock` only advances time when its `tick()` function is called. The time between the previous two `tick()` calls can be retrieved using the `tickedTime()` function.
###Pausing
A `Clock` can be paused by calling its `pause()` function. Calls to `tick()` will not advance time while a `Clock` is paused, and `tickedTime()` will return a duration of zero time. A `Clock` can be resumed by calling its `resume()` function.
###Time Dilation
A `Clock` can be run faster or slower than wall time by using the `timeScaling` parameter in the `Clock` constructor. The returned values from both `tickedTime()` and `totalElapsedTime()` will be scaled by the value of `timeScaling`.
###Clock::Seconds vs std::chrono::seconds
`Clock::Seconds` can represent fractional seconds while `std::chrono::seconds` can not.
##Timer
A `Timer` keeps track of the elapsed time of a `Clock`. Multiple `Timer`s can be tracking time of the same `Clock`. A `Timer`'s elapsed time is scaled by the same amount of the `Clock` is its tracking.
