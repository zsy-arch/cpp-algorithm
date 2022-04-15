//
// Created by zhangsiyu on 4/15/2022.
//
#include <iostream>
#include "kmp.h"

int main(int argc, char *argv[]) {
    auto result = kmp_search("hello", "0");
    for (const size_t &item: *result) {
        std::cout << item << " ";
    }
    return 0;
}