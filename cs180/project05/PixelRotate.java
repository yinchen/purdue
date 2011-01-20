import java.awt.*;

public class PixelRotate extends Thread {
    Picture pic;
    int start, end, type;
    
    public PixelRotate(Picture pic, int start, int end, int type) {
        this.pic=pic;
        this.start=start;
        this.end=end;
        this.type=type;
        
        System.out.println("Initialized thread (pic, " + start + ", " + end + ", " + type + ")");
    }    
    
    public void run() {
        if (type == 0) // rotate left
        {
            for (int x = start; x <= end; x++)
            {
                for (int y = 0; y < pic.getHeight(); y++)
                {
                    Color val = new Color(pic.getRGB(x, y));
                    Color newVal = new Color(val.getGreen(), val.getBlue(), val.getRed());
                    pic.setRGB(x, y, newVal.getRGB());
                }
            }
        }
        else if (type == 1) // rotate right
        {
            for (int x = start; x <= end; x++)
            {
                for (int y = 0; y < pic.getHeight(); y++)
                {
                    Color val = new Color(pic.getRGB(x, y));
                    Color newVal = new Color(val.getBlue(), val.getRed(), val.getGreen());
                    pic.setRGB(x, y, newVal.getRGB());
                }
            }
        }
    }   
    
}