package Chapter_17;

import java.io.*;

public class UTF {
	public static void main(String[] args) throws IOException {
		try (
				BufferedReader input = new BufferedReader(new FileReader("input.txt"));
				DataOutputStream output = new DataOutputStream(new FileOutputStream("output.dat"));
				) {
			String line;
			while ((line = input.readLine()) != null)
				output.writeUTF(line);
		}

		try (
				InputStream input1 = new FileInputStream("input.txt");
				InputStream input2 = new FileInputStream("output.dat");
				) {
			System.out.println("input.txt" + "'s size is " + input1.available() + " bytes");
			System.out.println("output.dat" + "'s size is " + input2.available() + " bytes");
		}
	}
}
