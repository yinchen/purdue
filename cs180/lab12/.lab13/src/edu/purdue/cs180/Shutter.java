package edu.purdue.cs180;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Matrix;
import android.hardware.Camera;
import android.view.View;
import android.widget.ImageButton;

/**
 * Provides a method to take a picture, waiting for the user to press the shutter button.
 * 
 * @author jtk
 */
public class Shutter {
	static int number = 0;
    static ImageButton ibTake;
    static Camera camera;
    static Bitmap pictureImage;
    
    static Camera.ShutterCallback cbShutter = new Camera.ShutterCallback() {
		public void onShutter() {
		}
	};
	
	static Camera.PictureCallback cbJpeg = new Camera.PictureCallback() {
		public void onPictureTaken(byte[] data, Camera cameraLocal) {
			System.gc();
			Bitmap bm = BitmapFactory.decodeByteArray(data, 0, data.length);
			int w = bm.getWidth();
			int h = bm.getHeight();
			Matrix m = new Matrix();
			//m.postRotate(90);
			m.postScale(300.0f/w, 200.0f/h); // TODO: magic
			pictureImage = Bitmap.createBitmap(bm, 0, 0, w, h, m, true);
			synchronized (camera) { camera.notify(); }
			camera.startPreview();
		}
	};
	
	Shutter(Activity main, Camera camera) {
	    ibTake = (ImageButton) main.findViewById(R.id.take);
        ibTake.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				synchronized(ibTake) {
					ibTake.notify();
				}
			}
		});
    	Shutter.camera = camera;
	}

	/**
	 * Block the current process until the user presses the shutter button.  Return a new
	 * picture object that includes the JPEG compressed image taken by the camera.
	 * 
	 * @return a <code>Picture</code> object with the new picture.
	 */
	public static Picture waitForPicture() {
		try {
			synchronized(ibTake) {
				ibTake.wait();
			}
		} catch (InterruptedException e) { e.printStackTrace(); }
		number++;
    	camera.takePicture(cbShutter, null, cbJpeg);
    	synchronized (camera) {
    		try {
				camera.wait();
			} catch (InterruptedException e) { e.printStackTrace(); }
    	}
		return new Picture(number, pictureImage);
	}
}
