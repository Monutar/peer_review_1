#include <cassert>
#include <cstdint>
#include <iostream>
#include <utility>
#include <optional>
#include <deque>
#include <numeric>
#include <cmath>
#include <vector>
#include <array>
#include <tuple>
#include <unordered_map>
#include <sstream>
#include <functional>
#include <iomanip>
#include <set>
#include <memory>
#include <random>
#include <climits>
#include <queue>
#include <chrono>
#include <iterator>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <list>
#include <string_view>
#include <string>

#include "log_duration.h"

using namespace std;
using namespace std::literals;

int main() {

    int num_requests;
    string command;
    int user_id;
    int read_pages;

    vector<int> user_data;
    vector<int> count_users;
    int num_users = 0;

    user_data.reserve(100000);
    count_users.reserve(1000);
    cin >> num_requests;

    for (int i = 0; i < num_requests; ++i) {
        cin >> command;

        if (command == "CHEER") {
            cin >> user_id;

            if (user_data[user_id] == 0) {
                cout << 0 << endl;
                continue;
            }

            if (num_users == 1) {
                cout << 1 << endl;
                continue;
            }

            int users_to_page = 0;
            for (int j = 0; j < user_data[user_id]; ++j) {
                users_to_page += count_users[j];
            }
            cout << setprecision(6) << users_to_page/(num_users - 1.) << endl;

        } else {
            cin >> user_id >> read_pages;

            if (user_data[user_id] == 0) {
                ++num_users;
            }

            if (count_users[user_data[user_id]] != 0) {
                --count_users[user_data[user_id]];
            }

            user_data[user_id] = read_pages;
            ++count_users[user_data[user_id]];
        }
    }

    return 0;
}