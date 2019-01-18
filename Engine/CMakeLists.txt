cmake_minimum_required(VERSION 3.13.2)

# engine gets linked to games in order to exist
add_library(amaneshi_engine Engine.cpp Engine.hpp)

# split config into a module to #ifndef hardware implementations
add_subdirectory(Config)
    target_link_libraries(amaneshi_engine config)

# Abstract useful code
add_subdirectory(Utility)
    target_link_libraries(amaneshi_engine file)
    
    target_link_libraries(amaneshi_engine math)
    
    target_link_libraries(amaneshi_engine time)

# Concrete hardware things
add_subdirectory(Core)
    target_link_libraries(amaneshi_engine input)
        target_link_libraries(input config)
    
    target_link_libraries(amaneshi_engine graphics)
        target_link_libraries(graphics config)
        target_link_libraries(graphics math)
    
    target_link_libraries(amaneshi_engine thread)

# Game elements
add_subdirectory(Game)
    target_link_libraries(amaneshi_engine camera)
        target_link_libraries(camera math)
    
    target_link_libraries(amaneshi_engine world)
        target_link_libraries(world math)
    
    target_link_libraries(amaneshi_engine object)
        target_link_libraries(object math)

# rant: suppose you wanted to split math into multiple libraries, 
# how do you do this cleanly without breaking everything
# you'll need to just add everything necessary really
# youll take one dependency and increase it
# not worrying about what to remove, just what to add. the debugger will tell you
# you're not splitting math into more than 20 modules i reckon so its not hurtful.
