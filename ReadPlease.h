#pragma once

//languages:
//RUS
//ENG


//������������� ������ �� �++
//��������� ����������� � ������:
// ������� ��� ����� ������ ��� �������������:

// ��� �������� ������:
//�����: admin
//������: 111111

//��� �������� �����:
//�����: Petya
//������: abc123
// ������: Moscow 5
//�����: 77543858


//���� ��������� �������� �� ������ � �������: ����� ������ ��������� � ��������� ��� �������,
//�� ������� ������� � ������ ������� users.json � admin.json, ���� ������� �������

//������������ ������ � ������ �������: openssl � nlohmann

//� console application ������������� �������, �������������� ���������
///��������� ��������� ����� ������������, ������ �� UserManager ����� ��������� ������� �������������
//� ������ �� ������ TestManager ����� �������� � �������.
//������� guest �������� � ���� ���� while ������� ���������� ����.
//������������ �� ������ ������������ ����������� ��������������� �������� � �������������� UserManager
//� TestManager.

//� main ������������ setlocale(LC_ALL, "Russian") ��� ����, ����� ������������� ������� ���� � �������
//� main ��������� �������:
//UserManager userManager
//AdminManager adminManager
//TestManager testManager
//testManager.loadTests("tests.json") -> ��������� ����� �� ����� test.json.


//����� ������������ �������� ����� ��� �����, �� ������������ ����� � ������
//��� ����� ������������ ����� userManager.login(login, password) ��� �������� ������
//���� ���� �������� ������� -> ���������� guest
//����� ������������ ��������� ����� �������, �� ������������� ����� ������  (�����, ������, ���, �����, �������)
//��� ����� ������������ ����� userManager.registerUser() ��� ����������� ������ ������������
//����� ������������ ������ ��� �������������, �� ���������� ����� adminManager.login()
//���� ���� �������� �������, ���������� ����� adminManager.menu()


//� ����� UserManager.h (������������ ����) ��� ������ �������� public (������������)
//��������� ��� ������:
//bool registerUser(const string& login, const string& password, const string& fullName, const string& address, const string& phone) ������������ ������ ������������
//void viewUserResults(const string& login) �������� ����������� ���������������� ������
//bool deleteUser(const string& login) ������� ������������
//bool login(const string& login, const string& password) ��������� ����� � ������ ������������
//json loadUsers() ��������� ������ ������������� �� �����
//bool isLoginUnique(const string& login) ���������, �������� �� ����� ������������
//void saveUsers(const json& users) ��������� ������ ������������� � ����
//string hashPassword(const string& password, const string& salt) �������� ������ � �������������� ���� (���� + ������)
//string generateSalt() ���������� ��������� ���� ��� �������

//� ����� UserManager.cpp ���������� ���������� ������� �� UserManager.h (������ UserManager)
//��� ������� �������� ��� ���� ���� ���������
//��� ���������� ������� ������������ ������������ SHA256 �� openssl


//����� AdminManager.h � AdminManager.cpp
//���������� ���������� �� UserManager.h � UserManager.cpp, ������ ��� ���������� admin
//� ������ ������ ����������� ������ ��� ����������� ������ � ���������� �������������� | �������
//����� ��� ����������� ���� ������


//����� TestManager.h � TestManager.cpp
//����� ���������� �� ��������� UserManager.h � UserManager.cpp
//��� �������� � ����: �������� ������ �� ����� JSON,� ��������� ������, ����� ����������� ������������
//� ���������� ������� (��������, ��������)


//�� ������ ������ ��� ��

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
// bool registerUser() � Registers a new user
// void viewUserResults() � Shows test results for a user
// bool deleteUser() � Deletes a user
// bool login() � Checks user login and password
// json loadUsers() � Loads users data from file
// bool isLoginUnique() � Checks if login is unique
// void saveUsers() � Saves users data to file
// string hashPassword() � Hashes password with salt (salt + password)
// string generateSalt() � Creates random salt for passwords

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

//that�s all for now
