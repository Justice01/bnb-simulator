#include "apply_settings.hpp"

#include <simulators/resolver.hpp>
#include <processes/process.hpp>

#include <kernel/dmmemory/sched.hpp>
#include <kernel/dmmemory/schedtracer.hpp>

#include <list>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

void input (int &n, std::vector<int> &balance_params);

int main()
{
    apply_settings();

    int n;

    std::vector<int> balance_params;

    input(n, balance_params);

    simulator::communicator comm(n);

    std::list<Sched> scheduler_pool;

    std::list<simulator::resolver> resolver_pool;

    std::list<SchedTracer> tracer_pool;

    std::list<simulator::process> process_pool;

    for (int i = 0; i < n; ++i) {
        scheduler_pool.emplace_back(balance_params);
        resolver_pool.emplace_back();
        tracer_pool.emplace_back(1);

        process_pool.emplace_back(comm, scheduler_pool.back(), resolver_pool.back(), tracer_pool.back());
    }

    while (!process_pool.empty()) {
        auto process_cursor = process_pool.end();

        long long time = simulator::timer::sleep_time;

        for (auto p = process_pool.begin(); p != process_pool.end(); ++p) {
            long long t = p->activate();

            if (t != simulator::timer::sleep_time) {
                if (time == simulator::timer::sleep_time || time > t) {
                    process_cursor = p;
                    time = t;
                }
            }
        }

        if (process_cursor == process_pool.end()) {
            std::cout << "All processes are sleeping" << std::endl;
            BNB_ERROR_REPORT("Deadlock");
        }

        bool quit = process_cursor->proceed();

        if (quit)
            process_pool.erase(process_cursor);
    }
}

void input (int &n, std::vector<int> &balance_params)
{
    std::vector<std::string> s_params;
    std::string input;
    int i_input = 0;
    getline(std::cin, input);
    std::istringstream iss(input);
    copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), back_inserter(s_params));
    if (!(std::istringstream(s_params[0]) >> n)) n = 0;

    for(unsigned int i = 1; i < s_params.size(); i++){
        if (!(std::istringstream(s_params[i]) >> i_input)) i_input = 0;
        balance_params.push_back(i_input);
    }
}
