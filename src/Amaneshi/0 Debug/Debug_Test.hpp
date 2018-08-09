#pragma once

// how to test a game engine

// things need to run
// edge cases need to be demonstrated

// things need to be drawn, non-human regression would be nice in that sense


// a big thing to test, efficiency
// 
// we need to ensure that we have the same conditions of processing power etc.
// just having a nice fine fpscounter is good for big changes
// but you should also measure how things scale to large worlds and whatnot
// 

// should behaviour be defined when you're taking longer than a frame to draw a frame?
// then you're simply going at whatever speed you CAN go at
// you could just make sure personally, is there a cheap test that exposes if it wasn't taken care of?

// THE BIG things to test: physics and rendering
// we can split them into a ton of little cases and scenarios

