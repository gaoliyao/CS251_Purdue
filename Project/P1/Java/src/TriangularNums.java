
/**
 * Read a file that contains 2 lines:
 * <p>
 * <ol>
 *     <li>There are 2 numbers in this line:
 *         <ul>
 *             <li>First one specifies maximum digits allowed for each number.</li>
 *             <li>Second one specifies X such that if current line in output has C numbers, then next line has C+X numbers.
 *                  The last line in the output can ignore this rule if numbers provided cannot fill up the last line.
 *             </li>
 *         </ul>
 *     </li>
 *     <li>Sequence of numbers.</li>
 * </ol>
 * writeToFile() writes the string of these numbers which are in triangular pattern to a file.
 * All numbers are <b>left justified</b>.
 * There is no "\n" at the end of the last line.
 *
 * E.g.
 * Input file:
 * 2 2
 * 1 2 3 4 5 6 7 8 9 10
 *
 * Output:
 * | 1  |
 * | 2  | 3  | 4  |
 * | 5  | 6  | 7  | 8  | 9  |
 * | 10 |
 *
 * @author Hongxin Chu
 */
public class TriangularNums {

    /**
     * Construct a new TriangularNums object.
     * @param inputPath Path of the input file.
     */
    public TriangularNums(String inputPath) {
        throw new NotImplementedException();
    }

    /**
     * Writes the string of numbers which are in triangular pattern to a file.
     * Make sure you flush the content to file instead of keeping the string inside the buffer.
     * Make sure no output stream is open when return.
     * @param filePath The path of the file to write.
     */
    public void writeToFile(String filePath) {
        throw new NotImplementedException();
    }
}
