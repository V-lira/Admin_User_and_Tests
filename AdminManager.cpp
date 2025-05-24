#include "AdminManager.h"
#include "UserManager.h"
#include "TestManager.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>
#include <random>
using namespace std;
using json = nlohmann::json;

string AdminManager::generateSalt() 
{
    const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string salt;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, sizeof(charset) - 2);
    for (int i = 0; i < 16; ++i) 
    {
        salt += charset[dist(gen)];
    }
    return salt;
}
string AdminManager::hashPassword(const string& password, const string& salt) 
{
    string salted = password + salt;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(salted.c_str()), salted.size(), hash);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) 
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}
void AdminManager::setup() 
{
    ifstream in("admin.json");
    if (in.peek() == ifstream::traits_type::eof()) 
    {
        cout << "Настройка админf\n";
        string login, password;
        cout << "Логин админа: ";
        cin >> login;
        cout << "Пароль админа: ";
        cin >> password;
        string salt = generateSalt();
        string hashed = hashPassword(password, salt);

        json admin = {{"login", login},
            {"salt", salt},
            {"password_hash", hashed}};

        ofstream out("admin.json");
        out << setw(4) << admin;
        out.close();
        cout << "Администратор есть!\n";
    }
}
bool AdminManager::login() 
{
    setup();
    ifstream in("admin.json");
    if (!in.is_open()) 
    {
        cout << "Не удалось открыть admin.json!\n";
        return false;
    }
    json admin;
    in >> admin;
    if (!admin.contains("login") || !admin.contains("salt") || !admin.contains("password_hash")) 
    {
        cout << "Ошибка! admin.json повреждён!\n";
        return false;
    }
    string login, password;
    cout << "Логин администратора: ";
    cin >> login;
    cout << "Пароль администратора: ";
    cin >> password;
    string hash = hashPassword(password, admin["salt"]);

    if (login == admin["login"] && hash == admin["password_hash"]) 
    {
        cout << "Вы успешно вошли!\n";
        return true;
    } 
    else 
    {
        cout << "Неверный логин или пароль!\n";
        return false;
    }
}
void AdminManager::menu() 
{
    UserManager userManager;
    TestManager testManager;
    testManager.loadTests("tests.json");
    while (true) 
    {
        cout << "\n/////////////////////////////////////// Админ ///////////////////////////////////////\n";
        cout << "1. ПОСМОТРЕТЬ ВСЕХ ПОЛЬЗОВАТЕЛЕЙ\n";
        cout << "2. УДАЛИТЬ ПОЛЬЗОВАТЕЛЯ\n";
        cout << "3. ПОСМОТРЕТЬ ВСЕ ДОСТУПНЫЕ ТЕСТЫ\n";
        cout << "4. УДАЛИТЬ ТЕСТ\n";
        cout << "0. ВЫХОД\n> ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) 
        {
            auto users = userManager.loadUsers();
            if (users.empty()) 
            {
                cout << "Такой пользователь не найден\n";
            }
            else 
            {
                cout << "Пользователи:\n";
                for (const auto& user : users)
                {
                    cout << "-> " << user["login"] << " (" << user["full_name"] << ")\n";
                }
            }
        } 
        else if (choice == 2) 
        {
            string login;
            cout << "Введите логин выбранного пользователя для удаления: ";
            cin >> login;
            if (userManager.deleteUser(login)) 
            {
                cout << "Пользователь успешно удалён!\n";
            } 
            else 
            {
                cout << "Пользователь не найден!\n";
            }
        } 
        else if (choice == 3) 
        {
            auto tests = testManager.getTests();
            if (tests.empty()) 
            {
                cout << "Доступных тестов нет!\n";
            } 
            else 
            {
                cout << "Тесты:\n";
                for (const auto& test : tests) 
                {
                    cout << "-> " << test["title"] << " (" << test["questions"].size() << " вопросов)\n";
                }
            }
        } 
        else if (choice == 4) 
        {
            string title;
            cout << "Введите название выбранного теста для удаления: ";
            getline(cin, title);
            if (testManager.deleteTest(title)) 
            {
                cout << "Тест успешно удалён!\n";
                testManager.saveTests("tests.json");
            } 
            else 
            {
                cout << "Тест не найден!\n";
            }
        } 
        else if (choice == 0) 
        {
            cout << "Выход\n";
            break;
        } 
        else
        {
            cout << "Неверный выбор!\n";
        }
    }
}
