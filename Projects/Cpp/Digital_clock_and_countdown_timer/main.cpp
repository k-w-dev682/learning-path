#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

void digitalClock();
void countDownTime();

int main() {
    //digitalClock();

    countDownTime();

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

    //std::this_thread::sleep_for(std::chrono::seconds(1));
}

void countDownTime() {
    int minutes, seconds;

    std::cout << "Countdown time\n";

    std::cout << "Enter minutes: ";
    std::cin >> minutes;

    std::cout << "Enter seconds: ";
    std::cin >> seconds;

    int totalSeconds = (minutes * 60) + seconds;

    while(totalSeconds >= 0) {
        system("cls");
        
        digitalClock();

        int currentMin = totalSeconds / 60;
        int currentSec = totalSeconds % 60;

        std::cout << "Time remaining: ";

        if(currentMin < 10) std::cout << "0";
        std::cout << currentMin << ":";

        if(currentSec < 10) std::cout << "0";
        std::cout << currentSec << "\n\n";

        totalSeconds--;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    system("cls");

    digitalClock();

    std::cout << "Time's up!";
}