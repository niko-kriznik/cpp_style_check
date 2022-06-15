#!/bin/bash

COMMAND=$1

if [ -z "$COMMAND" ]; then
    # No argument supplied. Default to "run" command.
    pre-commit run --all-files
elif [[ "$COMMAND" == "install" ]]; then
    # Install the git hook scripts
    pre-commit install
else
    echo "ERROR: Invalid script argument!"
    exit -1
fi
