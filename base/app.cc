#include "base/app.hpp"
#include "base/app_context.hpp"
#include <iostream>
#include "logger/Debugger.hpp"

BaseApp* g_currAppInstance = nullptr;

BaseApp::BaseApp() : _appContext {
    std::make_shared<AppContext>()
} {
    if (g_currAppInstance)
    {
        Debugger::Log("One instance of app is currently running.");
        return;
    }
    g_currAppInstance = this;
}

BaseApp::~BaseApp() {
    if (_appThread.joinable())
        _appThread.join();

    if (_appContext)
        _appContext->Dispose();
}

int BaseApp::run() {
    Debugger::Log("APP RUNNING.");
    this->OnUpdate();
    return 0;
}

inline std::shared_ptr<AppContext> BaseApp::GetContext() { 
    return _appContext;
}
