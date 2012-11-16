//Busy Newbie got AC somehow :)
import java.io.*;
public class Main 
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int tests=Integer.parseInt(input.readLine());
        int max=500000;
        int sum[]=new int[max];
        for(int i=1;i<max;i++)
            for(int j=2;j*i<max;j++)
                sum[j*i]+=i;
        while(tests-->0)
        {
            int num=Integer.parseInt(input.readLine());
            out.println(sum[num]);
        }
        out.flush();
    }
}

