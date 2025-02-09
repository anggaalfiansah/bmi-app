#include "bmi.h"

/**
 * @brief Menghitung BMI (Body Mass Index) berdasarkan tinggi dan berat badan yang diberikan.
 * 
 * Fungsi ini mengambil tinggi badan (dalam cm) dan berat badan (dalam kg), 
 * kemudian menghitung nilai BMI menggunakan rumus:
 * 
 * \f[
 * BMI = \frac{\text{berat badan (kg)}}{(\text{tinggi (m)})^2}
 * \f]
 * 
 * Berdasarkan nilai BMI yang diperoleh, fungsi ini juga menentukan status berat badan 
 * pengguna serta memberikan saran yang sesuai.
 * 
 * @param height Tinggi badan dalam satuan sentimeter (cm).
 * @param weight Berat badan dalam satuan kilogram (kg).
 * @return BMIResult Struktur yang berisi skor BMI, status berat badan, dan saran kesehatan.
 */
BMIResult calculateBMIResult(int height, int weight)
{
    BMIResult result;
    
    // Konversi tinggi dari cm ke meter
    float heightMeter = height / 100.0;

    // Hitung nilai BMI
    result.score = weight / (heightMeter * heightMeter);

    // Tentukan status BMI dan saran berdasarkan kategori BMI
    if (result.score < 18.5)
    {
        result.status = "Berat badan di bawah normal";
        result.suggestion = 
            "Berat badan Anda masih di bawah kisaran yang sehat. "
            "Disarankan untuk meningkatkan asupan kalori dengan makanan bergizi seimbang "
            "dan berkonsultasi dengan ahli gizi jika diperlukan.";
    }
    else if (result.score < 24.9)
    {
        result.status = "Berat badan ideal dan sehat";
        result.suggestion = 
            "Selamat! Berat badan Anda berada dalam kisaran ideal. "
            "Tetap pertahankan pola makan sehat, olahraga teratur, dan gaya hidup aktif "
            "untuk menjaga keseimbangan tubuh.";
    }
    else if (result.score < 29.9)
    {
        result.status = "Berat badan berlebih (Overweight)";

        // Variasi saran berdasarkan rentang BMI untuk overweight
        if (result.score < 27)
        {
            result.suggestion = 
                "Anda memiliki sedikit kelebihan berat badan. "
                "Cobalah mengatur pola makan yang lebih sehat dan meningkatkan aktivitas fisik agar tetap bugar.";
        }
        else
        {
            result.suggestion = 
                "Berat badan Anda sudah melebihi batas ideal. "
                "Pertimbangkan untuk mengadopsi pola makan sehat dan meningkatkan aktivitas fisik secara bertahap "
                "guna mencapai berat badan yang lebih seimbang.";
        }
    }
    else
    {
        result.status = "Obesitas (Perlu perhatian lebih)";

        // Variasi saran berdasarkan tingkat obesitas
        if (result.score < 35)
        {
            result.suggestion = 
                "Anda berada dalam kategori obesitas tingkat 1. "
                "Disarankan untuk mulai mengontrol pola makan dan berolahraga secara teratur "
                "guna menghindari risiko kesehatan di masa depan.";
        }
        else if (result.score < 40)
        {
            result.suggestion = 
                "Obesitas tingkat 2. Kondisi ini dapat meningkatkan risiko berbagai penyakit. "
                "Segera konsultasikan dengan dokter atau ahli gizi untuk mendapatkan panduan yang tepat.";
        }
        else
        {
            result.suggestion = 
                "Obesitas tingkat 3 (morbid obesity). "
                "Kondisi ini bisa berdampak serius pada kesehatan Anda. "
                "Penting untuk segera mencari bantuan medis dan mulai menerapkan pola hidup sehat yang terarah.";
        }
    }

    return result;
}
