#!/bin/bash

# Use this script as a reference. It's really not tested well!

################################################
# Before executing set the following variables!
################################################

# You need to have your $USER set to a start directory where you want to install all protobuf code
# export PROTO_HOME=<start-dir>

if [[ -z "${USER}" ]]; then
    export PROTO_HOME=/defaultuser
else
    export PROTO_HOME=/${USER}
fi

export PROTOBUF_HOME=${PROTO_HOME}/protobuf

# Set this to true first time setup, when protobuf has not been clone from git repo
initflag=false

# Set this to true for fresh recompile if you want to simply rebuild everything from scratch
cleanflag=false

# You will need to decide upfront what version of protobuf you need
EXPECTED_PROTOC_VERSION="libprotoc 3.19.1"
EXPECTED_PROTOBUF_VERSION="3019001"
################################################
################################################



##########################################
# Nothing needs to change below this LINE.
##########################################

#export PROTOBUF_HOME=${PROTO_HOME}/assign/smoothstack/protobuf
export PROTO_PREFIX=${PROTO_HOME}/usr
export PKG_CONFIG_PATH=${PROTO_PREFIX}/lib/pkgconfig
export PATH=${PROTO_PREFIX}/bin:${PATH}
export LD_LIBRARY_PATH=${PROTO_PREFIX}/lib:${LD_LIBRARY_PATH}

if [ "$initflag" = true ]; then
    if ! mkdir -p ${PROTOBUF_HOME}; then
        echo "Failed to create ${PROTOBUF_HOME}"
        exit 1
    fi
    if ! mkdir -p ${PROTO_PREFIX}; then
        echo "Failed to create ${PROTO_PREFIX}"
        exit 1
    fi
    cd ${PROTOBUF_HOME}
    if [ ! -d "protobuf" ]; then
        if ! git clone https://github.com/protocolbuffers/protobuf.git; then
            echo "Failed to clone protobuf.git"
            exit 1
        fi
        if [ ! -d "protobuf" ]; then
            echo "Looks like protobuf directory was not cloned."
            exit 1
        fi
        cd protobuf
        if ! git submodule update --init --recursive; then
            echo "Could not update git submodule"
            exit 1
        fi
else
    echo "Assuming protobuf is already checked out."
fi

if [ "$cleanflag" = true ]; then
        if ! ./autogen.sh; then
            echo "Failed to run autogen.sh"
            exit 1
        fi
        if ! make clean; then
            echo "Could not make clean"
            exit 1
        fi
        if ! ./configure --prefix=${PROTO_PREFIX}; then
            echo "Failed to configure"
            exit 1
        fi
        if ! make; then
            echo "Failed to make"
            exit 1
        fi
        # We do not check errors for this one as some tests fail, but proto still works
        make check
        if ! make install; then
            echo "Failed to make install"
            exit 1
        fi
        if ! ldconfig; then
            echo "Could not ldconfig"
            exit 1
        fi
        echo "Was able to build protobufs successfully"
    fi
else
    echo "Assuming protobufs is already built."
fi

if [ ! -d "${PROTOBUFS_HOME}" ] || [ ! -d "${PROTO_PREFIX}" ] || [ ! -d "${PKG_CONFIG_PATH}" ]; then
    echo "Either of PROTOBUFS_HOME:${PROTOBUFS_HOME} or PROTO_PREFIX:${PROTO_PREFIX} or PKG_CONFIG_PATH:${PKG_CONFIG_PATH} directories do not exist!"
    exit 1
fi

pc=`pkg-config --cflags --libs protobuf`
if [ "$pc" = "-I${PROTO_PREFIX}/include -L${PROTO_PREFIX}/lib -lprotobuf" ]; then
    echo "config $pc looks correct!"
else
    echo "config $pc looks bad!"
    exit 1
fi

echo "Make sure the following lines are added to your .profile" 
echo
echo "#########################################################"
echo "export PKG_CONFIG_PATH=${PROTO_PREFIX}/lib/pkgconfig"
echo "export PATH=${PROTO_PREFIX}/bin:${PATH}"
echo "export LD_LIBRARY_PATH=${PROTO_PREFIX}:${LD_LIBRARY_PATH}"
echo "#########################################################"
echo

echo "Now will build a demo proto file"

if [ ! -f `which protoc` ]; then
    echo "Could not find a protoc compiler"
    exit 1
fi

pcversion=`protoc --version`
if [ "$pcversion" = "${EXPECTED_PROTOC_VERSION}" ]; then
    echo "We have the expected protoc version."
else
    echo "We have unexpected protoc version!"
    exit 1
fi
pversion=`grep "define PROTOBUF_VERSION " ${PROTO_PREFIX}/include/google/protobuf/port_def.inc | awk '{print $3}'`
if [ "$pversion" = "${EXPECTED_PROTOBUF_VERSION}" ]; then
    echo "We have the expected protobuf version."
else
    echo "We have unexpected protobuf version!"
    exit 1
fi

export PROTO_DIR=${PROTO_HOME}/proto$$
if ! mkdir -p ${PROTO_DIR}; then
    echo "Could not create ${PROTO_DIR}"
    exit 1
else
    echo "Created ${PROTO_DIR} successfully."
fi

cd ${PROTO_DIR}

if ! git clone git@github.com:manoj-smoothstack/proto.git; then
    echo "Could not checkout proto templates"
    exit 1
fi

if ! cp ${PROTO_DIR}/proto/examples/person.proto .; then
    echo "Could not copy the proto template"
    exit 1 
fi

# Generate the stubs only after the above environment is set
if ! protoc -I=. --cpp_out=. person.proto; then
    echo "Could not build the proto stubs"
    exit 1
fi

# Use the stubs to generate the executables
if ! g++ -o person_read person_read.cpp person.pb.cc `pkg-config --cflags --libs protobuf`; then
    echo "Could not generate person reader"
    exit 1
fi
if ! g++ -o person_write person_write.cpp person.pb.cc `pkg-config --cflags --libs protobuf`; then
    echo "Could not generate person writer"
    exit 1
fi

# Create a person book
if ! ./person_write person_book; then
    echo "Could not generate demo person_book"
    exit 1
fi

# Read the person book
if ! ./person_read person_book; then
    echo "Could not read demo person_book"
    exit 1
fi

exit 0
