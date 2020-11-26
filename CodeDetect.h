//
// Created by pippin on 2020/11/27.
//

#ifndef ENCODINGTEST_CODEDETECT_H
#define ENCODINGTEST_CODEDETECT_H

#include <bitset>

class CodeDetect {
public:
    static std::string Guess(const std::string& str);
private:
    static bool IsViewAscii(char c);

    static bool IsFrequencyGbk(uint32_t code);

    static uint32_t GetUtf8Foo();

    static uint32_t GetUtf8Control();

    static bool IsUtfChinese(uint32_t code);

private:
    static int const VIEW_ASCII_START = 32;
    static int const VIEW_ASCII_END = 126;
    static int const GBK_FREQ_USE_CHINESE_START = 0xB0A1;
    static int const GBK_FREQ_USE_CHINESE_END = 0xF7FE;
    static uint32_t const UTF_8_CONTROL = 0x00E08080;
    static uint32_t const UTF_8_FOO = 0x00F0C0C0;
};


#endif //ENCODINGTEST_CODEDETECT_H
