#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/*
 * gtest中，断言的宏可以理解为分为两类，一类是ASSERT系列，一类是EXPECT系列。一个直观的解释就是：
 * 1. ASSERT_* 系列的断言，当检查点失败时，退出当前函数（注意：并非退出当前案例）。
 * 2. EXPECT_* 系列的断言，当检查点失败时，继续往下执行。
 *
 * 这两组断言是成对的版本
 * */

/*
 * 宏定义族
 * */
/**
 table

 布尔值检查

| Fatal assertion            | Nonfatal assertion         | Verifies             |
| ---------------------------| -------------------------- | -------------------- |
| ASSERT_TRUE(condition);  | EXPECT_TRUE(condition);  | condition is true  |
| ASSERT_FALSE(condition); | EXPECT_FALSE(condition); | condition is false |

 数值型数据检查  

| Fatal assertion                    | Nonfatal assertion                 | Verifies             |
| -------------------------------------- | -------------------------------------- | ------------------------ |
| ASSERT_EQ(expected, actual); | EXPECT_EQ(expected, actual); | expected == actual |
| ASSERT_NE(val1, val2);       | EXPECT_NE(val1, val2);       | val1 != val2       |
| ASSERT_LT(val1, val2);       | EXPECT_LT(val1, val2);       | val1 < val2        |
| ASSERT_LE(val1, val2);       | EXPECT_LE(val1, val2);       | val1 <= val2       |
| ASSERT_GT(val1, val2);       | EXPECT_GT(val1, val2);       | val1 > val2        |
| ASSERT_GE(val1, val2);       | EXPECT_GE(val1, val2);       | val1 >= val2       |

 字符串检查   

| Fatal assertion                                   | Nonfatal assertion                                | Verifies                                            |
| ----------------------------------------------------- | ----------------------------------------------------- | ------------------------------------------------------- |
| ASSERT_STREQ(expected_str, actual_str);     | EXPECT_STREQ(expected_str, actual_str);     | the two C strings have the same content                 |
| ASSERT_STRNE(str1, str2);                   | EXPECT_STRNE(str1, str2);                   | the two C strings have different content                |
| ASSERT_STRCASEEQ(expected_str, actual_str); | EXPECT_STRCASEEQ(expected_str, actual_str); | the two C strings have the same content, ignoring case(忽略大小写)  |
| ASSERT_STRCASENE(str1, str2);               | EXPECT_STRCASENE(str1, str2);               | the two C strings have different content, ignoring case(忽略大小写) |

 显示返回成功或失败

| Fatal assertion | Nonfatal assertion |
| ------------------- | ---------------------- |
| FAIL();       | ADD_FAILURE();   |
| SUCCEED();        |                        |

 异常检查  

| Fatal assertion                              | Nonfatal assertion                           | Verifies                                      |
| ------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------- |
| ASSERT_THROW(statement, exception_type); | EXPECT_THROW(statement, exception_type); | statement throws an exception of the given type, 第二个参数是类型 |
| ASSERT_ANY_THROW(statement);               | EXPECT_ANY_THROW(statement);               | statement throws an exception of any type       |
| ASSERT_NO_THROW(statement);                | EXPECT_NO_THROW(statement);                | statement doesn't throw any exception           |

 Predicate Assertions

| Fatal assertion                    | Nonfatal assertion                 | Verifies                     |
| -------------------------------------- | -------------------------------------- | -------------------------------- |
| ASSERT_PRED1(pred1, val1);       | EXPECT_PRED1(pred1, val1);       | pred1(val1) returns true       |
| ASSERT_PRED2(pred2, val1, val2); | EXPECT_PRED2(pred2, val1, val2); | pred2(val1, val2) returns true |
| ...                                    | ...                                    | ...                              |

| Fatal assertion                                  | Nonfatal assertion                             | Verifies                             |
| ---------------------------------------------------- | -------------------------------------------------- | ---------------------------------------- |
| ASSERT_PRED_FORMAT1(pred_format1, val1);       | EXPECT_PRED_FORMAT1(pred_format1, val1);       | pred_format1(val1) is successful       |
| ASSERT_PRED_FORMAT2(pred_format2, val1, val2); | EXPECT_PRED_FORMAT2(pred_format2, val1, val2); | pred_format2(val1, val2) is successful |
| ...                                              |                                                    |                                          |

 浮点型检查  

| Fatal assertion                       | Nonfatal assertion                    | Verifies                             |
| ------------------------------------- | ------------------------------------- | -------------------------------------- |
| ASSERT_FLOAT_EQ(expected, actual);  | EXPECT_FLOAT_EQ(expected, actual);  | the two float values are almost equal  |
| ASSERT_DOUBLE_EQ(expected, actual); | EXPECT_DOUBLE_EQ(expected, actual); | the two double values are almost equal |

对相近的两个数比较：



| Fatal assertion                       | Nonfatal assertion                    | Verifies                                                 |
| ----------------------------------------- | ----------------------------------------- | ------------------------------------------------------------ |
| ASSERT_NEAR(val1, val2, abs_error); | EXPECT_NEAR(val1, val2, abs_error); | the difference between val1 and val2 doesn't exceed the given absolute error |

 Windows HRESULT assertions  

| Fatal assertion                         | Nonfatal assertion                      | Verifies                        |
| ------------------------------------------- | ------------------------------------------- | ----------------------------------- |
| ASSERT_HRESULT_SUCCEEDED(expression); | EXPECT_HRESULT_SUCCEEDED(expression); | expression is a success HRESULT |
| ASSERT_HRESULT_FAILED(expression);    | EXPECT_HRESULT_FAILED(expression);    | expression is a failure HRESULT |
 * **/

