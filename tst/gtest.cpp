#include <gtest/gtest.h>
#include "../cassini.h"


TEST(Cassini_Constructor, get)
{
	cass::Cassini t(cass::Point(2,6),cass::Point(14,88),1337);
	ASSERT_EQ(2, t.get_F1().x);
	ASSERT_EQ(6, t.get_F1().y);
	ASSERT_EQ(14, t.get_F2().x);
	ASSERT_EQ(88, t.get_F2().y);
	ASSERT_EQ(1337, t.get_a());
}


TEST(Cassini_Constructor, set)
{
	cass::Cassini t(cass::Point(0,0),cass::Point(1,1),1);
	t.set_F1(cass::Point(2,6));
	t.set_F2(cass::Point(14,88));
	t.set_a(1337);

	ASSERT_EQ(2, t.get_F1().x);
	ASSERT_EQ(6, t.get_F1().y);
	ASSERT_EQ(14, t.get_F2().x);
	ASSERT_EQ(88, t.get_F2().y);
	ASSERT_EQ(1337, t.get_a());
}


TEST(Cassini_Methods, curvature)
{
	cass::Cassini t(cass::Point(1,4),cass::Point(98,54),30);
	ASSERT_FLOAT_EQ(8.05786, t.curvature(45));

}


TEST(Cassini_Methods, coordinate)
{
	cass::Cassini t(cass::Point(1,4),cass::Point(98,54),30);
	ASSERT_FLOAT_EQ(732.847, t.coordinate(60));

}
 

TEST(Cassini_Methods, type1)
{
	cass::Cassini t(cass::Point(2,6),cass::Point(14,88),1337);
	ASSERT_STREQ("Овал.", t.type());
}


TEST(Cassini_Methods, type2)
{
	cass::Cassini t(cass::Point(1,3),cass::Point(98,54),3);
	ASSERT_STREQ("Два отдельных овала.", t.type());
}


TEST(Cassini_Methods, type3)
{
	cass::Cassini t(cass::Point(41,33),cass::Point(98,54),0);
	ASSERT_STREQ("Кривая вырождается в две точки.", t.type());
}


TEST(Cassini_Methods, type4)
{
	cass::Cassini t(cass::Point(30,0),cass::Point(-30,0),30);
	ASSERT_STREQ("Лемниската Бернулли.", t.type());
}


TEST(Cassini_Methods, type5)
{
	cass::Cassini t(cass::Point(30,0),cass::Point(-30,0),34.8);
	ASSERT_STREQ("C перегибами.", t.type());
}


TEST(Cassini_Methods, type6)
{
	cass::Cassini t(cass::Point(0,0),cass::Point(0,0),5);
	ASSERT_STREQ("Стремление к окружности.", t.type());
}


TEST(Cassini_Methods, cartesian)
{
	cass::Cassini t(cass::Point(30,0),cass::Point(-30,0),30);
	char* res = (char*)malloc(1024);
	ASSERT_STREQ("(x^2 + y^2)^2 - 1800.000000*(x^2 - y^2) = 0.000000", t.cartesian(res));
	free(res);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
