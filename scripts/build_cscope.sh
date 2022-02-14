#!/bin/bash

cd ../src
find . \( -name "*.cpp" -o -name "*.h" -o -name "Makefile" -o -name "*.sh" \) > cscope.files
