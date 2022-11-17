print ("Enter a number :");

my $number = <STDIN>;

chomp($number); my $newnumber = "0";

$newnumber += $_ * $_ for split//, $number;

print ($newnumber);