#ifndef QUESTION_H
#define QUESTION_H

#include <stdexcept>
#include <cstdint>

class Histogram {
private:
    uint32_t* bins;
    double minVal;
    double maxVal;
    double binWidth;
    int numBins;

public:
    // Throws invalid_argument if invalid params:
    Histogram(double minVal, double maxVal, int numBins);
    // RAII:
    ~Histogram();

    int getBinIndex(double value) const;

    void append(double value);

    // throws out_of_range if invalid param:
    int get(int bin_index) const;
};

#endif // QUESTION_H