import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class DP9Server {
    public static void main(String[] args) throws IOException {

        DatagramSocket datagramSocket = new DatagramSocket(1234);
        byte[] receive = new byte[65535];
        InetAddress ip = InetAddress.getLocalHost();

        DatagramPacket datagramPacketReceiver = null;
        while (true) {

            datagramPacketReceiver = new DatagramPacket(receive, receive.length);

            datagramSocket.receive(datagramPacketReceiver);

            if (data(receive).toString().equals("bye")) {
                System.out.println("Client sent bye.....EXITING");
                break;
            } else {
                LocalDateTime myDateObj = LocalDateTime.now();
                DateTimeFormatter myFormatObj;
                String formattedDate = "";
                byte[] buf;
                DatagramPacket DpSend;
                switch (data(receive).toString()) {
                    case "dd/MM/yyyy HH:mm:ss":
                        myFormatObj = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
                        formattedDate = myDateObj.format(myFormatObj);
                        buf = formattedDate.getBytes();
                        DpSend = new DatagramPacket(buf, buf.length, ip, 123);
                        datagramSocket.send(DpSend);
                        break;
                    case "yyyy-MM-dd HH:mm:ss":
                        myFormatObj = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
                        formattedDate = myDateObj.format(myFormatObj);
                        buf = formattedDate.getBytes();
                        DpSend = new DatagramPacket(buf, buf.length, ip, 123);
                        datagramSocket.send(DpSend);
                        break;
                    default:
                        myFormatObj = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
                        formattedDate = myDateObj.format(myFormatObj);
                        buf = formattedDate.getBytes();
                        DpSend = new DatagramPacket(buf, buf.length, ip, 123);
                        datagramSocket.send(DpSend);
                        break;
                }
            }

            receive = new byte[65535];
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
