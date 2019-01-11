# takes care of most of cmake given sane folder names
# if youre new to shell scripting
# FIGURE OUT HOW TO ADD THIS FILE TO YOUR $PATH 
# otherwise, copy and paste this script into literally every module folder

CMAKE_VERSION="3.13.2"
DIRNAME=`basename "$PWD"`
MODULENAME=`echo "$DIRNAME" | tr '[A-Z]' '[a-z]'`
# automatically say yes to making intermediary file
FORCE='false'
if [ "$1" == "-f" ]; then
    FORCE='true'
fi

INPUT=''
if [ "$FORCE" == "false" ]; then
    printf "==========================================================\n"
    printf "This script overwrites CMakeLists.txt, is that okay? [y/Y]\n"
    printf "CMake Version set to generate: $CMAKE_VERSION\n"
    printf "==========================================================\n"
    read INPUT
fi

if [ "$FORCE" == "true" ] || [[ $INPUT =~ ^(y|Y) ]]; then

    if [ -e "CMakeLists.txt" ]; then
        printf "\nUpdating CMakeLists.txt\n"
    else
        printf "\nGenerating CMakeLists.txt\n"
    fi

    # take care of bottom level folders with isolated modules
    if [ -d "Public" ] && [ -d "Private" ]; then

        printf "Bottom level module (Public and Private folder) in current directory\n"
        CPPLIST=`ls -1 Private/*.cpp | sed 's/^\(.*\)$/    \1/'`
        if [ "$CPPLIST" != "" ]; then
            printf "Fetching .cpp files from ./Private\n\n"
            printf "    Found the following sources\n"
            printf "    =========================\n$CPPLIST\n\n"
        else 
            printf "No .cpp files found in ./Private\n"
        fi
        echo "cmake_minimum_required(VERSION $CMAKE_VERSION)\n" > CMakeLists.txt
        if [ "$CPPLIST" != "" ]; then
            echo "add_library($MODULENAME\n$CPPLIST\n)\n" >> CMakeLists.txt
        else
            echo "add_library($MODULENAME)\n" >> CMakeLists.txt
        fi
        printf "Setting folders as target include directories\n"
        echo "target_include_directories($MODULENAME PRIVATE Private)" >> CMakeLists.txt
        echo "target_include_directories($MODULENAME PUBLIC Public)" >> CMakeLists.txt

    else # take care of folders that contain a group of common modules

        printf "No Public/Private folder in current directory\n\n"
        echo "cmake_minimum_required(VERSION $CMAKE_VERSION)\n" > CMakeLists.txt
        echo "add_library(amaneshi_$MODULENAME)\n" >> CMakeLists.txt
        FOLDERLIST=`ls -1 -d */ | sed 's/\///' | sed 's/^\(.*\)$/    \1/'`
        MODULELIST=`echo "$FOLDERLIST" | tr "[A-Z]" "[a-z]"`
        if [ "$FOLDERLIST" != "" ]; then
            printf "    Found the following folders\n"
            printf "    ===========================\n$FOLDERLIST\n\n"
            echo "add_subdirectory(\n$FOLDERLIST\n)\n" >> CMakeLists.txt
            echo "target_include_directories(amaneshi_$MODULENAME\n$MODULELIST\n)" >> CMakeLists.txt
        else
            printf "No folders at all! Accidentally ran amns-cmake-generator?"
        fi
    fi
    printf "All Finished!\n"
fi
printf "Exiting...\n"

