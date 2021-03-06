# Overview
Setup a developer environment. This includes the following. You must checkin all your code you
develop in the day folder. This includes, Dockerfile, scripts, source code. Credit will be given
to how you organize your code also.

## Download docker

1. You need to use google search and figure out how to download docker for your PC.

## Create a dockerfile

1. Make sure you have a complete development environment including git, c++, gdb and all related
developer tools. Your c++ compiler should be clang++ c++17 at the minimum. Make sure you use a
standard Linux environment. Centos 8 or RHEL 8 is recommended. Ubuntu can be used in the worst case
but is not recommended.

2. Choose an editor for your program edits. We recommend vim, but if you prefer emacs or nano or sublime, or
anything else you can include this in your docker. You are encouraged to use cscope.  Your exercise 
at the minimum is to install cscope and use it with your command line editor

3. Your source directory can be mounted into your docker container, if you would like to save your changes when the container gets destroyed.

4. Install "Development Tools", gdb, zip, curl, htop, iftop, iotop, cscope, tree.

5. Set up a standard ".profile" or ".bashrc" that is included with your Dockerfile, so you have a 
standardized environment. Upon starting the docker container, your profile should be automatically
sourced.

## Create a docker image

Write a shell script that creates a docker image.

## Spin up a docker container

Write a shell script that spins up a docker container.

## Login to the container

Test if all functions are working. This includes sourcing your profile, clang++, command line editor,
gdb and tree command. 

## Write a short C++ program that prints "Hello World!?"

Write a C++ program, be as creative as possible.

## Compile it using clang++

## Execute the C++ program.

Verify the output.
