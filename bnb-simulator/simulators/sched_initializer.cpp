#include "sched_initializer.hpp"

std::string simulator::SchedInitializer::chaiIniFileName;
std::string simulator::SchedInitializer::chaiSchedFileName;

void simulator::SchedInitializer::apply_settings(const JSONNode& node)
{
    chaiIniFileName = libjson::to_std_string(node["c_chaiIniFileName"].as_string());
    chaiSchedFileName = libjson::to_std_string(node["c_chaiSchedFileName"].as_string());
}
