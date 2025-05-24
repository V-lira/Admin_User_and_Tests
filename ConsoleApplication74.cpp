#include <iostream>
#include <string>
#include "UserManager.h"
#include "AdminManager.h"
#include "TestManager.h"

using namespace std;
void guest(const string& login, UserManager& userManager, TestManager& testManager)
{
    while (true) 
    {
        cout << "/////////////////////////////////////// МЕНЮ ГОСТЯ ///////////////////////////////////////\n";
        cout << "1. ПОСМОТРЕТЬ РЕЗУЛЬТАТЫ ТЕСТИРОВАНИЙ\n";
        cout << "2. СДАТЬ ТЕСТ\n";
        cout << "0. ВЫХОД\n> ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) 
        {
            auto users = userManager.loadUsers();
            bool found = false;
            for (auto& user : users) 
            {
                if (user["login"] == login) 
                {
                    found = true;
                    if (user["results"].empty()) 
                    {
                        cout << "Результатов нет\n";
                    }
                    else 
                    {
                        cout << "РЕЗУЛЬТАТЫ ТЕСТИРОВАНИЯ:\n";
                        for (auto& res : user["results"]) 
                        {
                            cout << "БЫЛО ПРОЙДЕНО: " << res["date"] << ", НАЗВАНИЕ ТЕСТА: " << res["test_title"] << ", ПРАВИЛЬНЫХ: " << res["correct"] << " из " << res["total"] << ", ПРОЦЕНТОВ: " << res["percent"] << "%\n" << "100% = 5; 75% = 4; 50% = 3; 25% = 2\n";
                        }
                    }
                    break;
                }
            }
            if (!found) 
            {
                cout << "Пользователь не найден.\n";
            }
        }
        else if (choice == 2) 
        {
            testManager.startTest(login);
        }
        else if (choice == 0) 
        {
            cout << "Вы вышли из аккаунта\n";
            break;
        }
        else 
        {
            cout << "Error!\n";
        }
    }
}
int main() 
{
   


    setlocale(LC_ALL, "Russian");



    UserManager userManager;
    AdminManager adminManager;
    TestManager testManager;
    testManager.loadTests("tests.json");

    while (true) 
    {
        cout << "\n/////////////////////////////////////// ТЕСТИРОВАНИЕ ///////////////////////////////////////\n";
        cout << "1. Я ГОСТЬ\n";
        cout << "2. ДОБАВИТЬ АККАУНТ\n";
        cout << "3. Я АДМИН\n";
        cout << "0. ВЫХОД\n> ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1) 
        {
            string login, password;
            cout << "Логин: ";
            cin >> login;
            cout << "Пароль: ";
            cin >> password;

            if (userManager.login(login, password))
            {
                cout << "Успеншо!\n";
                guest(login, userManager, testManager);
            }
            else 
            {
                cout << "НЕПРАВИЛЬЫЙ ЛОГИН ИЛИ ПАРОЛЬ\n";
            }
        }
        else if (choice == 2) 
        {
            string login;
            string password;
            string fullName;
            string address;
            string phone;

            cout << "ДОБАВЛЕНИЕ НОВОГО АККАУНТА\n";
            cout << "Логин: ";

            cin >> login;
            cin.ignore();
            cout << "Пароль: ";
            getline(cin, password);
            cout << "ФИО: ";
            getline(cin, fullName);
            cout << "Домашний адрес: ";
            getline(cin, address);
            cout << "Телефон: ";
            getline(cin, phone);

            if (userManager.registerUser(login, password, fullName, address, phone))
            {
                cout << "УСПЕШНО\n";
            }
            else
            {
                cout << "ЛОГИН УЖЕ СУЩЕСТВУЕТ!!!\n";
            }
        }
        else if (choice == 3) 
        {
            if (adminManager.login())
            {
                adminManager.menu();
            }
        }
        else if (choice == 0)
        {
            cout << "ВЫЙТИ\n";
            break;
        }
        else
        {
            cout << "НЕПРАВИЛЬНО. ПОПРОБУЙ ЕЩЁ РАЗ\n";
        }
    }
}
