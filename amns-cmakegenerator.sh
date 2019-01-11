# takes care of most of cmake given sane folder names
# if youre new to shell scripting
# FIGURE OUT HOW TO ADD THIS FILE TO YOUR $PATH 
# otherwise, copy and paste this script into literally every module folder

CMAKE_VERSION="3.13.2"
DIRNAME=`basename "$PWD"`

# automatically say yes to making intermediary file
FORCE='false'
if [ "$1" == "-f" ]; then
    FORCE='true'
fi




printf "============================================================
Hey! Its the amaneshi module cmakelists updater shell script
making cmake more usable. use me to update files in a module
============================================================\n
CMake Version set to $CMAKE_VERSION\n"

if [ -d "Public" ] && [ -d "Private" ]; then

    printf "Bottom level module (Public and Private folder) detected\n"
    CPPLIST=`ls -1 Private/*.cpp | sed 's/^\(.*\)$/    \1/'`
    if [ "$CPPLIST" != "" ]; then
        printf "Fetching .cpp files from ./Private\n
    Found the following files
    =========================
$CPPLIST\n\n"
    else 
        printf "No .cpp files found in ./Private\n"
    fi

    if [ -e "CMakeLists.txt" ]; then
        printf "Updating CMakeLists.txt\n"
    else
        printf "Generating CMakeLists.txt\n"
    fi
    echo "cmake_minimum_required(VERSION $CMAKE_VERSION)\n" > CMakeLists.txt
    if [ "$CPPLIST" != "" ]; then
        echo "add_library($DIRNAME\n$CPPLIST\n)\n" >> CMakeLists.txt
    else
        echo "add_library($DIRNAME)\n" >> CMakeLists.txt
    fi
    echo "target_include_directories($DIRNAME PRIVATE Private)" >> CMakeLists.txt
    echo "target_include_directories($DIRNAME PUBLIC Public)" >> CMakeLists.txt
    printf "All Finished!\n"

else

    printf "No Public/Private folder found!\n\n"
    INPUT=''
    if [ "$FORCE" == "false" ]; then
        printf "==========================================================
Generate a mid-level subdirectory-based CMakeLists? [y/n]
==========================================================\n"
        read INPUT
    fi
    if [ "$FORCE" == "true" ] || [[ $INPUT =~ ^(y|Y) ]]; then
        echo "cmake_minimum_required(VERSION $CMAKE_VERSION)\n" > CMakeLists.txt
        echo "add_library(Amaneshi_$DIRNAME)\n" >> CMakeLists.txt
        FOLDERLIST=`ls -1 -d */ | sed 's/\///' | sed 's/^\(.*\)$/    \1/'`
        printf "\nFound the following folders
===========================\n$FOLDERLIST\n\n"
        echo "add_subdirectory(\n$FOLDERLIST\n)\n" >> CMakeLists.txt
        echo "target_include_directories(Amaneshi_$DIRNAME\n$FOLDERLIST\n)" >> CMakeLists.txt
        printf "All Finished!\n"
    fi
fi
printf "Exiting...\n"
