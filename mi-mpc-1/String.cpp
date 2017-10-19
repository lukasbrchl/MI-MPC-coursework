#include <ostream>
#include <cstring>
#include <iostream>

using namespace std;
class String {
public:
    String() : data_(nullptr), sso_(false) { }

    String(const char* arg) {
        if (strlen(arg) < 8) {
            strcpy(buf_, arg);
            sso_ = true;
        } else {
            data_ = new char[strlen(arg) + 1];
            strcpy(data_, arg);
            sso_ = false;
        }
    }

    ~String() {
        if (!sso_) delete [] data_;
    }

    const char * getStr() const {
        return sso_ ? buf_ : data_;
    }

    friend std::ostream& operator<<(std::ostream& str, const String& arg) {
        const char * tmp = arg.getStr();
        if (tmp) str << tmp;
        return str;
    }

private:
    union {
        char * data_;
        char buf_ [8];
    };
    bool sso_;
};