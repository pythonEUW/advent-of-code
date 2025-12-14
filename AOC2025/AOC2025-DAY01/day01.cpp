//
// Created by Python on 13/12/2025.
//

#include "../solutions.h"
#include "../utils.h"

REGISTER_SOLUTION(1, 1, part1) {
    const std::string file_path = "../AOC2025-DAY01/input.txt";
    try {
        int sum = 0;
        int dial = 50;
        const std::vector<std::string> lines = read_lines(file_path);

        for (const std::string& line : lines) {
            const std::vector<std::string> number = split(line,line[0]);
            const int distance = to_int(number)[0];
            if (line[0] == 'R') {
                dial = (dial + distance)%100;
            } else {
                dial = (dial- distance +100)%100;
            }
            if (dial == 0) {
                sum += 1;
            }
        }
        return sum;
    } catch (const std::exception& e) {
        std::cerr << "Une erreur est survenue: " << e.what() << std::endl;
        return 1;
    }
}

REGISTER_SOLUTION(1, 2, part2) {
    const std::string file_path = "../AOC2025-DAY01/input.txt";
    try {
        int sum = 0;
        int dial = 50;
        const std::vector<std::string> lines = read_lines(file_path);
        for (const std::string& line : lines) {
            const std::vector<std::string> number = split(line,line[0]);
            const int distance = to_int(number)[0];
            char direction = line[0];
            if (direction == 'R') {
                sum += (dial + distance - 1) / 100;
                dial = (dial + distance) % 100;
            } else {
                if (distance > dial) {
                    if (dial == 0) {
                        sum += (distance - dial - 1) / 100;
                    } else {
                        sum += (distance - dial - 1) / 100 + 1;
                    }
                }
                dial = (dial - distance % 100 + 100) % 100;
            }
            if (dial == 0) {
                sum += 1;
            }
        }
        return sum;
    } catch (const std::exception& e) {
        std::cerr << "Une erreur est survenue dans la partie 2: " << e.what() << std::endl;
        return -1;
    }
}