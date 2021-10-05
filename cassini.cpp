#include "cassini.h"


namespace cass
{
	Cassini::Cassini(Point first, Point second, double arg): F1(first), F2(second), c((std::sqrt(pow(second.x-first.x,2)+pow(second.y-first.y,2)))/2), a(arg), center(Point((first.x+second.x)/2,(first.y+second.y)/2)) {};

	void Cassini::set_F1(Point dot)
	{
		F1 = dot;
	}


	void Cassini::set_F2(Point dot)
	{
		F2 = dot;
	}


	void Cassini::set_a(int dist)
	{
		if (dist < 0) throw std::runtime_error("invalid distance");
		a = dist;
	}


	const char* Cassini::type()
	{
		if (a == 0 && c != 0) return "Кривая вырождается в две точки.";
		if (c == 0 && a != 0) return "Стремление к окружности.";
		if (0 < a && a < c) return "Два отдельных овала.";
		if (a == c) return "Лемниската Бернулли.";
		if (c < a && a < c*std::sqrt(2)) return "C перегибами.";
		if (a >= c*std::sqrt(2)) return "Овал.";
		return "Ошибка";
	}

	
	double Cassini::coordinate(double fi)
	{
		double t, r;
		double D = 4*std::pow(c,2)*std::pow(std::cos((2*fi)),2) - 4*(std::pow(a,4)-std::pow(c,4));
		if (D == 0) t = (-2*c*std::cos(2*fi))/(2*a);
		if (D > 0)
		{
			t = (-2*c*std::cos(2*fi) + D)/(2*a);
			if (t <= 0) t = (-2*c*std::cos(2*fi) - D)/(2*a);
			r = std::sqrt(t);
		}
		return r;
	}


	double Cassini::curvature(double ro)
	{
		if (ro < 0 ) throw std::runtime_error("invalid argument");
		double R;
		R = (2*std::pow(a,2)*std::pow(ro,3))/(std::pow(c,4) - std::pow(a,4) + 3*std::pow(ro,4));
		return R;
	}


	const char* Cassini::cartesian(char* res)
	{
		sprintf(res, "(x^2 + y^2)^2 - %f*(x^2 - y^2) = %f", 2*std::pow(get_c(),2), std::pow(get_a(),4) - std::pow(get_c(),4));
		return res;
	}
}