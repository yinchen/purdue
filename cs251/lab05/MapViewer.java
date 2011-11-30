import javax.swing.*; 
import javax.swing.event.*; 
import javax.swing.text.*; 
import javax.swing.border.*; 
import javax.swing.colorchooser.*; 
import javax.swing.filechooser.*; 
import javax.accessibility.*; 

import java.awt.*; 
import java.awt.event.*; 
import java.beans.*; 
import java.util.*; 
import java.io.*; 
import java.applet.*; 
import java.net.*;

class MapViewer extends MapUI
{
    public Graph graph = null;
    
    public static void main(String[] args) 
    { 
        MapViewer mapViewer = new MapViewer(); 
        mapViewer.setVisible(true);
    }

    MapViewer()
    {
        setTitle("Map Viewer");
        setSize(PREFERRED_WIDTH, PREFERRED_HEIGHT);
        setBackground(Color.gray);
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        _data = new XmlDataSource();        
        initialize();
    }
    
    private void initialize()
    {
        System.out.print("Initializing... ");
        
        Image image = new ImageIcon(_data.getBitmapFileName()).getImage();
        
        _menu = new ViewerMenu(this, this);
        
        _map = new MapScene(this, image);
        _zoomPane = new ZoomPane(_map);
        
        getContentPane().add(_zoomPane);
        
        _zoomSlider = _zoomPane.getJSlider();
        
        getContentPane().add(_zoomSlider, "Last");
        
        _listener = new MouseAdapter() {
            public void mousePressed(MouseEvent e)
            {
                Point point = _zoomPane.toViewCoordinates(e.getPoint());
                _map.mousePressed(point);
            }
            
            public void mouseReleased(MouseEvent e)
            {
                Point point = _zoomPane.toViewCoordinates(e.getPoint());
                _map.mouseReleased(point);
            }
            
            public void mouseClicked(MouseEvent e)
            {
                Point point = _zoomPane.toViewCoordinates(e.getPoint());
                _map.mouseClicked(point);
            }
        };
        
        _motionListener = new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e)
            {
                Point point = _zoomPane.toViewCoordinates(e.getPoint());
                _map.mouseDragged(point);
            }
        };
        
        _zoomPane.getZoomPanel().addMouseListener(_listener);
        _zoomPane.getZoomPanel().addMouseMotionListener(_motionListener);
        
        System.out.println("Ready.");
    }
    
    private void reinitialize()
    {
        System.out.print("Reinitializing... ");
        
        Image image = new ImageIcon(_data.getBitmapFileName()).getImage();        
        
        _map = new MapScene(this, image);
        _zoomPane.updateScene(_map);
        
        _map.changeNotify();
        
        System.out.println("Ready.");
    }
    
    public void actionPerformed(ActionEvent event)
    {
        String action = event.getActionCommand();
        
        if (action == "Open...")
        {
            openFile();
        }
       else if (action == "Exit")
        {
            System.exit(0);
        }
        
        if (action == "Zoom In")
        {
            _zoomSlider.setValue(_zoomSlider.getValue() + 5);
        }
        else if (action == "Zoom Out")
        {
            _zoomSlider.setValue(_zoomSlider.getValue() - 5);
        }
        
        if (action == "Find")
        {
            find();
        }
        else if (action == "Directions")
        {
            directions();
        }
    }
    
    void openFile()
    {
        JFileChooser fc = new JFileChooser();
        
        try
        {
            File f = new File(new File(".").getCanonicalPath());
            fc.setCurrentDirectory(f);
        }
        catch (Exception ex)
        {
        }
        
        int returnVal = fc.showOpenDialog(this);
        if (returnVal == JFileChooser.APPROVE_OPTION)
        {
            File file = fc.getSelectedFile();
            _data = new XmlDataSource(file.getName());
            
            currentFileName = file.getName();
            
            reinitialize();
            
            graph = new Graph(_data.Locations.size());
            
            for (Location l : _data.Locations)
            {
                graph.setVertex(l.getID(), l.getName());
            }
            
            for (Path p : _data.Paths)
            {
                Location start = _data.getLocationByID(p.getFrom());
                Location end = _data.getLocationByID(p.getTo());
                
                Point sp = new Point((int)start.getX(), (int)start.getY());
                Point ep = new Point((int)end.getX(), (int)end.getY());
                
                graph.setEdge(start.getID(), end.getID(), (int)(sp.distance(ep) * _data._scale));
            }
        }
    }
    
    void find()
    {
        ArrayList<String> locationNames = new ArrayList<String>();
        for (Location l : _data.Locations)
        {
            locationNames.add(l.getName());
        }
        
        Collections.sort(locationNames);
        
        String locationName = (String)JOptionPane.showInputDialog(this, "Select a location to find: ", "Find", JOptionPane.PLAIN_MESSAGE, null, locationNames.toArray(), "");
        if ((locationName == null) || (locationName.length() == 0))
        {
            return;
        }
        
        Location target = null;
        for (Location l : _data.Locations)
        {
            if (l.getName().equals(locationName))
            {
                target = l;
                break;
            }
        }
        
        _map.find(target.getID());
    }
    
    void directions()
    {
        ArrayList<String> locationNames = new ArrayList<String>();
        for (Location l : _data.Locations)
        {
            locationNames.add(l.getName());
        }
        
        Collections.sort(locationNames);
        
        String locationName;
        
        locationName = (String)JOptionPane.showInputDialog(this, "Select a starting location: ", "Directions", JOptionPane.PLAIN_MESSAGE, null, locationNames.toArray(), "");
        if ((locationName == null) || (locationName.length() == 0))
        {
            return;
        }
        
        Location start = null;
        for (Location l : _data.Locations)
        {
            if (l.getName().equals(locationName))
            {
                start = l;
                break;
            }
        }
        
        locationName = (String)JOptionPane.showInputDialog(this, "Select an ending location: ", "Directions", JOptionPane.PLAIN_MESSAGE, null, locationNames.toArray(), "");
        if ((locationName == null) || (locationName.length() == 0))
        {
            return;
        }
        
        Location end = null;
        for (Location l : _data.Locations)
        {
            if (l.getName().equals(locationName))
            {
                end = l;
                break;
            }
        }
        
        Graph.Path p = graph.shortestPath(start.getID());
        
        JOptionPane.showMessageDialog(this, "The distance from " + start.getName() + " to " + end.getName() + " is " + p.distance[end.getID()] + " feet.", "Directions", JOptionPane.PLAIN_MESSAGE);
        
        ArrayList<Path> directionPaths = new ArrayList<Path>();
        
        int u = end.getID();
        do
        {
            directionPaths.add(_data.getPathByIDs(p.path[u], u));
            u = p.path[u];
        } while (u != start.getID());
		
		_map.directions(start, end, directionPaths);
    }
}

