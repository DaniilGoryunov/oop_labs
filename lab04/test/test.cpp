#include <gtest/gtest.h>
#include "src/coord.hpp"
#include "src/hexagon.hpp"
#include "src/pentagon.hpp"
#include "src/romb.hpp"
#include "src/array.hpp"
#include "src/figure.hpp"
#include <cmath>

/*------------------------HEX_GET_CENTER------------------------------------------------------------------*/

TEST(hex_get_center, test01) {
    Hexagon<int> h;
    ASSERT_TRUE(h.get_center() == Coord<int>(0, 0));
}

TEST(hex_get_center, test02) {
    Hexagon<double> h = {Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5), Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1),
    Coord<double>(0.8660254037844386, -0.5), Coord<double>(0.8660254037844386, 0.5)};
    ASSERT_TRUE(h.get_center() == Coord<double>(0, 0));
}

TEST(hex_get_center, test03) {
    Hexagon<double> h = {Coord<double>(0.8660254037844386, 0.5), Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5), Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1),
    Coord<double>(0.8660254037844386, -0.5)};
    ASSERT_TRUE(h.get_center() == Coord<double>(0, 0));
}

TEST(hex_get_center, test04) {
    Hexagon<double> h = {Coord<double>(123.0, 432.0), Coord<double>(-312.62297443487745, 322.52112466548596), 
    Coord<double>(-435.62297443487745, -109.47887533451406), Coord<double>(-123.0, -432.0), 
    Coord<double>(312.62297443487745, -322.52112466548596), Coord<double>(435.62297443487745, 109.47887533451406)};
    ASSERT_TRUE(h.get_center() == Coord<double>(0, 0));
}

TEST(hex_get_center, test05) {
    Hexagon<double> h = {Coord<double>(-0.848076211353316, 10.12916512459885), Coord<double>(-7.348076211353316, 7.129165124598851), Coord<double>(-8, 0),
    Coord<double>(-2.151923788646684, -4.129165124598851), Coord<double>(4.348076211353316, -1.1291651245988508), Coord<double>(5, 6)};
    ASSERT_TRUE(h.get_center() == Coord<double>(-1.5, 3));
}

/*------------------------------HEX_GET_AREA-----------------------------------------------------------------*/


TEST(hex_get_area, test01) {
    Hexagon<int> h;
    ASSERT_TRUE(is_eq((double) h, 0));
}

TEST(hex_get_area, test02) {
    Hexagon<double> h = {Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5), Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1),
    Coord<double>(0.8660254037844386, -0.5), Coord<double>(0.8660254037844386, 0.5)};
    ASSERT_TRUE(is_eq((double) h, 2.5980762113533156));
}

TEST(hex_get_area, test03) {
    Hexagon<double> h = {Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1), Coord<double>(0.8660254037844386, -0.5), 
    Coord<double>(0.8660254037844386, 0.5), Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5)};
    ASSERT_TRUE(is_eq((double) h, 2.5980762113533156));
}

TEST(hex_get_area, test04) {
    Hexagon<double> h = {Coord<double>(-243.5, -198.665), Coord<double>(-15.233731546200573, -290.2637746161375), Coord<double>(178.22626845379943, -138.3787746161375),
    Coord<double>(143.42000000000002, 105.10499999999999), Coord<double>(-84.84626845379944, 196.70377461613748), Coord<double>(-278.3062684537995, 44.81877461613749)};
    ASSERT_TRUE(is_eq((double) h, 157172.76336402984));
}

TEST(hex_get_area, test05) {
    Hexagon<double> h = {
        Coord<double>(7.0, 45.0), Coord<double>(-70.07883832488648, 112.50446416709055), Coord<double>(-167.07883832488648, 79.50446416709055), 
        Coord<double>(-187.0, -21.0), Coord<double>(-109.92116167511352, -88.50446416709055), 
        Coord<double>(-12.921161675113527, -55.504464167090546)
    };
    ASSERT_TRUE(is_eq((double) h, 27274.604066787113));
}

