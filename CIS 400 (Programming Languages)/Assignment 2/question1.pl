#!user/bin/perl

print("Enter the IP Address to validate - ");
my $ip = <STDIN>;

my $char = ".";
my $count = () = $ip =~ /\Q$char/g;
print($count);
if ($count != 3)
{
    print("$ip is in INVALID format.")
}
elsif($ip =~ /(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})/)
{
   $ip = $1;
}

chomp($ip);
if($count !=3)
{
    if($ip =~ m/^(\d\d?\d?)\.(\d\d?\d?)\.(\d\d?\d?)\.(\d\d?\d?)$/)
    {
    print("\nIP address found - $ip\n");
    if($1 == 255 && $2 == 255 && $3 == 255 && $4 == 255)
        {
            print("This IP is not assignable. INVALID!")
        }
    elsif($1 <= 255 && $2 <= 255 && $3 <= 255 && $4 <= 255)
    {
        print("\n-> $ip IP address accepted!\n");
    }
    else
    {
        print("Octet(s) out of range. ",
            "Valid number range between 0-255\n");
    }
    }
    else
    {
    print("IP Address $ip is INVALID\n");
    }
}


