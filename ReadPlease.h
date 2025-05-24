#pragma once

//languages:
//RUS
//ENG


//Лаборатнорная работа по С++
//Небольшие комментарии к работе:
// брались вот такеи данные для пользователей:

// для аккаунта админа:
//логин: admin
//пароль: 111111

//для аккаунта гостя:
//логин: Petya
//пароль: abc123
// адресс: Moscow 5
//номер: 77543858


//если возникают проблемы со входом в аккаунт: пишет ошибки связанные с аккаунтом или файлами,
//то следует удалить в файлах проекта users.json и admin.json, если таковые имеются

//обязательные пакеты в данном проекте: openssl и nlohmann

//в console application распологаются функции, представляющие интерфейс
///интерфейс принимает логин пользователя, ссылку на UserManager чтобы управлять данными пользователей
//и ссылку на обьект TestManager чтобы работать с тестами.
//Функция guest содержит в себе цикл while который отображает меню.
//взависимости от выбора пользователя выполняются соответствующие действия с использованием UserManager
//и TestManager.

//в main используется setlocale(LC_ALL, "Russian") для того, чтобы поддерживался русский язык в консоли
//в main создаются обьекты:
//UserManager userManager
//AdminManager adminManager
//TestManager testManager
//testManager.loadTests("tests.json") -> загружает тесты из файла test.json.


//Когда пользователь выбирает войти как гость, то спрашивается логин и пароль
//для этого используется метод userManager.login(login, password) для проверки данных
//Если вход выполнен успешно -> вызывается guest
//Когда пользователь добавляет новый аккаунт, то запрашивается новые данные  (логин, пароль, имя, адрес, телефон)
//для этого используется метод userManager.registerUser() для регистрации нового пользователя
//Когда пользователь входит как администратор, то вызывается метод adminManager.login()
//Если вход выполнен успешно, вызывается метод adminManager.menu()


//в файле UserManager.h (заголовочный файл) все методы являются public (общедоступны)
//подробнее про методы:
//bool registerUser(const string& login, const string& password, const string& fullName, const string& address, const string& phone) Регистрирует нового пользователя
//void viewUserResults(const string& login) просмотр результатов пользовательских тестов
//bool deleteUser(const string& login) удаляет пользователя
//bool login(const string& login, const string& password) проверяет логин и пароль пользователя
//json loadUsers() загружает данные пользователей из файла
//bool isLoginUnique(const string& login) проверяет, уникален ли логин пользователя
//void saveUsers(const json& users) сохраняет данные пользователей в файл
//string hashPassword(const string& password, const string& salt) хеширует пароль с использованием соли (соль + пароль)
//string generateSalt() генерирует случайную соль для паролей

//в файле UserManager.cpp происходит реализация методов из UserManager.h (класса UserManager)
//для личного удобства они были мною разделены
//для хэшрования паролей используется используется SHA256 из openssl


//файлы AdminManager.h и AdminManager.cpp
//Аналогичны структурой на UserManager.h и UserManager.cpp, только там реализован admin
//в данных файлах реализованы методы для регистрации админа и управления пользователями | тестами
//также там реализовано меню админа


//Файлы TestManager.h и TestManager.cpp
//также аналогичны по структуре UserManager.h и UserManager.cpp
//они включают в себя: загрузки тестов из файла JSON,п роведения тестов, учета результатов тестирования
//и управление тестами (просмотр, удаление)


//на данный момент это всё

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

//Lab work for C++
//some small comments about the work:

//These are the user accounts used:

//Admin account:
//login: admin
//password: 111111

//Guest account:
//login: Petya
//password: abc123
//address: Moscow 5
//phone number: 77543858

//If there are problems logging into the account (for example, errors about accounts or files),
//you should delete the files "users.json" and "admin.json" from the project folder (if they exist)

//Required libraries for this project: OpenSSL and nlohmann

//A console application has functions that work as a menu (interface).
// The interface takes the user's login, a reference to UserManager (to manage user data),
// and a reference to TestManager (to work with tests).
// The guest function has a while loop that shows the menu.
// Based on what the user chooses, different actions are done using UserManager and TestManager.

// In main, we use setlocale(LC_ALL, "Russian") to support Russian text in the console.
// In main, we create objects:
// UserManager userManager
// AdminManager adminManager
// TestManager testManager
// testManager.loadTests("tests.json") -> loads tests from tests.json file

// When the user chooses to log in as a guest, they must enter login and password.
// userManager.login(login, password) is used to check the data.
// If the login is successful -> the guest function is called.
// When the user wants to create a new account, they enter new data (login, password, full name, address, phone).
// userManager.registerUser() is used to register a new user.
// When the user logs in as admin, adminManager.login() is called.
// If login is successful, adminManager.menu() is called.

// In UserManager.h (header file), all methods are public (available).
// More about the methods:
// bool registerUser() – Registers a new user
// void viewUserResults() – Shows test results for a user
// bool deleteUser() – Deletes a user
// bool login() – Checks user login and password
// json loadUsers() – Loads users data from file
// bool isLoginUnique() – Checks if login is unique
// void saveUsers() – Saves users data to file
// string hashPassword() – Hashes password with salt (salt + password)
// string generateSalt() – Creates random salt for passwords

// In UserManager.cpp we write the code for the methods from UserManager.h
// I separated the files for better organization
// For password hashing, we use SHA256 from openssl

// Files AdminManager.h and AdminManager.cpp
// They are similar in structure to UserManager files, but for admin
// These files have methods for admin login and managing users/tests
// They also include the admin menu

// Files TestManager.h and TestManager.cpp
// Also have a similar structure to UserManager files
// They include: loading tests from JSON, doing tests, saving test results,
// and managing tests (viewing, deleting)

//that’s all for now