/*-----------------------------------HEX_EQ------------------------------------------------------------------------*/

TEST(hex_eq, test01) {
    Hexagon<double> h1 = {Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5), Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1),
    Coord<double>(0.8660254037844386, -0.5), Coord<double>(0.8660254037844386, 0.5)};
    Hexagon<double> h2 = {Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1), Coord<double>(0.8660254037844386, -0.5), 
    Coord<double>(0.8660254037844386, 0.5), Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5)};
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_eq, test02) {
    Hexagon<float> h1, h2;
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_eq, test03) {
    Hexagon<double> h1 = {Coord<double>(5, 0), Coord<double>(3, 3.4641016151377544), Coord<double>(-1, 3.4641016151377544), Coord<double>(-3, 0), 
    Coord<double>(-1, -3.4641016151377544), Coord<double>(3, -3.4641016151377544)};
    Hexagon<double> h2 = {Coord<double>(5, 2), Coord<double>(3, 5.464101615137754), Coord<double>(-1, 5.464101615137754), Coord<double>(-3, 2),
    Coord<double>(-1, -1.4641016151377544), Coord<double>(3, -1.4641016151377544)};
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_eq, test04) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(0, 2), Coord<double>(-1.7320508075688772, 1), Coord<double>(-1.7320508075688772, -1), Coord<double>(0, -2),
    Coord<double>(1.7320508075688772, -1), Coord<double>(1.7320508075688772, 1)};
    ASSERT_TRUE(h1 == h2);
}

/*------------------------------------HEX_NOT_EQ---------------------------------------------------------*/

TEST(hex_not_eq, test01) {
    Hexagon<double> h1 = {Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5), Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1),
    Coord<double>(0.8660254037844386, -0.5), Coord<double>(0.8660254037844386, 0.5)};
    Hexagon<double> h2 = {Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1), Coord<double>(0.8660254037844386, -0.5), 
    Coord<double>(0.8660254037844386, 0.5), Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5)};
    ASSERT_FALSE(h1 != h2);
}

TEST(hex_not_eq, test02) {
    Hexagon<int> h1, h2;
    ASSERT_FALSE(h1 != h2);
}

TEST(hex_not_eq, test03) {
    Hexagon<double> h1 = {Coord<double>(5, 0), Coord<double>(3, 3.4641016151377544), Coord<double>(-1, 3.4641016151377544), Coord<double>(-3, 0), 
    Coord<double>(-1, -3.4641016151377544), Coord<double>(3, -3.4641016151377544)};
    Hexagon<double> h2 = {Coord<double>(5, 2), Coord<double>(3, 5.464101615137754), Coord<double>(-1, 5.464101615137754), Coord<double>(-3, 2),
    Coord<double>(-1, -1.4641016151377544), Coord<double>(3, -1.4641016151377544)};
    ASSERT_FALSE(h1 != h2);
}

TEST(hex_not_eq, test04) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {
        Coord<double>(1.0, 7.0), Coord<double>(0.6339745962155614, 5.633974596215562), Coord<double>(1.6339745962155614, 4.633974596215562), 
        Coord<double>(3.0, 5.0), Coord<double>(3.3660254037844384, 6.366025403784438), Coord<double>(2.3660254037844384, 7.366025403784438)
    };
    ASSERT_TRUE(h1 != h2);
}

/*--------------------------------------------HEX_GREATER----------------------------------------------------------*/

TEST(hex_greater, test01) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(5, 0), Coord<double>(2.5, 4.330127018922193), Coord<double>(-2.5, 4.330127018922193), Coord<double>(-5, 0),
    Coord<double>(-2.5, -4.330127018922193), Coord<double>(2.5, -4.330127018922193)};
    ASSERT_TRUE(h2 > h1);
}

