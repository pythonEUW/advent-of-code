// solutions.h
#ifndef AOC2025_SOLUTIONS_H
#define AOC2025_SOLUTIONS_H

#include <vector>
#include <functional>
#include <map>

// Structure pour une solution
struct Solution {
    int day;
    int part;
    std::function<long long()> solver;
};

// Registre global des solutions
inline std::vector<Solution>& get_solutions() {
    static std::vector<Solution> solutions_registry;
    return solutions_registry;
}

// Classe utilitaire pour l'auto-enregistrement
struct SolutionRegistrar {
    SolutionRegistrar(int day, int part, std::function<long long()> solver) {
        get_solutions().push_back({day, part, std::move(solver)});
    }
};

// Macro pour simplifier l'enregistrement
#define REGISTER_SOLUTION(day, part, func) \
long long func(); \
SolutionRegistrar registrar_##day##_##part(day, part, func); \
long long func()

#endif //AOC2025_SOLUTIONS_H
