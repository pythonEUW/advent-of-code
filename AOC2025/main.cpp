// main.cpp
#include <iostream>
#include <algorithm>
#include "solutions.h"

int main() {
    auto& solutions = get_solutions();

    //Tri des solutions par jour et partie
    std::ranges::sort(solutions, [](const Solution& a, const Solution& b) {
        if (a.day != b.day) return a.day < b.day;
        return a.part < b.part;
    });

    std::cout << "--- Advent of Code 2025 ---" << std::endl;

    for (const auto& sol : solutions) {
        long long result = sol.solver();
        std::cout << "Reponse de la partie " << sol.part << " du jour " << sol.day << ": " << result << std::endl;
    }

    return 0;
}
