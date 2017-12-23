//
// Created by Lukas on 23-Dec-17.
//

#include <cstring>
#include <ostream>
#include <memory>

class String {
public:

    String() = default;  // default constructor

    String(const String &rhs) : data_(nullptr) { // copy constructor
        if (rhs.data_) {
            data_ = createPtr(strlen(rhs.data_.get()) + 1);
            strcpy(data_.get(), rhs.data_.get());
        }
    }

    String(String &&rhs) noexcept = default; // move constructor

    String &operator=(const String &rhs) { // copy assignment operator
        String temp(rhs);
        swap(temp);
        return *this;
    }

    String &operator=(String &&rhs) noexcept = default; // move assignment operator

    String(const char *arg) { // converting constructor
        data_ = createPtr(strlen(arg) + 1);
        strcpy(data_.get(), arg);
    }

    ~String() = default;  // destructor

    void swap(String &rhs) noexcept {
        data_.swap(rhs.data_);
    }

    friend std::ostream &operator<<(std::ostream &str, const String &arg) {
        if (arg.data_) str << arg.data_.get();
        return str;
    }

private:

    std::unique_ptr<char[]> createPtr(int n) {
        return std::unique_ptr<char[]>(new char[n]);
    }

    std::unique_ptr<char[]> data_; // String data: pointer to null-terminated byte string
};