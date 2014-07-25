// Copyright (c) 2014 Filip Szufnarowski
// All rights reserved.

#ifndef _TEST1_H_
#define _TEST1_H_

#include "fructose/fructose.h"
using fructose::test_base;

const int one = 1;

struct sample_test : public test_base<sample_test>
{
    void test1(const std::string& test_name)
    {
        fructose_assert(one == 1);
    }

    void test5(const std::string& test_name)
    {
        const int five = 5;
        fructose_assert_eq(five, one);
    }
};
#endif /* _TEST1_H_ */
