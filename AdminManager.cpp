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
        cout << "��������� �����f\n";
        string login, password;
        cout << "����� ������: ";
        cin >> login;
        cout << "������ ������: ";
        cin >> password;
        string salt = generateSalt();
        string hashed = hashPassword(password, salt);

        json admin = {{"login", login},
            {"salt", salt},
            {"password_hash", hashed}};

        ofstream out("admin.json");
        out << setw(4) << admin;
        out.close();
        cout << "������������� ����!\n";
    }
}
bool AdminManager::login() 
{
    setup();
    ifstream in("admin.json");
    if (!in.is_open()) 
    {
        cout << "�� ������� ������� admin.json!\n";
        return false;
    }
    json admin;
    in >> admin;
    if (!admin.contains("login") || !admin.contains("salt") || !admin.contains("password_hash")) 
    {
        cout << "������! admin.json ��������!\n";
        return false;
    }
    string login, password;
    cout << "����� ��������������: ";
    cin >> login;
    cout << "������ ��������������: ";
    cin >> password;
    string hash = hashPassword(password, admin["salt"]);

    if (login == admin["login"] && hash == admin["password_hash"]) 
    {
        cout << "�� ������� �����!\n";
        return true;
    } 
    else 
    {
        cout << "�������� ����� ��� ������!\n";
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
        cout << "\n/////////////////////////////////////// ����� ///////////////////////////////////////\n";
        cout << "1. ���������� ���� �������������\n";
        cout << "2. ������� ������������\n";
        cout << "3. ���������� ��� ��������� �����\n";
        cout << "4. ������� ����\n";
        cout << "0. �����\n> ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) 
        {
            auto users = userManager.loadUsers();
            if (users.empty()) 
            {
                cout << "����� ������������ �� ������\n";
            }
            else 
            {
                cout << "������������:\n";
                for (const auto& user : users)
                {
                    cout << "-> " << user["login"] << " (" << user["full_name"] << ")\n";
                }
            }
        } 
        else if (choice == 2) 
        {
            string login;
            cout << "������� ����� ���������� ������������ ��� ��������: ";
            cin >> login;
            if (userManager.deleteUser(login)) 
            {
                cout << "������������ ������� �����!\n";
            } 
            else 
            {
                cout << "������������ �� ������!\n";
            }
        } 
        else if (choice == 3) 
        {
            auto tests = testManager.getTests();
            if (tests.empty()) 
            {
                cout << "��������� ������ ���!\n";
            } 
            else 
            {
                cout << "�����:\n";
                for (const auto& test : tests) 
                {
                    cout << "-> " << test["title"] << " (" << test["questions"].size() << " ��������)\n";
                }
            }
        } 
        else if (choice == 4) 
        {
            string title;
            cout << "������� �������� ���������� ����� ��� ��������: ";
            getline(cin, title);
            if (testManager.deleteTest(title)) 
            {
                cout << "���� ������� �����!\n";
                testManager.saveTests("tests.json");
            } 
            else 
            {
                cout << "���� �� ������!\n";
            }
        } 
        else if (choice == 0) 
        {
            cout << "�����\n";
            break;
        } 
        else
        {
            cout << "�������� �����!\n";
        }
    }
}
