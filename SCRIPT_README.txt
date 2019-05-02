did you forget? heres what you do:

scripts at root should be in path
then run genCMake-engine.sh in ./Engine.

-------------------------------------------------------

all scripts are just to auto-generate appropriate CMakeLists.txt files

scripts located root work when in your $PATH
one of the scripts assume you have zsh.

in ./Engine, genCMake-engine.sh just runs these files and fetches every module. don't add that to $PATH
