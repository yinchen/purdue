import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.geom.*;
import java.awt.image.*;
import java.util.*;

public class MapScene implements Scene
{
    private ChangeListener _listener;
    private Image _image;

    private Point _lineStart;
    private Point _lineEnd;

    public MapScene(Image image)
    {
        _image = image;
    }

    private void changeNotify()
    {
        if (_listener != null) _listener.stateChanged(null);
    }

    public void draw(Graphics2D g)
    {
        g.drawImage(_image, 0, 0, null);

        g.setColor(Color.BLUE);
        g.setStroke(new BasicStroke(3, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
        if (_lineStart != null && _lineEnd != null)
        {
            g.drawLine(_lineStart.x, _lineStart.y, _lineEnd.x, _lineEnd.y);
        }
    }

    public void mousePressed(Point p)
    {
        _lineEnd = null;
        _lineStart = p;
    }

    public void mouseDragged(Point p)
    {
        _lineEnd = p;
        changeNotify();
    }

    public int getWidth() { return _image.getWidth(null); }
    public int getHeight() { return _image.getHeight(null); }

    public void addChangeListener(ChangeListener listener)
    {
        _listener = listener;
    }
}
