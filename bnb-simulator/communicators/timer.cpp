#include "timer.hpp"

void simulator::timer::apply_settings(const JSONNode& node)
{
    time_cost::apply_settings(node["time_cost"]);
}

int simulator::timer::time_cost::solve;
int simulator::timer::time_cost::store;
int simulator::timer::time_cost::load;
int simulator::timer::time_cost::overhead;

void simulator::timer::time_cost::apply_settings(const JSONNode& node)
{
    solve = node["n_solve"].as_int();
    store = node["n_store"].as_int();
    load = node["n_load"].as_int();
    overhead = node["n_overhead"].as_int();
}
