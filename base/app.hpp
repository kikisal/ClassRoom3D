#pragma once

#include <thread>
#include <memory>

struct ILoopListener {
    
};

struct AppContext;

extern struct BaseApp* g_currAppInstance;

struct BaseApp {

    BaseApp();
public:
    virtual void OnUpdate() = 0;

public:
    int run();
    inline std::shared_ptr<AppContext> GetContext();
    ~BaseApp();

private:
    std::thread _appThread;
    std::shared_ptr<AppContext> _appContext;

};