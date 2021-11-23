CC=javac

# The target
all: MultiThreadServer.class Client.class

# To generate the class files
MultiThreadServer.class: MultiThreadServer.java ChildThread.java
	$(CC) MultiThreadServer.java


Client.class: Client.java
	$(CC) Client.java

Client.class: Record.java
	$(CC) Record.java

# clean out the dross
clean:
	-rm *.class
