#pragma once

#include "all_includes.h"
#include <chrono>

class Timer {
public:
    Timer() : start(std::chrono::high_resolution_clock::now()) {}
    float elapsed() {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        return duration.count();
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};