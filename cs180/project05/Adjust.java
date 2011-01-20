import java.awt.*;

public class Adjust extends Thread {
    Picture pic;
    int start, end, r, g, b;
    
    public Adjust(Picture pic, int start, int end, int r, int g, int b) {
        this.pic=pic;
        this.start=start;
        this.end=end;
        this.r=r;
        this.g=g;
        this.b=b;
        
        System.out.println("Initialized thread (pic, " + start + ", " + end + ", " + r + ", " + g + ", " + b + ")");
    }    
    
    public void run() {
        for (int x = start; x <= end; x++)
        {
            for (int y = 0; y < pic.getHeight(); y++)
            {
                Color val = new Color(pic.getRGB(x, y));
                int tr, tg, tb;
                
                if ((val.getRed() + r) > 255)
                    tr = 255;
                else if ((val.getRed() + r) < 0)
                    tr = 0;
                else
                    tr = val.getRed() + r;
                    
                if ((val.getGreen() + g) > 255)
                    tg = 255;
                else if ((val.getGreen() + g) < 0)
                    tg = 0;
                else
                    tg = val.getGreen() + g;
                    
                if ((val.getBlue() + b) > 255)
                    tb = 255;
                else if ((val.getBlue() + b) < 0)
                    tb = 0;
                else
                    tb = val.getBlue() + b;
                
                Color newVal = new Color(tr, tg, tb);
                pic.setRGB(x, y, newVal.getRGB());
            }
        }
    }   
    
}
