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

class MapEditor extends JFrame implements ActionListener
{
    private int PREFERRED_WIDTH = 680;
    private int PREFERRED_HEIGHT = 600;
    
    private EditorMenu _menu;
    private ZoomPane _zoomPane;
    private MapScene _map;
    private JSlider _zoomSlider;
    
    private MouseAdapter _listener;
    private MouseMotionAdapter _motionListener;
    
    public int CURRENT_MODE = 0;
    
    public XmlDataSource _data;

    public static void main(String[] args) 
    { 
        MapEditor mapEditor = new MapEditor(); 
        mapEditor.setVisible(true);
    }

    MapEditor()
    {
        setTitle("Map Editor");
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
        
        _menu = new EditorMenu(this, this);
        
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
        
        if (action == "New")
        {
            newFile();
        }
        else if (action == "Open...")
        {
            openFile();
        }
        else if (action == "Save")
        {
            saveFile();
        }
        else if (action == "Save As...")
        {
            saveFileAs();
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
        
        if (action == "Insert Location")
        {
            CURRENT_MODE = 1;
            _menu.toggleModeMenu(action);
        }
        else if (action == "Insert Path")
        {
            CURRENT_MODE = 2;
            _menu.toggleModeMenu(action);
        }
        else if (action == "Delete Location")
        {
            CURRENT_MODE = 3;
            _menu.toggleModeMenu(action);
        }
        else if (action == "Delete Path")
        {
            CURRENT_MODE = 4;
            _menu.toggleModeMenu(action);
        }
        else if (action == "Show Properties")
        {
            CURRENT_MODE = 0;
            _menu.toggleModeMenu(action);
        }
    }
    
    void newFile()
    {
        _data = new XmlDataSource();
        reinitialize();
    }
    
    void openFile()
    {
        JFileChooser fc = new JFileChooser();
        
        int returnVal = fc.showOpenDialog(this);
        if (returnVal == JFileChooser.APPROVE_OPTION)
        {
            File file = fc.getSelectedFile();
            _data = new XmlDataSource(file.getName());
                  
            reinitialize();
            
            for (Location l : _data.Locations)
            {
                System.out.println(l.getID() + ": (" + l.getX() + ", " + l.getY() + ")");
            }
        }
    }
    
    void saveFile()
    {
        // not implemented
    }
    
    void saveFileAs()
    {
        JFileChooser fc = new JFileChooser();
        
        int returnVal = fc.showSaveDialog(this);
        if (returnVal == JFileChooser.APPROVE_OPTION)
        {
            File file = fc.getSelectedFile();
            _data.writeFile(file.getName());
        }
    }
}

