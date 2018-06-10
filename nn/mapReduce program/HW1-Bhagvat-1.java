//filewrite1.java writes the contents into the input file named "inputFile24" located on the desktop of the virtual machine.
//But before writing the contents, this input file must already exist on the virtual machine desktop.  Only desktop on virtual machine.
//You must create this file first on the virtual machine desktop and save it without writing code or using command prompt.
//Once that is done, then you can run filewrite1.java by clicking on the run button in Eclipse which will then write the contents into inputFile24
//The card suit type and number will be displayed with no comma in between them.  Once you run filewrite1.java, then 100 deck of cards will be displayed into input file.



import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;


public class filewrite1
{
 public static String filename="/home/cloudera/Desktop/inputFile24";
 
 public static void main(String[] args)
 {
	 BufferedWriter writer1=null;
	 FileWriter writer2=null;
	 
	 try
	 {
		 String fileStuff="hearts Ace\nhearts 2\nhearts 3\nhearts 4\nhearts 5\nhearts 6\nhearts 7\nhearts 8\nhearts 9\nhearts 10\nhearts Jack\nhearts Queen\nhearts King\nclubs Ace\nclubs 2\nclubs 3\nclubs 4\nclubs 5\nclubs 6\nclubs 7\nclubs 8\nclubs 9\nclubs 10\nclubs Jack\nclubs Queen\nclubs King\nspade Ace\nspade 2\nspade 3\nspade 4\nspade 5\nspade 6\nspade 7\nspade 8\nspade 9\nspade 10\nspade Jack\nspade Queen\nspade King\ndiamonds Ace\ndiamonds 2\ndiamonds 3\ndiamonds 4\ndiamonds 5\ndiamonds 6\ndiamonds 7\ndiamonds 8\ndiamonds 9\ndiamonds 10\ndiamonds Jack\ndiamonds Queen\ndiamonds King\nJoker\nJoker\n";
		 writer2=new FileWriter(filename);
	     writer1=new BufferedWriter(writer2);
	     for(int i=0; i<100; i++)
	     {
	     writer1.write(fileStuff);
	     }
	  
	     if(writer1!=null)
	     {
	    	 writer1.close();
	     }
	     if(writer2!=null)
	     {
	    	 writer2.close();
	     }
	     
	 }
	 catch(IOException e)
	 {
		 
	 }
	
 }
}

