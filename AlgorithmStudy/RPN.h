
#pragma once
class CRPN
{
public:
    CRPN();
    ~CRPN();

    stack<double> calcStack;

    bool isOperator(const string& input);
    void performOp(const string& input);
    void Calculator();
};

