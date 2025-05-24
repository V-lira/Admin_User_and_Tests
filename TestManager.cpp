#include "TestManager.h"
#include "UserManager.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const json& TestManager::getTests() const 
{
    return tests;
}
bool TestManager::deleteTest(const string& title) 
{
    for (auto it = tests.begin(); it != tests.end(); ++it) 
    {
        if ((*it)["title"] == title) 
        {
            tests.erase(it);
            return true;
        }
    }
    return false;
}
void TestManager::saveTests(const string& filename)
{
    ofstream out(filename);
    if (!out.is_open()) 
    {
        cout << "Ошибка при сохранении тестов в " << filename << "\n";
        return;
    }
    out << setw(4) << tests << endl;
}
void TestManager::loadTests(const string& filename) 
{
    ifstream in(filename);
    if (!in.is_open()) 
    {
        cout << "Не удалось загрузить тесты из файла " << filename << "\n";
        return;
    }
    in >> tests;
}
void TestManager::showTest(const json& test)
{
    cout << "\nТест: " << test["title"] << "\n";
    int num = 1;
    for (auto& question : test["questions"]) 
    {
        cout << num++ << ". " << question["text"] << "\n";
        char option = 'a';
        for (auto& ans : question["answers"]) 
        {
            cout << "  " << option++ << ") " << ans["text"] << "\n";
        }
    }
}
void TestManager::startTest(const string& userLogin) 
{
    if (tests.empty()) 
    {
        cout << "Тесты не загружены!\n";
        return;
    }
    cout << "\nДоступные тесты:\n";
    for (size_t i = 0; i < tests.size(); i++) 
    {
        cout << i + 1 << ". " << tests[i]["title"] << "\n";
    }
    cout << "Выберите номер теста для прохождения: ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice >(int)tests.size()) 
    {
        cout << "Неверный выбор!\n";
        return;
    }
    const json& test = tests[choice - 1];
    int total = (int)test["questions"].size();
    int correct = 0;
    cin.ignore(); //очистка буфера | clears the buffer
    for (auto& question : test["questions"]) 
    {
        cout << "\n" << question["text"] << "\n";
        char option = 'a';
        for (auto& ans : question["answers"])
        {
            cout << "  " << option++ << ") " << ans["text"] << "\n";
        }
        cout << "Ваш ответ: ";
        char userAnswer;
        cin >> userAnswer;
        userAnswer = tolower(userAnswer);
        int answerIndex = userAnswer - 'a';
        if (answerIndex >= 0 && answerIndex < (int)question["answers"].size()) 
        {
            if (question["answers"][answerIndex]["correct"] == true) 
            {
                correct++;
            }
        }
    }
    //подсчёт процентов
    //percentage calculation
    int percent = (int)((correct * 100.0f) / total);
    time_t now = time(nullptr);
    tm localTime;
    localtime_s(&localTime, &now);
    char datetime[20];
    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M", &localTime);
    
    UserManager userManager;
    json users = userManager.loadUsers();
    for (auto& user : users) 
    {
        if (user["login"] == userLogin) 
        {
            user["results"].push_back({
                {"date", string(datetime)},
                {"test_title", test["title"]},
                {"correct", correct},
                {"total", total},
                {"percent", percent}
                });


            break;
        }
    }
    userManager.saveUsers(users);
    cout << "\nРезультат:\n";
    cout << "Правильных ответов: " << correct << " из " << total << "\n";
    cout << "Процент правильных ответов: " << percent << "%\n";
}
