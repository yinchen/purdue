// Matt McCormick
// Lab16.java
//simple test class to test the print tree and add tree methods
public class Lab16 {
 
 public static void main(String [] args) {
  Tree theTree=new Tree();
  fillTree(theTree);
  System.out.println("The sum of all numbers in the tree is " + theTree.addTree(theTree.getHead()));
  theTree.printTree(theTree.getHead());
  System.out.println("");
 }
 
 public static void fillTree(Tree theTree) {
  theTree.add(17);
  theTree.add(1);
  theTree.add(100);
  theTree.add(34);
  theTree.add(21);
  theTree.add(5);
  theTree.add(9);
  theTree.add(77);
  theTree.add(49);
 }
}
