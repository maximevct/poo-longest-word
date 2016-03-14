#!/bin/sh

echo "1\n$1\n2\n0\n" > params
./longest_word dataset/dictionary.txt < params
