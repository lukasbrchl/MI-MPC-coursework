#include <ostream>
#include <cstring>
#include <iostream>
#include "String.h"

const int MAX_SSO_LENGTH = 8;

class String::Impl {
public:

    Impl() : data_(nullptr), sso_(false) {}

    Impl(const Impl &rhs) {
        sso_ = rhs.sso_;

        if (sso_) strcpy(buf_, rhs.buf_);
        else {
            data_ = new char[strlen(rhs.data_) + 1];
            strcpy(data_, rhs.data_);
        }
    }

    Impl &operator=(const Impl &rhs) {
        if (!sso_) delete[] data_;
        sso_ = rhs.sso_;
        Impl temp(rhs);

        if (sso_) strcpy(buf_, temp.buf_);
        else std::swap(data_, temp.data_);

        return *this;
    }

    Impl(const char *arg) {
        if (strlen(arg) < MAX_SSO_LENGTH) {
            strcpy(buf_, arg);
            sso_ = true;
        } else {
            data_ = new char[strlen(arg) + 1];
            strcpy(data_, arg);
            sso_ = false;
        }
    }

    ~Impl() {
        if (!sso_) delete[] data_;
        data_ = buf_ = nullptr;
    }

    const char *getStr() const {
        return sso_ ? buf_ : data_;
    }

    friend std::ostream &operator<<(std::ostream &str, const Impl &arg) {
        const char *tmp = arg.getStr();
        if (tmp) str << tmp;
        return str;
    }

private:
    union {
        char *data_;
        char buf_[MAX_SSO_LENGTH];
    };
    bool sso_;
};

String::String() : pimpl_(new Impl()) {}

String::String(const String &rhs) : pimpl_(new Impl(*rhs.pimpl_)) {}

String &String::operator=(const String &rhs) {
    *pimpl_ = *rhs.pimpl_;
    return *this;
}

String::String(const char *arg) : pimpl_(new Impl(arg)) {}

String::~String() {
    delete pimpl_;
    pimpl_ = nullptr;
}

void String::swap(String &rhs) {
    std::swap(pimpl_, rhs.pimpl_);
}

std::ostream &operator<<(std::ostream &str, const String &arg) {
    str << *arg.pimpl_;
}