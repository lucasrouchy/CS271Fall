// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

(LOOPKBD)
    // initialization R2 = 0
    @R2
    M = 0
    // read keyboard
    @KBD
    D = M
    // R1 = *(@KBD)
    @R1
    M = D
    // R2 = -1, if KBD != 0
    @SKIP
    D;JEQ
    @R2
    M = -1
(SKIP)