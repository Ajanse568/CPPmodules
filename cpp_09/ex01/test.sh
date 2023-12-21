#!/bin/bash

expression1="8 9 * 9 - 9 - 9 - 4 - 1 +"
expression2="7 7 * 7 -"
expression3="1 2 * 2 / 2 * 2 4 - +"
expression4="(1 + 1)"

expression5=""
expression6="     "
expression7=" 4 3 2 0 /"
expression8=" 2 4 + - / "
expression9="3 4 * 5 6 * +"
expression10="  1 2 3 * 4 + +"
tab=$'\t'

echo "./RPN \"$expression1\""
./RPN "$expression1"
echo
echo "./RPN \"$expression2\""
./RPN "$expression2"
echo
echo "./RPN \"$expression3\""
./RPN "$expression3"
echo
echo "./RPN \"$expression4\""
./RPN "$expression4"
echo
echo "./RPN \"$expression5\""
./RPN "$expression5"
echo
echo "./RPN \"$expression6\""
./RPN "$expression6"
echo
echo "./RPN \"$expression7\""
./RPN "$expression7"
echo
echo "./RPN \"$expression8\""
./RPN "$expression8"
echo
echo -e "./RPN \"$tab\""
./RPN "$tab"
echo
echo "./RPN \"$expression9\""
./RPN "$expression9"
echo
echo "./RPN \"$expression10\""
./RPN "$expression10"
echo