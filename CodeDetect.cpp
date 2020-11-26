//
// Created by pippin on 2020/11/27.
//

#include "CodeDetect.h"

bool CodeDetect::IsViewAscii(char c) {
    return c >= VIEW_ASCII_START && c <= VIEW_ASCII_END;
}

bool CodeDetect::IsFrequencyGbk(uint32_t code) {
    return code >= GBK_FREQ_USE_CHINESE_START && code <= GBK_FREQ_USE_CHINESE_END;
}

std::string CodeDetect::Guess(const std::string &str) {
    int gbk = 0;
    int utf = 0;
    for (int i = 0; i < str.size() - 1; i++) {
        if (IsViewAscii(str[i])) {
            ++i;
            continue;
        }
        uint32_t gbkNum = ((static_cast<uint32_t>(str[i]) << 8) & 0xff00) + (static_cast<uint32_t>(str[i + 1]) & 0x00ff);
        if (IsFrequencyGbk(gbkNum)) {
            ++gbk;
        }
        i += 2;
    }
    for (int i = 0; i < str.size() - 2; ) {
        if (IsViewAscii(str[i])) {
            i++;
            continue;
        }
        uint32_t utfNum = ((static_cast<uint32_t>(str[i]) << 16)&0xff0000) + ((static_cast<uint32_t>(str[i + 1]) << 8)&0x00ff00) +
                (static_cast<uint32_t>(str[i + 2])&0x0000ff);
        if (IsUtfChinese(utfNum)) {
            ++utf;
        }
        i += 3;
    }
    return gbk > utf ? "GBK" : "UTF-8";
}

bool CodeDetect::IsUtfChinese(uint32_t code) {
    const uint32_t control = 0x00ffffff;
    code &= control;
    return (code & UTF_8_FOO) == UTF_8_CONTROL;
}
