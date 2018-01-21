
* ----------------------------------------------------------------------------
 * "LICENCE BEERWARE" (Révision 42):
 * Red-J a créé ce fichier. Tant que vous conservez cet avertissement,
 * vous pouvez faire ce que vous voulez de ce truc. Si on se rencontre un jour et
 * que vous pensez que ce truc vaut le coup, vous pouvez me payer une bière en
 * retour.
   	__________           .___             ____.
   	\______   \ ____   __| _/            |    |
	|       _// __ \ / __ |   ______     |    |
	|    |   \  ___// /_/ |  /_____/ /\__|    |
	|____|_  /\___  >____ |          \________|
	       \/     \/     \/                    
 * ----------------------------------------------------------------------------

#include <psp2/kernel/processmgr.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <psp2/ctrl.h>
#include <psp2/io/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <libpng16/png.h>
#include <ogg/ogg.h> 
#include <zlib.h>
#include <vorbis/codec.h>
#include <string.h>
#include <psp2/io/dirent.h>
#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/modulemgr.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/sysmodule.h>
#include <psp2/io/stat.h>
#include <psp2/types.h>
#include <psp2/power.h>
#include <sys/stat.h>


/*char magik[] = {
	0xBE, 0xBA, 0xFE, 0xCA
};*/

int main(int argc, char *argv[])
{ 
	const int WIDTH = 960;
	const int HEIGHT = 544;  

	SDL_Init(SDL_INIT_EVERYTHING);  //initialisation SDL 
	
	IMG_Init(IMG_INIT_PNG);// initialisation SDL_IMAGE
	
 TTF_Init();// initialisation police d'écriture
 
TTF_Font * font = TTF_OpenFont("app0:sce_sys/ttf/PS3.ttf", 25); //chemin de la police  et taile 25
TTF_Font * font2 = TTF_OpenFont("app0:sce_sys/ttf/PS3.ttf", 17);//chemin de la police  et taile 17
 SDL_Color colorwhite = { 255, 255, 255 };  //couleur de texte blanc
 SDL_Color colorred = { 255, 0, 0 };//couleur de texte rouge
//Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
Mix_OpenAudio(22050, AUDIO_S16SYS, 1, 1024);   //on ouvre le canal de la musique sur une fréquence de 22050

    // Load audio files
    Mix_Music *backgroundSound = Mix_LoadMUS("app0:sce_sys/music/music.ogg");  //on charge une musique

    Mix_Music *backgroundSound2 = Mix_LoadMUS("app0:sce_sys/music/music2.ogg"); //on charge une seconde musique

Mix_VolumeMusic(MIX_MAX_VOLUME *20);  //on multiplie le volume de la musique par 20

    Mix_Chunk *Redj= Mix_LoadWAV("app0:sce_sys/music/sonredj.ogg"); // on charge un effet sonore
	
	Mix_Chunk *Touches= Mix_LoadWAV("app0:sce_sys/music/sontouche.ogg");// on charge un second effet sonore

//Mix_VolumeChunk(Touches, MIX_MAX_VOLUME/10);

	SDL_Window *screen = NULL;//on initialise l'écran

	SDL_Renderer *rendu = NULL;//on initialise le rendu
    SDL_Surface *surfaceintro = NULL; //on initialise les surfaces à 0
	SDL_Surface *surface = NULL;
	SDL_Surface *surfaceb1 = NULL;
    SDL_Surface *surfaceb2 = NULL;
    SDL_Surface *surfaceb3 = NULL;
    SDL_Surface *surfaceb4 = NULL;
	SDL_Surface *surfacebs = NULL;

    SDL_Texture *textureintro = NULL;// on initialise les textures à 0
	SDL_Texture *texture = NULL;
	SDL_Texture *texture2 = NULL;
	SDL_Texture *texture3 = NULL;
	SDL_Texture *texture4 = NULL;
	SDL_Texture *texture5 = NULL;
	SDL_Texture *texture6 = NULL;



	screen=SDL_CreateWindow("-=PARADOX=- SDL TEST RED-J",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);//creation fenetre

	rendu=SDL_CreateRenderer(screen, -1,SDL_RENDERER_SOFTWARE);//création renderer   

	surfaceintro = IMG_Load("app0:sce_sys/img/intro.png"); //on choisi l'image de la surface d'intro

	textureintro = SDL_CreateTextureFromSurface(rendu, surfaceintro);// on crée une texture à partir de la surface d'intro
    SDL_RenderCopy(rendu, textureintro, NULL,NULL);// on affiche la texture sur le rendu 
    Mix_PlayChannel(-1, Redj, 0); // on joue l'effet sonore Redj
    SDL_RenderPresent(rendu);// on met a jour l'écran 
    SDL_Delay(2000);// on attends 2s
	Mix_FreeChunk(Redj);// on libère l'effet sonore redj

	surface = IMG_Load("app0:sce_sys/img/menu.png"); //on choisi les images 
	
	surfaceb1 = IMG_Load("app0:sce_sys/img/b1.png");

	surfaceb2 = IMG_Load("app0:sce_sys/img/b2.png");

	surfaceb3 = IMG_Load("app0:sce_sys/img/b3.png");

	surfaceb4 = IMG_Load("app0:sce_sys/img/b4.png");
	
	surfacebs = IMG_Load("app0:sce_sys/img/bs.png");

	SDL_Surface * surfacetxt1 = TTF_RenderText_Solid(font,"Universal Menu Vita", colorwhite); // on défini le texte du titre en blanc avec la 1ère police et sa taille

	SDL_Texture * texturetxt1 = SDL_CreateTextureFromSurface(rendu, surfacetxt1); //on crée la texture du texte du titre a partir de la surface
    int texX1=212;//position 
    int texY1=10;// position
	int texW1 = 0;
	int texH1 = 0;//horizon
	SDL_QueryTexture(texturetxt1, NULL, NULL, &texW1, &texH1);//determine la taille du texte
	SDL_Rect dstrect1 = { texX1, texY1, texW1, texH1 };//cree un rectangle où sera le texte
						//h	//vertical
						
    SDL_Surface * surfacetxtb1 = TTF_RenderText_Solid(font2,"Rebuild Database", colorwhite);

	SDL_Texture * texturetxtb1 = SDL_CreateTextureFromSurface(rendu, surfacetxtb1);

	int texWb1 = 0;
	int texHb1 = 0;
	SDL_QueryTexture(texturetxtb1, NULL, NULL, &texWb1, &texHb1);

	SDL_Rect dstrectb1 = { 157, 467, texWb1, texHb1 };
						//h	//vertical

		SDL_Surface * surfacetxtb2 = TTF_RenderText_Solid(font2,"Quitter", colorwhite);

	SDL_Texture * texturetxtb2 = SDL_CreateTextureFromSurface(rendu, surfacetxtb2);

	int texWb2 = 0;
	int texHb2 = 0;
	SDL_QueryTexture(texturetxtb2, NULL, NULL, &texWb2, &texHb2);

	SDL_Rect dstrectb2 = { 197, 507, texWb2, texHb2 };
						//h	//vertical

		SDL_Surface * surfacetxtb3 = TTF_RenderText_Solid(font2,"Eteindre", colorwhite);

	SDL_Texture * texturetxtb3 = SDL_CreateTextureFromSurface(rendu, surfacetxtb3);

	int texWb3 = 0;
	int texHb3 = 0;
	SDL_QueryTexture(texturetxtb3, NULL, NULL, &texWb3, &texHb3);

	SDL_Rect dstrectb3 = { 753, 467, texWb3, texHb3 };
						//h	//vertical

	SDL_Surface * surfacetxtb4 = TTF_RenderText_Solid(font2,"Veille", colorwhite);

	SDL_Texture * texturetxtb4 = SDL_CreateTextureFromSurface(rendu, surfacetxtb4);

	int texWb4 = 0;
	int texHb4 = 0;
	SDL_QueryTexture(texturetxtb4, NULL, NULL, &texWb4, &texHb4);

	SDL_Rect dstrectb4 = { 713, 507, texWb4, texHb4 };
						//h	//vertical
						
	SDL_Surface * surfacetxtbs = TTF_RenderText_Solid(font2,"Son", colorwhite);

	SDL_Texture * texturetxtbs = SDL_CreateTextureFromSurface(rendu, surfacetxtbs);

	int texWbs = 0;
	int texHbs = 0;
	SDL_QueryTexture(texturetxtbs, NULL, NULL, &texWbs, &texHbs);

	SDL_Rect dstrectbs = { 550, 507, texWbs, texHbs };
						//h	//vertical

						
						
						
	texture = SDL_CreateTextureFromSurface(rendu, surface);//test

	SDL_RenderCopy(rendu, texture, NULL,NULL);

	SDL_RenderPresent(rendu);

	SceCtrlData pad; //pad
	sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);//pad


	texture2 = SDL_CreateTextureFromSurface(rendu, surfaceb1);//test

