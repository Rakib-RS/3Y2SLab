import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class MailSentMe{
     public static void main(String[] args) throws Exception{
        Socket socket = new Socket("127.0.0.1",25);
        PrintWriter pw = new PrintWriter(socket.getOutputStream(),true);
        BufferedReader br = new  BufferedReader(new InputStreamReader(socket.getInputStream()));
        pw.println("HELO "+"cse");
        System.out.println("Response1 : " + br.readLine());
        //.println("MAIL FROM:" + " rakib@rakibDomain");
        //pw.println("MAIL FROM:"+" rakib@rakibDomain");
        //.out.println("Response2 :" +  br.readLine());
        for (int i =0; i<10000000;i++){
        pw.println("MAIL FROM:"+" rakib@cse");
        System.out.println("Response2: " + br.readLine());
        pw.println("RCPT TO:" + " bepul@cse");
        System.out.println("Response3 :" + br.readLine());
        pw.println("DATA");
        System.out.println("Response4 :" + br.readLine());
            String s = "pagol" + i +"new" + i;
        pw.println("Subject: "+ s);
        pw.println();
        pw.println("Hello mojid mama, mamir ki khobor");
        pw.println();
        pw.println(".");

        System.out.println("Response 5 :" + br.readLine());
        }



    }
}