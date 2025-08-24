// {{cookiecutter.project_name}} 라이브러리 테스트 파일
// Google Test 및 Google Mock을 사용하는 테스트

#include <gtest/gtest.h>
#include <gmock/gmock.h>

// 간단한 더미 테스트 함수
bool dummyFunction()
{
    return true;
}

// Google Test 테스트 케이스
TEST(DummyTest, BasicTest)
{
    EXPECT_TRUE(dummyFunction());
}

TEST(DummyTest, AnotherTest)
{
    EXPECT_EQ(1 + 1, 2);
}

// Google Mock을 사용한 모의 객체 예제
class MockExample
{
public:
    virtual ~MockExample() = default;
    virtual bool doSomething() = 0;
};

class MockExampleImpl : public MockExample
{
public:
    MOCK_METHOD(bool, doSomething, (), (override));
};

TEST(MockTest, MockExample)
{
    MockExampleImpl mock;
    EXPECT_CALL(mock, doSomething()).WillOnce(testing::Return(true));

    EXPECT_TRUE(mock.doSomething());
}