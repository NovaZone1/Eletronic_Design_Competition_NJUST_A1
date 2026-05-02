#pragma once

#include "SysDefs.hpp"
#include "System.hpp"

class Track : public Application {
    SINGLETON(Track) : Application("Track") {};
    APPLICATION_OVERRIDE;
};

extern Track &track;