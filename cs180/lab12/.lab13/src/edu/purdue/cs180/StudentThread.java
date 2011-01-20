package edu.purdue.cs180;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import android.util.Log;



public class StudentThread extends Thread {
  String name;
  public static final String TAG = "Student Thread";
  //Class<?> myClass;
  
  StudentThread(String name) {
    this.name=name;
    /*
    System.out.format("StudentThread(%s)\n", name);
    this.name = name;
    myClass = loadClass(name);
    System.out.format("loaded class %s\n", myClass);
    */
  }
  
  /*
  static Class<?> loadClass(String name) {
    Class<?> myClass = null;
    try {
      myClass = Class.forName(name);
    } catch (ClassNotFoundException e) { e.printStackTrace(); }
    return myClass;
  }
  
  
   static void runMain(Class<?> myClass) {
   Method[] myMethods = myClass.getDeclaredMethods();
   Method myMethod = null;
   
   for (int i = 0; i < myMethods.length; i++) {
   if (myMethods[i].getName().equals("main")) {
   myMethod = myMethods[i];
   break;
   }
   }
   
   try {
   myMethod.setAccessible(true);
   // TODO: Consider passing meaningful arguments here...
   String[] args = {"hello", "there"};
   Object[] myArguments = {args};
   myMethod.invoke(null, (Object[]) myArguments);
   } catch (InvocationTargetException e) {
   Throwable cause = e.getCause();
   System.out.format("invocation of %s failed: %s\n", myMethod, cause.getMessage());
   } catch (IllegalArgumentException e) { e.printStackTrace();
   } catch (IllegalAccessException e) { e.printStackTrace(); }
   }
   */
  
  public void run() {
    Class n=null;
    
    try{
      n = Class.forName(name);
    }catch(Exception e){}
    
    Method[] myMethods = n.getDeclaredMethods();
    
    Method myMethod = myMethods[0];
    //System.out.println(myMethod.toString());
    
    try {
      myMethod.setAccessible(true);
      // TODO: Consider passing meaningful arguments here...
      String[] args = {"hello", "there"};
      Object[] myArguments = {args};
      Log.i(TAG,"Starting User's Method");
      myMethod.invoke(null, (Object[]) myArguments);
    } catch (Exception e) {
    	e.printStackTrace();
    	Log.d(TAG,"Problem Executing Student Code",e);
    }
  }
  
  // TODO: Consider deleting... FROM HERE DOWN IS NOT USED BY THIS CLASS...
  
// static void loadAndRun(Context context, String name) {
//  Class<?> c = loadClass(name);
//  Object o = createObject(c);
//  String s = invokeMethod(c, o);
//        Toast.makeText(context, "hello " + name + " at " + o + " returned " + s, Toast.LENGTH_SHORT).show();
// }
// 
// static Object createObject(Class<?> myClass) {
//  Object myObject = null;
//  try {
//   myObject = myClass.newInstance();
//  } catch (Exception e) { e.printStackTrace(); }
//  return myObject;
// }
// 
// static String invokeMethod(Class<?> myClass, Object myObject) {
//  String myReturnValue = null;
//  
//     Method[] myMethods = myClass.getDeclaredMethods();
//     Method myMethod = myMethods[0];
//     
//  try {
//      myMethod.setAccessible(true);
//      Object[] myArguments = {"hello", 5};
//      myReturnValue = (String) myMethod.invoke(myObject, (Object[]) myArguments);
//  } catch (InvocationTargetException e) {
//      Throwable cause = e.getCause();
//      System.out.format("invocation of %s failed: %s\n", myMethod, cause.getMessage());
//  } catch (IllegalArgumentException e) { e.printStackTrace();
//  } catch (IllegalAccessException e) { e.printStackTrace(); }
//  return myReturnValue;
// }
}
