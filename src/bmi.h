#ifndef BMI_H
#define BMI_H

#include <string>

// Struktur untuk menyimpan hasil perhitungan BMI
struct BMIResult {
    float score;
    std::string status;
    std::string suggestion;
};

// Fungsi untuk menghitung BMI dan mengembalikan objek BMIResult
BMIResult calculateBMIResult(int height, int weight);

#endif
