#include "time.h"

int main() {
    Time time;
    std::cout << "Input time: ";
    std::cin >> time;

    std::cout << "Time: " << time << std::endl;
    std::cout << time << " + 5 seconds = " << time + 5 << std::endl;

    Time time1, time2;
    std::cout << "Input time1: ";
    std::cin >> time1;
    std::cout << "Input time2: ";
    std::cin >> time2;

    std::cout << time1 << " + " << time2 << " = " << time1 + time2 << std::endl;

    std::cout << "Is time1 == time2: " << (time1 == time2) << std::endl;

    std::cout << "Time1 + 1 = " << ++time1 << std::endl;

    return 0;
}