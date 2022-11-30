#include "correct.h"

#include <iostream>
#include <limits>

int get_data() {
    int temp;
    std::cin >> temp;
    while (std::cin.fail() || std::cin.get() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.sync();
        std::cin >> temp;
    }
    return temp;
}