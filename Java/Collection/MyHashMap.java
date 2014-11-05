import java.util.*;

public class MyHashMap
{
    public static void main(String args[])
    {
        HashMap<Integer, String> hm = new HashMap<Integer, String>();

        hm.put(1, "one");
        hm.put(2, "two");
        hm.put(3, "three");

        hm.get(1);                      // return value of this key
        hm.remove(3);                   // remove elem key 3
        hm.replace(1, "hundred");       // replace old key-value into new key-value
        hm.size();                      // return size of continer

        System.out.println(hm);
    }
}