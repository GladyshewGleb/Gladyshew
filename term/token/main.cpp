#include <iostream>
#include <string>
#include <clocale>
#include <locale>
#include <fstream>
#include <sstream>
#include <codecvt>

#include "tokenization.h"

using namespace std;

int main() {
    clock_t tStart = clock();

    setlocale(LC_ALL, "ru_RU.UTF-8");
    locale imbue(const locale& L);
    wcout.imbue(locale("ru_RU.UTF-8"));

    std::ifstream fin("../plain_text.txt");

    std::stringstream buffer;
    buffer << fin.rdbuf();
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring s = converter.from_bytes(buffer.str());

    Tokenization tokenization(s, "../base.txt");

    fin.close();
    printf("Время работы: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
