import java.io.PrintStream;
import java.util.*;

/**
 * Generic Chaining Hashtable
 * @param <K> Key type
 * @param <V> Value type
 */
public class HashTable<K, V> {

    /**
     * Auxiliary class for HashTable
     * @param <F> Key type
     * @param <S> Value type
     */
    public class Pair<F, S> {
        public F key;
        public S value;

        /**
         * Construct a key value Pair
         * @throws NullPointerException if key is null
         * @param key key
         * @param value value
         */
        public Pair(F key, S value) {
            if(key == null) {
                throw new NullPointerException("Key cannot be null");
            }
            this.key = key;
            this.value = value;
        }

        @Override
        public boolean equals(Object other) {
            if(! (other instanceof Pair)) {
                return false;
            }
            @SuppressWarnings("unchecked")
            Pair<?, ?> po = (Pair) other;
            // Hack here. We only compare key value
            // so that we can use it to call List.contains
            return key.equals(po.key);
        }
    }

    private static final int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271};

    private List<List<Pair<K, V>>> table;
    private int size;
    private int capacity;

    /**
     * Initialize an array of length capacity,
     * then initialize the table with empty Lists at each index.
     * @param capacity Initial capacity of the table.
     */
    public HashTable(int capacity) {
        throw new NotImplementedException();
    }

    /**
     * Get the hash code of key.
     * You may design any hashCode function you like.
     * @param key key
     * @return hashCode of key
     */
    private int hashCode(K key) {
        throw new NotImplementedException();
    }

    /**
     * Returns the value of the key if found, return null otherwise.
     * @param key key
     * @throws NullPointerException if key is null
     * @return Returns the value of the key if found. Otherwise, return null.
     */
    public V get(K key) {
        throw new NotImplementedException();
    }

    /**
     * Adds the (key, value) pair to the table.
     * If key already presents in the hashtable, overwrite the original value.
     * Resize the hashtable if the load factor becomes greater than 0.5 after inserting this (key, value) pair.
     * @throws NullPointerException if key or value is null
     * @param key key
     * @param value value
     * @return the previous value of the specified key in this hashtable, or null if it did not have one
     */
    public V put(K key, V value) {
        throw new NotImplementedException();
    }

    /**
     * Resize the hashtable if the load factor becomes greater than 0.5 after inserting this (key, value) pair.
     * We hard code a list of prime number for you to use. You can assume you will never run out of prime number to use.
     */
    private void resize() {
        throw new NotImplementedException();
    }

    /**
     * Removes the key from the table, if it's there.
     * @throws NullPointerException if the key is null
     * @param key key
     * @return Return the value of the key if key exists in the hashtable, return null otherwise
     */
    public V remove(K key) {
        throw new NotImplementedException();
    }

    /**
     * Returns whether the key is in the hashtable.
     * @throws NullPointerException if key is null
     * @param key key
     * @return Return true if the key is in the hashtable. Return false otherwise.
     */
    public boolean containsKey(K key) {
        throw new NotImplementedException();
    }

    /**
     * Returns the number of (key, value) pairs in the table.
     * @return size of hashtable
     */
    public int size() {
        throw new NotImplementedException();
    }

    /**
     * Replaces the value for the specified key only if it is currently mapped to some value.
     * @param key key
     * @param value value
     * @return Return the previous value associated with the specified key, or null if there was no mapping for the key.
     */
    public V replace(K key, V value) {
        throw new NotImplementedException();
    }

    /**
     * Return the chain length at index in this hashtable.
     * @param index index of the chain to get length of
     * @return chain length at index in this hashtable.
     */
    public int getCollision(int index) {
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
}
