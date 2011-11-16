import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.geom.*;
import java.awt.image.*;
import java.util.*;

public class MapScene implements Scene
{
    private MapEditor _parent;
    
    private ChangeListener _listener;
    private Image _image;

    private Point _point;
    private Point _lineStart;
    private Point _lineEnd;
    
    private int _locationID = 0;
    private int _pathID = 0;

    public MapScene(MapEditor parent, Image image)
    {
        _parent = parent;     
        _image = image;
    }

    public void changeNotify()
    {
        if (_listener != null) _listener.stateChanged(null);
    }

    public void draw(Graphics2D g)
    {
        g.drawImage(_image, 0, 0, null);

        if (_parent.CURRENT_MODE == 1)
        {
            g.setColor(Color.RED);
            if (_point != null)
            {
                g.fillOval(_point.x - 16, _point.y - 16, 32, 32);
            }
        }
        else if (_parent.CURRENT_MODE == 2)
        {
            g.setColor(Color.BLUE);
            g.setStroke(new BasicStroke(8, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
            if (_lineStart != null && _lineEnd != null)
            {
                g.drawLine(_lineStart.x, _lineStart.y, _lineEnd.x, _lineEnd.y);
            }
        }
        
        for (Location l : _parent._data.Locations)
        {
            g.setColor(Color.RED);
            g.fillOval(l.getX() - 16, l.getY() - 16, 32, 32);
        }
        
        for (Path p : _parent._data.Paths)
        {
            // implement this
        }
    }

    public void mousePressed(Point p)
    {
        if (_parent.CURRENT_MODE == 1)
        {
            _point = p;
        }
        else if (_parent.CURRENT_MODE == 2)
        {
            _lineEnd = null;
            _lineStart = p;
        }
        
        changeNotify();
    }
    
    public void mouseReleased(Point p)
    {
        if (_parent.CURRENT_MODE == 1)
        {
            Location l = new Location("", _locationID, p.x, p.y);
            _locationID++;
            
            _parent._data.Locations.add(l);
        }
        else if (_parent.CURRENT_MODE == 2)
        {
            // save
        }
    }

    public void mouseDragged(Point p)
    {
        if (_parent.CURRENT_MODE == 1)
        {
            _point = p;
        }
        else if (_parent.CURRENT_MODE == 2)
        {
            _lineEnd = p;
        }
        
        changeNotify();
    }

    public int getWidth() { return _image.getWidth(null); }
    public int getHeight() { return _image.getHeight(null); }

    public void addChangeListener(ChangeListener listener)
    {
        _listener = listener;
    }
}
