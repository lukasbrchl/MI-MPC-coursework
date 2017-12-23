//
// Created by Lukas on 23-Dec-17.
//

class Lambda {
public:

    Lambda(int &first, int second) : first(&first), second(second) {}

    void operator()(int num) {
        (*first) += second + num;
    }

private:
    int *first, second;
};