TEST(hex_greater, test02) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(100, 25), Coord<double>(35.17949192431123, 97.27241335952166), Coord<double>(-59.82050807568877, 77.27241335952166),
    Coord<double>(-90, -15), Coord<double>(-25.17949192431123, -87.27241335952166), Coord<double>(69.82050807568876, -67.27241335952166)};
    ASSERT_TRUE(h2 > h1);
}

TEST(hex_greater, test03) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(0, 2), Coord<double>(-1.7320508075688772, 1), Coord<double>(-1.7320508075688772, -1), Coord<double>(0, -2),
    Coord<double>(1.7320508075688772, -1), Coord<double>(1.7320508075688772, 1)};
    ASSERT_FALSE(h2 > h1);
}

/*---------------------------------------HEX_GREATER_OR_NOT------------------------------------------------------------*/

TEST(hex_greater_or_eq, test01) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(5, 0), Coord<double>(2.5, 4.330127018922193), Coord<double>(-2.5, 4.330127018922193), Coord<double>(-5, 0),
    Coord<double>(-2.5, -4.330127018922193), Coord<double>(2.5, -4.330127018922193)};
    ASSERT_TRUE(h2 >= h1);
}

TEST(hex_greater_or_eq, test02) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(100, 25), Coord<double>(35.17949192431123, 97.27241335952166), Coord<double>(-59.82050807568877, 77.27241335952166),
    Coord<double>(-90, -15), Coord<double>(-25.17949192431123, -87.27241335952166), Coord<double>(69.82050807568876, -67.27241335952166)};
    ASSERT_TRUE(h2 >= h1);
}

TEST(hex_greater_or_eq, test03) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(0, 2), Coord<double>(-1.7320508075688772, 1), Coord<double>(-1.7320508075688772, -1), Coord<double>(0, -2),
    Coord<double>(1.7320508075688772, -1), Coord<double>(1.7320508075688772, 1)};
    ASSERT_TRUE(h2 >= h1);
}

/*------------------------------------------HEX_LESS----------------------------------------------------------*/

TEST(hex_less, test01) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(5, 0), Coord<double>(2.5, 4.330127018922193), Coord<double>(-2.5, 4.330127018922193), Coord<double>(-5, 0),
    Coord<double>(-2.5, -4.330127018922193), Coord<double>(2.5, -4.330127018922193)};
    ASSERT_FALSE(h2 < h1);
}

TEST(hex_less, test02) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(100, 25), Coord<double>(35.17949192431123, 97.27241335952166), Coord<double>(-59.82050807568877, 77.27241335952166),
    Coord<double>(-90, -15), Coord<double>(-25.17949192431123, -87.27241335952166), Coord<double>(69.82050807568876, -67.27241335952166)};
    ASSERT_FALSE(h2 < h1);
}

TEST(hex_less, test03) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(0, 2), Coord<double>(-1.7320508075688772, 1), Coord<double>(-1.7320508075688772, -1), Coord<double>(0, -2),
    Coord<double>(1.7320508075688772, -1), Coord<double>(1.7320508075688772, 1)};
    ASSERT_FALSE(h2 < h1);
}

/*-----------------------------------------HEX_LESS_OR_EQ----------------------------------------------------*/

TEST(hex_less_or_eq, test01) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(5, 0), Coord<double>(2.5, 4.330127018922193), Coord<double>(-2.5, 4.330127018922193), Coord<double>(-5, 0),
    Coord<double>(-2.5, -4.330127018922193), Coord<double>(2.5, -4.330127018922193)};
    ASSERT_FALSE(h2 <= h1);
}

TEST(hex_less_or_eq, test02) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(100, 25), Coord<double>(35.17949192431123, 97.27241335952166), Coord<double>(-59.82050807568877, 77.27241335952166),
    Coord<double>(-90, -15), Coord<double>(-25.17949192431123, -87.27241335952166), Coord<double>(69.82050807568876, -67.27241335952166)};
    ASSERT_FALSE(h2 <= h1);
}

