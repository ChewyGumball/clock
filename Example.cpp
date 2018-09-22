#include <iostream>
#include <thread>

#include "Clock.h"

void printClocks(Time::Clock& fastClock, Time::Clock& slowClock);
void printTimers(Time::Timer& fastTimer, Time::Timer& slowTimer);

int main() {
    using Time::Clock;
    using Time::Timer;

    constexpr Clock::Seconds SLEEP_TIME = std::chrono::seconds(1);
    constexpr float TIME_SCALE = 1.0f / 3.0f;

    Clock clock;
    Clock slowClock(TIME_SCALE);
    Timer timer(&clock);
    Timer slowTimer(&slowClock);

    std::cout << "Seconds per tick: " << SLEEP_TIME.count() << "\n";
    std::cout << "Time Dilation Factor: " << TIME_SCALE << std::endl;

    for(int i = 0; i < 10; i++) {
        std::this_thread::sleep_for(SLEEP_TIME);
        clock.tick();
        slowClock.tick();

        Clock::Seconds tickedSeconds = clock.tickedTime();
        Clock::Seconds elapsedSeconds = clock.totalElapsedTime();

        std::cout << "Tick " << i + 1 << "\n";
        printClocks(clock, slowClock);

        if(i == 3) {
            timer.stop();
            slowTimer.stop();
            std::cout << "Timer Stopped:\n";
            printTimers(timer, slowTimer);
        }

        if(i == 5) {
            std::cout << "Timer Started:\n";
            printTimers(timer, slowTimer);
            timer.start();
            slowTimer.start();
        }

        if(i == 7) {
            std::cout << "Timer Resetting:\n";
            printTimers(timer, slowTimer);
            timer.reset();
            slowTimer.reset();
        }
    }

    std::cout << "Final Timer Times:\n";
    printTimers(timer, slowTimer);
}

void printClocks(Time::Clock& fastClock, Time::Clock& slowClock)
{
    using Time::Clock;

    Clock::Seconds tickedSeconds = fastClock.tickedTime();
    Clock::Seconds elapsedSeconds = fastClock.totalElapsedTime();

    Clock::Seconds slowTickedSeconds = slowClock.tickedTime();
    Clock::Seconds slowElapsedSeconds = slowClock.totalElapsedTime();

    std::cout << "\t Fast Clock: Tick Time = " << tickedSeconds.count() << "s Elapsed Time = " << elapsedSeconds.count() << "s\n";
    std::cout << "\t Slow Clock: Tick Time = " << slowTickedSeconds.count() << "s Elapsed Time = " << slowElapsedSeconds.count() << "s\n";

    std::cout << std::flush;
}

void printTimers(Time::Timer& fastTimer, Time::Timer& slowTimer)
{
    using Time::Clock;
    using Time::Timer;

    Clock::Seconds timerElapsedSeconds = fastTimer.elapsedTime();
    Clock::Seconds slowTimerElapsedSeconds = slowTimer.elapsedTime();

    std::cout << "\t Fast Timer: Elapsed Time = " << timerElapsedSeconds.count() << "s\n";
    std::cout << "\t Slow Timer: Elapsed Time = " << slowTimerElapsedSeconds.count() << "s\n";
    
    std::cout << std::flush;
}