#!/bin/bash

# Define the list of submodule paths here
SUBMODULES=(
    "lib/DCMotor"
    "lib/Car"
    "lib/IRSensor"
)

for SUBMODULE_PATH in "${SUBMODULES[@]}"
do
    echo "Removing submodule: $SUBMODULE_PATH"

    # Remove from .gitmodules if it exists
    if git config -f .gitmodules --get "submodule.$SUBMODULE_PATH.path" > /dev/null; then
        git config -f .gitmodules --remove-section "submodule.$SUBMODULE_PATH"
        echo "Removed from .gitmodules"
    fi

    # Remove from .git/config if it exists
    if git config --get "submodule.$SUBMODULE_PATH.path" > /dev/null; then
        git config --remove-section "submodule.$SUBMODULE_PATH"
        echo "Removed from .git/config"
    fi

    # Deinitialize submodule if it's initialized
    git submodule deinit -f "$SUBMODULE_PATH" 2>/dev/null

    # Remove the submodule directory from the index
    git rm -f "$SUBMODULE_PATH"

    # Delete cached submodule from .git/modules
    if [ -d ".git/modules/$SUBMODULE_PATH" ]; then
        rm -rf ".git/modules/$SUBMODULE_PATH"
        echo "Removed cached data from .git/modules"
    fi

    echo "Submodule '$SUBMODULE_PATH' removed."
    echo "-------------------------------------------"
done

# Commit the changes
git commit -m "Remove submodules: ${SUBMODULES[*]}"

echo "All specified submodules have been removed and committed."
