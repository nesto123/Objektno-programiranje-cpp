#include "gtest/gtest.h"                    //google testove uključit
#include "../src/zadatak.h"
 
#include <cmath>

using namespace std;

TEST(INTRO, Zadatak) {
    double P = zadatak(1.0);
	
    ASSERT_DOUBLE_EQ (P, 2*M_PI);       //jesu li 2 doublea = ?
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
