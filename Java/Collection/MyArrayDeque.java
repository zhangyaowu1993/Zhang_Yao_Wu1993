import java.util.*;

public class MyArrayDeque
{
    public static void main(String args[])
    {
        ArrayDeque<Integer> ad = new ArrayDeque<Integer>();

        ad.add(1);
        ad.add(2);
        ad.add(3);

        ad.addFirst(0);                         // add elem in deque head
        ad.addLast(4);                          // add elem in deque tail
        ad.contains(2);                         // container contains elem 2
        ad.element();                           // get the first elem in deque but do not delete it
        ad.getFirst();                          // get the first elem in deque but do not delete it
        ad.getLast();                           // get the last elem in deque but do not delete it
        ad.isEmpty();                           // return true if container is empty
        ad.offer(5);                            // add elem in deque tail
        ad.offerFirst(-1);                      // add elem in deque head
        ad.offerLast(6);                        // add elem in deque tail
        ad.peek();                              // get the first elem in deque but do not delete it
        ad.peekFirst();                         // get the first elem in deque but do not delete it
        ad.peekLast();                          // get the last elem in deque but do not delete it
        ad.poll();                              // get the first elem in deque and delete it
        ad.pollFirst();                         // get the first elem in deque and delete if
        ad.pollLast();                          // get the last elem in deque and delete it
        ad.remove(1);                           // remove elem , auto boxing worked
        //ad.remove(int);
        ad.size();                              // return size of deque
        Object arr[] = ad.toArray();            // transform ArrayDeque to Array

        System.out.println(ad);
    }
}