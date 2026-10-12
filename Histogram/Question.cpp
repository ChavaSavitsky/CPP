#include "Question.h"
#include <algorithm> 

Histogram::Histogram(double minVal, double maxVal, int numBins) 
    : bins(nullptr), minVal(minVal), maxVal(maxVal), binWidth(0.0), numBins(numBins) {
    if (minVal >= maxVal) {
        throw std::invalid_argument("minVal must be less than maxVal");
    }
    if (numBins <= 0) {
        throw std::invalid_argument("numBins must be positive");
    }

    binWidth = (maxVal - minVal) / static_cast<double>(numBins);
    bins = new uint32_t[numBins]();
}

Histogram::~Histogram() {
    delete[] bins;
    bins = nullptr;
}

int Histogram::getBinIndex(double value) const {
    if (value < minVal) return 0;

    for (int i = 0; i < numBins - 1; ++i) {
        double upper = minVal + static_cast<double>(i + 1) * binWidth;
        if (value <= upper) {
            return i;
        }
    }

    return numBins - 1;
}

void Histogram::append(double value) {
    int idx = getBinIndex(value);
    ++_bins[idx];
}

int Histogram::get(int bin_index) const {
    if (bin_index < 0 || bin_index >= numBins) {
        throw std::out_of_range("bin_index out of range");
        //return 0;
    }
    return static_cast<int>(bins[bin_index]);
}