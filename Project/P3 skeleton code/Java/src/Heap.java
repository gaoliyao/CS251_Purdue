import java.io.PrintStream;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Heap {

    private static final int BRANCHES = 2;

    private int[] heap;
    private int size;

    /**
     * Construct a new heap
     */
    public Heap() {
        throw new NotImplementedException();
    }

    /**
     * Insert element into this heap
     */
    public void insert(int e) {
        throw new NotImplementedException();
    }

    /**
     * Return number of elements in this heap
     * @return size of the heap
     */
    public int size() {
        throw new NotImplementedException();
    }

    /**
     * Peek the smallest element in this heap
     * @throws NoSuchElementException if heap is empty
     * @return the smallest element in this heap.
     */
    public int min() {
        throw new NotImplementedException();
    }

    /**
     * Remove the smallest element in this heap
     * @throws NoSuchElementException if heap is empty
     * @return the smallest element in this heap
     */
    public int removeMin() {
        throw new NotImplementedException();
    }

    /**
     * Return a sorted array of this heap.
     * Call removeMin until all elements are removed from the heap.
     * @return a sorted array of this heap
     */
    public int[] sort() {
        throw new NotImplementedException();
    }

    /**
     * Read in an input file and write output to output stream
     * Scanner in starts from the beginning of the file
     * @param in input Scanner
     * @param out output PrintStream
     */
    public void generateOutput(Scanner in, PrintStream out) {
        throw new NotImplementedException();
    }

    private void resize() {
        throw new NotImplementedException();
    }

}
