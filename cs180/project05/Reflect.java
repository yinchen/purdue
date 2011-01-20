public class Reflect extends Thread {
    Picture pic;
    int start, end, type;
    
    public Reflect(Picture pic, int start, int end, int type) {
        this.pic=pic;
        this.start=start;
        this.end=end;
        this.type=type;
        
        System.out.println("Initialized thread (pic, " + start + ", " + end + ", " + type + ")");
    }    
    
    public void run() {
        if (type == 0) // reflect top onto bottom
        {
            for (int x = start; x <= end; x++)
            {
                int top = 0;
                int bottom = pic.getHeight() - 1;
  
                while (top < bottom) {
                    pic.setRGB(x, bottom, pic.getRGB(x, top));
                    
                    top++;
                    bottom--;
                }
            }            
        }
        else if (type == 1) // reflect bottom onto top
        {
            for (int x = start; x <= end; x++)
            {
                int top = 0;
                int bottom = pic.getHeight() - 1;
  
                while (top < bottom) {
                    pic.setRGB(x, top, pic.getRGB(x, bottom));
                    
                    top++;
                    bottom--;
                }
            }            
        }
        else if (type == 2) // reflect left onto right
        {
            for (int y = start; y <= end; y++)
            {
                int left = 0;
                int right = pic.getWidth() - 1;
  
                while (left < right) {
                    pic.setRGB(right, y, pic.getRGB(left, y));
                    
                    left++;
                    right--;
                }
            }
        }
        else if (type == 3) // reflect right onto left
        {
            for (int y = start; y <= end; y++)
            {
                int left = 0;
                int right = pic.getWidth() - 1;
  
                while (left < right) {
                    pic.setRGB(left, y, pic.getRGB(right, y));
                    
                    left++;
                    right--;
                }
            }
        }
    }   
    
}