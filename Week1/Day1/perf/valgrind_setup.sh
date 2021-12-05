#!/bin/bash

if ! mkdir -p $HOME/valgrind; then
    echo "mkdir failed"
    fi
fi

if ! curl -o valgrind-3.18.1.tar.bz2 https://sourceware.org/pub/valgrind/valgrind-3.18.1.tar.bz2; then
    echo "Failed to download valgrind"
    exit 1
fi

if ! bzip2 -d valgrind-3.18.1.tar.bz2; then
    echo "Failed to decompress valgrind"
    exit 1
fi

if ! tar xvf valgrind-3.18.1.tar; then
    echo "Failed to untar valgrind"
    exit 1
fi

cd valgrind-3.18.1

if ! ./configure --prefix=$HOME/valgrind; then
    echo "Failed to configure valgrind"
    exit 1
fi

if ! make; then
    echo "make failed"
    exit 1
fi

if ! make install; then
    echo "make install failed"
    exit 1
fi

echo "You will need to update your .profile env!"
echo "Add the following lines to your profile"

set -x
export VALGRIND=$HOME/valgrind
export PATH="$VALGRIND/bin:$PATH"
export VALGRIND_LIB=$VALGRIND/libexec/valgrind

echo "Then to test valgrind you can just run:"

if ! valgrind ls -l; then
    echo "valgrind failed"
    exit 1
fi

echo "Function profiling"

if ! valgrind --tool=callgrind ./stl_perf; then
    echo "valgrind call failed"
    exit 1
fi

outfile=`ls -1 callgrind.out.*`
echo "Generated output file $outfile"

if ! callgrind_annotate $outfile; then
    echo "calgrind_annotate failed"
    exit 1
fi

echo "You can now install qcachegrind and visualize the $outfile"
set +x

exit 0
