#!user/bin/perl

print "Enter card number: ";
$card = <>; 
chomp $card; 
print "Entered card number is: ",$card;
$cardLength = length($card);
$card = $card*1; 
while($card>0)
{
$n=int($card%10);
$rev=int($rev*10)+$n; 
$card=int($card/10);
  
}
$temp2=$rev%100;
while($temp2>0)
{
$n=int($temp2%10);
$rev2=int($rev2*10)+$n;
$temp2=int($temp2/10);
  
}

$temp4=$rev%10000;
while($temp4>0)
{
$n=int($temp4%10);
$rev4=int($rev4*10)+$n; 
$temp4=int($temp4/10);
  
}

if($cardLength==13)
{
if($rev%10==4) 
{
print "\n Card number valid: VISA.\n";
}
else
{
print "\n Invalid card number.";
}
}
elsif($cardLength==16) 
{

if($rev%10==4) 
{
print "\n Card number valid: VISA.\n";
}
elsif($rev2>=51 && $rev2<=55) 
{
print "\n Card number valid: Master Card.\n";
}
elsif($rev4==6011 || $rev4==65 ||$rev4 == 644)
{
print "\n Card number valid: Discover\n";
}
else
{
print "\n Invalid card number.";
}
}
elsif($cardLength==15) 
{
if($rev2==34 || $rev2==37)
{
print "\n Card number valid: American Express\n";
}
else
{
print "\n Invalid card number.";
}
}
else
{
print "\n Invalid card number.";
}
