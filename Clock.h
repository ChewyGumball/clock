#pragma once
#include <chrono>

namespace Time {
	class Clock
	{
	public:
        using Seconds = std::chrono::duration<float>;
        using Nanoseconds = std::chrono::nanoseconds;

		Clock(float timeScaling = 1.0f)
            : previousTick(clock.now()), currentTick(clock.now()), elapsedTime(Clock::Nanoseconds::zero()), scale(timeScaling), running(true)
        { }

		bool isRunning() const { return running; }

		void pause() {
            running = false;
            previousTick = currentTick;
        }

		void resume() {
            running = true;
            currentTick = clock.now();
            previousTick = currentTick;
        }

		void tick() {
            if (running) {
                previousTick = currentTick;
                currentTick = clock.now();
                elapsedTime += currentTick - previousTick;
            }
        }

        Nanoseconds tickedTime() const {
            return std::chrono::duration_cast<Clock::Nanoseconds>((currentTick - previousTick) * scale);
        }

        Nanoseconds totalElapsedTime() const {
            return std::chrono::duration_cast<Clock::Nanoseconds>(elapsedTime * scale);
        }

    private:
        std::chrono::steady_clock clock;
        std::chrono::steady_clock::time_point previousTick;
        std::chrono::steady_clock::time_point currentTick;
        Nanoseconds elapsedTime;

        float scale;
        bool running;
	};

	class Timer
	{
        enum class StartType {
            STARTED,
            STOPPED
        };

		const Clock* clock;
		Clock::Nanoseconds startTime;
        Clock::Nanoseconds savedTime;
        bool running;

	public:
		Timer(const Clock* clock, StartType startType = StartType::STARTED)
            : clock(clock), startTime(clock->totalElapsedTime()), savedTime(Clock::Nanoseconds::zero()), running(startType == StartType::STARTED)
        { }

		bool isRunning() const { return running; }

        void start() {
            if (!running) {
                startTime = clock->totalElapsedTime();
                running = true;
            }
        }
		void stop() {
            if (running) {
                savedTime = elapsedTime();
                running = false;
            }
        }
		void reset() {
            startTime = clock->totalElapsedTime();
            savedTime = Clock::Nanoseconds::zero();
        }

        Clock::Nanoseconds elapsedTime() const {
            if (running) {
                return clock->totalElapsedTime() - startTime + savedTime;
            }
            else {
                return savedTime;
            }
        }
	};
}
