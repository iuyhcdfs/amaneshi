# add me to path!
# while I do run the script in every folder, keep in mind
# that every folder that contains public and private is treated as a leaf in the tree
find . -type d -exec zsh -c "cd '{}' && amns-cmakegenerator.sh -f" \;
