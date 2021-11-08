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
    // off = 0
    @off
    M = 0
    (LOOP)
        // if (off == 8192) goto STOP
        @8192
        D = A
        @off
        D = M - D
        @STOP
        D;JEQ
        // write 16 pixels black (@SCREEN+@off)
        @off
        D = M
        @SCREEN
        A = A + D
        D = A
        // R0 = @SCREEN+@off
        @R0
        M = D
        A = M
        // off++
        @off
        M = M + 1
        // goto LOOP
        @LOOP
        0;JMP
    (STOP)
        // check KBD
        @LOOPKBD
        0;JMP