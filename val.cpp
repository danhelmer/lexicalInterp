#include <iostream>
#include <string>
#include <vector> 
#include "val.h"
Value Value::operator-(const Value& op) const {
    
    if (this->IsErr() || op.IsErr() || this->IsBool() || op.IsBool() || this->IsString() || op.IsString()) {
        return Value();
    }
    int a1 = 0;
    float a2 = 0;
    int b1 = 0;
    float b2 = 0;
    if (this->IsInt()) {
        a1 = this->GetInt();
    }
    else {
        a2 = this->GetReal();
    }
    if (op.IsInt()) {
        b1 = op.GetInt();
    }
    else {
        b2 = op.GetReal();
    }
    if (this->IsReal() && op.IsReal()) {
        float temp = a2 - b2;
        return Value(temp);
    }
    else if (this->IsReal()) {
        float temp = a2 - b1;
        return Value(temp);
    }
    else if (op.IsReal()) {
        float temp = a1 - b2;
        return Value(temp);
    }
    return Value(a1-b1);
}

Value Value::operator*(const Value& op) const {
    if (this->IsErr() || op.IsErr() || this->IsBool() || op.IsBool() || this->IsString() || op.IsString()) {
        return Value();
    }
    int a1 = 0;
    float a2 = 0;
    int b1 = 0;
    float b2 = 0;
    if (this->IsInt()) {
        a1 = this->GetInt();
    }
    else {
        a2 = this->GetReal();
    }
    if (op.IsInt()) {
        b1 = op.GetInt();
    }
    else {
        b2 = op.GetReal();
    }
    if (this->IsReal() && op.IsReal()) {
        float temp = a2 * b2;
        return Value(temp);
    }
    else if (this->IsReal()) {
        float temp = a2 * b1;
        return Value(temp);
    }
    else if (op.IsReal()) {
        float temp = a1 * b2;
        return Value(temp);
    }
    return Value(a1 * b1);
}

Value Value::operator<(const Value& op) const {
    if (this->IsErr() || op.IsErr() || this->IsString() || op.IsString()) {
        return Value();
    }
    if ((this->IsBool() && !op.IsBool()) || (!this->IsBool() && op.IsBool())) {
        return Value();
    }
    else if (this->IsBool() && op.IsBool()) {

        return Value(this->GetBool() < op.GetBool());
    }
    int a1 = 0;
    float a2 = 0;
    int b1 = 0;
    float b2 = 0;
    if (this->IsInt()) {
        a1 = this->GetInt();
    }
    else {
        a2 = this->GetReal();
    }
    if (op.IsInt()) {
        b1 = op.GetInt();
    }
    else {
        b2 = op.GetReal();
    }

    if (this->IsReal() && op.IsReal()) {
        bool temp = a2 < b2;
        return Value(temp);
    }
    else if (this->IsReal()) {
        bool temp = a2 < b1;
        return Value(temp);
    }
    else if (op.IsReal()) {
        bool temp = a1 < b2;
        return Value(temp);
    }
    return Value(a1 < b1);
}

Value Value::operator&&(const Value& op) const {
    if (!this->IsBool() || !op.IsBool()) {
        return Value();
    }
    return Value((this->GetBool() && op.GetBool()));
}

Value Value::operator+(const Value& op) const {
    if (this->IsErr() || op.IsErr() || this->IsBool() || op.IsBool() || this->IsString() || op.IsString()) {
        return Value();
    }
    int a1 = 0;
    float a2 = 0;
    int b1 = 0;
    float b2 = 0;
    if (this->IsInt()) {
        a1 = this->GetInt();
    }
    else {
        a2 = this->GetReal();
    }
    if (op.IsInt()) {
        b1 = op.GetInt();
    }
    else {
        b2 = op.GetReal();
    }
    if (this->IsReal() && op.IsReal()) {
        float temp = a2 + b2;
        return Value(temp);
    }
    else if (this->IsReal()) {
        float temp = a2 + b1;
        return Value(temp);
    }
    else if (op.IsReal()) {
        float temp = a1 + b2;
        return Value(temp);
    }
    return Value(a1 + b1);
}

