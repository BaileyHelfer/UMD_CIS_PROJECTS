
//Record class to hold the data of each person in phonebook
public class Record {
	int id;
    String firstName;
    String lastName;
    String phoneNumber;
    //Constructor for Record Class
    public Record(int struct_id,String nameFirst,String nameLast,String phone)
    {
        id = struct_id;
        firstName = nameFirst;
        lastName = nameLast;
        phoneNumber = phone;
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
}
