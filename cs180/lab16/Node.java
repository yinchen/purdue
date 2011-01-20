//node class
// holds a value and a left and right value
public class Node {
	
	private Node left, right;
	private int value;
	
	//creates a node w/ null child nodes and value from the paramater
	public Node(int value) {
		this.value=value;
		left=null;
		right=null;
	}
	
	//creates a node with value from the paramater and one child node specified by 1 for right or 2 for left
	public Node(int value, Node node, int side) {
		this.value=value;
		if(side==0) {
			this.right=right;
			left=null;
		}
		else {
			this.value=value;
			this.left=left;
			right=null;
		}
	}
	
	//creates a node w/ 2 child nodes
	public Node(int value, Node right, Node left) {
		this.value=value;
		this.left=left;
		this.right=right;
	}
	
	//sets left node
	public void setLeft(Node left) {
		this.left=left;
	}
	
	//sets right node
	public void setRight(Node right) {
		this.right=right;
	}
	
	public Node getLeft() {
		return left;
	}
	
	//gets right node
	public Node getRight() {
		return right;
	}
	
	//gets left node
	public int getValue() {
		return value;
	}
	
	//either adds a node to current tree or tells the child with a shorter depth to add
	public void add(Node node) {
		if(left==null)
			left=node;
		else if(right==null)
			right=node;
		else {
			int l=left.getDepth();
			int r=right.getDepth();
			if(l<=r)
				left.add(node);
			else
				right.add(node);
		}
	}
	
	//returns the shortest depth of a child node
	public int getDepth() {
		int r;
		int l;
		if(right==null)
			r=0;
		else
			r=right.getDepth()+1;
		if(left==null)
			l=0;
		else
			l=left.getDepth()+1;
		if(l<=r)
			return l;
		else
			return r;
	}
}