SDL_Rect SrcR2;
SDL_Rect DestR2;

  SrcR2.x = 0;
  SrcR2.y = 0;
  SrcR2.w = 50;
  SrcR2.h = 40;

  DestR2.x = 132 -20;//960 / 4 - 40 / 2;    horizon  157
  DestR2.y = 476 -25;//544 / 4 - 50 / 2;   hauteur   467
  DestR2.w = 50;
  DestR2.h = 40;

  texture3 = SDL_CreateTextureFromSurface(rendu, surfaceb2);//test

SDL_Rect SrcR3;
SDL_Rect DestR3;

  SrcR3.x = 0;
  SrcR3.y = 0;
  SrcR3.w = 50;
  SrcR3.h = 40;

  DestR3.x = 172 -20;//960 / 4 - 40 / 2;    horizon
  DestR3.y = 516 -25;//544 / 4 - 50 / 2;   hauteur
  DestR3.w = 50;
  DestR3.h = 40;

  texture4 = SDL_CreateTextureFromSurface(rendu, surfaceb3);//test

SDL_Rect SrcR4;
SDL_Rect DestR4;

  SrcR4.x = 0;
  SrcR4.y = 0;
  SrcR4.w = 50;
  SrcR4.h = 40;

  DestR4.x = 728 -20;//960 / 4 - 40 / 2;    horizon
  DestR4.y = 476 -25;//544 / 4 - 50 / 2;   hauteur
  DestR4.w = 50;
  DestR4.h = 40;

