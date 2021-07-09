#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	gfxInitDefault();
		PrintConsole topScreen, bottomScreen;

	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	
	consoleSelect(&bottomScreen);
	
	printf("\x1b[1;16HPress A to say Fuck you, Press B to say Bitch, Press Y to say Shut up, Press X to Clear the Screen, Press Start to exit.");
	
	consoleSelect(&topScreen);
	while (aptMainLoop())
	{
		hidScanInput();

		u32 kDown = hidKeysDown();
		
		
		if (kDown & KEY_A) printf("\x1b[16;20HFuck You                      ");
		

		if (kDown & KEY_B) printf("\x1b[16;20HBitch                         ");

		
		if (kDown & KEY_Y) printf("\x1b[16;20HShut Up                       ");
		
		
		if (kDown & KEY_X) consoleClear(                            );
		
		
		if (kDown & KEY_SELECT) printf("\x1b[16;20HGlazy's Anti Aging Cream ");
		
		
		if (kDown & KEY_START) break;
		
		gfxFlushBuffers();
		gfxSwapBuffers();
		
		gspWaitForVBlank();
	}
	
	gfxExit();
	return 0;
}
