import java.math.*;
import java.util.*;
import java.io.*;
public class Main{
    public static void main(String args[]){
        InputStream is = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(is);
        PrintWriter out = new PrintWriter(outputStream);



        out.close();
    }
}
class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;
    public InputReader(InputStream is) {
        reader = new BufferedReader(new InputStreamReader(is));
        tokenizer = null;
    }
    public void getToken() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
    public boolean hasNext() {
        try {
            getToken();
        } catch (Exception e) {
            return false;
        }
        return true;
    }
    public String next() {
        getToken();
        return tokenizer.nextToken();
    }
    public int nextInt() {
        return Integer.parseInt(next());
    }
    public long nextLong() {
        return Long.parseLong(next());
    }
}
