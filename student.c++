#include "student.h"

#include <iostream>
#include "correct.h"
#include <limits>

Student::Student()
{
    std::cout << "Full name:";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.sync();
	std::cin.getline(full_name, MAX_BUFFER, '\n');
    if(!*full_name)
        throw "Incorrect input";

    std::cout << "Group number:";
    group_number = get_data();
    if(group_number <= 0)
        throw "Incorrect input";

    std::cout << "Count of marks:";
    count_of_marks = get_data();
    if(count_of_marks <= 0)
        throw "Incorrect input";

    marks = new int[count_of_marks];
    for (int i = 0; i < count_of_marks; ++i) {
		std::cout << i + 1 << ".";
        marks[i] = get_data();
        if(marks[i] <= 0 || marks[i] > 5) {
            delete[] marks;
            throw "Incorrect input";
        }
    }
}

Student::Student(const char* full_name, int group_number,
                 int count_of_marks, const int* marks)
{
    for (int i = 0; full_name[i] != '\0'; ++i)
        this->full_name[i] = full_name[i];

    this->group_number = group_number;

    this->count_of_marks = count_of_marks;
    for (int i = 0; i < count_of_marks; ++i)
        this->marks[i] = marks[i];
}

Student::Student(const Student &copy)
{
    for (int i = 0; copy.full_name[i] != '\0'; ++i)
        this->full_name[i] = copy.full_name[i];

    this->group_number = copy.group_number;

    this->count_of_marks = copy.count_of_marks;
    for (int i = 0; i < copy.count_of_marks; ++i)
        this->marks[i] = copy.marks[i];
}

Student::~Student()
{
    delete[] marks;
}

char* Student::get_full_name()
{
    return full_name;
}

int Student::get_group_number()
{
    return group_number;
}

int* Student::get_marks()
{
    return marks;
}

int Student::get_average_score()
{
    int average_score = 0;
    for (int i = 0; i < count_of_marks; ++i) {
        average_score += marks[i];
    }
    return average_score / count_of_marks;
}

void Student::show()
{
    std::cout << "Full name: " << full_name << std::endl;
    std::cout << "Group number: " << group_number << std::endl;
    std::cout << "Marks: " << std::endl;
    for (int i = 0; i < count_of_marks; ++i)
        std::cout << i + 1 << ". " << marks[i] << std::endl;
}

bool Student::is_b_student()
{
    bool is_b_student = true;
    for (int i = 0; i < count_of_marks; ++i) {
        if (marks[i] < 4){
            is_b_student = false;
        }
    }
    return is_b_student;
}
