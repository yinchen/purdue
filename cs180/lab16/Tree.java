public class Tree {
 
 private Node head; //head node
 
 //creates an empty tree
 public Tree() {
  head=null;
 }
 
 //creates a tree w/ head as the head
 public Tree(Node head) {
   this.head=head;
  }
 
 //returns head
 public Node getHead() {
  return head;
 }
 
 //sets head
 public void setHead(Node Head) {
  this.head=head;
 }
 
 //sets as head if null, otherwise adds to head
 public void add(int value) {
   if(head==null)
    head=new Node(value);
   else
    head.add(new Node(value));
 }
 
 //TODO: wirte a method to sum all values
 public int addTree(Node node) {
   int sum = node.getValue();
   if (node.getRight() != null){
       sum = sum + addTree(node.getRight());
   }
   
   if (node.getLeft() != null) {
       sum = sum + addTree(node.getLeft());
   }
   
   return sum;
 }
 
 //TODO: write a print all nodes starting a the left most and working the way up
 public void printTree(Node node) {
   if (node.getLeft() != null) {
       printTree(node.getLeft());
   }else{
       System.out.print(node.getValue() + " ");
       return;
   }
   
   System.out.print(node.getValue() + " ");
   
   if (node.getRight() != null){
       printTree(node.getRight());
   }else{
       System.out.print(node.getValue() + " ");
       return;
   }
 }
}
