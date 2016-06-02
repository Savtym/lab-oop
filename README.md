# lab-oop
lab oop c++

tasks:
#1
Варіант 1.
Сконструювати клас MultiString для визначення вектора рядків з наступним інтерфейсом:
/*!
* file: MultiString.h
* MultiString class definition
* written: 01/05/2012
* Copyright (c) 2012 by Yu.Zorin
*/
#pragma once
#include <string.h>
#include <stdio.h>
class MultiString{
public:
//constructors destructor
MultiString();
MultiString(int );
~MultiString();
//methods
MultiString & operator=(const MultiString &ms){};
char * operator[] (int nindex) const;
MultiString & operator+=(const MultiString &);
void MergeMultiStringexclusive(const MultiString &);
int Find(const char *pszsub ) const;
int Getlength( ) const;
bool Isempty()const{ return str_nmb == 0;};
void Empty();
void Setat( int nindex, const char* str );
void Printstr(int nindex) const;
private:
//forbidden copy constructor
MultiString ( const MultiString & ms){};
//attributes
char **buf;//pointer to vector
int str_nmb;//strings number
};
Mетоды.
MultiString ( ) – створює порожній вектор.
MultiString ( const MultiString & ) – конструктор копирoвания.
MultiString(MultiStrings(int n ) – створює вектор з n порожніх рядків.
char * operator[] (int nindex) cons – повертає покажчик на КОПІЮ рядка з
індексом indx.
MultiString & operator+=(const MultiString &src) – виконує порядкову
конкатенацію вектора, з яким викликаний цей оператор і вектора src.
MultiString MergeMultiStringexcl(const MultiString &src) - виконує злиття
двох векторів з виключенням повторюваних елементів і повертає результуючий
об'єкт.
int Find( const char *pszsub ) const – повертає індекс pszsub у векторі.
int Getlength( ) const – возврщает довжину вектора.
bool Isempty()const – повертає true, якщо вектор порожній.
void Empty() – очищає вектор.
void SetAt( int nindex, const char* str ) – заміщає у векторі рядок з
індексом nindex на рядок str.
void PrintStr(int nindex) const – виводить на консоль рядок з індексом
nindex.

#2
Написати додаток Database, яке зберігає відомості про співробітників компанії. У додатку використовується наступна ієрархія поліморфних класів.
Базовим є абстрактний клас //An abstract class class Person{ public: Person(){}; Person(string _f_name, string _l_name, int _age) : age(_age), f_name(_f_name), l_name(_l_name){ } virtual void Display(bool) = 0; protected: string f_name;//first name string l_name;//last name int age; };
Відомості про рядових співробітників представлені класом class Employee : public Person{ public: Employee(){}; Employee(string _f_name, string _l_name, int _age, int _id) : Person(_f_name, _l_name, _age), id(_id){}; Employee(const Employee &e); Employee& operator=(const Employee &e); void SetSalary(int s); void SetDepartment(string dept); void SetId(int n); int GetId(); string GetDepartment(); virtual void Display(); //Add here whatever you need
protected: string department; int salary; int id; };
Відомості про менеджерів представлені класом class Manager : public Employee { public: Manager(){}; Manager(string _f_name, string _l_name, int _age, int _id) : Employee(_f_name, _l_name, _age, _id){}; Manager(const Manager &m; Manager& operator=(const Manager &m); virtual void Display(bool); //add an employee to the subordinates list Person* AddSubordinate(Person *p); void DisplaySubordinates(); //Add here whatever you need
private: list<Person *> subordinates;//список подчиненных }; Тобто, крім відомостей, спільних із класом Employee, клас Manager містить список його підлеглих (усі вони працюють у тому ж відділі, що й менеджер).
База даних представлена класом class Database{
public: Database(){}; ~Database(){};//no need in destructor //creates “flat” database bool LoadFromFile(const char *file); //arranges "flat" database after loading from the file void ArrangeSubordinates();
//hire a new employee Person* HireEmployee(Person *p); void DisplayDepartmentEmployees(string _department);
//fire the employee bool FireEmployee(int id); void DisplayAll(); //Add here whatever you need
private: vector<Person*> employees; };

#3
Варіант 1.
Двійкове дерево (CBinTree) містить поточну інформацію про книги в бібліотеці. Дерево відсортовано по інвентарних номерах.
Відомості про книги (CTreeNode) містять:
інвентарний номер – m_Bookid;
прізвище автора – m_Author;
назва – m_Title;
рік видання – m_Year;
кількість екземплярів даної книги в бібліотеці – m_Quantity.
Програма повинна забезпечувати:
початкове формування даних про всі книги в бібліотеці у вигляді двійкового дерева; вихідні дані читаються з csv-файлу, кожний рядок якого містить запис виду
m_Bookid; m_Author; m_Title; m_Year; m_Quantity
додавання даних про книги, що знову надходять у бібліотеку;
видалення даних про книги, що списуються ( по інвентарному номеру);
по імені автора видаються відомості про наявність усіх його книг у бібліотеці.
по найменуванню видаються відомості про наявність книги в бібліотеці.
