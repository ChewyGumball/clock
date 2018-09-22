#include <iostream>
#include <thread>

#include "Clock.h"

int main() {
    using Time::Clock;
    using Time::Timer;

    constexpr Clock::Seconds SLEEP_TIME = std::chrono::seconds(1);

    Clock clock;
    Timer timer(&clock);

    for(int i = 0; i < 10; i++) {
        std::this_thread::sleep_for(SLEEP_TIME);
        clock.tick();

        Clock::Seconds tickedSeconds = clock.tickedTime();
        Clock::Seconds elapsedSeconds = clock.totalElapsedTime();

        std::cout << "Iteration " << i + 1 << ": Tick Time = " << tickedSeconds.count() << "s Elapsed Time = " << elapsedSeconds.count() << "s\n";

        if(i == 3) {
            timer.stop();
            Clock::Seconds timerElapsedSeconds = timer.elapsedTime();
            std::cout << "Timer Stopped: Elapsed Time = " << timerElapsedSeconds.count() << "s\n";
        }

        if(i == 5) {
            timer.start();
            Clock::Seconds timerElapsedSeconds = timer.elapsedTime();
            std::cout << "Timer Started: Elapsed Time = " << timerElapsedSeconds.count() << "s\n";
        }

        if(i == 7) {
            Clock::Seconds timerElapsedSeconds = timer.elapsedTime();
            std::cout << "Timer Resetting: Elapsed Time = " << timerElapsedSeconds.count() << "s\n";
            timer.reset();
        }
    }

    Clock::Seconds timerElapsedSeconds = timer.elapsedTime();
    std::cout << "Timer Elapsed Time = " << timerElapsedSeconds.count() << "s\n";
}