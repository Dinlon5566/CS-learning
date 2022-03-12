import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.Buffer;

public class Server {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket=new ServerSocket(20123);
        System.out.println("Server address: "+serverSocket.getInetAddress());

        //wait client connect
        Socket client =serverSocket.accept();
        todo(client);
        //
        ClientHandler clientHandler=new ClientHandler(client);
        //start
        clientHandler.start();


    }
    private static class ClientHandler extends Thread{
        private Socket socket;
        private boolean flag=true;
        ClientHandler(Socket socket){
            this.socket=socket;
        }

        @Override
        public void run() {
            super.run();
            System.out.println("new Cliner address: "+socket.getInetAddress()+" P : "+socket.getPort());
            try{
                PrintStream socketPrint=new PrintStream(socket.getOutputStream());
                BufferedReader socketInput=new BufferedReader(new InputStreamReader(socket.getInputStream()));
                do{
                    String str=socketInput.readLine();
                    if("bye".equalsIgnoreCase(str)||"null".equalsIgnoreCase(str)){
                        flag=false;
                    }else{
                        System.out.println(str);
                        socketPrint.println("reback!"+str.length());
                    }

                }while(flag);
                socketInput.close();
                socketPrint.close();

            }catch (Exception e){
                System.out.println("Exception disconnect");
            }finally {
                try {
                    socket.close();
                }catch (IOException e){
                    e.printStackTrace();
                }
                System.out.println("disconnect success!");
            }

        }
    }
    private static void todo(Socket client)throws IOException{

    }
}
