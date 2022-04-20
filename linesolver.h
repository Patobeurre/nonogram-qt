#ifndef LINESOLVER_H
#define LINESOLVER_H

#include <vector>
#include <iostream>
#include <cstdint>
#include <stdint.h>

using namespace std;

class LineSolver {
private:
    uint64_t length;
    vector<uint64_t> *clue;
    uint64_t partialSolid;
    uint64_t partialDot;
    uint64_t improvedSolid;
    uint64_t improvedDot;
    uint64_t improvedDotMask;
    bool isDotCovered(uint64_t test);
    bool isSolidAbutted (uint64_t test);
    bool isSolidRevealed (uint64_t test);
    bool isSolidMatch (uint64_t test);
    uint64_t bitRepresentationOfBlock (uint64_t block_size, uint64_t position);
    bool solve (uint64_t block, uint64_t position, uint64_t parents);

public:
    LineSolver();
    void printBitblock (uint64_t bitblock);
    void printResult();
    void solve(uint64_t l, uint64_t ps, uint64_t pd, vector<uint64_t> *c);
    uint64_t getSolid();
    uint64_t getDot();
};

#endif
