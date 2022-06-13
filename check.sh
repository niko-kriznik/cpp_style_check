#!/bin/bash

OUT_DIR=".out"
ENTRY_SUFFIX=".o.json"

COMPILER_OPTIONS="--std=c++17
                  -Wall
                  -Wextra"
CLANG_TIDY_OPTIONS="--use-color 
                    --format-style=file
                    --header-filter=.* 
                    -p ${OUT_DIR}/compile_commands.json
                    *.cpp"

function compile_file() {
    local filename=$1
    local basename="$(basename $filename .cpp)"

    # TODO (Niko Kriznik - 13-Jun-2022):
    # Support other compilers
    clang++ ${COMPILER_OPTIONS} -MJ ${OUT_DIR}/${basename}${ENTRY_SUFFIX} ${filename} -o ${OUT_DIR}/${basename}
}

# Clean-up after the previous run
if [ -d "${OUT_DIR}" ]; then
    rm -r ${OUT_DIR}
fi
mkdir ${OUT_DIR}

# Compile the files and export the per-file compile commands
compile_file main.cpp

# Combine the individual compile commands' files into a single `compile_commands.json` file
sed -e '1s/^/[\n/' -e '$s/,$/\n]/' ${OUT_DIR}/*$ENTRY_SUFFIX >${OUT_DIR}/compile_commands.json

# Run checks
clang-tidy ${CLANG_TIDY_OPTIONS}
