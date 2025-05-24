#pragma once

//languages:
//RUS
//ENG


//�������:
//����������� ������������������� ������� ������������.
//� ������� ������ ���� 2 ������: ������������� � �����������.
//�������� ������ ������ ��� ������������(� ���������� �����) :
//	��� ����� � ������� ����� ������ ������������������ ������ ���������
//	����������� ���� ���, ��� ���������� ������ � ������� ������ ���� �� ������ �
//	������.
//	��� ����������� ����� ��������� �.�.�., �������� �����, �������.
//	�����, ����� ������ ��� ������������� ���� �����������.
//	����� ����� ����� ����� ����������� ����������� ���� ���������� ����������
//	������������, ����� ����� ������������.
//	������������ ����� �������������� �� ��������� ���������� ������.
//	��������:
//����������(������)
//	->���������� ����������(���������� ����)
//	->�������������� ������(���������� ����)
//	������(������)
//	->��������� ������(���������� ����)
//	->��������(���������� ����)
//	����� ����� ����� ����� ����� ��������� ������������, ���������� ���������
//	���������� ��������, ������� ���������� ������� � ���������� ������.
//	������� ����� ����������� �������� ������������ � ���������� ��� �����, �����
//	��� ��� ����� ������.
//	���������� ����� ����� �� ��������� � �������� �������, ����������� �
//	���������� �������� �����.
//	������ � ������ ������ �������� � ������������� ����.
//	�������� ������ ������ ��� ��������������(� ���������� �����) :
//	� ������� ����� ���� ������ ���� �����, ����� � ������ ������ ������� ���
//	������ ����� � ���������.
//
//� ���������� ������ � ����� ����� ��������(�� ������ ����������� �����
//������ �����).
//������ � ����� ���������� ������� ������ � ������������� ����.
//��� ������ � �������� ����� ����� ��������� �����������:
//���������� �������������� ��������, ��������, ����������� �������������.
//�������� ���������� �������� ����������� �� ���������� � ����� ��
//����������, �� ���������� ������, �� ���������� �������������.����������
//��������� ���������� ����� ������� � ����.
//���������� ������������� � ����� ����� ��� �������� ���������
//���������, �����, ������� �������, �������� ���������� � ������������ ������,
//������������� � �������������� ��������� � ����� � ��������� �� �����(� � ����)



/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////



// TASK:
// Create a full-featured testing system.
// The system must have 2 modes: Administrator and Test Taker (Guest).

// Description of Guest Mode:
// To enter the system, the guest must register. This is done only once.
// Next time, the guest logs in using their login and password.
// During registration, the guest must enter full name, home address, and phone number.
// It is important that each login is unique.

// After logging in, the guest can:
// - View their previous test results
// - Take a new test

// Tests can be in different knowledge categories, for example:
// Math (category)
//   -> Discrete Math (specific test)
//   -> Calculus (specific test)
// Physics (category)
//   -> Quantum Physics (specific test)
//   -> Mechanics (specific test)

// After the test, the guest sees:
// - Their result
// - How many questions were answered correctly
// - The percentage of correct answers
// - The final grade

// The guest can stop the test and continue it later.

// Grading should use a point system, based on the number of questions in the test.

// Guest logins and passwords must be stored in encrypted form.

// Description of Admin Mode:
// The system can have only one admin.
// The admin sets their login and password during the first launch of the program.
// Later, the admin can change the login and password (only the admin can do this).
// The admin's login and password must also be stored in encrypted form.

// The admin can do the following:
// - Manage users: create, delete, or update users
// - View statistics: see test results by category, by test, or by user
//   The admin can also export the statistics to a file
// - Manage testing: add categories, tests, and questions
//   Set correct and incorrect answers
//   Import and export categories and tests with questions (to and from a file)
