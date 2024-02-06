#pragma once

#include "base/app.hpp"

struct ClassRoomApp : public BaseApp {
    explicit ClassRoomApp() = default;

    void OnUpdate() final;
};