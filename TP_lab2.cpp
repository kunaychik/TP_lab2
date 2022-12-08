#include <iostream>

#include "keeper.h"
#include "file_stream.h"
#include "correct.h"

#define BUFFER 64

void try_del_student(Keeper& keeper)
{
	try {
		keeper.del_student();
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}
}

void try_show_all_students(Keeper& keeper)
{
	try {
		keeper.show_all_students();
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}
}

void try_show_b_students(Keeper& keeper)
{
	try {
		keeper.show_b_students();
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}
}

void keeper_switch(Keeper& keeper, const int& selection, bool& isExit)
{
	switch (selection) {
	case 1:
		keeper.add_student();
		break;
	case 2:
		try_del_student(keeper);
		break;
	case 3:
		try_show_all_students(keeper);
		break;
	case 4:
		try_show_b_students(keeper);
		break;
	default:
		isExit = true;
		break;
	}
}

void student_loop()
{
	Keeper keeper;
	int selection;
	bool isExit = false;

	do {
		std::cout << "1. Add new student\n"
			"2. Delete student\n"
			"3. Show all students\n"
			"4. Show B students\n"
			"5. Exit" << std::endl;

		std::cin >> selection;

		keeper_switch(keeper, selection, isExit);
	} while (!isExit);
}

void do_file_stream()
{
	try {
		char file_name[BUFFER];
		char word[BUFFER];
		std::cout << "File name:";
		std::cin >> file_name;
		std::cout << "Key word:";
		std::cin >> word;
		file(file_name, word);

	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}
}

void loop_switch(const int& selection, bool& isExit)
{
	switch (selection) {
	case 1:
		student_loop();
		break;

	case 2:
		do_file_stream();
		break;

	case 3:
		isExit = true;
		break;

	default:
		std::cout << "Incorrect input" << std::endl;
		break;
	}
}

void loop()
{
	int selection;
	bool isExit = false;
	do {
		std::cout << "1. STUDENT\n"
			"2. File stream\n"
			"3. Exit" << std::endl;
		selection = get_data();

		loop_switch(selection, isExit);
	} while (!isExit);
}

int main()
{
	loop();

	return 0;
}