texture5 = SDL_CreateTextureFromSurface(rendu, surfaceb4);//test

SDL_Rect SrcR5;
SDL_Rect DestR5;

  SrcR5.x = 0;
  SrcR5.y = 0;
  SrcR5.w = 50;
  SrcR5.h = 40;

  DestR5.x = 688 -20;//960 / 4 - 40 / 2;    horizon
  DestR5.y = 516 -25;//544 / 4 - 50 / 2;   hauteur
  DestR5.w = 50;
  DestR5.h = 40;
  
texture6 = SDL_CreateTextureFromSurface(rendu, surfacebs);//test

SDL_Rect SrcR6;
SDL_Rect DestR6;

  SrcR6.x = 0;
  SrcR6.y = 0;
  SrcR6.w = 59;
  SrcR6.h = 39;

  DestR6.x = 489;//960 / 4 - 40 / 2;    horizon
  DestR6.y = 496;//544 / 4 - 50 / 2;   hauteur
  DestR6.w = 59;
  DestR6.h = 39;



SDL_RenderCopy(rendu, texture2, &SrcR2, &DestR2);
SDL_RenderCopy(rendu, texture3, &SrcR3, &DestR3);
SDL_RenderCopy(rendu, texture4, &SrcR4, &DestR4);
SDL_RenderCopy(rendu, texture5, &SrcR5, &DestR5);
SDL_RenderCopy(rendu, texture6, &SrcR6, &DestR6);
SDL_RenderCopy(rendu, texturetxt1, NULL, &dstrect1);
SDL_RenderCopy(rendu, texturetxtb1, NULL, &dstrectb1);
SDL_RenderCopy(rendu, texturetxtb2, NULL, &dstrectb2);
SDL_RenderCopy(rendu, texturetxtb3, NULL, &dstrectb3);
SDL_RenderCopy(rendu, texturetxtb4, NULL, &dstrectb4);
SDL_RenderCopy(rendu, texturetxtbs, NULL, &dstrectbs);
SDL_RenderPresent(rendu);

    // Start the background music
    Mix_PlayMusic(backgroundSound, -1);

  
  //  SDL_Event event;


  while (1) {
sceCtrlPeekBufferPositive(0, &pad, 1);



/*if (pad.buttons & SCE_CTRL_VOLDOWN)
                {
                    Mix_PlayChannel(-1, Touches, 0);
                    Mix_VolumeMusic(MIX_MAX_VOLUME /2);
                }
if (pad.buttons & SCE_CTRL_VOLUP)
                {
                    Mix_PlayChannel(-1, Touches, 0);
                    Mix_VolumeMusic(MIX_MAX_VOLUME * 2);
                 

                }*/
if (pad.buttons & SCE_CTRL_SELECT)
                {
					Mix_PlayChannel(-1, Touches, 0);
					if(Mix_PausedMusic()!=1)
					{Mix_PauseMusic();}
					else{Mix_ResumeMusic();}

                }
if (pad.buttons & SCE_CTRL_RIGHT)
                {

                    Mix_PlayMusic(backgroundSound2, -1);

                }
if (pad.buttons & SCE_CTRL_LEFT)
                {

                    Mix_PlayMusic(backgroundSound, -1);

                }
		
				
if (pad.buttons & SCE_CTRL_CROSS) 	
	{
	
				sceIoRemove("ur0:shell/db/app.db");
		
				Mix_PlayChannel(-1, Touches, 0);

                SDL_Surface * surfacetxta1 = TTF_RenderText_Solid(font2,"Rebuild database after reboot", colorred);
                SDL_Texture * texturetxta1 = SDL_CreateTextureFromSurface(rendu, surfacetxta1);

                int texWa1 = 0;
                int texHa1 = 0;
                SDL_QueryTexture(texturetxta1, NULL, NULL, &texWa1, &texHa1);
                SDL_Rect dstrecta1 = { 212, 370, texWa1, texHa1 };
                SDL_RenderCopy(rendu, texturetxta1, NULL, &dstrecta1);
                SDL_RenderPresent(rendu);
                //Mix_HaltMusic();

                SDL_DestroyTexture(texturetxta1);
                SDL_FreeSurface(surfacetxta1);
                SDL_Delay(4000);
               // goto quit;

		scePowerRequestColdReset();
		exit(0);
	break;
	}
if (pad.buttons & SCE_CTRL_CIRCLE) 	
	{
				Mix_PlayChannel(-1, Touches, 0);
                // Press "2" and play laser effect
                SDL_Surface * surfacetxta2 = TTF_RenderText_Solid(font2,"Fermeture de l'application", colorred);
				SDL_Texture * texturetxta2 = SDL_CreateTextureFromSurface(rendu, surfacetxta2);

		int texWa2 = 0;
		int texHa2 = 0;
		SDL_QueryTexture(texturetxta2, NULL, NULL, &texWa2, &texHa2);
		SDL_Rect dstrecta2 = { 212, 370, texWa2, texHa2 };
		SDL_RenderCopy(rendu, texturetxta2, NULL, &dstrecta2);
		SDL_RenderPresent(rendu);

		SDL_DestroyTexture(texturetxta2);
		SDL_FreeSurface(surfacetxta2);
		SDL_Delay(4000);
		 sceKernelExitProcess(0);
		//goto quit;
		
	break;
	}
if (pad.buttons & SCE_CTRL_SQUARE) 	
	{
		
		Mix_PlayChannel(-1, Touches, 0);


		SDL_Surface * surfacetxta3 = TTF_RenderText_Solid(font2,"Extinction de la console", colorred);
		SDL_Texture * texturetxta3 = SDL_CreateTextureFromSurface(rendu, surfacetxta3);

		int texWa3 = 0;
		int texHa3 = 0;
		SDL_QueryTexture(texturetxta3, NULL, NULL, &texWa3, &texHa3);
		SDL_Rect dstrecta3 = { 212, 370, texWa3, texHa3 };
		SDL_RenderCopy(rendu, texturetxta3, NULL, &dstrecta3);
		SDL_RenderPresent(rendu);
		SDL_DestroyTexture(texturetxta3);
		SDL_FreeSurface(surfacetxta3);
		SDL_Delay(4000);
		
		scePowerRequestStandby();
		//goto quit;
	
	break;
	}
	if (pad.buttons & SCE_CTRL_TRIANGLE) 	
	{		
		Mix_PlayChannel(-1, Touches, 0);
        SDL_Surface * surfacetxta4 = TTF_RenderText_Solid(font2,"mise en veille de la console", colorred);
		SDL_Texture * texturetxta4 = SDL_CreateTextureFromSurface(rendu, surfacetxta4);

		int texWa4 = 0;
		int texHa4 = 0;
		SDL_QueryTexture(texturetxta4, NULL, NULL, &texWa4, &texHa4);
		SDL_Rect dstrecta4 = { 212, 370, texWa4, texHa4 };
		SDL_RenderCopy(rendu, texturetxta4, NULL, &dstrecta4);
		SDL_RenderPresent(rendu);

		SDL_DestroyTexture(texturetxta4);
		SDL_FreeSurface(surfacetxta4);

		SDL_Delay(4000);
		//goto quit;
		scePowerRequestSuspend();
	break;
	}
		}

	SDL_DestroyRenderer(rendu);//ok
	SDL_DestroyWindow(screen); //ok
