#include "file_stream.h"

#include <iostream>
#include <fstream>
#include <cstring>

#define  MAX_LEN 512
#define MAX_SUB_WORD_COUNT 5

bool is_end_point(unsigned char ch)
{
	unsigned char end_point[] = {'.', '!', '?'};
	bool isEnd = false;

	for (unsigned char& i : end_point) {
		if(i == ch)
			isEnd = true;
	}

	return isEnd;
}

char* is_word_in_sentence(char* sentence, char** word)
{
	char* sub_str = nullptr;
	for (int i = 0; i < MAX_SUB_WORD_COUNT; ++i) {
		sub_str = strstr(sentence, word[i]);
		if(sub_str != NULL) {
			break;
		}
	}

	return sub_str;
}

void create_sub_words(char* sub_word[], const char* word)
{
	unsigned word_len = strlen(word);
	sub_word[0] = new char[word_len + 3];
	sub_word[1] = new char[word_len + 2];
	sub_word[2] = new char[word_len + 2];
	sub_word[3] = new char[word_len + 2];
	sub_word[4] = new char[word_len + 3];
	snprintf(sub_word[0], word_len + 3, " %s ", word);
	snprintf(sub_word[1], word_len + 2, "%s.", word);
	snprintf(sub_word[2], word_len + 2, "%s!", word);
	snprintf(sub_word[3], word_len + 2, "%s?", word);
	snprintf(sub_word[4], word_len + 3, ",%s ", word);\
}

void file(const char* file_name, const char* word)
{
	char* sub_word[MAX_SUB_WORD_COUNT];

	create_sub_words(sub_word, word);

	std::ifstream my_file;
	my_file.open(file_name);

	if (!my_file.is_open())
		throw "File doesn't exist";

	int count = 0;

	char* sub_string = NULL;

	char buffer[MAX_LEN] = {0};

	do {
		buffer[count++] = my_file.get();

		if(is_end_point(buffer[count - 1])) {

			buffer[count++] = '\0';

			sub_string = is_word_in_sentence(buffer, sub_word);
			if(sub_string != NULL)
				std::cout << buffer << std::endl;

			sub_string = NULL;
			count = 0;
		}
	} while (!my_file.eof());


	for (auto& i : sub_word) {
		delete[] i;
	}
	std::cout << "\n";
}