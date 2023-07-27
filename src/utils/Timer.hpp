/*
** EPITECH PROJECT, 2023
** $
** File description:
** Timer
*/

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <chrono>

class Timer {
    public:
        Timer() {
            restart();
        }

        double getElapsedTime() const {
            auto currentTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> elapsedTime = currentTime - _startTime;
            return elapsedTime.count();
        }

        double getElapsedTimeSec() const {
            auto currentTimeSec = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsedTime = currentTimeSec - _startTimeSec;
            return elapsedTime.count();
        }

        void restart() {
            _startTime = std::chrono::high_resolution_clock::now();
        }

        void restartSec()
        {
            _startTimeSec = std::chrono::high_resolution_clock::now();
        }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> _startTime;
        std::chrono::time_point<std::chrono::high_resolution_clock> _startTimeSec;
};


#endif /* !TIMER_HPP_ */
