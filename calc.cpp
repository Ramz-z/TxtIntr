#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
int main(int argc, char **argv) {
    if(argc == 1) { // если запускаем без аргументов, выводим справку
        std::cout << "Статистический калькулятор" << '\n' << "Поддерживает 2 функции: нахожд. медианы и ср. арифм. ряда чисел" << '\n' << "Количество аргументов: от 6 до 8" << std::endl;
        std::cout << "Для опции -o два знач median(медиана) и arithm(средн. арифм)" << '\n' << "Пример:" << '\n' << "./'исх. файл' -o m 323 23 5 735 24 15 74" << '\n'<< "Медиана введенных числел = 24" << '\n';
        return 0;
    }
    std::vector<int> a; // тут храним числа
    std::string op; // а тут оператор
    int opt; // каждая следующая опция попадает сюда
    double sum=0;
    while((opt = getopt(argc, argv, "o:")) != -1) { // вызываем getopt пока она не вернет -1
        switch(opt) {
            case 'o': // в op сохраняем оператор
            //optarg = type (std::string)
                op = std::string(optarg);
                if(op!="median" && op!="arithm"){ //обработка неверного ввода
    				std::cout << "Введено неправильное значение опции"<< "\n";
    				return 0;
    			}else{
                	for(int i=3; i<argc; i++){ //заполнение вектора числами
        				a.push_back(atoi(argv[i]));
        			}
        		}
        		if (op=="median"){ // медиана
        			std::sort(a.begin(), a.end());
        			if(a.size()%2!=0){
        				std::cout << "Медиана введенных числел = " << a[(a.size()-1)/2.0] << "\n";
        			}else{
            			std::cout << "Медиана введенных числел = "<< (a[a.size()/2]+a[(a.size())/2-1])/2.0 << "\n";
        			}
        		}
        		if(op=="arithm"){ // среднее арифметическое
        			for(uint i=0; i<a.size(); i++){
        			sum+=a[i];
        			}
            		std::cout << "Среднее арифметическое введенных числел = "<< sum/a.size() << "\n";
        		}
                 break;
        }
    }
}
