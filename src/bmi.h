#ifndef BMI_H
#define BMI_H

#include <string>

/**
 * @brief Struktur untuk menyimpan hasil perhitungan BMI.
 * 
 * Struktur ini menyimpan tiga informasi utama terkait hasil perhitungan BMI:
 * - **score**: Nilai indeks massa tubuh (BMI).
 * - **status**: Kategori berat badan berdasarkan nilai BMI.
 * - **suggestion**: Rekomendasi atau saran kesehatan berdasarkan kategori BMI.
 */
struct BMIResult {
    float score;           ///< Nilai BMI yang dihitung.
    std::string status;    ///< Kategori berat badan berdasarkan BMI.
    std::string suggestion; ///< Saran kesehatan yang sesuai dengan hasil BMI.
};

/**
 * @brief Menghitung BMI berdasarkan tinggi dan berat badan.
 * 
 * Fungsi ini menerima tinggi badan (dalam cm) dan berat badan (dalam kg),
 * lalu menghitung nilai BMI menggunakan rumus:
 * 
 * \f[
 * BMI = \frac{\text{berat badan (kg)}}{(\text{tinggi (m)})^2}
 * \f]
 * 
 * Berdasarkan nilai BMI yang diperoleh, fungsi ini menentukan status berat badan
 * dan memberikan rekomendasi yang sesuai.
 * 
 * @param height Tinggi badan dalam satuan sentimeter (cm).
 * @param weight Berat badan dalam satuan kilogram (kg).
 * @return BMIResult Struktur berisi skor BMI, status berat badan, dan saran kesehatan.
 */
BMIResult calculateBMIResult(int height, int weight);

#endif // BMI_H
