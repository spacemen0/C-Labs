#ifndef CONNECTION_H
#define CONNECTION_H

// TODO: Complementary work needed: If a class only has public members, use a
// struct instead, it makes the intent behind the type much clearer.
//
// Hint: If all you want is a different name for a base type, use 
// "using Connection = double"
class Connection
{
public:
    Connection() : voltage(0.0) {}

    double voltage;
};
#endif
