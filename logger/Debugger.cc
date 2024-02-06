#include "Debugger.hpp"
#include <iostream>

#define DEBUGGER_TAG "[DEBUGGER]: "

void Debugger::Log(StringStream message) {
    auto ptr = message.Join(", ");
    std::cout << DEBUGGER_TAG << ptr.get() << std::endl;
}