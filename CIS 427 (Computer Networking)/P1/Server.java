import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.*;


public class Server {    
	public static final int SERVER_PORT = 5432;
	
	//Creates DataStructure to hold Records
	public static ArrayList<Record> recordList = new ArrayList<Record>(); 
	
	//Counter to name ID of record
	public static int counter = 0;
	
	
	public static void main(String args[])
	{
		
		
		ServerSocket myServerice = null;
		String line;
		BufferedReader is;
		PrintStream os;
		Socket serviceSocket = null;

		// Try to open a server socket 
		try 
		{    
			myServerice = new ServerSocket(SERVER_PORT);
			}
		catch (IOException e) 
		{    
			System.out.println(e);
			}  
		// Create a socket object from the ServerSocket to listen and accept connections.
		// Open input and output stream
		while (true)
		{    
			try     
			{
				serviceSocket = myServerice.accept();
				is = new BufferedReader (new InputStreamReader(serviceSocket.getInputStream()));
				os = new PrintStream(serviceSocket.getOutputStream());
				
				
				
				// As long as we receive data, echo that data back to the client.
				while ((line = is.readLine()) != null) 
				{    
					os.println(line);
					//Parses the user input into an array
					String[] userInput = line.split(" "); 
					//Switch statement that grabs the first word of userInput to decide which function to run 
					switch (userInput[0])
					{
					case "ADD":
						//Error handling that checks to see if the right amount of arguments are in userInput
						if (userInput.length==4) {
						//Splits input into corresponding attributes for Record Class
						String firstName = userInput[1];
						String lastName = userInput[2];
						String phoneNumber = userInput[3];
						//Adds a record to our record book and gives it the corresponding attributes
						addRecord(firstName,lastName,phoneNumber);
						//Adds record to our "output.txt" file
						printFile(recordList);
						}
						else
						{
							System.out.println("ADD function in wrong format");
						}
						break;
					case "DELETE":
						//Error handling that checks to see if the right amount of arguments are in userInput
						if (userInput.length == 2)
						{
						//Splits input into corresponding attributes for Record Class
						String id = userInput[1];
						//Removes the user with the following id out of our record book
						removeRecord(id);
						//Removes all users from "output.txt" file
						clearFile();
						//Adds all BUT deleted user to "output.txt" file
						printRemove(recordList);
						}
						else
						{
							System.out.println("DELETE function in wrong format");
						}
						
						break;
					case "LIST":
						//Error handling that checks to see if the right amount of arguments are in userInput
						if (userInput.length == 1)
						{
							System.out.println("200 OK" + "\n"+"The list of records in the book:");
							//Prints the records held in record book 
							printList();
						}
						else
						{
							System.out.println("LIST function in wrong format");
						}
						break;
					case "SHUTDOWN":
						//Error handling that checks to see if the right amount of arguments are in userInput
						if (userInput.length == 1)
						{
						System.out.println("200 OK");
						try {
						//Closes connection to server and client 
						is.close();
						os.close();
						serviceSocket.close();
						}
						catch (IOException e)
						{
							System.out.println(e);
						}
						}
						else
						{
							System.out.println("SHUTDOWN function in wrong format");
						}
						break;
					case "QUIT":
						//Error handling that checks to see if the right amount of arguments are in userInput
						if (userInput.length == 1)
						{
						System.out.println("200 OK");
						}
						else
						{
							System.out.println("QUIT function in wrong format");
						}
						break;
					default:
						//Error handling that executes if the user enters in wrong command
						System.out.println("Incorrect Input");
						break;
					}
					}
				//close input and output stream and socket
				is.close();
				os.close();
				serviceSocket.close();
				}       
			catch (IOException e)
			{
				System.out.println(e);
			}
			}    
		}
			//Returns the size of our DataStructure holding records
			public static int getRecordPos()
			{
				return recordList.size();
			}
			//Removes a record with the given id from out Data Structure
			public static void removeRecord(String id)
			{
				int realInt = Integer.parseInt(id);
				int index = -1;
				//Checks to see if record is in record book
				for(int i = 0;i < getRecordPos();i++)
				{
					if (recordList.get(i).getId() == realInt)
					{
						index = i;
					}
				}
				//If record not in record book, print to server error.
				if (index == -1)
				{
					System.out.println("Error no record with id: "+id + " in record book");
				}
				//If record is in record book, remove from Data Structre
				else
				{
				recordList.remove(index);
				System.out.println("200 OK");
				}
				
			}
			//Appends a record to out record book with the given attributes
			public static void addRecord(String firstName,String lastName, String phoneNumber)
			{
				int id = counter + 1001;
				//Create a new object of type Record with given attributes 
				Record newPerson = new Record(id,firstName,lastName,phoneNumber);
				//Append record to Data Structure
				recordList.add(newPerson);
				System.out.println("200 OK");
				System.out.println("The new Record ID is "+id);
				counter ++;
			}
			//Prints record to file when a new person is added
			public static void printFile(ArrayList<Record> list) throws IOException
			{
				Path fileName = Path.of("output.txt");
				String content = "";
				//gets the attributes of the added record and stores in string
				content = list.get(list.size()-1).getId() + "	" + list.get(list.size()-1).getFirst() + " " + list.get(list.size()-1).getLast()+ "		" + list.get(list.size()-1).getPhone() + "\n";			
				//Append this string to our "output.txt" file
				Files.writeString(fileName,content,StandardOpenOption.APPEND);

				
			}
			//Prints new record book to "output.txt" after record has been deleted
			public static void printRemove(ArrayList<Record> list) throws IOException
			{
				Path fileName = Path.of("output.txt");
				String content = "";
				//Appends to our record book after deleting going for the size of new Data Structure 
				for (int i = 0;i<list.size();i++)
				{
					content = list.get(i).getId() + "	" + list.get(i).getFirst() + " " + list.get(i).getLast()+ "		" + list.get(i).getPhone()+"\n";			
					Files.writeString(fileName,content,StandardOpenOption.APPEND);

				}
				
				
			}
			//Clears out "output.txt"
			public static void clearFile()throws IOException
			{
				Path fileName = Path.of("output.txt");
				Files.writeString(fileName,"");
			}
			//Prints the list of records in record book
			public static void printList()
			{
				//Checks if record book is empty
				if (recordList.size() == 0)
				{
					System.out.println("LIST is empty");
				}
				else
				{
				//Prints out records at each index
				for(int i = 0;i<getRecordPos();i++)
				{
					recordList.get(i).printRecord();
				}
				}
			}
	}
