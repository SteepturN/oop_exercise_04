/*
Бутырев М8О-206Б-20
var 12
связный список + треугольник
Необходимо спроектировать и запрограммировать на языке C++ класс-контейнер первого уровня, содержащий одну фигуру (одна из фигур ЛР3 на выбор). Вариант структуры данных для контейнера выбрать из документа “Варианты структур данных”  (контейнер 1-го уровня) согласно своему номеру из  Варианты ЛР4..
Классы должны удовлетворять следующим правилам:
·   Требования к классу фигуры аналогичны требованиям из лабораторной работы 3
·   Классы фигур должны иметь переопределенный оператор вывода в поток std::ostream (<<). Оператор должен распечатывать параметры фигуры (тип фигуры, длины сторон, радиус и т.д).
·         Классы фигур должны иметь переопределенный оператор ввода фигуры из потока std::istream (>>). Оператор должен вводить основные параметры фигуры (длины сторон, радиус и т.д).
·         Классы фигур должны иметь операторы копирования (=).
·         Классы фигур должны иметь операторы сравнения с такими же фигурами (==).

·         Класс-контейнер должен содержать объекты фигур “по значению” (не по ссылке).
·         Класс-контейнер должен иметь метод по добавлению фигуры в контейнер.
·         Класс-контейнер должен иметь методы по получению фигуры из контейнера (определяется структурой контейнера).
·         Класс-контейнер должен иметь метод по удалению фигуры из контейнера (определяется структурой контейнера).
·         Класс-контейнер должен иметь перегруженный оператор по выводу контейнера в поток std::ostream (<<).
·         Класс-контейнер должен иметь деструктор, удаляющий все элементы контейнера.
·         Классы должны быть расположены в раздельных файлах: отдельно заголовки (.h), отдельно описание методов (.cpp).
Программа должна позволять:
·         Вводить произвольное количество фигур и добавлять их в контейнер.
·         Распечатывать содержимое контейнера.
·         Удалять фигуры из контейнера.
*/
#include <iostream>
#include "Triangle.h"
#include "Read_input.hpp"
#include "List.h"
#include "Iterator.h"
#include "ListEl.h"
#include <cstdio>
#include <set>
#include <string>
int main(){ // можно вынести названия команд как константы
	std::string help_message = "You can use\n\
--put triangle: p [(point) 3 times]\n\
--print container: print\n\
--delete (figure number): d (number of figure)\n\
--exit\n";
	List list;
	char ch(' ');
	char command[20];
	std::set<std::string> valid_commands = {"p", "print", "d", "exit"};
//"
	std::cout << help_message;
	do {
		bool valid_input = false;
		do{
			read_return_t answer = get_command(valid_commands, command);
			switch(answer) {
				case END_OF_FILE: return 0;
				case END_OF_LINE: continue;
				case VALID_INPUT: valid_input = true; break;
				case INVALID_INPUT:
					do ch=getchar(); while((ch != EOF) && (ch != '\n'));
					std::cout << "wrong input" << std::endl;
					if(ch == EOF) return 0;
					else break;
			}
		} while(!valid_input);
		std::string&& command_string = static_cast<std::string>(command);
		if(command_string == "exit") return 0;
		if(command_string == "p") {
			Triangle triangle;
			unsigned int input_figure_number = 0;
			if(get_value<unsigned int>(input_figure_number) != VALID_INPUT ||
			   input_figure_number > list.size) { //if there would be EOF
				std::cout << "wrong input";
			} else {
				bool all_done = false;
				Iterator i = list.begin();
				while(!all_done) {
					if(input_figure_number == 0) {
						all_done = true;
					} else {
						++i;
						--input_figure_number;
					}
				}
				if(get_value<Triangle>(triangle) != VALID_INPUT)
					std::cout << "wrong input";
				else {
					list.put(triangle, i);
					continue;
				}
			}
		} else if(command_string == "print") {
			std::cout << list;
			continue;
		} else { //delete
			unsigned int input_figure_number = 0;
			if(get_value<unsigned int>(input_figure_number) != VALID_INPUT ||
			input_figure_number >= list.size) { //if there would be EOF
				std::cout << "wrong input";
			} else {
				bool all_done = false;
				Iterator i = list.begin();
				while(!all_done) {
					if(input_figure_number == 0) {
						list.remove(i);
						all_done = true;
					} else {
						++i;
						--input_figure_number;
					}
				}
			}
		}
		do ch = getchar(); while((ch != '\n') && (ch != EOF));
		std::cout << std::endl;
		if(ch == EOF) return 0;
	} while(true);
	return 0;
}

