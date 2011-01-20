public class ChallengeProblem
{
 public static void main(String args[])
 {
   // declare array of integers
   int data[] = { 3, 43, 129, 32, 400, 452, 5 };
   
   // declare bins
   int bin1[], bin2[], bin3[];
   
   // declare bin sorters, and separate data
   BinSorter bs1 = new BinSorter(data, 0, 120);
   BinSorter bs2 = new BinSorter(data, 121, 240);
   BinSorter bs3 = new BinSorter(data, 241, 500);
   
   // start all threads
   bs1.start();
   bs2.start();
   bs3.start();
   
   // synchronize threads
   try
   {
     bs1.join();
     bs2.join();
     bs3.join();
   }
   catch (Exception e)
   {
   }
   
   // print results
   bs1.printResults();
   bs2.printResults();
   bs3.printResults();
 }
}