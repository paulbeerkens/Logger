//
// Created by pbeerken on 6/7/17.
//

#include <gtest/gtest.h>
#include "../Logger.h"
#include <algorithm>

TEST(MyLogTest, Simple) {
    testing::internal::CaptureStdout();

    Logger::Instance().logInfo() << "Hello World" << LogStream::endl;

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("|Hello World") != std::string::npos);

    //check that there is a separator after the date
    EXPECT_TRUE(output[6] == '|');
    //check that there is a dot separator for miliseconds
    EXPECT_TRUE(output[13] == '.');

    //check that there are 4 separators
    EXPECT_EQ (std::count(output.begin(), output.end(), '|'), 4);
}

TEST(MyLogTest, TwoLines) {
    testing::internal::CaptureStdout();

    Logger::Instance().logInfo() << "First Line" << LogStream::endl;
    Logger::Instance().logInfo() << "Second Line" << LogStream::endl;

    std::string output = testing::internal::GetCapturedStdout();

    //check that there are 4 separators
    EXPECT_EQ (std::count(output.begin(), output.end(), '|'), 8);

    //check that there are 2 lines
    EXPECT_EQ (std::count(output.begin(), output.end(), '\n'), 2);

    EXPECT_TRUE(output.find("|First Line") != std::string::npos);
    EXPECT_TRUE(output.find("|Second Line") != std::string::npos);
};

TEST(MyLogTest, ThreadTest) {
    testing::internal::CaptureStdout();

    std::thread t1([]() {
        std::stringstream ss;
        for (int i = 0; i < 50; i++) ss << "A";

        for (int i = 0; i < 50'000; i++) {
            Logger::Instance().logInfo() << ss.str() << LogStream::endl;
        };
    });

    std::thread t2([]() {
        std::stringstream ss;
        for (int i = 0; i < 50; i++) ss << "B";

        for (int i = 0; i < 50'000; i++) {
            Logger::Instance().logInfo() << ss.str() << LogStream::endl;
        };
    });

    t1.join();
    t2.join();

    std::string output = testing::internal::GetCapturedStdout();

    //check that there are 100000 lines
    EXPECT_EQ (std::count(output.begin(), output.end(), '\n'), 100'000);

    //make sure that nothing was interleaved
    EXPECT_TRUE(output.find("AB") == std::string::npos);
    EXPECT_TRUE(output.find("BA") == std::string::npos);

    //check that there are 4 separators per line
    EXPECT_EQ (std::count(output.begin(), output.end(), '|'), 400'000);
}

TEST(MyLogTest, SeverityTestInfo)
{
    testing::internal::CaptureStdout();

    Logger::Instance().logInfo() << "Hello World" << LogStream::endl;

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("|Info|") != std::string::npos);
}

TEST(MyLogTest, SeverityTestError)
{
    testing::internal::CaptureStdout();

    Logger::Instance().logError() << "Hello World" << LogStream::endl;

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("|Error|") != std::string::npos);
}

TEST(MyLogTest, SeverityTestMixed)
{
    testing::internal::CaptureStdout();

    Logger::Instance().logInfo() << "Hello World";
    Logger::Instance().logError() << "Hello World";
    Logger::Instance().logInfo() << LogStream::endl;
    Logger::Instance().logError() << LogStream::endl;

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("|Info|") != std::string::npos);
    EXPECT_TRUE(output.find("|Error|") != std::string::npos);
    //check that there are 2 lines
    EXPECT_EQ (std::count(output.begin(), output.end(), '\n'), 2);
}