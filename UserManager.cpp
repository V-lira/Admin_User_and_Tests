#include "UserManager.h"
#include <iostream>
#include <fstream>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>
#include <random>
using namespace std;


//������ Hex?
//������� toHex(����������� ����) ���������� ����� � ������ �� ����������������� ����� (hex-������)
//��� ���������� ASCII ���������, ����� ���������� ������ ������ ������ � ��� �������� ��������, 
//� ����� ���������� ��� ����� � ����������������� �����
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Why Hex?
// The toHex function (shown below) changes text into a string of hexadecimal numbers (hex string).
// It uses ASCII encoding to get a number for each character in the string,
// and then writes that number in hexadecimal format.
string toHex(const string& input) 
{
    stringstream ss;
    ss << hex << setfill('0');
    for (unsigned char c : input) 
    {
        ss << setw(2) << (int)c;
    }
    return ss.str();
}
void UserManager::viewUserResults(const string& login) 
{
    json users = loadUsers();
    for (const auto& user : users) 
    {
        if (user["login"] == login)
        {
            cout << "���������� ������������ " << login << ":\n";
            for (const auto& result : user["results"])
            {
                cout << "-> ����: " << result["date"] << "\n";
                cout << "����: " << result["test_title"] << "\n";
                cout << "����������: " << result["correct"] << " �� " << result["total"] << "\n";
                cout << "�������: " << result["percent"] << "%\n\n";
            }
            return;
        }
    }
    cout << "����� ������� �� ������\n";
}
bool UserManager::deleteUser(const string& login) 
{
    json users = loadUsers();
    bool found = false;
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if ((*it)["login"] == login) 
        {
            users.erase(it);
            found = true;
            break;
        }
    }
    if (found) 
    {
        saveUsers(users);
        cout << "������������ ��� �����\n";
    }
    else 
    {
        cout << "����� ������� �� ������\n";
    }
    return found;
}
json UserManager::loadUsers() 
{
    ifstream in("users.json");
    if (!in.is_open())
        return json::array();
    json users;
    in >> users;
    return users;
}
void UserManager::saveUsers(const json& users) 
{
    ofstream out("users.json");
    if (!out.is_open()) 
    {
        cout << "�� ������� ������� users.json!" << endl;
        return;
    }
    out << setw(4) << users << endl;
}
bool UserManager::isLoginUnique(const string& login) 
{
    json users = loadUsers();
    for (auto& user : users) 
    {
        if (user["login"] == login)
            return false;
    }
    return true;
}
string UserManager::generateSalt() 
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 255);
    string saltBytes;
    for (int i = 0; i < 16; ++i) 
    {
        saltBytes += static_cast<char>(dis(gen));
    }
    return toHex(saltBytes);
}
string UserManager::hashPassword(const string& password, const string& salt)
{
    string input = salt + password;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    return ss.str();
}
bool UserManager::registerUser(const string& login, const string& password,
    const string& fullName, const string& address, const string& phone) 
{
    if (!isLoginUnique(login)) 
    {
        cout << "����� ��� ����������!\n";
        return false;
    }
    string salt = generateSalt();
    string hashed = hashPassword(password, salt);
    json users = loadUsers();
    users.push_back(
        {
        {"full_name", fullName},{"address", address},
        {"phone", phone},
        {"login", login},
        {"password_hash", hashed},
        {"salt", salt},
        {"results", json::array()}
        });

    saveUsers(users);
    cout << "������������ ������� ���������������!\n";
    return true;
}

bool UserManager::login(const string& login, const string& password) 
{
    json users = loadUsers();
    for (auto& user : users) 
    {
        if (user["login"] == login) 
        {
            string salt = user["salt"];
            string hashed = hashPassword(password, salt);
            if (hashed == user["password_hash"])
            {
                cout << "�� ������� �����\n";
                return true;
            }
            else 
            {
                cout << "������ �� ����������\n";
                return false;
            }
        }
    }
    cout << "����� ������� �� ������\n";
    return false;
}
