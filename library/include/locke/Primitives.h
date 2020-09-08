#pragma once
#include <cstdint>

typedef struct Bool {
    uint_least8_t value;

    Bool() { value = 0; }
    Bool(uint_least8_t value) { this->value = value; }
    Bool(bool value) { this->value = value ? 0b1 : 0x0; }

    bool ToBoolean() const { return value == 0x1; }
} Bool;


typedef struct Number {
} Number;