package edu.purdue.cs180;

import java.io.IOException;

import android.app.Activity;
import android.hardware.Camera;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

class Preview implements SurfaceHolder.Callback {
    SurfaceHolder holder;
    Camera camera;
    SurfaceView sv;

    Preview(Activity activity, Camera camera) {
        sv = (SurfaceView) activity.findViewById(R.id.SurfaceView01);
        this.camera = camera;
        
        // Install a SurfaceHolder.Callback so we get notified when the
        // underlying surface is created and destroyed.
        holder = sv.getHolder();
        holder.addCallback(this);
        holder.setType(SurfaceHolder.SURFACE_TYPE_PUSH_BUFFERS);
    }

    public void surfaceCreated(SurfaceHolder holder) {
        // The Surface has been created, acquire the camera and tell it where
        // to draw.
        Camera.Parameters parameters = camera.getParameters();
        parameters.set("orientation", "portrait");
        camera.setParameters(parameters);
        try {
           camera.setPreviewDisplay(holder);
        } catch (IOException exception) {
            camera.release();
            camera = null;
            // TODO: add more exception handling logic here
        }
    }

    public void surfaceDestroyed(SurfaceHolder holder) {
        // Surface will be destroyed when we return, so stop the preview.
        // Because the CameraDevice object is not a shared resource, it's very
        // important to release it when the activity is paused.
        camera.stopPreview();
        camera.release();
        camera = null;
    }

    public void surfaceChanged(SurfaceHolder holder, int format, int w, int h) {
        // Now that the size is known, set up the camera parameters and begin
        // the preview.
    	Log.i("surfaceChanged", String.format("w = %d, h = %d", w, h));
        Camera.Parameters parameters = camera.getParameters();
        parameters.setPreviewSize(w, h);
        camera.setParameters(parameters);
    	camera.startPreview();
    }
}
