//
// Created by zhangsiyu on 4/15/2022.
//

#ifndef CPP_ALGORITHM_KMP_H
#define CPP_ALGORITHM_KMP_H

#include <vector>
#include <string>

std::vector<size_t> *get_prefix_table(const std::string &pattern) {
    auto prefix_table = new std::vector<size_t>;
    prefix_table->push_back(0);
    size_t i = 1, len = 0;
    while (i < pattern.size()) {
        if (pattern[i] == pattern[len]) {
            len++;
            prefix_table->push_back(len);
            i++;
        } else {
            if (len > 0) {
                len = prefix_table->at(len - 1);
            } else {
                prefix_table->push_back(len);
                i++;
            }
        }
    }
    return prefix_table;
}

std::vector<size_t> *kmp_search(const std::string &text, const std::string &pattern) {
    auto prefix_table = get_prefix_table(pattern);
    auto matches = new std::vector<size_t>;
    size_t i = 0, j = 0;
    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++, j++;
        } else {
            if (j > 0) {
                j = prefix_table->at(j - 1);
            } else {
                i++;
            }
        }
        if (j == pattern.size()) {
            matches->push_back(i - pattern.size());
            j = prefix_table->at(j - 1);
        }
    }
    return matches;
}

#endif //CPP_ALGORITHM_KMP_H
