#ifndef _sched_initializer_hpp_
#define _sched_initializer_hpp_

#define NDEBUG
#include <string>
#include <libjson/libjson.h>

namespace simulator
{
    struct SchedInitializer
    {
        static std::string chaiIniFileName;

        static std::string chaiSchedFileName;

        static void apply_settings(const JSONNode& node);
    };
}

#endif // _sched_initializer_hpp_
