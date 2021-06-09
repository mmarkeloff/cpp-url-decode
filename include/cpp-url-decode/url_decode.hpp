/**
 * @file url_decode.hpp
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

#include <string>

/**
 * Lib space
 */
namespace url {
    /**
     * Decode URL
     * 
     * @param text encoded URL
     * 
     * @return decoded URL
     */
    std::string decode(const std::string& text) noexcept;
};

std::string url::decode(const std::string& text) noexcept {
    std::string out;
    for (auto it = text.begin(); it != text.end(); ++it) {
        char ch = *it;
        switch (ch) {
            case '+': {
                out += ' ';
                break;
            }
            case '%': {
                //Check by "%XX" pattern
                if (text.end() != it + 1 && text.end() != it + 2) {
                    const std::string s{it[1], it[2]}; // s is "XX"
                    out += std::stol(s, nullptr, 16); // convert hex to long int and concate with result string
                    it += 2; // skip "XX"
                }

                break;
            }
            default: { 
                out += ch;
            }
        }
    }

    return out;
}