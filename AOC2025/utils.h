//
// Created by Python on 13/12/2025.
//

#ifndef AOC2025_UTILS_H
#define AOC2025_UTILS_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

inline std::vector<std::string> read_lines(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << file_path << std::endl;
        return {};
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

inline std::string read_file(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << file_path << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

inline std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

inline std::vector<int> to_int(const std::vector<std::string>& string_vec) {
    std::vector<int> int_vec;
    for (const auto& s : string_vec) {
        if (!s.empty()) {
            int_vec.push_back(std::stoi(s));
        }
    }
    return int_vec;
}

#endif //AOC2025_UTILS_H

