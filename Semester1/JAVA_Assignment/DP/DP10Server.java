import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class DP10Server {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(888);
        Socket socket = serverSocket.accept();
        System.out.println("Connection established");
        PrintStream printStream = new PrintStream(socket.getOutputStream());
        BufferedReader clientInput = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        BufferedReader keyboardInput = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String clientString;
            while ((clientString = clientInput.readLine()) != null) {
                LocalDateTime myDateObj = LocalDateTime.now();
                DateTimeFormatter myFormatObj;
                String formattedDate = "";
                switch (clientString) {
                    case "dd/MM/yyyy HH:mm:ss":
                        myFormatObj = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
                        formattedDate = myDateObj.format(myFormatObj);
                        printStream.println(formattedDate);
                        break;
                    case "yyyy-MM-dd HH:mm:ss":
                        myFormatObj = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
                        formattedDate = myDateObj.format(myFormatObj);
                        printStream.println(formattedDate);
                        break;
                    default:
                        myFormatObj = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
                        formattedDate = myDateObj.format(myFormatObj);
                        printStream.println(formattedDate);
                        break;
                }
            }
            System.out.println("Connection closed!");
            clientInput.close();
            printStream.close();
            keyboardInput.close();
            serverSocket.close();
            socket.close();
            break;
        }
    }
}
