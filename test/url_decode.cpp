/**
 * @file url_decode.cpp
 * @authors Max Markeloff (https://github.com/mmarkeloff)
 */

// MIT License
//
// Copyright (c) 2021 mmarkeloff
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <gtest/gtest.h>

#include "url_decode.hpp"

using namespace url;

////////////////////////////////////////////////////////////////////////////
///
//
class TestURLDecode : public ::testing::Test {
protected:
    void SetUp() { }

    void TearDown() { }
};

////////////////////////////////////////////////////////////////////////////
///
//
TEST_F(TestURLDecode, case1) {
    ASSERT_EQ("Hello Günter", decode("Hello%20G%C3%BCnter"));
}

TEST_F(TestURLDecode, case2) {
    ASSERT_EQ("%qwerty%u%uuu", decode("%25qwerty%25u%25uuu"));
}

TEST_F(TestURLDecode, case3) {
    ASSERT_EQ("$%,.%$;$$%$%", decode("%24%25%2C.%25%24%3B%24%24%25%24%25"));
}

TEST_F(TestURLDecode, case4) {
    ASSERT_EQ("++%++", decode("%2B%2B%25%2B%2B"));
}

TEST_F(TestURLDecode, case5) {
    ASSERT_EQ("Hello world", decode("Hello%20world"));
}
