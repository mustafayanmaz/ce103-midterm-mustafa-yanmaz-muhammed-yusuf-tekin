#include "gtest/gtest.h"
#include "pharmacy.h"  // Adjust this include path based on your project structure

using namespace Pharmacy;

class PharmacyTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Setup test data
  }

  void TearDown() override {
    // Clean up test data
  }
};

TEST_F(PharmacyTest, TestAdd) {
  double result = Pharmacy::add(5.0, 3.0);
  EXPECT_DOUBLE_EQ(result, 8.0);
}

TEST_F(PharmacyTest, TestSubtract) {
  double result = Pharmacy::subtract(5.0, 3.0);
  EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(PharmacyTest, TestMultiply) {
  double result = Pharmacy::multiply(5.0, 3.0);
  EXPECT_DOUBLE_EQ(result, 15.0);
}

TEST_F(PharmacyTest, TestDivide) {
  double result = Pharmacy::divide(6.0, 3.0);
  EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(PharmacyTest, TestDivideByZero) {
  EXPECT_THROW(Pharmacy::divide(5.0, 0.0), std::invalid_argument);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
