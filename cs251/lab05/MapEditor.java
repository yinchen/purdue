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
        
        Image image = new ImageIcon("purdue-map.jpg").getImage();
        
        _menu = new EditorMenu(this, this);
        
        _map = new MapScene(image);
        _zoomPane = new ZoomPane(_map);
        
        getContentPane().add(_zoomPane);
        
        _zoomSlider = _zoomPane.getJSlider();
        
        getContentPane().add(_zoomSlider, "Last");
        
        MouseAdapter listener = new MouseAdapter() {
            public void mousePressed(MouseEvent e)
            {
                Point point = _zoomPane.toViewCoordinates(e.getPoint());
                _map.mousePressed(point);
            }
        };
        
        MouseMotionAdapter motionListener = new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e)
            {
                Point point = _zoomPane.toViewCoordinates(e.getPoint());
                _map.mouseDragged(point);
            }
        };
        
        _zoomPane.getZoomPanel().addMouseListener(listener);
        _zoomPane.getZoomPanel().addMouseMotionListener(motionListener);
    }
    
    public void actionPerformed(ActionEvent event)
    {
        String action = event.getActionCommand();
        
        if (action == "New")
        {
        
        }
        else if (action == "Open...")
        {
        
        }
        else if (action == "Save")
        {
        
        }
        else if (action == "Save As...")
        {
        
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
        
        }
        else if (action == "Insert Path")
        {
        
        }
        else if (action == "Delete Location")
        {
        
        }
        else if (action == "Delete Path")
        {
        
        }
        else if (action == "Show Properties")
        {
        
        }
    }
}

