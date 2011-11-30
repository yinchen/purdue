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

abstract class MapUI extends JFrame implements ActionListener
{
    public int PREFERRED_WIDTH = 680;
    public int PREFERRED_HEIGHT = 600;
    
    public MapMenu _menu;
    public ZoomPane _zoomPane;
    public MapScene _map;
    public JSlider _zoomSlider;
    
    public MouseAdapter _listener;
    public MouseMotionAdapter _motionListener;
    
    public int CURRENT_MODE = 5;
    
    public XmlDataSource _data;
    
    public String currentFileName = null;
}

