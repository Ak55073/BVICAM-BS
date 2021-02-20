import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class DP8Client {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("localhost", 888);
        DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());
        BufferedReader serverInput = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        BufferedReader keyboardInput = new BufferedReader(new InputStreamReader(System.in));
        String clientString, serverString;
        System.out.print("Enter Employee ID: ");
        while (!(clientString = keyboardInput.readLine()).equals("exit")) {
            dataOutputStream.writeBytes(clientString + "\n");
            serverString = serverInput.readLine();
            System.out.println(serverString);
            System.out.print("Enter Employee ID: ");
        }
        dataOutputStream.close();
        serverInput.close();
        keyboardInput.close();
        socket.close();
    }
}
