i thought this hacky version was cool okay

if a dev wants to experiment with shaders, there are online glsl sandboxes

this is less error prone since the compiler will see us mis-spell a function
also faster since the file is "read" during compile time.
============================
check out helloworld.fs/vs/hpp

the hpp will always have a function that returns the shader name

the way i'm bringing fs and vs files into the project is the 2nd top response here:
https://stackoverflow.com/questions/20443560/how-to-practically-ship-glsl-shaders-with-your-c-software

basically, with c++11 raw string literals
you can type up your shader files with R"( stuff here including new lines )"

and then #include them exactly where you needed string literals.

this saves you the trouble of importing them during runtime.