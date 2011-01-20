package edu.purdue.ball;

import java.io.IOException;

import android.content.Context;
import android.media.MediaPlayer;

public class SoundPlayer {
	
	MediaPlayer mp;
	Context ctx;
	
	public SoundPlayer(Context context){
		ctx = context;
		mp = MediaPlayer.create(ctx, R.raw.row);
	}
	
	public SoundPlayer(Context context, int num){
		ctx = context;
		int sound = 0;
		switch(num){
		
		case 1: 
			sound = R.raw.row;
			break;
		case 2:
			sound = R.raw.dj;
			break;
		case 3:
			sound = R.raw.adm;
			break;
		case 4:
			sound = R.raw.as;
			break;
		case 5:
			sound = R.raw.beat;
			break;
		}
		
		mp = MediaPlayer.create(ctx, sound);
		
	}
	
	public void play(){
		mp.seekTo(0);
	    mp.start();
	}

}
