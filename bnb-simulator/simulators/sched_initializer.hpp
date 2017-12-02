#ifndef _sched_initializer_hpp_
#define _sched_initializer_hpp_

#define NDEBUG
#include <string>
#include <libjson/libjson.h>

namespace simulator
{
    class SchedInitializer
    {
        static std::string simulator::chaiIniFileName;

        static std::string simulator::chaiSchedFileName;

    public:

        static void apply_settings(const JSONNode& node);
    };
}

#endif // _sched_initializer_hpp_
