#include <iostream>

//using namespace std;

struct point
{
	double m_x;
	double m_y;
	point(double x, double y)
	{
		this->m_x = x;
		//y = y;
		this->m_y = y;
	}
};

void print_point(const point& point_object)
{
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}

int main()
{
	//int i;
	for (int i = 0; i < 5; i++)//; 
	{
		point my_point(static_cast<double>(i), 2 * (static_cast<double>(i)));
		print_point(my_point);
	}
	return 0;
}

//void print_point(const point& point_object) 
//{
//	std::cout << "x:" << point_object.m_x << ", y: "
//		<< point_object.m_y << std::endl;
//}
