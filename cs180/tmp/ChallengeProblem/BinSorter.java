public class BinSorter extends Thread
{
  int data[];
  int min;
  int max;
  
  int bin[];
  
  public BinSorter(int data[], int min, int max)
  {
    this.data = data;
    this.min = min;
    this.max = max;
  }
  
  public void run()
  {
    // sort the data
    for (int n = 0; n < data.length; n++)
    {
      for (int i = 0; i < data.length-1; i++)
      {
        if (data[i] > data[i + 1])
        {
          int temp = data[i];
          data[i] = data[i+1];
          data[i+1] = temp;
        }
      }
    }
  }
  
  public void printResults()
  {
    for (int i = 0; i < data.length; i++)
    {
      if (data[i] >= min &&
          data[i] <= max)
      {
        System.out.print(data[i] + " "); 
      }
    }
    System.out.println();
  }
}