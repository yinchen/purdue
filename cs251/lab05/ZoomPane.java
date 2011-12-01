import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.geom.*;
import java.awt.image.*;
import java.util.*;

public class ZoomPane extends JScrollPane
{
    private ZoomPanel _panel;

    public ZoomPane(Scene scene)
    {
        _panel = new ZoomPanel(scene);
        getViewport().add(_panel);

        getVerticalScrollBar().setUnitIncrement(5);
        getHorizontalScrollBar().setUnitIncrement(5);
    }
    
    public void updateScene(Scene scene)
    {
        _panel.setScene(scene);    
    }

    public ZoomPanel getZoomPanel() { return _panel; }

    public Point toViewCoordinates(Point point)
    {
        double scale = _panel.getScale();
        int x = (int) (point.getX() / scale);
        int y = (int) (point.getY() / scale);
        return new Point(x, y);
    }

    public void zoom(double scale)
    {
        double oldScale = _panel.getScale();

        Point point = getViewport().getViewPosition();

        _panel.zoom(scale);

        double w = getViewport().getWidth();
        double h = getViewport().getHeight();

        int halfW = (int) (w/2.0);
        int halfH = (int) (h/2.0);
        point.translate(halfW, halfH);

        double relScale = scale / oldScale;

        point.move((int) (point.getX() * relScale), (int) (point.getY() * relScale));

        point.translate(-halfW, -halfH);

        getViewport().setViewPosition(point);
    }
    
    public void centerAt(Point pt)
    {
        Point point = toViewCoordinates(pt);

        double w = getViewport().getWidth();
        double h = getViewport().getHeight();

        int halfW = (int) (w/2.0);
        int halfH = (int) (h/2.0);
        point.translate(-halfW, -halfH);

        getViewport().setViewPosition(point);
    }

    protected JSlider getJSlider()
    {
        int min = 1, max = 36, inc = 5;
        final JSlider slider = new JSlider(min, max, 16);
        slider.setMajorTickSpacing(5);
        slider.setMinorTickSpacing(1);
        slider.setPaintTicks(true);
        slider.setSnapToTicks(true);
        slider.setLabelTable(getLabelTable(min, max, inc));
        slider.setPaintLabels(true);
        slider.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e)
            {
                double scale = (slider.getValue() + 4) / 20.0;
                zoom(scale);
                repaint();
            }
        });
        return slider;
    }

    private Hashtable getLabelTable(int min, int max, int inc)
    {
        Hashtable<Integer,JLabel> table = new Hashtable<Integer,JLabel>();
        for (int j = min; j <= max; j += inc)
        {
            String s = String.format("%.2f", (j+4)/20.0);
            table.put(Integer.valueOf(j), new JLabel(s));
        }
        return table;
    }

    public class ZoomPanel extends JPanel implements ChangeListener
    {
        private double _scale = 1.0;
        private Scene _scene;

        public ZoomPanel()
        {
            setLayout(new BorderLayout());
        }

        public ZoomPanel(Scene scene)
        {
            this();
            setScene(scene);
        }

        public void setScene(Scene scene)
        {
            _scene = scene;
            _scene.addChangeListener(this);
            
            repaint();
        }

        public void stateChanged(ChangeEvent e)
        {
            repaint();
        }

        protected void paintComponent(Graphics g)
        {
            super.paintComponent(g);
            Graphics2D g2 = (Graphics2D)g;
            g2.setRenderingHint(RenderingHints.KEY_INTERPOLATION, RenderingHints.VALUE_INTERPOLATION_BICUBIC);

            g2.scale(_scale, _scale);
            if (_scene != null) _scene.draw(g2);
        }

        public double getScale() { return _scale; }

        public Dimension getPreferredSize()
        {
            int w = 0, h = 0;
            if (_scene != null)
            {
                w = (int)(_scale*_scene.getWidth());
                h = (int)(_scale*_scene.getHeight());
            }
            return new Dimension(w, h);
        }

        protected void zoom(double scale)
        {
            _scale = scale;
            revalidate();
            repaint();
        }
    }
}
