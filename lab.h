#pragma once

//languages:
//RUS
//ENG


//ЗАДАНИЕ:
//Реализовать полнофункциональную систему тестирования.
//В системе допжны быть 2 режима: администратор и тестируемый.
//Описание режима работа для Тестируемого(в дальнейшем гость) :
//	Для входа в систему гость должен зарегистрироваться данная процедура
//	выполняется один раз, при дальнейших входах в систему доступ идет по логину и
//	паролю.
//	При регистрации нужно указывать Ф.И.О., домашний адрес, телефон.
//	Важно, чтобы логины для пользователей были уникальными.
//	Поспе входа гость имеет возможность просмотреть свои предыдущие результаты
//	тестирования, сдать новое тестирование.
//	Тестирование может осуществляться по различным категориям знаний.
//	Например:
//Математика(раздел)
//	->Дискретная математика(конкретный тест)
//	->Математический Анализ(конкретный тест)
//	Физика(раздеп)
//	->Квантовая физика(конкретный тест)
//	->Механика(конкретный тест)
//	Поспе сдачи теста гость видит результат тестирования, количество правильно
//	отвеченных вопросов, процент правильных ответов и полученную оценку.
//	Студент имеет возможность прервать тестирование и продолжить его тогда, когда
//	ему это будет удобно.
//	Оценивание нужно вести на основании Б балльной системы, привязанной к
//	количеству вопросов теста.
//	Пароли и логины гостей хранятся в зашифрованном виде.
//	Описание режима работы для Администратора(в дальнейшем админ) :
//	В системе может быть только один админ, логин и пароль админа задаётся при
//	первом входе в программу.
//
//В дапьнейшем паропь и логин можно изменить(но данную возможность имеет
//только админ).
//Паропь и логин необходимо хранить только в зашифрованном виде.
//При работе с системой админ имеет спедующие возможности:
//Управление пользователями— создание, удапение, модификация пользоватепей.
//Просмотр статистики— просмотр результатов те стирования в общем по
//категориям, по конкретным тестам, по конкретным пользователям.Резупьтаты
//просмотра статистики можно вывести в файл.
//Управление тестированием — админ имеет воз можность добавпять
//категории, тесты, вопросы ктестам, задавать правильные и неправильные ответы,
//импортировать и экспортировать категории и тесты с вопросами из файла(и в файл)



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
