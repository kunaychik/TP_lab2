#include "keeper.h"

#include <iostream>
#include "correct.h"
#include <cstring>

Keeper::Keeper()
{
    count_of_students = 0;
    students = nullptr;
}

Keeper::~Keeper()
{
    for (int i = 0; i < count_of_students; ++i) {
        delete students[i];
    }

    delete[] students;
}

void Keeper::show_b_students()
{
    if (count_of_students == 0)
        throw "There are no student";

    bool isSame = false;
    for (int i = 0, j = 0; i < count_of_students; ++i) {
        if (students[i]->is_b_student()){
            std::cout << j++ + 1 << "." << std::endl;
            students[i]->show();
            isSame = true;
        }
    }
    if (!isSame)
        std::cout << "There are no same destination" << std::endl;

}

void Keeper::show_all_students()
{
    if (count_of_students == 0)
        throw "There are no students";

    for (int i = 0; i < count_of_students; ++i) {
        std::cout << i + 1 << ":" << std::endl;
        students[i]->show();
    }
}

void Keeper::add_student()
{
    Student* new_student = create_new_student();

    append_student_to_students(new_student);
}


void Keeper::del_student()
{
    if (count_of_students == 0)
        throw "There are no student";

    int selection = select_student();

    delete_student_from_list(selection);
}

void Keeper::delete_student_from_list(int student_number)
{
    auto** new_students = new Student*[count_of_students - 1];
    for (int i = 0, j = 0; i < count_of_students; ++i) {
        if(i == (student_number-1))
            continue;

        new_students[j++] = students[i];
    }
    --count_of_students;

    delete[] students;
    students = new_students;
}

int Keeper::select_student()
{
    int selection;
    show_all_students();
    std::cout << "Select student" << std::endl;
    selection = get_data();
    if(selection <= 0 || selection > count_of_students)
        throw "There is no such student";

    return selection;
}

Student* Keeper::create_new_student()
{
    auto* student = new Student();

    return student;
}

void Keeper::append_student_to_students(Student* new_student)
{
    if (count_of_students == 0)
        init(new_student);
    else
        sort_and_add(new_student);
}

void Keeper::sort_and_add(Student* student)
{
    auto** new_flights = new Student * [count_of_students + 1];
    bool isInsert = false;
    for (int i = 0, j = 0; i < count_of_students;) {
        if (students[i]->get_average_score() > student->get_average_score()
        && !isInsert){
            new_flights[j++] = student;
            isInsert = true;
        }
        new_flights[j++] = students[i++];
    }

    ++count_of_students;
    if(!isInsert)
        new_flights[count_of_students - 1] = student;

    delete[] students;
    students = new_flights;
}

void Keeper::init(Student* student)
{
    students = new Student*[1];
    students[0] = student;
    ++count_of_students;
}