Value Value::operator/(const Value& op) const {
    if (this->IsErr() || op.IsErr() || this->IsBool() || op.IsBool() || this->IsString() || op.IsString()) {
        return Value();
    }
    int a1 = 0;
    float a2 = 0;
    int b1 = 0;
    float b2 = 0;
    if (this->IsInt()) {
        a1 = this->GetInt();
    }
    else {
        a2 = this->GetReal();
    }
    if (op.IsInt()) {
        b1 = op.GetInt();
    }
    else {
        b2 = op.GetReal();
    }
    if (op.GetInt() == 0 || op.GetReal() == 0.0) {
        return Value();
    }
    if (this->IsReal() && op.IsReal()) {
        
        float temp = a2 / b2;
        return Value(temp);
    }
    else if (this->IsReal()) {
        float temp = a2 / b1;
        return Value(temp);
    }
    else if (op.IsReal()) {
        float temp = a1 / b2;
        return Value(temp);
    }
    return Value(a1 / b1);
}
Value Value::operator==(const Value& op) const {
    if (this->IsErr() || op.IsErr()) {
        return Value();
    }
    if ((this->IsString() && !op.IsString()) || (!this->IsString() && op.IsString())) {
        return Value();
    }
    if (this->IsString() && op.IsString()) {
        return Value(this->GetString() == op.GetString());
    }
    if ((this->IsBool() && !op.IsBool()) || (!this->IsBool() && op.IsBool())) {
        return Value();
    }
    else if (this->IsBool() && op.IsBool()) {

        return Value(this->GetBool() == op.GetBool());
    }
    int a1 = 0;
    float a2 = 0;
    int b1 = 0;
    float b2 = 0;
    if (this->IsInt()) {
        a1 = this->GetInt();
    }
    else {
        a2 = this->GetReal();
    }
    if (op.IsInt()) {
        b1 = op.GetInt();
    }
    else {
        b2 = op.GetReal();
    }

    if (this->IsReal() && op.IsReal()) {
        bool temp = a2 == b2;
        return Value(temp);
    }
    else if (this->IsReal()) {
        bool temp = a2 == b1;
        return Value(temp);
    }
    else if (op.IsReal()) {
        bool temp = a1 == b2;
        return Value(temp);
    }
    return Value(a1 == b1);
    /*
    if (this->IsString && !op.IsString() || !this->IsString && op.IsString()) {
        return Value();
    }
    if (this->IsString() && op.IsString()) {
        return Value(this->GetString() == op.GetString());
    }
    if (this->IsInt() && op.IsInt()) {
        return Value(this->GetInt() == );
    }
    */
}
Value Value::operator>(const Value& op) const {
    if (this->IsErr() || op.IsErr() || this->IsString() || op.IsString()) {
        return Value();
    }
    if ((this->IsBool() && !op.IsBool()) || (!this->IsBool() && op.IsBool())) {
        return Value();
    }
    else if (this->IsBool() && op.IsBool()) {

        return Value(this->GetBool() > op.GetBool());
    }
    int a1 = 0;
    float a2 = 0;
    int b1 = 0;
    float b2 = 0;
    if (this->IsInt()) {
        a1 = this->GetInt();
    }
    else {
        a2 = this->GetReal();
    }
    if (op.IsInt()) {
        b1 = op.GetInt();
    }
    else {
        b2 = op.GetReal();
    }

    if (this->IsReal() && op.IsReal()) {
        bool temp = a2 > b2;
        return Value(temp);
    }
    else if (this->IsReal()) {
        bool temp = a2 > b1;
        return Value(temp);
    }
    else if (op.IsReal()) {
        bool temp = a1 > b2;
        return Value(temp);
    }
    return Value(a1 > b1);
}
Value Value::operator||(const Value& op) const {
    if (!this->IsBool() || !op.IsBool()) {
        return Value();
    }
    return Value((this->GetBool() || op.GetBool()));
}
Value Value::operator!() const {
    if (!this->IsBool()) {
        return Value();
    }
    return Value(!(this->GetBool()));
}