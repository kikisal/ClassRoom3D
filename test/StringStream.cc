#include <iostream>
#include "types/StringStream.hpp"

int main() {
    StringStream str {"hello", "everyone", "adsidsasdao", "dasiosdasdajo"};
    auto result = str.Join(", ");
    std::cout << result.get() << std::endl;
    return 0;
}