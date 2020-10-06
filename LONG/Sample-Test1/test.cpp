#include "pch.h"
#include "../LONG/class_LI.cpp"

TEST(LongConstructor, DefaultConstructor) {
    LInteger::LongInteger b;
    char* arr = new char[b.getlen() + 2];
    ASSERT_EQ(0, b.getlen());
    delete[] arr;
}

TEST(LongConstructor, InitConstructorsANDSetters)
{
    const char* str = { "+1234" };
    LInteger::LongInteger b(str);
    int numb = 213;
    long int mega_numb = -2141342123;
    LInteger::LongInteger a(numb);
    LInteger::LongInteger c(mega_numb);
    char* arr = new char[b.getlen() + 2];
    b.getInfo(arr);
    str = "1234";
    for (int i = 0; i < b.getlen() + 1; ++i)
    {
        ASSERT_EQ(str[i], arr[i]);
    }
    ASSERT_EQ(4, b.getlen());
    delete[] arr;
    arr = new char[a.getlen() + 2];
    a.getInfo(arr);
    str = "213";
    for (int i = 0; i < a.getlen() + 1; ++i)
    {
        ASSERT_EQ(str[i], arr[i]);
    }
    delete[] arr;
    arr = new char[c.getlen() + 2];
    c.getInfo(arr);
    str = "-2141342123";
    for (int i = 0; i < c.getlen() + 1; ++i)
    {
        ASSERT_EQ(str[i], arr[i]);
    }
    delete[] arr;
}

TEST(LongMethods, Parameters)
{
    const char* str = { "+1234" };
    LInteger::LongInteger b(str);
    int numb = 213;
    long int mega_numb = -2141342123;
    LInteger::LongInteger a(numb);
    LInteger::LongInteger c(mega_numb);
    c.add(b);
    char* arr = new char[c.getlen() + 2];
    c.getInfo(arr);
    str = "-2141340889";
    for (int i = 0; i < c.getlen() + 1; ++i)
    {
        ASSERT_EQ(str[i], arr[i]);
    }
    c.add(c);
    arr = new char[c.getlen() + 2];
    c.getInfo(arr);
    str = "-4282681778";
    for (int i = 0; i < c.getlen() + 1; ++i)
    {
        ASSERT_EQ(str[i], arr[i]);
    }
    delete[] arr;
    arr = new char[c.getlen() + 2];
    c.sub(c);
    c.getInfo(arr);
    str = "";
    std::cout << std::endl;
    for (int i = 0; i < c.getlen() + 1; ++i)
    {
        std::cout << arr[i];
    }
    std::cout << std::endl;
    delete[] arr;

}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}