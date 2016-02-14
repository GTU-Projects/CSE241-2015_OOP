/* 
 * File:   main.cpp
 * Author: HASAN MEN - 131044009
 *
 * This file include a general function which find mode index on supported arrays
 *  and some easy class definition for use testing.
 * Created on October 16, 2015, 10:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class DayOfYear {
public:
  void output() const;
  int day;
  int month;
  int year;
};

class Person {
public:
  void output() const;
  char name[20];
  char surname[20];
  int age;

};

// takes array,size of array, size of array items, and function pointer
int return_mode(const void *base, size_t num, size_t size, bool (*equals)(const void *, const void *));

// compare two integer variable
bool equals_int(const void *first, const void *second);

//compare to dayOfYear object
bool equals_day_of(const void *first, const void *second);

// compare two char variable
bool equals_char(const void *first, const void *second);

//compara two double number
bool equals_double(const void *first, const void *second);

// compare two Person object
bool equals_person(const void *first, const void *second);

int main(int argc, char** argv) {

  // testing ingeter arrays
  const int intArrSize = 10;
  int arrInt[intArrSize] = {1, 3, 3, 1, 4, 5, 3, 1, 7, 3};
  cout << endl << "TEST FOR INT ARRAY" << endl;
  for (int i = 0; i < intArrSize; ++i)
    cout << i << ": " << arrInt[i] << endl;
  cout << " -> int_Mode_index = " << return_mode(arrInt, intArrSize, sizeof (int), equals_int) << endl;

  //testing dayofyear array
  const int dayArrSize = 5;
  DayOfYear dayYear[dayArrSize] = {
    {1, 4, 2100},
    {2, 6, 1886},
    {3, 8, 1887},
    {3, 8, 1887},
    {4, 4, 2015}
  };
  cout << endl << "TEST FOR DAYOFYEAR" << endl;
  for (int i = 0; i < dayArrSize; ++i) {
    cout << i << ":";
    dayYear[i].output();
  }
  cout << " -> class_mode_index =" << return_mode(dayYear, dayArrSize, sizeof (DayOfYear), equals_day_of) << endl;

  //testing char array
  const int charArrSize = 5;
  cout << endl << "TEST FOR CHAR ARRAY" << endl;
  char arrChar[charArrSize] = {'h', 'a', 's', 'a', 'n'};
  for (int i = 0; i < charArrSize; ++i)
    cout << i << ": " << arrChar[i] << endl;
  cout << " -> char_mode_index =" << return_mode(arrChar, charArrSize, sizeof (char), equals_char) << endl;

  // testing double array
  const int doubleArrSize = 10;
  cout << endl << "TEST FOR DOUBLE ARRAY" << endl;
  double arrDouble[doubleArrSize] = {1.04, 3.001, 3.00000001, 1.0002, 42, 1.0, 3, 1.0, 7.5, 3};
  for (int i = 0; i < doubleArrSize; ++i)
    cout << i << ": " << arrDouble[i] << endl;
  cout << " -> Double_Mode index = " << return_mode(arrDouble, doubleArrSize, sizeof (double), equals_double) << endl;

  //testing person array
  const int personArrSize = 5;
  cout << endl << "TEST FOR PERSON ARRAY" << endl;
  Person arrPerson[personArrSize] = {
    {"hasan", "men", 20},
    {"mercan", "men", 20},
    {"hasan", "MEN", 20},
    {"mercan", "men", 20},
    {"hasan", "MEN", 21}
  };
  for (int i = 0; i < personArrSize; ++i) {
    cout << i << " :";
    arrPerson[i].output();
  }
  cout << " ->Person index = " << return_mode(arrPerson, 5, sizeof (Person), equals_person) << endl;

  return 0;
}

int return_mode(const void *base, size_t num, size_t size, bool (*equals)(const void *, const void *)) {

  unsigned char *end = (unsigned char *) base + (num * size); // end of base array
  unsigned char *current = NULL; // cursor
  int i = 0; // store index of mode 
  int max = 0;
  int mod_id = 0;

  int mode_num;
  for (unsigned char *start = (unsigned char *) base; start < end; ++i, start += size) {
    mode_num = 0; // clear old modes -- and increase i in the loop -||||
    for (current = start; current < end; current += size) {
      if (equals(start, current))
        ++mode_num; // if equal, increase mode_num
    }
    if (max < mode_num) {
      max = mode_num;
      mod_id = i;
    }
  }

  return mod_id;
}

// if difference is zero, they are equal and return true

bool equals_int(const void *first, const void *second) {
  return (*(int *) first - *(int *) second) == 0 ? true : false;
}

// Control member of basis dayofyear objects and return result 

bool equals_day_of(const void *first, const void *second) {
  return ((DayOfYear *) first)->day == ((DayOfYear *) second)->day &&
          ((DayOfYear *) first)->month == ((DayOfYear *) second)->month
          ? true : false;
}

// compare asci number of chars and returns result

bool equals_char(const void *first, const void *second) {
  return *(char *) first == *(char *) second ? true : false;
}

// if difference is zero, they are equal and return true

bool equals_double(const void *first, const void *second) {
  return *(double *) first == *(double *) second ? true : false;
}

// control two object and their members and return result

bool equals_person(const void *first, const void *second) {

  Person *a = (Person *) first;
  Person *b = (Person *) second;

  return (a->age == b->age && !strcmp(a->name, b->name) && !strcmp(a->surname, b->surname))
          ? true : false;

}

// test for member variables

void DayOfYear::output() const {
  cout << " " << day << " " << month << " " << year << " - " << endl;
}

void Person::output() const {
  cout << name << " " << surname << " " << age << " " << endl;
}

// END OF HW02 


