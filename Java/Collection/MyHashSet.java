import java.util.*;

public class MyHashSet
{
    public static void main(String args[])
    {
        HashSet<Integer> hs = new HashSet<Integer>();
        hs.add(1);
        hs.add(2);
        hs.add(3);
        hs.add(4);
        hs.add(4);                              // add fail, set not allow two same elem
        hs.contains(3);                         // return true if container contains value 3
        hs.isEmpty();                           // return true if container empty
        hs.remove(2);                           // remove object 2 
        hs.size();                              // return container size

        System.out.println(hs);
    }
}