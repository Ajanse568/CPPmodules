#!/bin/bash


echo "./convert a"
echo
./convert "a"
echo
echo
echo "./convert 0"
echo
./convert "0"
echo
echo
echo "./convert 42"
echo
./convert "42"
echo
echo
echo "./convert 42.0f"
echo
./convert "42.0f"
echo
echo
echo "./convert 42.0"
echo
./convert "42.0"
echo
echo
echo "./convert nan"
echo
./convert "nan"
echo
echo
echo "./convert nanf"
echo
./convert "nanf"
echo
echo
echo "./convert inff"
echo
./convert "inff"
echo
echo
echo "./convert -inff"
echo
./convert "-inff"
echo
echo
echo "./convert -42.0f"
echo
./convert "-42.0f"
echo
echo
echo "./convert -42.0"
echo
./convert "-42.0"
echo
echo
echo "./convert 2147483647"
echo
./convert "2147483647"
echo
echo
echo "./convert 2147483649."
echo
./convert "2147483649."
