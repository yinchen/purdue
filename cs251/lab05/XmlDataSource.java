import java.beans.*; 
import java.util.*; 
import java.io.*; 
import java.applet.*; 
import java.net.*;

public class XmlDataSource
{
    private String _bitmapFile;
    private double _scale;
    public ArrayList<Location> Locations;
    public ArrayList<Path> Paths;
    
    public XmlDataSource()
    {
        _bitmapFile = "purdue-map.jpg";
        _scale = 1.0;
        Locations = new ArrayList<Location>();
        Paths = new ArrayList<Path>();
    }
    
    public XmlDataSource(String fileName)
    {
        _bitmapFile = "purdue-map.jpg";
        _scale = 1.0;
        Locations = new ArrayList<Location>();
        Paths = new ArrayList<Path>();
        
        this.readFile(fileName);
    }
    
    public String getBitmapFileName()
    {
        return _bitmapFile;    
    }
    
    public void setBitmapFileName(String value)
    {
        _bitmapFile = value;    
    }
    
    public double getFeetPerPixel()
    {
        return _scale;    
    }
    
    public void setFeetPerPixel(double value)
    {
        _scale = value;    
    }
    
    public void readFile(String fileName)
    {
        try
        {
            FileReader fr = new FileReader(fileName);        
            BufferedReader br = new BufferedReader(fr);
            
	        String line = br.readLine();
	        
	        StringTokenizer st = new StringTokenizer(line, "\"");
	        
	        _bitmapFile = st.nextToken();
	        _scale = Double.valueOf(line.split("\"")[3]);
	        
	        line = br.readLine();
	        while (line != null)
	        {
	            if (line == "</mapfile>" ||
	                line.split("\"") == null) break;
	            
	            if (line.split("\"")[0] == "<location id=")
                {
                    Location l = new Location();
                    l.setID(Integer.valueOf(line.split("\"")[1]));
                    l.setName(line.split("\"")[3]);
                    l.setX(Integer.valueOf(line.split("\"")[5]));
                    l.setY(Integer.valueOf(line.split("\"")[7]));
                    Locations.add(l);
                }
                else if (line.split("\"")[0] == "<path idfrom=")
                {
                    Path p = new Path();
                    p.setFrom(Integer.valueOf(line.split("\"")[1]));
                    p.setTo(Integer.valueOf(line.split("\"")[3]));
                    p.setType(line.split("\"")[5]);
                    
                    Paths.add(p);
                }
                
                line = br.readLine();
	        }
        }
        catch (Exception ex)
        {
            ex.printStackTrace(System.out);
        }
    }
    
    public void writeFile(String fileName)
    {
        try
        {
            FileWriter fw = new FileWriter(fileName);
            PrintWriter pw = new PrintWriter(fw);
            
            pw.println("<mapfile bitmap=\"" + _bitmapFile + "\" scale-feet-per-pixel=\"" + _scale + "\">");
            
            for (Location l : Locations)
            {
                pw.println("<location id=\"" + l.getID() + "\" name=\"" + l.getName() + "\" x=\"" + l.getX() + "\" y=\"" + l.getY() + "\" />");
            }
            
            for (Path p : Paths)
            {
                pw.println("<path idfrom=\"" + p.getFrom() + "\" idto=\"" + p.getTo() + "\" type=\"" + p.getType() + "\" />");
            }
            
            pw.println("</mapfile>");
            pw.close();
        }
        catch (Exception ex)
        {
            ex.printStackTrace(System.out);
        }
    }
}