/*	SDL_FreeSurface(background1);///
	SDL_FreeSurface(b1);
	SDL_FreeSurface(b2);
	SDL_FreeSurface(b3);
	SDL_FreeSurface(b4);
	SDL_DestroyTexture(texturebg1);
	SDL_DestroyTexture(textureb1);
	SDL_DestroyTexture(textureb2);
	SDL_DestroyTexture(textureb3);
	SDL_DestroyTexture(textureb4);
	SDL_DestroyTexture(texturetxt1);
	SDL_DestroyTexture(texturetxtb1);
	SDL_DestroyTexture(texturetxtb2);
	SDL_DestroyTexture(texturetxtb3);
	SDL_DestroyTexture(texturetxtb4);

	SDL_FreeSurface(surfacetxt1);
	SDL_FreeSurface(surfacetxtb1);
	SDL_FreeSurface(surfacetxtb2);
	SDL_FreeSurface(surfacetxtb3);
	SDL_FreeSurface(surfacetxtb4);
*/
	TTF_CloseFont(font);
	TTF_CloseFont(font2);
	Mix_FreeMusic(backgroundSound);
	Mix_FreeMusic(backgroundSound2);
    Mix_FreeChunk(Touches);
    Mix_CloseAudio();

  IMG_Quit();
   TTF_Quit();

 SDL_Quit();
 sceKernelExitProcess(0);
  
 return 0;
}

