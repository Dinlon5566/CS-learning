import java.io.*;
import java.net.Inet4Address;
import java.net.InetSocketAddress;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException {
        System.out.println("發起連接...");
        Socket socket =new Socket();
        socket.setSoTimeout(3000);


        try{
            socket.connect(new InetSocketAddress(Inet4Address.getLocalHost(),20123),3000);
        }catch (IOException e){
        System.out.println("發起連接失敗");
        System.out.println(e.getMessage());
        return;
        }


        System.out.println("已發起連接");
        System.out.println("Client address: "+socket.getLocalAddress()+" P : "+socket.getLocalPort());
        System.out.println("Server address: "+socket.getInetAddress()+" P : "+socket.getPort());
        try{
            todo(socket);
        }catch (IOException e){
            System.out.println("Error in todo!");
        }
        socket.close();
        System.out.println("Client close!");
    }

    private static void todo(Socket client) throws IOException{

        //keyboard input
        InputStream in=System.in;
        BufferedReader input = new BufferedReader(new InputStreamReader(in));

        //to get socket outputStream,and change to printStream.
        OutputStream outputStream=client.getOutputStream();
        PrintStream socketPrintStream=new PrintStream(outputStream);

        InputStream inputStream = client.getInputStream();
        BufferedReader socketInput = new BufferedReader(new InputStreamReader(inputStream));


        boolean outflag=true;
        do{
            //read a line foram keyboard
            String str=input.readLine();
            //print to socket
            socketPrintStream.println(str);

            String echo=socketInput.readLine();

            if("bye".equalsIgnoreCase(echo)||"null".equalsIgnoreCase(echo)){
                outflag=false;
            }else{
                System.out.println(echo);
            }
        }while (outflag);

    }
}
