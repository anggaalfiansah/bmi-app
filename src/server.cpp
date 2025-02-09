#define CROW_STATIC_DIRECTORY "src/templates/"
#include "crow.h"
#include "crow/middlewares/cors.h"
#include "bmi.h"
#include <fstream>
#include <sstream>

/**
 * @brief Memulai server HTTP menggunakan Crow.
 * 
 * Fungsi ini menginisialisasi server dengan middleware CORS, menetapkan route untuk
 * menyajikan halaman HTML, dan menyediakan endpoint API untuk perhitungan BMI.
 */
void StartServer()
{
    // Inisialisasi aplikasi Crow dengan middleware CORS
    crow::App<crow::CORSHandler> app;

    // Konfigurasi middleware CORS
    auto &cors = app.get_middleware<crow::CORSHandler>();
    cors.global()
        .headers("X-Custom-Header", "Upgrade-Insecure-Requests") // Header tambahan yang diizinkan
        .methods("POST"_method, "GET"_method, "OPTIONS"_method)   // Metode HTTP yang diizinkan
        .prefix("/api")   // Prefix untuk API endpoint
        .origin("*");     // Mengizinkan semua domain (CORS policy)

    /**
     * @brief Route untuk halaman utama ("/").
     * 
     * Saat pengguna mengakses root "/", server akan mengembalikan halaman index.html.
     * Jika file tidak ditemukan, server mengembalikan respons 404.
     */
    CROW_ROUTE(app, "/")([]()
                         {
        std::ifstream file("src/templates/index.html");
        if (!file)
        {
            return crow::response(404, "File not found");
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        return crow::response{buffer.str()}; });

    /**
     * @brief API endpoint untuk menghitung BMI.
     * 
     * Endpoint: POST /api/bmi
     * 
     * Mengharapkan JSON dengan format:
     * {
     *   "name": "John Doe",
     *   "gender": "male",
     *   "height": 170,
     *   "weight": 65,
     *   "age": 25
     * }
     * 
     * Respon sukses:
     * {
     *   "status": "success",
     *   "data": {
     *     "name": "John Doe",
     *     "gender": "male",
     *     "height": 170,
     *     "weight": 65,
     *     "age": 25,
     *     "bmi_score": 22.5,
     *     "status": "Berat badan ideal dan sehat",
     *     "suggestion": "Tetap pertahankan pola makan sehat..."
     *   }
     * }
     * 
     * Jika ada data yang hilang atau tidak valid, server mengembalikan respons error 400.
     */
    CROW_ROUTE(app, "/api/bmi").methods(crow::HTTPMethod::Post)([](const crow::request &req)
                                                                {
        auto body = crow::json::load(req.body);
        std::vector<std::string> requiredFields = {"name", "gender", "height", "weight", "age"};

        // Validasi apakah semua field yang diperlukan ada dalam JSON request
        for (const auto &field : requiredFields)
        {
            if (!body.has(field))
            {
                return crow::response(400, "Invalid input: Harap sertakan semua field yang diperlukan (name, gender, height, weight, age).");
            }
        }

        // Ambil nilai dari JSON request
        std::string name = body["name"].s();
        std::string gender = body["gender"].s();
        int height = body["height"].i();
        int weight = body["weight"].i();
        int age = body["age"].i();

        // Validasi nilai numerik
        if (height <= 0 || weight <= 0 || age <= 0)
        {
            return crow::response(400, "Invalid input: Height, weight, dan age harus lebih besar dari 0.");
        }

        // Hitung BMI menggunakan fungsi dari bmi.h
        BMIResult result = calculateBMIResult(height, weight);

        // Format respons dalam JSON
        crow::json::wvalue response;
        response["status"] = "success";
        response["data"]["name"] = name;
        response["data"]["gender"] = gender;
        response["data"]["height"] = height;
        response["data"]["weight"] = weight;
        response["data"]["age"] = age;
        response["data"]["bmi_score"] = result.score;
        response["data"]["status"] = result.status;
        response["data"]["suggestion"] = result.suggestion;

        return crow::response{response}; });

    // Menjalankan server di port 5000 dengan mode multi-threading
    app.port(5000).multithreaded().run();
}