/*	SCE_CTRL_SELECT      = 0x00000001,            //!< Select button.
	SCE_CTRL_L3          = 0x00000002,            //!< L3 button.
	SCE_CTRL_R3          = 0x00000004,            //!< R3 button.
	SCE_CTRL_START       = 0x00000008,            //!< Start button.
	SCE_CTRL_UP          = 0x00000010,            //!< Up D-Pad button.
	SCE_CTRL_RIGHT       = 0x00000020,            //!< Right D-Pad button.
	SCE_CTRL_DOWN        = 0x00000040,            //!< Down D-Pad button.
	SCE_CTRL_LEFT        = 0x00000080,            //!< Left D-Pad button.
	SCE_CTRL_LTRIGGER    = 0x00000100,            //!< Left trigger.
	SCE_CTRL_RTRIGGER    = 0x00000200,            //!< Right trigger.
	SCE_CTRL_L1          = 0x00000400,            //!< L1 button.
	SCE_CTRL_R1          = 0x00000800,            //!< R1 button.
	SCE_CTRL_TRIANGLE    = 0x00001000,            //!< Triangle button.
	SCE_CTRL_CIRCLE      = 0x00002000,            //!< Circle button.
	SCE_CTRL_CROSS       = 0x00004000,            //!< Cross button.
	SCE_CTRL_SQUARE      = 0x00008000,            //!< Square button.
	SCE_CTRL_INTERCEPTED = 0x00010000,            //!< Input not available because intercepted by another application
	SCE_CTRL_PSBUTTON    = SCE_CTRL_INTERCEPTED,  //!< Playstation (Home) button.
	SCE_CTRL_HEADPHONE   = 0x00080000,            //!< Headphone plugged in.
	SCE_CTRL_VOLUP       = 0x00100000,            //!< Volume up button.
	SCE_CTRL_VOLDOWN     = 0x00200000,            //!< Volume down button.
SCE_CTRL_POWER = 0x40000000 //!< Power button.

scePowerRequestColdReset();         redemarre
scePowerRequestSuspend();           eteint
scePowerRequestStandby();           veille


*/
