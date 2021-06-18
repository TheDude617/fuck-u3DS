/*
	Hello World example made by Aurelio Mannara for libctru
	This code was modified for the last time on: 12/12/2014 21:00 UTC+1
*/

#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	gfxInitDefault();
        PrintConsole topScreen, bottomScreen;

	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, &topScreen);
        // Refer to https://libctru.devkitpro.org/console_8h.html
	//consoleInit(GFX_BOTTOM, &bottomScreen);

	//Move the cursor to row 15 and column 19 and then prints "Hello World!"
	//To move the cursor you have to print "\x1b[r;cH", where r and c are respectively
	//the row and column where you want your cursor to move
	//The top screen has 30 rows and 50 columns
	//The bottom screen has 30 rows and 40 columns
	
	consoleSelect(&topScreen);
	printf("\x1b[30;16HPress A to say Fuck you, Press B to say Bitch, Press Y to say Shut up, Press X to Clear the Screen, Press Start to exit.");

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();
		
		if (kDown & KEY_A) printf("\x1b[16;20HFuckYou");

		if (kDown & KEY_B) printf("\x1b[16;20HBitch");
		
		if (kDown & KEY_Y) printf("\x1b[16;20HShutUp");
		
		if (kDown & KEY_X) consoleClear(); // Clears the selected console

		if (kDown & KEY_START) break; //break in order to return to hbmenu
		
		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();
		
		//Wait for VBlank
		gspWaitForVBlank();
		
	}

	gfxExit();
	return 0;
}
