#pragma once
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
class AdminManager 
{
public:
    static bool login();
    static void menu();
    static void setup();
    static string hashPassword(const string& password, const string& salt);
    static string generateSalt();
};
//реализация данных функций находится в AdminManager.cpp
//the code for these functions is written in AdminManager.cpp