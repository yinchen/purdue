class Path
{
    private String _type;
    private int _to, _from;
    
    public Path() {}
    
    public Path(String type, int to, int from)
    {
        _type = type;
        _to = to;
        _from = from;
    }
    
    public String getType()
    {
        return _type;
    }
    
    public void setType(String type)
    {
        _type = type;
    }
    
    public int getTo()
    {
        return _to;
    }
    
    public void setTo(int to)
    {
        _to = to;
    }
    
    public int getFrom()
    {
        return _from;
    }
    
    public void setFrom(int from)
    {
        _from = from;
    } 
}
