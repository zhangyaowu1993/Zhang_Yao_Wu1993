import java.util.*;

public class MyArrayList
{
    public static void main(String args[])
    {
        ArrayList<String> al1 = new ArrayList<String>();
        al1.add("World");                          // add item
        al1.add(0, "Hello");                       // add item in location 0

        ArrayList<String> al2 = new ArrayList<String>();
        al2.addAll(al1);
        al2.add("Hello");
        al2.add("People");

        System.out.println(al2.contains("Hello")); // contains object
        System.out.println(al2.get(1));            // return index 1 object
        System.out.println(al2.indexOf("Hello"));  // return object "Hello" index
        System.out.println(al2.isEmpty());         // return container is empty
        System.out.println(al2.remove(1));         // remove object index 1
        System.out.println(al2.remove("Hello"));   // remove object "People" once
        al2.set(1, "World");                       // set index 1 object to "World"
        System.out.println(al2.size());            // return size of container
        Object arr[] = al2.toArray();              // transform ArrayList to Array
        System.out.println(al2);                   // print container
    }
}