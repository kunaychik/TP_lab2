#ifndef __KEEPER_H__
#define __KEEPER_H__

#include "student.h"

class Keeper
        {
private:
    Student** students;
    unsigned int count_of_students;

public:
    Keeper();
    ~Keeper();

    void show_b_students();
    void show_all_students();

    void add_student();
    void del_student();

private:
    Student* create_new_student();
    void append_student_to_students(Student* new_student);

    void init(Student* student);
    void sort_and_add(Student* student);

    int select_student();
    void delete_student_from_list(int student_number);
};


#endif //__KEEPER_H__