TEST(hex_less_or_eq, test03) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(0, 2), Coord<double>(-1.7320508075688772, 1), Coord<double>(-1.7320508075688772, -1), Coord<double>(0, -2),
    Coord<double>(1.7320508075688772, -1), Coord<double>(1.7320508075688772, 1)};
    ASSERT_TRUE(h2 <= h1);
}

/*---------------------------------HEX_OP_COPY--------------------------------------------------------------------*/

TEST(hex_op_copy, test01) {
    Hexagon<double> h1;
    Hexagon<double> h2 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    h1 = h2;
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_op_copy, test02) {
    Hexagon<double> h1;
    Hexagon<double> h2 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    h2 = h1;
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_op_copy, test03) {
    Hexagon<double> h1 = {Coord<double>(100, 25), Coord<double>(35.17949192431123, 97.27241335952166), Coord<double>(-59.82050807568877, 77.27241335952166),
    Coord<double>(-90, -15), Coord<double>(-25.17949192431123, -87.27241335952166), Coord<double>(69.82050807568876, -67.27241335952166)};
    Hexagon<double> h2(Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772));
    h1 = h2;
    ASSERT_TRUE(h1 == h2);
}

/*--------------------------------------HEX_OP_MOVE--------------------------------------------------------------*/

TEST(hex_op_move, test01) {
    Hexagon<double> h1;
    Hexagon<double> h2 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h3(h2);
    h1 = std::move(h2);
    ASSERT_TRUE(h1 == h3);
}

TEST(hex_op_move, test02) {
    Hexagon<double> h1;
    Hexagon<double> h2 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    h2 = std::move(h1);
    ASSERT_TRUE(h2 == Hexagon<double>());
}

TEST(hex_op_move, test03) {
    Hexagon<double> h1 = {Coord<double>(100, 25), Coord<double>(35.17949192431123, 97.27241335952166), Coord<double>(-59.82050807568877, 77.27241335952166),
    Coord<double>(-90, -15), Coord<double>(-25.17949192431123, -87.27241335952166), Coord<double>(69.82050807568876, -67.27241335952166)};
    Hexagon<double> h2(Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772));
    Hexagon<double> h3(h2);
    h1 = std::move(h2);
    ASSERT_TRUE(h1 == h3);
}

/*--------------------------------------ROMB_GET_CENTER--------------------------------------------------------------*/

TEST(romb_center, test01){
    Romb<double> r1 = {Coord<double>(4, 3), Coord<double>(7, 0), Coord<double>(4, -3), Coord<double>(1, 0)};
    ASSERT_TRUE(r1.get_center() == Coord<double>(4, 0));
}

TEST(romb_center, test02){
    Romb<double> r1 = {Coord<double>(4, 4), Coord<double>(8, 0), Coord<double>(4, -4), Coord<double>(0, 0)};
    ASSERT_TRUE(r1.get_center() == Coord<double>(4, 0));
}

/*--------------------------------------ROMB_GET_AREA--------------------------------------------------------------*/

TEST(romb_get_area, test01){
    Romb<double> r1 {Coord<double>{4, 4}, Coord<double>{8, 0}, Coord<double>{4, -4}, Coord<double>{0, 0}};
    ASSERT_EQ(double(r1), 32);
}

TEST(romb_get_area, test02){
    Romb<double> r1;
    ASSERT_EQ(double (r1), 0);
}

/*----------------------------------------PENT_GET_AREA-------------------------------------------------------------*/

TEST(pent_get_area, test01){
    Pentagon<double> pent{Coord<double>{1, 0}, Coord<double>{0.3090, 0.9511}, Coord<double>{-0.8090, 0.5878}, Coord<double>{-0.8090, -0.5878}, Coord<double>{0.3090, -0.9511}};
    double s = double(pent);
    ASSERT_TRUE(s = 2.37784);
}

TEST(pent_get_area, test02){
    Romb<double> r1;
    ASSERT_EQ(double (r1), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}