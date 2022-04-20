#ifndef NONOGRAM_H
#define NONOGRAM_H

#include <ctime>
#include <cstdlib>
#include <QDebug>
#include "solver.h"

class Nonogram {
 private:
    uint64_t width, height;
    int solids, dots;
    uint64_t *field;
    vector<uint64_t> **xAxis;
    vector<uint64_t> **yAxis;
    void generateField();
    void generatePuzzle();
    double probability(int above, int left);

 public:
    Nonogram(uint64_t w, uint64_t h);
    Nonogram(uint64_t w, uint64_t h, uint64_t* f);
    ~Nonogram();
    void print();
    vector<uint64_t>** getXAxis();
    vector<uint64_t>** getYAxis();
    uint64_t* getField();
    uint64_t getWidth();
    uint64_t getHeight();
};
#endif

