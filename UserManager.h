#pragma once
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;


class UserManager 
{
public:
    bool registerUser(const string& login, const string& password, const string& fullName, const string& address, const string& phone);
    void viewUserResults(const string& login);
    bool deleteUser(const string& login);
    bool login(const string& login, const string& password);
    json loadUsers();
    bool isLoginUnique(const string& login);
    void saveUsers(const json& users);
    string hashPassword(const string& password, const string& salt);
    string generateSalt();
};
//реализация данных функций находится в UserManager.cpp
//the code for these functions is written in UserManager.cpp
