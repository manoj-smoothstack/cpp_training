
//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include <vector>
#include <string>
#include <unordered_map>
#include <numeric>
#include <execution>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <iostream>

std::vector<std::string> browsers = {"chrome", "firefox", "safari", "ie"};
std::vector<std::string> pages = {"home", "aboutus", "contactus", "sales", "products", "downloads"};
time_t current = std::time(nullptr);

struct log_info {
    std::string page;
    time_t visit_time;
    std::string browser;
    // any other fields
};

log_info parse_log_line(std::string const &line) {
    std::string browser = browsers[rand() % browsers.size()];
    std::string page = pages[rand() % pages.size()];
    time_t visit_time = rand() % current;
    log_info li = {page, visit_time, browser};
    return li;
}

using visit_map_type = std::unordered_map<std::string, unsigned long long>;

visit_map_type count_visits_per_page(std::vector<std::string> const &log_lines) {
    struct combine_visits {
        visit_map_type operator()(visit_map_type lhs, visit_map_type rhs) const {
            if (lhs.size() < rhs.size())
                std::swap(lhs, rhs);
            for (auto const &entry : rhs) {
                lhs[entry.first]+= entry.second;
            }
            //std::cout << "called map, map" << std::endl;
            return lhs;
        }

        visit_map_type operator()(log_info log, visit_map_type map) const{
            ++map[log.page];
            //std::cout << "called log, map" << std::endl;
            return map;
        }

        visit_map_type operator()(visit_map_type map, log_info log) const{
            ++map[log.page];
            //std::cout << "called map, log" << std::endl;
            return map;
        }

        visit_map_type operator()(log_info log1, log_info log2) const{
            visit_map_type map;
            ++map[log1.page];
            ++map[log2.page];
            std::cout << "called log1, log2" << std::endl;
            return map; 
        }
    };

    return std::transform_reduce(
            std::execution::par, log_lines.begin(), log_lines.end(),
            visit_map_type(), combine_visits(), parse_log_line);
}

int main(void) {
    std::vector<std::string> log_lines;
    for (int ii = 0; ii < 250000; ii++) {
        log_lines.push_back("");
    }
    visit_map_type vmt = count_visits_per_page(log_lines);
    for (auto entry : vmt) {
        std::cout << entry.first << "," << entry.second << std::endl;
    }
}

