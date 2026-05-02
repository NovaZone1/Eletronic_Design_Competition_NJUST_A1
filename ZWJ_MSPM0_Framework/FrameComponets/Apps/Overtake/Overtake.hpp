#pragma once

#include "SysDefs.hpp"
#include "System.hpp"

class Overtake : public Application {
    SINGLETON(Overtake) : Application("Overtake") {};
    APPLICATION_OVERRIDE;
};

extern Overtake &overtake;
