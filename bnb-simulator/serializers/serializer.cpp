#include "serializer.hpp"

void simulator::serializer::apply_settings(const JSONNode& node)
{
    parcel_size::apply_settings(node["parcel_size"]);
}

int simulator::serializer::parcel_size::command;
int simulator::serializer::parcel_size::record;
int simulator::serializer::parcel_size::subproblem;

void simulator::serializer::parcel_size::apply_settings(const JSONNode& node)
{
    command = node["n_command"].as_int();
    record = node["n_record"].as_int();
    subproblem = node["n_subproblem"].as_int();
}
