#ifndef __STUDENT_H__
#define __STUDENT_H__

#define MAX_BUFFER 64

class Student
{
private:
    char full_name[MAX_BUFFER];
    int group_number;

    int count_of_marks;
    int* marks;

public:
    Student();
    Student(const char* full_name, int group_number,
            int count_of_marks, const int* marks);
    Student(const Student& copy);

    ~Student();

    char* get_full_name();
    int get_group_number();
    int* get_marks();
    int get_average_score();

    bool is_b_student();

    void show();
};


#endif //__STUDENT_H__
