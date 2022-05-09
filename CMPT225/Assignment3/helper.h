#pragma once
#include <random>
#include <string>

std::string random_string()
{
    std::string str("0123456789abcdefghijklmnopqrstuvwxyz");

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(str.begin(), str.end(), generator);

    return str.substr(0, 12);    // assumes 32 < number of characters in str         
}