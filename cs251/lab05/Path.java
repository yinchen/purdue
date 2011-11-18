class Path
{
    private int _to, _from;
    
    public Path() {}
    
    public Path(int from, int to)
    {
        _from = from;
        _to = to;
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
