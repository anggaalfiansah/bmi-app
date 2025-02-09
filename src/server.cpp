#define CROW_STATIC_DIRECTORY "src/templates/"
#include "crow.h"
#include "crow/middlewares/cors.h"
#include "bmi.h"
#include <fstream>
#include <sstream>

void StartServer()
{
    crow::App<crow::CORSHandler> app;

    auto &cors = app.get_middleware<crow::CORSHandler>();
    cors.global()
        .headers("X-Custom-Header", "Upgrade-Insecure-Requests")
        .methods("POST"_method, "GET"_method, "OPTIONS"_method)
        .prefix("/api")
        .origin("*");

    // Serve index.html saat akses root "/"
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

    // Route untuk menghitung BMI
    CROW_ROUTE(app, "/api/bmi").methods(crow::HTTPMethod::Post)([](const crow::request &req)
                                                                {
        auto body = crow::json::load(req.body);
        std::vector<std::string> requiredFields = {"name", "gender", "height", "weight", "age"};

        for (const auto &field : requiredFields)
        {
            if (!body.has(field))
            {
                return crow::response(400, "Invalid input: Harap sertakan semua field yang diperlukan (name, gender, height, weight, age).");
            }
        }

        std::string name = body["name"].s();
        std::string gender = body["gender"].s();
        int height = body["height"].i();
        int weight = body["weight"].i();
        int age = body["age"].i();

        if (height <= 0 || weight <= 0 || age <= 0)
        {
            return crow::response(400, "Invalid input: Height, weight, dan age harus lebih besar dari 0.");
        }

        BMIResult result = calculateBMIResult(height, weight);

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

    app.port(5000).multithreaded().run();
}
