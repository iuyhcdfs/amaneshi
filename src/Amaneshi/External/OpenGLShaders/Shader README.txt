https://stackoverflow.com/questions/20443560/how-to-practically-ship-glsl-shaders-with-your-c-software

basically, with c++11 raw string literals
you can type up your shader files with R"( stuff here including new lines )"

and then #include them exactly where you needed string literals.

this saves you the trouble of importing them during runtime.