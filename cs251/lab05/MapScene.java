import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.geom.*;
import java.awt.image.*;
import java.util.*;

public class MapScene implements Scene
{
    private MapUI _parent;
    
    private ChangeListener _listener;
    private Image _image;

    private Point _point;
    private Point _lineStart;
    private Point _lineEnd;
    
    private int _locationID = 0;
    private int _pathID = 0;
    
    private Location _locationFound = null;

    public MapScene(MapUI parent, Image image)
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
        else if (_parent.CURRENT_MODE == 3)
        {
            // do nothing
        }
        else if (_parent.CURRENT_MODE == 4)
        {
            // do nothing
        }
        else if (_parent.CURRENT_MODE == 5)
        {
            // do nothing
        }
        
        for (Path p : _parent._data.Paths)
        {
            Location start = _parent._data.getLocationByID(p.getFrom());
            Location end = _parent._data.getLocationByID(p.getTo());
            
            if (start != null && end != null)
            {
                if (_parent instanceof MapViewer)
                    g.setColor(new Color(115, 192, 255, 100));
                else
                    g.setColor(Color.BLUE);
                g.setStroke(new BasicStroke(8, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
                g.drawLine(start.getX(), start.getY(), end.getX(), end.getY());
            }
        }
        
        for (Location l : _parent._data.Locations)
        {
            if (_parent instanceof MapViewer)
                g.setColor(new Color(245, 115, 115, 100));
            else
                g.setColor(Color.RED);
            g.fillOval(l.getX() - 16, l.getY() - 16, 32, 32);
        }
        
        if (_locationFound != null)
        {
            g.setColor(Color.RED);
            g.fillOval(_locationFound.getX() - 16, _locationFound.getY() - 16, 32, 32);
        }
    }

    public void mousePressed(Point pt)
    {
        if (_parent.CURRENT_MODE == 1)
        {
            _point = pt;
        }
        else if (_parent.CURRENT_MODE == 2)
        {
            _lineEnd = null;
            _lineStart = pt;
        }
        else if (_parent.CURRENT_MODE == 3)
        {
            // do nothing
        }
        else if (_parent.CURRENT_MODE == 4)
        {
            // do nothing
        }
        else if (_parent.CURRENT_MODE == 5)
        {
            // do nothing
        }
        
        changeNotify();
    }
    
    public void mouseReleased(Point pt)
    {
        if (_parent.CURRENT_MODE == 1)
        {
            Location l = new Location("", _locationID, pt.x, pt.y);
            _locationID++;
            
            _parent._data.Locations.add(l);
        }
        else if (_parent.CURRENT_MODE == 2)
        {
            Location start = _parent._data.getLocationByPoint(_lineStart.x, _lineStart.y, 16);
            Location end = _parent._data.getLocationByPoint(pt.x, pt.y, 16);
            
            if (start != null && end != null)
            {
                Path p = new Path(start.getID(), end.getID());            
                _parent._data.Paths.add(p);
            }
        }
        else if (_parent.CURRENT_MODE == 3)
        {
            // do nothing
        }
        else if (_parent.CURRENT_MODE == 4)
        {
            // do nothing
        }
        else if (_parent.CURRENT_MODE == 5)
        {
            // do nothing
        }
    }

    public void mouseDragged(Point pt)
    {
        if (_parent.CURRENT_MODE == 1)
        {
            _point = pt;
        }
        else if (_parent.CURRENT_MODE == 2)
        {
            _lineEnd = pt;
        }
        else if (_parent.CURRENT_MODE == 3)
        {
            // do nothing
        }
        else if (_parent.CURRENT_MODE == 4)
        {
            // do nothing
        }
        else if (_parent.CURRENT_MODE == 5)
        {
            // do nothing
        }
        
        changeNotify();
    }
    
    public void mouseClicked(Point pt)
    {
        if (_parent.CURRENT_MODE == 1)
        {
            // do nothing
        }
        else if (_parent.CURRENT_MODE == 2)
        {
            // do nothing
        }
        else if (_parent.CURRENT_MODE == 3)
        {
            Location l = _parent._data.getLocationByPoint(pt.x, pt.y, 16);
            
            if (l != null)
            {
                Path target = null;
                for (Path p : _parent._data.Paths)
                {
                    if (p.getFrom() == l.getID() ||
                        p.getTo() == l.getID())
                    {
                        target = p;
                    }
                }
                
                if (target != null)
                {
                    _parent._data.Paths.remove(target);
                }
                
                _parent._data.Locations.remove(l);
            }
        }
        else if (_parent.CURRENT_MODE == 4)
        {
            Path target = null;
            for (Path p : _parent._data.Paths)
            {
                Location start = _parent._data.getLocationByID(p.getFrom());
                Location end = _parent._data.getLocationByID(p.getTo());
                
                Line2D line = new Line2D.Double();
                line.setLine((double)start.getX(), (double)start.getY(), (double)end.getX(), (double)end.getY());
                
                if (line.ptSegDist((double)pt.x, (double)pt.y) <= 8.0)
                {
                    target = p;
                }
            }
            
            if (target != null)
            {
                _parent._data.Paths.remove(target);
            }
        }
        else if (_parent.CURRENT_MODE == 5)
        {
            Location l = _parent._data.getLocationByPoint(pt.x, pt.y, 16);
            
            if (l != null)
            {
                String result = (String)JOptionPane.showInputDialog(_parent, "Location " + l.getID() + " is at position (" + l.getX() + ", " + l.getY() + ").\nYou can update the Name for this Location below: ", "Location Properties", JOptionPane.PLAIN_MESSAGE, null, null, l.getName());

                if ((result != null) && (result.length() > 0))
                {
                    l.setName(result);
                }
            }
        }
        
        changeNotify();
    }
    
    public void find(int locationID)
    {
        Location l = _parent._data.getLocationByID(locationID);
        _locationFound = l;

        _parent._zoomPane.centerAt(new Point(l.getX(), l.getY()));        
    }

    public int getWidth() { return _image.getWidth(null); }
    public int getHeight() { return _image.getHeight(null); }

    public void addChangeListener(ChangeListener listener)
    {
        _listener = listener;
    }
}
