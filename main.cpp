#include <iostream>
#include "boost/locale.hpp"
#include "boost/format.hpp"
#include "CodeDetect.h"

using namespace std;

string ToHex(const string &src) {
    boost::format toHex("%02X");
    string result;
    result.reserve(src.size() * 2);
    for (unsigned char c : src) {
        toHex % static_cast<uint32_t>(c);
        result.append(toHex.str());
        toHex.clear();
    }
    return result;
}

string ToHex(const wstring &src) {
    boost::format toHex("%04X");
    string result;
    result.reserve(src.size() * 4);
    for (wchar_t c : src) {
        toHex % static_cast<uint32_t>(c);
        result.append(toHex.str());
        toHex.clear();
    }
    return result;
}


int main() {
    string str = "你好";
    cout << CodeDetect::Guess(str) << endl;
    cout << ToHex(str) << endl;
    string ss = boost::locale::conv::between(str, "GBK", "UTF-8");
    cout << CodeDetect::Guess(ss) << endl;
    cout << ToHex(ss) << endl;
    auto wutf = boost::locale::conv::to_utf<wchar_t>(ss, "GBK");
    cout << ToHex(wutf) << endl;
    string code(2, '\0');

    return 0;
}
