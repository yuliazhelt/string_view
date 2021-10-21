#pragma once

#include <string>
#include <cstring>

class StringView {
public:
    StringView(const std::string& s, size_t pos = 0, size_t len = std::string::npos)
            : begin_(&s[pos]), size_(std::min(len, s.size() - pos)) {
    }

    StringView(const char* s) : begin_(s), size_(strlen(s)) {
    }

    StringView(const char* s, size_t len) : begin_(s), size_(len) {
    }

    char operator[](size_t i) const {
        return *(begin_ + i);
    }

    size_t Size() const {
        return size_;
    }

private:
    const char* begin_;
    size_t size_;
};