TEST(TestAssert, example_case) {
  EXPECT_EQ(9, 9);
  // ASSERT_EQ(8, 9); // 会退出
  ASSERT_EQ(9, 9);
}

TEST(TestAssert, add_cout) {
  array<int, 6> arr = {1, 2, 3, 4, 5, 6};

  for (int i = 0; i < arr.size(); i++) {
    EXPECT_NE(arr[i], i+1) << ", index = [" << i << "]" << endl; // 后面追加打印，不过只有出错时才会有打印
  }
}

TEST(TestAssert, ch_string) {
  // *STREQ*和*STRNE*同时支持char*和wchar_t*类型的，*STRCASEEQ*和*STRCASENE*却只接收char*，估计是不常用吧。
    char* pszCoderZh = "CoderZh";
    wchar_t* wszCoderZh = L"CoderZh";
    std::string strCoderZh = "CoderZh";
    std::wstring wstrCoderZh = L"CoderZh";

    EXPECT_STREQ("CoderZh", pszCoderZh);
    EXPECT_STREQ(L"CoderZh", wszCoderZh);

    EXPECT_STRNE("CnBlogs", pszCoderZh);
    EXPECT_STRNE(L"CnBlogs", wszCoderZh);

    EXPECT_STRCASEEQ("coderzh", pszCoderZh);
    // EXPECT_STRCASEEQ(L"coderzh", wszCoderZh); //    不支持

    EXPECT_STREQ("CoderZh", strCoderZh.c_str());
    EXPECT_STREQ(L"CoderZh", wstrCoderZh.c_str());
}

TEST(TestAssert, priv_result) {
  // 自己决定成功或失败
    ADD_FAILURE() << "Sorry"; // None Fatal Asserton，继续往下执行。

    // FAIL(); // Fatal Assertion，不往下执行该用例。

    SUCCEED();
}

int Foo(int a, int b) {
    if (0 == a|| 0 == b) {
        throw "don't do that";
    }

    int c = a % b;

    if (0 == c)
        return b;
    return Foo(b, c);
}

TEST(TestAssert, HandleZeroInput) {
    EXPECT_ANY_THROW(Foo(10, 0));

    EXPECT_THROW(Foo(0, 5), char*); // 希望返回一个char *的异常
}

bool MutuallyPrime(int m, int n) {
    return m > n;
}

TEST(TestAssert, param) {
    int m = 5, n = 6;
    // 自带断言，当函数返回为假时，会出错，并且把传入的这两个参数的值给打印出来，
    // 注意:这个这个宏定义族最多5个参数
    EXPECT_PRED2(MutuallyPrime, m, n); 
    m = 7;
    n = 6;
    EXPECT_PRED2(MutuallyPrime, m, n);
}

testing::AssertionResult AssertFoo(const char* m_expr, const char* n_expr, const char* k_expr, int m, int n, int k) {
  // 成倍的参数个数，不过前半表示后半的原始值
    if (Foo(m, n) == k)
        return testing::AssertionSuccess();
    testing::Message msg;
    msg << m_expr << " 和 " << n_expr << " 的最大公约数应该是：" << Foo(m, n) << " 而不是：" << k_expr;
    return testing::AssertionFailure(msg);
}

TEST(TestAssert, pretty_cout) {
  // 和前面的类似，不过输出更灵活
    EXPECT_PRED_FORMAT3(AssertFoo, 3, 6, 2);
}
/*
template <typename T> class FooType {
public:
    void Bar() { testing::StaticAssertTypeEq<int, T>(); }
};

// 类型检查，检查不通过会编译不通过，并且给出错误信息

TEST(TestAssert, type_check) {
    FooType<bool> fooType;
    fooType.Bar();
}
*/

TEST(TestAssert, running) {
  // PASS
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
