#pragma once
#include <string>
using namespace std;
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class TestManager 
{
public:
    void loadTests(const string& filename);
    void startTest(const string& userLogin);
    const json& getTests() const;
    bool deleteTest(const string& title);
    void saveTests(const string& filename);
    json tests;
    void showTest(const json& test);
};
//реализация данных функций находится в TestManager.cpp
//the code for these functions is written in TestManager.cpp