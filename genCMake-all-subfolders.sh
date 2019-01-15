#is amns-cmakegenerator.sh in your $PATH?
find . -type d -exec bash -c "cd '{}' && amns-cmakegenerator.sh -f" \;
