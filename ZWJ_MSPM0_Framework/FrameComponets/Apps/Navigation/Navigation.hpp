#pragma once

#include "SysDefs.hpp"
#include "System.hpp"

class Navigation : public Application {
    SINGLETON(Navigation) : Application("Navigation") {};
    APPLICATION_OVERRIDE;
};

extern Navigation &navigation;