// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson


class Minimum : public BinaryOperator {
public:
    Minimum(Expression* left, Expression* right) : BinaryOperator(left, right) {}
    double evaluate() override {
        return std::min(left->evaluate(), right->evaluate());
    }
};

#endif
//added as a reminder that this file did not exist in the skeleton