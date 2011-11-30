import java.beans.*; 
import java.util.*; 
import java.io.*; 
import java.applet.*; 
import java.net.*;

public class XmlDataSource
{
    private String _bitmapFile;
    public double _scale;
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
    
    public Location getLocationByID(int ID)
    {
        for (Location l : Locations)
        {
            if (l.getID() == ID)
            {
                return l;
            }
        }
        
        return null;
    }
    
    public Location getLocationByPoint(int x, int y, int radius)
    {
        for (Location l : Locations)
        {
            if (((x - radius) <= l.getX() && l.getX() <= (x + radius)) &&
                ((y - radius) <= l.getY() && l.getY() <= (y + radius)))
            {
                return l;
            }
        }
        
        return null;
    }
    
    public Path getPathByIDs(int from, int to)
    {
        for (Path p : Paths)
        {
            if ((p.getFrom() == from &&
                 p.getTo() == to) ||
                (p.getFrom() == to &&
                 p.getTo() == from))
            {
                return p;
            }
        }
        
        return null;
    }
    
    public void readFile(String fileName)
    {
        try
        {
            FileReader fr = new FileReader(fileName);        
            BufferedReader br = new BufferedReader(fr);
            
	        String line = br.readLine();
	        
	        line = line.substring(line.indexOf('"') + 1, line.length());
            _bitmapFile = line.substring(0, line.indexOf('"'));
            
            line = line.substring(line.indexOf('"') + 1, line.length());
            line = line.substring(line.indexOf('"') + 1, line.length());
	        _scale = Double.parseDouble(line.substring(0, line.indexOf('"')));
	        
	        line = br.readLine();
	        while (line.equals("</mapfile>") == false)
	        {   
	            String tmp = line.substring(1, line.indexOf(' '));
	            if (tmp.equals("location") == true)
                {
                    Location l = new Location();
                    
                    line = line.substring(line.indexOf('"') + 1, line.length());
                    l.setID(Integer.parseInt(line.substring(0, line.indexOf('"'))));
                    
                    line = line.substring(line.indexOf('"') + 1, line.length());
                    line = line.substring(line.indexOf('"') + 1, line.length());
                    l.setName(line.substring(0, line.indexOf('"')));
                    
                    line = line.substring(line.indexOf('"') + 1, line.length());
                    line = line.substring(line.indexOf('"') + 1, line.length());
                    l.setX(Integer.parseInt(line.substring(0, line.indexOf('"'))));
                    
                    line = line.substring(line.indexOf('"') + 1, line.length());
                    line = line.substring(line.indexOf('"') + 1, line.length());
                    l.setY(Integer.parseInt(line.substring(0, line.indexOf('"'))));
                    
                    Locations.add(l);
                }
                else if (tmp.equals("path") == true)
                {
                    Path p = new Path();
                    
                    line = line.substring(line.indexOf('"') + 1, line.length());
                    p.setFrom(Integer.parseInt(line.substring(0, line.indexOf('"'))));
                    
                    line = line.substring(line.indexOf('"') + 1, line.length());
                    line = line.substring(line.indexOf('"') + 1, line.length());
                    p.setTo(Integer.parseInt(line.substring(0, line.indexOf('"'))));
                    
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
                pw.println("<path idfrom=\"" + p.getFrom() + "\" idto=\"" + p.getTo() + "\" />");
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
