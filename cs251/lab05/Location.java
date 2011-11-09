import javax.swing.*; 
import javax.swing.event.*; 
import javax.swing.text.*; 
import javax.swing.border.*; 
import javax.swing.colorchooser.*; 
import javax.swing.filechooser.*; 
import javax.accessibility.*; 

import java.awt.*; 
import java.awt.Color;
import java.awt.BorderLayout;
//
import java.awt.event.*; 
import java.beans.*; 
import java.util.*; 
import java.io.*; 
import java.applet.*; 
import java.net.*;




class Location extends JPanel{
	private String name;
	private int x, y, id;
	
	public Location(){
	}
	
	public Location(int xIn, int yIn){
		x = xIn;
		y = yIn;
	}
	
	public Location(String nameIn, int xIn, int yIn, int idIn){
		name = nameIn;
		x = xIn;
		y = yIn;
		id = idIn;
	}
	
	public void setName(String nameIn){
		name = nameIn;
	}
	
	public void setCoor(int xIn, int yIn){
		x = xIn;
		y = yIn;
	}
	
	public void setId(int idIn){
		id = idIn;
	}
	
	public String getName(){
		return name;
	}
	
	public int getX(){
		return x;
	}
	
	public int getY(){
		return y;
	}
	
	public void setX(int xIn){
		x = xIn;
	}
	
	public void setY(int yIn){
		y = yIn;
	}
	
	public int getId(){
		return id;
	}
	
	public void paint(Graphics g){
		g.fillOval(x-8, y-8, 16, 16);
	}
}

