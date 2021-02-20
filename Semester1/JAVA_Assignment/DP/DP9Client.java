import java.io.IOException;
import java.net.*;
import java.util.Scanner;

public class DP9Client {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        DatagramSocket datagramSocket = new DatagramSocket(123);

        InetAddress ip = InetAddress.getLocalHost();
        byte buf[] = null;
        byte[] receive = new byte[65535];

        DatagramPacket datagramPacketReceiver;
        System.out.print("Enter time format: ");
        while (true) {
            String inp = sc.nextLine();
            buf = inp.getBytes();
            DatagramPacket DpSend = new DatagramPacket(buf, buf.length, ip, 1234);
            datagramSocket.send(DpSend);
            if (inp.equals("bye"))
                break;

            datagramPacketReceiver = new DatagramPacket(receive, receive.length);
            datagramSocket.receive(datagramPacketReceiver);
            System.out.println(data(receive).toString());
            System.out.print("Enter time format: ");
        }
    }

    public static StringBuilder data(byte[] a) {
        if (a == null)
            return null;
        StringBuilder ret = new StringBuilder();
        int i = 0;
        while (a[i] != 0) {
            ret.append((char) a[i]);
            i++;
        }
        return ret;
    }
}
