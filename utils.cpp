#include "utils.hpp"
#include <regex>
#include <stdexcept>

using namespace std;

void check_email(const string& email) {
    regex pattern(".+@.+\\..+");

    if (!regex_match(email, pattern)) {
        throw invalid_argument("Invalid email");
    }
}
