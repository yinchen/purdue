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

class MapEditor extends JFrame
{
    private int PREFERRED_WIDTH = 680;
    private int PREFERRED_HEIGHT = 600;
    
    private JScrollPane _scrollPane;
    private ZoomPane _zoomPane;
    private MapScene _map;

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
        
        _map = new MapScene(image);
        _zoomPane = new ZoomPane(_map);
        
        getContentPane().add(_zoomPane);
        getContentPane().add(_zoomPane.getJSlider(), "Last");
        
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
}

