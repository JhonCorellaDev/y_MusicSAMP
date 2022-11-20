/*
	---------------------------------------

		y_MusicSamp
		@author: TioJhon
		@version: 2.0
		@release: 19/11/2022
		@build: 1.9	
		@download: github.com/eltiojhon7/JCMusic
	---------------------------------------
*/


#include <a_samp>


#define Y_MUSICSAMP_VERSION "2.0"

#if defined _Y_MUSIC_SAMP_INCLUDE
	#endinput
#endif
#define _Y_MUSIC_SAMP_INCLUDE

public OnGameModeInit()
{
	printf("[-] y_MusicSamp v"Y_MUSICSAMP_VERSION" by TioJhon initialized successfully [-]");

	#if defined MV_OnGameModeInit
		return MV_OnGameModeInit();
	#else
		return 1;
	#endif
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit MV_OnGameModeInit
#if defined MV_OnGameModeInit
	forward MV_OnGameModeInit();
#endif



#define DIALOG_Y_MUSIC 1066547


hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	new y_url[1024];
	if(dialogid == DIALOG_Y_MUSIC)
	{
		format(y_url, 1024, "http://devforo-seattlerp.epizy.com/index.php?n=%s", inputtext);//Aqui hace la conexión con nuestro sitio web(Ya en el script php se hace el trabajo)
		PlayAudioStreamForPlayer(playerid, y_url);
		SendClientMessage(playerid, 0x00ff00ff, "Escuchando Musica!");
		return 1;
	}

	return 0;
}
#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif

#define OnDialogResponse RT_OnDialogResponse
#if defined RT_OnDialogResponse
	forward RT_OnDialogResponse(playerid);
#endif

