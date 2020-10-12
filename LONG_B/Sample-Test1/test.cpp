#include "pch.h"
#include "../LONG_B/LONG_OP.cpp"

TEST(LongMethods, Parameters)
{
    const char* str = { "+1234" };
    LInteger::LongInteger b(str);
    int numb = 213;
    long int mega_numb = -2141342123;
    LInteger::LongInteger a(numb);
    LInteger::LongInteger c(mega_numb);
    c = a + b;
    const char* arr;
    int l = c.getlen();
    str = "1447";
    for (int i = 0; i < l; ++i)
    {
        arr = c.getInfo();
        ASSERT_EQ(str[i], arr[i]);
    }
    c = c + c;
    str = "2894";
    l = c.getlen();
    for (int i = 0; i < l; ++i)
    {
        arr = c.getInfo();
        ASSERT_EQ(str[i], arr[i]);
    }

}
TEST(LongConstructor, InitConstructorsANDSetters)
{
    const char* str = { "+1234" };
    LInteger::LongInteger b(str);
    int numb = 213;
    long int mega_numb = -2141342123;
    LInteger::LongInteger a = mega_numb;
    LInteger::LongInteger c(numb);
    const char* arr;
    str = "1234";
    int l = b.getlen();
    for (int i = 0; i < l; ++i)
    {
        arr = b.getInfo();
        ASSERT_EQ(str[i], arr[i]);
    }
    ASSERT_EQ(4, b.getlen());
    str = "-2141342123";
    l = a.getlen();
    for (int i = 0; i < l-2; ++i)
    {
        arr = a.getInfo();
        ASSERT_EQ(str[i], arr[i]);
    }
    str = "213";
    l = c.getlen();
    for (int i = 0; i < l; ++i)
    {
        arr = c.getInfo();
        ASSERT_EQ(str[i], arr[i]);
    }
}
TEST(LongConstructor, DefaultConstructor) {
    LInteger::LongInteger b;
    ASSERT_EQ(0, b.getlen());
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}