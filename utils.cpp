#include "utils.hpp"
#include <regex>
#include <stdexcept>

void check_email(const std::string& email) {
    std::regex pattern("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");

    if (!std::regex_match(email, pattern)) {
        throw std::invalid_argument("Invalid email format");
    }
}
