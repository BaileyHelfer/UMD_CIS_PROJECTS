
//Record class to hold the data of each person in phonebook
public class Record {
	int id;
    String firstName;
    String lastName;
    String phoneNumber;
    String password;
    boolean loggedOn;
    String ipAddress;
    //Constructor for Record Class
    public Record(int struct_id,String nameFirst,String nameLast,String phone)
    {
        id = struct_id;
        firstName = nameFirst;
        lastName = nameLast;
        phoneNumber = phone;
        password = firstName + "01";
        loggedOn = false;
    }
    //Prints the record variables to server
    public void printRecord()
    {
    	System.out.println(id+ "	"+firstName+ " "+lastName+ "	"+phoneNumber);
    }
    //Returns the Id of the Record
    public int getId()
    {
    	return id;
    }
    //Returns the first name of the Record
    public String getFirst()
    {
    	return firstName;
    }
    //Returns the last name of the Record
    public String getLast()
    {
    	return lastName;
    }
    //Returns the phone number of the Record
    public String getPhone()
    {

    	return phoneNumber;
    }
    //Returns the password of Record
    public String getPassword()
    {
        return password;
    }
    //Sets the user to logged on
    public void setLogOn(boolean loginStatus)
    {
        loggedOn = loginStatus;
    }
    //Sets the ip address of the user
    public void setIpAddress(String currentIp)
    {
        ipAddress = currentIp;
    }
    //Returns if logged on or not
    public boolean getLoggedOn()
    {
        return loggedOn;
    }
    //Returns the IP adress of Record
    public String getIpAddress()
    {
        return ipAddress;
    }
}
