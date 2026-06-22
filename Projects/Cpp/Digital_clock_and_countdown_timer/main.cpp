#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

void digitalClock();

int main() {
    digitalClock();

    return 0;
}

void digitalClock() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::tm* localTime = std::localtime(&currentTime);

    system("cls");

    std::cout << "Current time: ";
    //hours
    if(localTime -> tm_hour < 10) std::cout << "0";
    std::cout << localTime -> tm_hour << ":";
    //minutes
    if(localTime -> tm_min < 10) std::cout << "0";
    std::cout << localTime -> tm_min << ":";
    //seconds
    if(localTime -> tm_sec < 10) std::cout << "0";
    std::cout << localTime -> tm_sec << '\n';

    std::cout << '\n';

    std::this_thread::sleep_for(std::chrono::seconds(1));
}