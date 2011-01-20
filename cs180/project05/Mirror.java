public class Mirror extends Thread {
    Picture pic;
    int start, end, type;
    
    public Mirror(Picture pic, int start, int end, int type) {
        this.pic=pic;
        this.start=start;
        this.end=end;
        this.type=type;
        
        System.out.println("Initialized thread (pic, " + start + ", " + end + ", " + type + ")");
    }    
    
    public void run() {
        if (type == 0) // flip horizontal
        {
            for (int y = start; y <= end; y++)
            {
                int left = 0;
                int right = pic.getWidth() - 1;
  
                while (left < right) {
                    int temp = pic.getRGB(left, y);
                    pic.setRGB(left, y, pic.getRGB(right, y));
                    pic.setRGB(right, y, temp);
                    
                    left++;
                    right--;
                }                  
            }
        }
        else if (type == 1) // flip vertical
        {
            for (int x = start; x <= end; x++)
            {
                int top = 0;
                int bottom = pic.getHeight() - 1;
  
                while (top < bottom) {
                    int temp = pic.getRGB(x, top);
                    pic.setRGB(x, top, pic.getRGB(x, bottom));
                    pic.setRGB(x, bottom, temp);
                    
                    top++;
                    bottom--;
                }
            }
        }
    }   
    
}