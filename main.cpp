#include "cassini.h"
#include "func.h"


void menu();

int main()
{
	int mode;
	double x1,y1,x2,y2,param;
	double arg;
	std::cout << "Введите x-координату первого фокуса: " << std::endl;
	get(x1);
	std::cout << "Введите y-координату первого фокуса: " << std::endl;
	get(y1);
	std::cout << "Введите x-координату второго фокуса: " << std::endl;
	get(x2);
	std::cout << "Введите y-координату второго фокуса: " << std::endl;
	get(y2);
	std::cout << "Введите Параметр Кассини: " << std::endl;
	get(param);
	cass::Cassini line(cass::Point(x1,y1),cass::Point(x2,y2),param);


	while(mode != 777)
	{

		std::cout << std::endl << std::endl;
		std::cout << "Выберите режим работы:" << std::endl << "[1] - Вывод" << std::endl << "[2] - Расстояние до центра в полярной системе координат в зависимости от угла" << std::endl << "[3] - Тип формы линии Кассини" << std::endl << "[4] - Радиус кривизны в зависимости от угла полярного радиуса" << std::endl << "[5] - Текстовое представление уравнения" << std::endl << "[6] - Выход" << std::endl ;
		std::cout << ":";
		get(mode);


		if (mode == 1) //геттеры
		{
			std::cout << "Первый фокус: (" << line.get_F1().x << "," << line.get_F1().y << ")" << std::endl; 
			std::cout << "Второй фокус: (" << line.get_F2().x << "," << line.get_F2().y << ")" << std::endl; 
			std::cout << "Параметр Кассини: " << line.get_a() << std::endl; 
			std::cout << "Центр: (" << line.get_center().x << "," << line.get_center().y << ")" << std::endl;
			std::cout << "Половина фокусного расстояния: " << line.get_c() << std::endl; 
		}


		if (mode == 2) //расстояние по углу
		{
			
			std::cout << "Введите угол: " << std::endl;
			std::cin >> arg;
			std::cout << line.coordinate(arg) << std::endl;
		}


		if (mode == 3) //тип кривой
		{
			std::cout << "Форма:" << std::endl;
			std::cout << line.type() << std::endl;
		}


		if (mode == 4) //радиус кривизны
		{
			
			std::cout << "Введите полярный радиус: " << std::endl;
			get(arg);
			std::cout << line.curvature(arg) << std::endl;
		}


		if (mode == 5) //текст
		{
			char* res = (char*)malloc(1024);
			std::cout << "Уравнение:" << std::endl;
			std::cout << line.cartesian(res);
			free(res);
		}


		if (mode == 6) //выход
		{
			mode = 777;
		}

	}

}