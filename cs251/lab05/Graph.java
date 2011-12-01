import java.util.*;

class Graph
{
    class Vertex
    {
        String _name;
    }

    int _n;
    Vertex [] _vertex;
    
    boolean [][] _adjacent;
    int [][] _weight;

    public Graph(int n)
    {
        _n = n;
        _vertex = new Vertex[n];
        for (int i = 0; i < n; i++)
        {
            _vertex[i] = new Vertex();
        }
        _adjacent = new boolean[n][n];
        _weight = new int[n][n];
    }

    public void setVertex(int i, String name)
    {
        _vertex[i]._name = name;
    }

    public void setEdge(int i, int j, int weight)
    {
        _adjacent[i][j] = true;
        _adjacent[j][i] = true;
        _weight[i][j] = weight;
        _weight[j][i] = weight;
    }

    // Display the graph as a string
    public String toString()
    {
        String s;
        s = "Vertices:\n";
        for (int i = 0; i < _n; i++)
        {
            s += "  " + i + ": " + _vertex[i]._name + "\n";
        }
        s += "\n";
        
        s += "Edges:\n";
        for (int i = 0; i < _n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (_adjacent[i][j])
                {
                    s += "  " + i + "->" + j + ": " + _weight[i][j] + "\n";
                }
            }
        }
        
        return s;
    }

    public class Path
    {
        public int [] distance;
        public int [] path;
    }

    Path shortestPath(int startVertex)
    {
        int [] distance = new int[_n];
        int [] path = new int[_n];

        boolean [] visited = new boolean[_n];

        int MaxDistance = 1000000000;
        for (int i=0; i < _n; i++)
        {
            distance[i] = MaxDistance;
        }
        distance[startVertex] = 0;

        path[startVertex] = startVertex;

        while (true)
        {
            int u = -1;
            for (int i = 0; i < _n; i++)
            {
                if (!visited[i])
                {
                    if (u < 0 || distance[i] < distance[u])
                    {
                        u=i;
                    }
                }
            }

            if (u == -1)
            {
                break;
            }

            visited[u]=true;

            for (int z = 0; z < _n; z++)
            {
                if (_adjacent[u][z])
                {
                    if (distance[z] > distance[u] + _weight[u][z])
                    {
                        distance[z] = distance[u] + _weight[u][z];
                        path[z] = u;
                    }
                }
            }
        }

        Path p = new Path();
        p.distance = distance;
        p.path = path;

        return p;
    }
}

