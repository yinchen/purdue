package edu.purdue.cs180;

import android.graphics.Bitmap;

/**
 * A Picture object encapsulates a picture taken by the camera.
 * <p>
 * It includes a serial number that identifies the picture and a Bitmap image (JPEG compressed).
 * 
 * @author jtk
 */
public class Picture {
	/**
	 * Each picture created has a unique serial number.  This is it.
	 * 
	 * @return	the serial number of the picture
	 */
	public int getSerial() {
		return serial;
	}

	/**
	 * Get the image associated with a picture.  It is a <code>Bitmap</code> object.
	 * 
	 * @return
	 */
	public Bitmap getImage() {
		return image;
	}

	int serial;
	Bitmap image;
	
	Picture(int take, Bitmap image) {
		this.serial = take;
		this.image = image;
	}
}
