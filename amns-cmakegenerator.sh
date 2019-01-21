
CMAKE_VERSION="3.13.2"
DIRNAME=`basename "$PWD"`
MODULE_NAME=`echo "$DIRNAME" | tr '[A-Z]' '[a-z]'`
IFS=$'\n'

if [ "$MODULE_NAME" == "amaneshi" ]; then
    printf "Refusing to overwrite root directory CMakeLists.txt.\n"
    exit 0
fi

if [ "$MODULE_NAME" == "engine" ]; then
    printf "Handling any folder NOT called engine, where the subdirectory include order matters\n"
    exit 0
fi

if [ "$MODULE_NAME" == "public" ] || [ "$MODULE_NAME" == "private" ]; then
    printf "Public and Private folders should only contain source code\n"
    exit 0
fi

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
else
    printf "==========================================================\n"
    printf "generating/overwriting cmakelists.txt in forced mode"
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
        CPP_LIST=`ls -1 Private/*.cpp`
        if [ "$CPP_LIST" != "" ]; then
            printf "Fetching .cpp files from ./Private\n\n"
            printf "Found the following sources\n"
            printf "=========================\n$CPP_LIST\n\n"
            CPP_LIST=`echo "$CPP_LIST" | sed 's/ /\\\\ /g' | sed 's/^\(.*\)$/    \1/'`
        else 
            printf "No .cpp files found in ./Private\n"
        fi
        echo "cmake_minimum_required(VERSION $CMAKE_VERSION)\n" > CMakeLists.txt
        if [ "$CPP_LIST" != "" ]; then
            echo "add_library($MODULE_NAME\n$CPP_LIST\n)\n" >> CMakeLists.txt
        else
            echo "add_library($MODULE_NAME)\n" >> CMakeLists.txt
        fi
        printf "Setting folders as target include directories\n"
        echo "target_include_directories($MODULE_NAME PRIVATE Private)" >> CMakeLists.txt
        echo "target_include_directories($MODULE_NAME PUBLIC Public)" >> CMakeLists.txt

    else # take care of folders that contain a group of common modules

        printf "No Public/Private folder: updating/adding all subdirectories\n\n"
        echo "cmake_minimum_required(VERSION $CMAKE_VERSION) \n" > CMakeLists.txt
        FOLDER_LIST=`ls -1 -d */ | sed 's/\///' | sed 's/ /\\\\ /g'`
        #MODULELIST=`echo "$FOLDER_LIST" | tr "[A-Z]" "[a-z]" | sed 's/^\(.*\)$/    \1/'`
        if [ "$FOLDER_LIST" != "" ]; then
            printf "Found the following folders\n"
            printf "===========================\n$FOLDER_LIST\n\n"
            for EACH_LINE in $FOLDER_LIST; do
                echo "add_subdirectory($EACH_LINE)" >> CMakeLists.txt
            done
        else
            printf "No folders at all! You accidentally ran amns-cmake-generator?\n"
        fi
    fi
    printf "All Finished!\n"
fi
printf "Exiting...\n"

