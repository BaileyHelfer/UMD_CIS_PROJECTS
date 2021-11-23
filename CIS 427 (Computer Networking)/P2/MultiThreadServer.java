/*
 * Server.java
 */

import java.io.*;
import java.net.*;
import java.util.*;
import java.util.ArrayList;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.*;

public class MultiThreadServer {

    public static final int SERVER_PORT = 5432;
	public static ArrayList<Record> recordList = new ArrayList<Record>(); 
	public static int counter = 0;
    public static void main(String args[]) 
    {
	ServerSocket myServerice = null;
	Socket serviceSocket = null;

	// Try to open a server socket 
	try {
	    myServerice = new ServerSocket(SERVER_PORT);
	}
	catch (IOException e) {
	    System.out.println(e);
	}   
	
	
	//Append record to Data Structure
	try
	{
	clearFile();
	addRecord("root","lastname","313-232-1123");
	printFile(recordList);
	addRecord("john","smith","248-232-9012");
	printFile(recordList);
	addRecord("david","johnson","734-456-1211");
	printFile(recordList);
	addRecord("marry","lamb","248-343-1121");
	printFile(recordList);
	}
	catch(IOException e)
	{

	}
	// Create a socket object from the ServerSocket to listen and accept connections.
	while (true)
	{
	    try 
	    {
		// Received a connection
		serviceSocket = myServerice.accept();
		System.out.println("MultiThreadServer: new connection from " + serviceSocket.getInetAddress());
		// Create and start the client handler thread
		ChildThread cThread = new ChildThread(serviceSocket,recordList);
		cThread.start();
		
	    }   
	    catch (IOException e) 
	    {
		System.out.println(e);
	    }
		
	}
	
    }
	public static void addRecord(String firstName,String lastName, String phoneNumber)
			{
				int id = counter + 1001;
				//Create a new object of type Record with given attributes 
				Record newPerson = new Record(id,firstName,lastName,phoneNumber);
				//Append record to Data Structure
				recordList.add(newPerson);
				// System.out.println("200 OK");
				// System.out.println("The new Record ID is "+id);
				counter ++;
			}
	public static void printFile(ArrayList<Record> list)throws IOException
			{
				Path fileName = Path.of("output.txt");
				String content = "";
				//gets the attributes of the added record and stores in string
				content = list.get(list.size()-1).getId() + "	" + list.get(list.size()-1).getFirst() + " " + list.get(list.size()-1).getLast()+ "		" + list.get(list.size()-1).getPhone() + "\n";			
				//Append this string to our "output.txt" file
				Files.writeString(fileName,content,StandardOpenOption.APPEND);		
			}
	public static void clearFile()throws IOException
			{
				Path fileName = Path.of("output.txt");
				Files.writeString(fileName,"");
			}
}
