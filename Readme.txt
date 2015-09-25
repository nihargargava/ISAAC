Accompanying this readme file is a CodeBlocks project containing a CodeBlocks Project file (CBP).
Forget about it if CodeBlocks is not available.

main.cpp contains the main function. The source files are in the src folder. Headers are in the include folder.
But this is not all that is needed to be able to compile it.

To be able to directly run the exe accompanying, you need to arrange for a freeglut.dll file.
It can be found in the freeglut package accompanying this readme.

Also, to compile the code, freeglut has to be installed. Accompanying is freeglut for MinGW in windows.
Read the readme in that to install it.

Comment out the #include<windows.h> in everything.h to run in linux (This will hopefully work as no windows specefic commands are used).

Also, ISAAC is a non-copy-protected freewhere. You may freely use any part of the code wherever you like.
But please try to give me some credit. Or else I will find you.

Decrease the value of dt in or incease the value of timer in everything.h to suit your computers speed (reducing timer increases resolution of time, and increasing dt changes length of the resolved time unit). Draw some objects or use demo version to run preset objects.

Have fun playing with physics.



