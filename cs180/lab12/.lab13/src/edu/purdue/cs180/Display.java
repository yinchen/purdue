package edu.purdue.cs180;

import android.app.Activity;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

/**
 * Interact with the Android phone display.
 * 
 * @author jtk
 */
public class Display {
	static Handler handler;
	static TextView tv;
	static ImageView iv;
	static ImageButton ibPrev;
	static ImageButton ibNext;
	static View.OnClickListener ocl;
	static boolean result;

	/**
	 * Display a text message in the one line "status" field area of the display.
	 * 
	 * @param s text message to be displayed.
	 */
	public static void setText(final String s) {
		// Post a runnable object to display the message.  This approach is used
		// because the UI methods are only accessible from the UI thread.  Since
		// this method is running in a separate thread, it is necessary to queue
		// the action as a runnable method to be done by the handler, which runs
		// in the UI thread (in which it was created).
		handler.post(new Runnable() {
			public void run() {
				tv.setText(s);
			}
		});
	}
	
	/**
	 * Display a text message as a popup ("toast" in Android parlance) on the display.
	 * 
	 * @param s text message to be displayed
	 */
	public static void popupToast(final String s) {
		handler.post(new Runnable() {
			public void run() {
				Toast toast = Toast.makeText(tv.getContext(), s, Toast.LENGTH_SHORT);
				toast.show();
			}
		});
	}

	/**
	 * Display a picture in the image display window.
	 * 
	 * @param picture picture to be displayed
	 */
	public static void showPicture(final Picture picture) {
		handler.post(new Runnable() {
			public void run() {
				iv.setImageBitmap(picture.image);
			}
		});
	}

	Display(Activity main) {
		handler = new Handler();
		tv = (TextView) main.findViewById(R.id.TextView01);
		iv = (ImageView) main.findViewById(R.id.ImageView01);
		ibPrev = (ImageButton) main.findViewById(R.id.left);
		ibNext = (ImageButton) main.findViewById(R.id.right);

		ocl = new View.OnClickListener() {
			public void onClick(View v) {
				result = v == ibNext;
				synchronized (ocl) {
					ocl.notify();
				}
			}
		};
		ibPrev.setOnClickListener(ocl);
		ibNext.setOnClickListener(ocl);
	}

	/**
	 * Block until the user presses an image display selection button on the screen.  Options
	 * are backward (previous) and forward (next).
	 * 
	 * @return <code>true</code> to move forward; <code>false</code> to move backward
	 */
	public static boolean waitForButton() {
		Log.i("waitForButton", "waiting");
		try {
			synchronized (ocl) {
				ocl.wait();
			}
		} catch (InterruptedException e) { e.printStackTrace();	}
		Log.i("waitForButton", "button pressed: " + result);
		return result;
	}
}
