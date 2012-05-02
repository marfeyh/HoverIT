/*
 * @author : Aida Monzavi,Massih Mozahhebi
 * This class create a socket accordig to the given IP and port and send the messages that
 * user enter  
 * */
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

public class telnetMain {

	/**
	 * @param args
	 */
	Socket socket;
	int port = 2000;
	String MAC = "00:06:66:13:c8:7b";

	public telnetMain() {
		try {
//			DatagramSocket dSocket = new DatagramSocket(55555);		
			telcl();

		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void telcl() throws UnknownHostException, IOException {
		Socket soc = new Socket("192.168.1.2", port);

		DataInputStream din = new DataInputStream(soc.getInputStream());
		DataOutputStream dout = new DataOutputStream(soc.getOutputStream());
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String H = "";

		System.out.println(din.available());
		// dout.writeUTF(Password);
		// soc.close();
		while (true) {
			while (din.available() > 0) {
				H = H + din.read();
			}
			System.out.println(H);
			H = "";
			dout.writeByte(br.readLine().charAt(0));
		}

	}

	public static void main(String[] args) {
		telnetMain t = new telnetMain();

	}

}
