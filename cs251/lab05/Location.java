class Location
{
    private String _name;
    private int _id, _x, _y;
    
    public Location() {}
    
    public Location(int x, int y)
    {
        _x = x;
        _y = y;
    }
    
    public Location(String name, int id, int x, int y)
    {
        _name = name;
        _id = id;
        _x = x;
        _y = y;
    }
    
    public String getName()
    {
        return _name;
    }
    
    public void setName(String name)
    {
        _name = name;
    }
    
    public int getID()
    {
        return _id;
    }
    
    public void setID(int id)
    {
        _id = id;
    }    
    
    public int getX()
    {
        return _x;
    }
    
    public void setX(int x)
    {
        _x = x;
    }
    
    public int getY()
    {
        return _y;
    }
    
    public void setY(int y)
    {
        _y = y;
    }
}
