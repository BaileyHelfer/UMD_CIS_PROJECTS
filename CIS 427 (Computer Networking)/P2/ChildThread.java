/* 
 * ChildThread.java
 */


import java.io.*;
import java.net.Socket;
import java.util.Vector;
import java.util.ArrayList;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.*;


public class ChildThread extends Thread 
{
    static  Vector<ChildThread> handlers = new Vector<ChildThread>(20);
    private Socket socket;
    private BufferedReader in;
    private PrintWriter out;
	boolean login = false;
	public static int counter = 4;
	public static String currentUser;
	public static String ipAddress;
	public static ArrayList<Record> recordList = new ArrayList<Record>();
	public static ArrayList<String> ipList = new ArrayList<String>();
	
	 

    public ChildThread(Socket socket,ArrayList<Record> tempList) throws IOException 
    {
	this.socket = socket;
	in = new BufferedReader(
	    new InputStreamReader(socket.getInputStream()));
	out = new PrintWriter(
	    new OutputStreamWriter(socket.getOutputStream()));
		recordList = tempList;
	
    }

    public void run() 
    {
	String line;
	boolean shuttingDown = false;

	synchronized(handlers) 
	{
	    //Assigns the ip addresses to the specific sockets/users
	    handlers.addElement(this);
		ipAddress = this.socket.getInetAddress().toString();
		ipAddress = ipAddress.substring(1);
		ipList.add(ipAddress);
	}

	try 
	{
	    while ((line = in.readLine()) != null) 
		{
			String[] userInput = line.split(" "); 
			//Switch statement to get the first command given by user
			switch (userInput[0])
			{
				//ADD function that adds user to record book
				case "ADD":
					//Error handling that checks to see if the right amount of arguments are in userInput
					if (userInput.length==4) {
						if(login == true)
						{
							//Splits input into corresponding attributes for Record Class
							String firstName = userInput[1];
							String lastName = userInput[2];
							String phoneNumber = userInput[3];
							//Adds a record to our record book and gives it the corresponding attributes
							addRecord(firstName,lastName,phoneNumber);
							//Adds record to our "output.txt" file
							printFile(recordList);
						}
						else{
							System.out.println("410 You are not currently logged in, login first");
						}
					}
					//Error handling if function in wrong format
					else
					{
						System.out.println("ADD function in wrong format");
					}
					break; 
					
				//DELETE function that deletes record from book
				case "DELETE":
					//Error handling that checks to see if the right amount of arguments are in userInput
					if (userInput.length == 2)
					{
						if(login == true)
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
							System.out.println("410 You are not currently logged in, login first");
						}
					}
					//Error handling if function in wrong format
					else
					{
						System.out.println("DELETE function in wrong format");
					}
					
					break;
				//LIST function that list the currnet records in the book
				case "LIST":
					//Error handling that checks to see if the right amount of arguments are in userInput
					if (userInput.length == 1)
					{
						System.out.println("200 OK" + "\n"+"The list of records in the book:");
						//Prints the records held in record book 
						printList();
					}
					//Error handling if function in wrong format
					else
					{
						System.out.println("LIST function in wrong format");
					}
					break;

				//LOGIN function that logs a user in
				case "LOGIN":
					if(userInput.length == 3)
					{
						String userId = userInput[1];
						String userPass = userInput[2];
						String clientIp = " ";
						for(int i = 0; i < handlers.size(); i++) 
							{	
								synchronized(handlers) 
								{
								ChildThread handler = (ChildThread)handlers.elementAt(i);
									if (handler == this) 
									{					
										//Gets the ip of client being called from		
										clientIp = ipList.get(i);

									}
								}
							}
						//Checks to see if user and pass match up, if do then check to login and set ip of user
						login = userLookUp(userId,userPass,clientIp);
						if (login == true)
						{
							System.out.println("200 OK");							

						}
						else
						{
							System.out.println("410 Wrong UserID or Password");
						}
					}
					//Error handling if function in wrong format
					else
					{
						System.out.println("LOOK function in wrong format");
					}
					break;

				//LOGOUT function that logs the current user out
				case "LOGOUT":
					if(userInput.length == 1)
					{

						String tempIp = this.socket.getInetAddress().toString();
						tempIp = tempIp.substring(1);	
						String username = " ";
						for(int i = 0; i <recordList.size();i++)
						{
							if (recordList.get(i).getIpAddress() != null)
							{
							
								if(recordList.get(i).getIpAddress().equals(tempIp))
								{
									username = recordList.get(i).getFirst();
								}
							}

						}


						login = false;
						for (int i =0;i < recordList.size();i++)
						{
							if (username.equals(recordList.get(i).getFirst()))
							{
								recordList.get(i).setLogOn(false);
							}
						}
						System.out.println("200 OK");
					}
					//Error handling if function in wrong format
					else
					{
						System.out.println("LOGOUT function in wrong format");
					}
					break;

				//WHO function whos displays the active connections/users
				case "WHO":
					if(userInput.length == 1 )
					{
						ArrayList<Record> loggedOn = new ArrayList<Record>(); 
						for(int i = 0;i < recordList.size();i++)
						{
							if (recordList.get(i).getLoggedOn() == true)
							{
								loggedOn.add(recordList.get(i));
							}
						}
						System.out.println("200 OK");
						System.out.println("The list of active users:\n");
						for(int i=0;i<loggedOn.size();i++)
						{
							System.out.println(loggedOn.get(i).getFirst() + "		" + loggedOn.get(i).getIpAddress());
						}
					}
					//Error handling if function in wrong format
					else
					{
						System.out.println("WHO function in wrong format");
					}
					break;
				//SHUTDOWN function who shuts down all clients and server as well
				case "SHUTDOWN":
					if(userInput.length == 1)
					{
						String currentIp = this.socket.getInetAddress().toString();
						currentIp = currentIp.substring(1);	
						String username = " ";
						for(int i = 0; i <recordList.size();i++)
						{
							if (recordList.get(i).getIpAddress() != null)
							{
							
								if(recordList.get(i).getIpAddress().equals(currentIp))
								{
									username = recordList.get(i).getFirst();
								}
							}

						}

						if(username.equals("root"))
						{

						shuttingDown = true;
						System.out.println("210 Sever is about to shutdown. . . . . .");
						this.socket.close();
						// in.close();
						// out.close();
						// socket.close();
						}
						else
						{
							System.out.println("402 User not allowed to execute this command");
						}

					}
					//Error handling if function in wrong format
					else
					{
						System.out.println("SHUTDOWN function in wrong format");
					}
					break;
				//QUIT function who quits the current client is is called from, server and other clients remain open
				case "QUIT":
				{
					if(userInput.length == 1)
					{
						if(login == true)
						{
							login = false;
							for (int i =0;i < recordList.size();i++)
							{
								if (currentUser.equals(recordList.get(i).getFirst()))
								{
									recordList.get(i).setLogOn(false);
								}
							}
						}

						in.close();
						out.close();
						socket.close();
						synchronized(handlers) 
						{
							handlers.removeElement(this);
						}
					}
					//Error handling if function in wrong format
					else
					{
						System.out.println("QUIT function in wrong format");
					}
					break;
				}
				//LOOK function who can find someone in record book based off first/last name as well as phone number
				case "LOOK":
					if(userInput.length == 3)
					{
						ArrayList<Record> lookList = new ArrayList<Record>();
						String lookType = userInput[1];
						String lookInfo = userInput[2];
						boolean match = false;

						//Case 1 = first Name
						//Case 2 = last Name
						//Case 3 = phone number
						switch (lookType)
						{
							case "1":
							match = lookFirst(lookInfo,lookList);
							if(match == false)
							{
								System.out.println("404 Your search did no match any records");
							}
							else
							{
								int numMatches = lookList.size();
								System.out.println("Found " + numMatches + " match(s)");
								for (int i = 0;i<lookList.size();i++)
								{
									lookList.get(i).printRecord();
								}
							}
							break;

							case "2":
							match = lookLast(lookInfo,lookList);
							if(match == false)
							{
								System.out.println("404 Your search did no match any records");
							}
							else
							{
								int numMatches = lookList.size();
								System.out.println("Found " + numMatches + " match(s)");
								for (int i = 0;i<lookList.size();i++)
								{
									lookList.get(i).printRecord();
								}
							}
							break;

							case "3":
							match = lookNumber(lookInfo,lookList);
							if(match == false)
							{
								System.out.println("404 Your search did no match any records");
							}
							else
							{
								int numMatches = lookList.size();
								System.out.println("Found " + numMatches + " match(s)");
								for (int i = 0;i<lookList.size();i++)
								{
									lookList.get(i).printRecord();
								}
							}
							break;

							default:
							System.out.println("Incorrect number given, give number 1-3");
							break;
						}

					}
					//Error handling if function in wrong format
					else
					{
						System.out.println("LOOK function in wrong format");
					}
					break;
				default:
					//Error handling that executes if the user enters in wrong command
					System.out.println("Incorrect Input");
					break;
			}


			// Broadcast it to everyone!  You will change this.  
			// Most commands do not need to broadcast
			for(int i = 0; i < handlers.size(); i++) 
			{	
				synchronized(handlers) 
				{
				ChildThread handler = (ChildThread)handlers.elementAt(i);
					if (handler != this) 
					{
						if(line.equals("SHUTDOWN"))
						{
							if(shuttingDown)
							{
								handler.out.println("210 Sever is about to shutdown. . . . . .");
								handler.out.flush();
								
							}
							// handler.in.close();
							// handler.out.close();
							// // handler.socket.close();
						}
						// handler.out.println(line); //Info from Client to Cleint
						// handler.out.flush();
					}
				}
			}
			if (shuttingDown)
			{
				for(int i = 0; i < handlers.size(); i++) 
				{	
					synchronized(handlers) 
					{
					ChildThread handler = (ChildThread)handlers.elementAt(i);
						
							handler.in.close();
							handler.out.close();
							handler.socket.close();

					}
				}
			}
		
	    }
	} 
	catch(IOException ioe) 
	{
	    ioe.printStackTrace();
	} 
	finally 
	{
	    try 
	    {
		in.close();
		out.close();
		socket.close();
	    } 
	    catch(IOException ioe) 
	    {
	    } 
	    finally 
	    {
		synchronized(handlers) 
		{
		    handlers.removeElement(this);
		}
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
				System.out.println("200 OK");
				System.out.println("The new Record ID is "+id);
				counter ++;
			}

	public static Boolean userLookUp(String userId,String userPass,String ip)
	{
		boolean isThere = false;
		for (int i = 0; i < recordList.size();i++)
		{
			//if the given username AND password match a record in book then client is logged on
			if(recordList.get(i).getFirst().equals(userId))
			{
				if(recordList.get(i).getPassword().equals(userPass))
				{
				isThere = true;
				recordList.get(i).setLogOn(true);
				recordList.get(i).setIpAddress(ip);
				currentUser = recordList.get(i).getFirst();
				}
			}
		}
		return isThere;
	}

	public static boolean lookFirst(String info,ArrayList<Record> lookList)
	{
		boolean match = false;
		for(int i = 0;i<recordList.size();i++)
		{
			if (recordList.get(i).getFirst().equals(info))
			{
				//adds all the records who first name match search name
				lookList.add(recordList.get(i));
				match = true;
			}
		}
		return match;
	}

	public static boolean lookLast(String info,ArrayList<Record> lookList)
	{
		boolean match = false;
		for(int i = 0;i<recordList.size();i++)
		{
			if (recordList.get(i).getLast().equals(info))
			{
				//adds all the records who last name match search name
				lookList.add(recordList.get(i));
				match = true;
			}
		}
		return match;
	}

	public static boolean lookNumber(String info,ArrayList<Record> lookList)
	{
		boolean match = false;
		for(int i = 0;i<recordList.size();i++)
		{
			if (recordList.get(i).getPhone().equals(info))
			{
				//adds all the records who phone number match search number
				lookList.add(recordList.get(i));
				match = true;
			}
		}
		return match;
	}

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
			for(int i = 0;i<recordList.size();i++)
			{
				recordList.get(i).printRecord();
			}
			}
		}
	public static void removeRecord(String id)
		{
			int realInt = Integer.parseInt(id);
			int index = -1;
			//Checks to see if record is in record book
			for(int i = 0;i < recordList.size();i++)
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
	public static void printFile(ArrayList<Record> list) throws IOException
		{
			Path fileName = Path.of("output.txt");
			String content = "";
			//gets the attributes of the added record and stores in string
			content = list.get(list.size()-1).getId() + "	" + list.get(list.size()-1).getFirst() + " " + list.get(list.size()-1).getLast()+ "		" + list.get(list.size()-1).getPhone() + "\n";			
			//Append this string to our "output.txt" file
			Files.writeString(fileName,content,StandardOpenOption.APPEND);		
		}
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
	public static void clearFile()throws IOException
		{
			Path fileName = Path.of("output.txt");
			Files.writeString(fileName,"");
		}
}

