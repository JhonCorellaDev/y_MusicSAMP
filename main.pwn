/*Includes*/
#include <a_samp>
#include <sscanf2>
#include <Pawn.CMD>

#define DIALOG_Y_MUSIC 52343

CMD:mp3(playerid, params[])
{
	return ShowPlayerDialog(playerid, DIALOG_Y_MUSIC, DIALOG_STYLE_INPUT, "Escuchar Musica", "Escribe el nombre de la canción:", "Reproducir", "Cancelar");
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	new y_url[1024];
	if(dialogid == DIALOG_Y_MUSIC)
	{
		format(urlfinal, 1024, "http://your.domain/music/index.php?n=%s", inputtext);
		PlayAudioStreamForPlayer(playerid, y_url);
		SendClientMessage(playerid, 0x00ff00ff, "Escuchando Musica!");
		return 1;
	}
	return 0;
}
CMD:detener(playerid)
{
	StopAudioStreamForPlayer(playerid);
	SendClientMessage(playerid, 0xff0000ff, "Has detenido la musica!");
	return 1;
}
