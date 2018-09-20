// @author G. Hemingway, copyright 2018 - All rights reserved
//
#include "ArrayList.h"
#include <gtest/gtest.h>

namespace {
// The fixture for testing ArrayList and ArrayListIterator.
class ArrayListTest : public ::testing::Test {
};

TEST_F(ArrayListTest, Constructor)
{
    ArrayList<int> a;
    EXPECT_TRUE(a.isEmpty());
    EXPECT_EQ(a.size(), 0UL);
    ArrayList<int> b(20);
    EXPECT_EQ(b.size(), 20UL);
    ArrayList<int> c(20, -12345);
    EXPECT_EQ(c.size(), 20UL);
    for (uint32_t i = 0; i < 20; ++i) {
        EXPECT_EQ(c.get(i), -12345);
    }
    ArrayList<int> d(c);
    EXPECT_EQ(d.size(), 20UL);
    for (uint32_t i = 0; i < 20; ++i) {
        EXPECT_EQ(d.get(i), -12345);
    }
    d = c = b = a;
    EXPECT_EQ(b.size(), 0UL);
    EXPECT_EQ(c.size(), 0UL);
    EXPECT_EQ(d.size(), 0UL);
}

TEST_F(ArrayListTest, AddAndAssignment)
{
    ArrayList<uint32_t> a, b;

    // Add one to a
    const uint32_t num1 = a.add(10U);
    EXPECT_EQ(num1, 1U);
    const uint32_t num2 = a.add(11U);
    EXPECT_EQ(num2, 2U);
    const uint32_t num3 = a.add(12U);
    EXPECT_EQ(num3, 4U);
    const uint32_t num4 = a.add(13U);
    EXPECT_EQ(num4, 4U);
    const uint32_t num5 = a.add(14U);
    EXPECT_EQ(num5, 8U);
    const uint32_t num6 = a.add(15U);
    EXPECT_EQ(num6, 8U);

    for (uint32_t i = 6; i < 106; ++i)
        a.add(i);

    b = a;

    for (uint32_t i = 6; i < 106; ++i)
        b[i] = 100 - i;

    for (uint32_t i = 6; i < 106; ++i) {
        EXPECT_EQ(a[i], i);
        EXPECT_EQ(b[i], 100 - i);
    }
}

TEST_F(ArrayListTest, SizeAndAdd)
{
    ArrayList<double> a;
    EXPECT_EQ(a.size(), 0UL);
    a.add(2.0);
    EXPECT_EQ(a.size(), 1UL);
    EXPECT_EQ(a[0], 2.0);
    a.add(0, 1.0);
    EXPECT_EQ(a.size(), 2UL);
    a.add(3.0);
    a.add(4.0);
    a.add(5.0);
    EXPECT_EQ(a.size(), 5UL);
    a.add(3, 9.0);
    EXPECT_EQ(a.size(), 6UL);
    const double vals[] = { 1.0, 2.0, 3.0, 9.0, 4.0, 5.0 };
    for (uint32_t i = 0; i < 6; ++i)
        EXPECT_EQ(a[i], vals[i]);
}

TEST_F(ArrayListTest, AddAndGet)
{
    ArrayList<uint32_t> a;
    for (uint32_t i = 0; i < 4000; i += 2)
        a.add(i);

    for (uint32_t i = 0; i < 2000; ++i) {
        EXPECT_EQ(a[i], i * 2);
        EXPECT_EQ(a.get(i), i * 2);
    }

    for (uint32_t i = 1; i < 4000; i += 2)
        a.add(i, i);

    for (uint32_t i = 0; i < 4000; ++i) {
        EXPECT_EQ(a[i], i);
        EXPECT_EQ(a.get(i), i);
    }
}

TEST_F(ArrayListTest, GetWorks)
{
    ArrayList<char> a(20, 'c');
    for (uint32_t i = 0; i < 20; ++i) {
        EXPECT_EQ(a.get(i), 'c');
    }
    const char& c = a.get(0);
    char& d = a.get(0);
    EXPECT_EQ(d, c);
}

TEST_F(ArrayListTest, ConstGetWorks)
{
    const ArrayList<char> a(20, 'c');
    const char& c = a.get(0);
    EXPECT_EQ(c, 'c');
}

TEST_F(ArrayListTest, StillMoreGets)
{
    ArrayList<char> a(20, 'c');
    const char& c = a.get(9);
    char& d = a.get(19);
    EXPECT_EQ(c, d);
}

TEST_F(ArrayListTest, IsEmpty)
{
    const ArrayList<char> a(20, 'c');
    const char& c = a[0];
    EXPECT_EQ(c, a.get(0));
    bool e = a.isEmpty();
    EXPECT_EQ(e, false);
    uint32_t s = a.size();
    EXPECT_EQ(s, 20UL);
}

TEST_F(ArrayListTest, Remove)
{
    ArrayList<long> a(20, 100L);
    a[10] = 99L;
    a.remove(10);
    EXPECT_EQ(a.size(), 19UL);
    for (uint32_t i = 0; i < a.size(); ++i) {
        EXPECT_EQ(a[i], 100L);
    }
    try {
        a.remove(22);
    } catch (const std::out_of_range& ex) {
        EXPECT_STREQ(ex.what(), "22");
    }
    a.set(18, 12345L);
    EXPECT_EQ(a[18], 12345L);
}

TEST_F(ArrayListTest, RepeatRemove)
{
    ArrayList<uint32_t> a;
    for (uint32_t i = 0; i < 4000; ++i)
        a.add(i);

    for (uint32_t i = 0; i < 1000; ++i) {
        EXPECT_EQ(a[1999], 1999U);
        EXPECT_EQ(a[2000], i + 2000U);
        EXPECT_EQ(a[2001], i + 2001U);
        a.remove(2000);
    }

    for (uint32_t i = 0; i < 2000; ++i) {
        EXPECT_EQ(a[0], i);
        a.remove(0);
    }

    for (uint32_t i = 0; i < 1000; ++i) {
        EXPECT_EQ(a[0], i + 3000U);
        a.remove(0);
    }

    EXPECT_TRUE(a.isEmpty());
}

TEST_F(ArrayListTest, Empty)
{
    ArrayList<long> a(20, 100L);
    a.clear();
    EXPECT_TRUE(a.isEmpty());
    try {
        a.remove(0);
    } catch (const std::out_of_range& ex) {
        EXPECT_STREQ(ex.what(), "0");
    }
    try {
        a.set(0, 100L);
    } catch (const std::out_of_range& ex) {
        EXPECT_STREQ(ex.what(), "0");
    }
    //     a[0] = 100L;   // This is not correct - should compile, but cause segfault if uncommented
}

} // Namespace
