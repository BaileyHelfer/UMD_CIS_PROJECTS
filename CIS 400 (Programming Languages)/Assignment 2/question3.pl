use strict; use warnings; use feature 'say';

use autodie; # does `... or die "Can't open $file: $!"` for me

my $regex = qr/[A-Z0-9._%+-]+\@[A-Z0-9.-]+\.[edu]{2,4}/i;

my $found = 0;

my $contact_file = "IJCA_reviewer_list.txt";

my $email_file = "output.txt";

open my $contact, "<", $contact_file;

open my $email, ">", $email_file;

while (<$contact>) { # read from the $contact filehandle

while (/($regex)/g) { # the /g is optional if there is max one address per line

$found++;

say {$email} "$found:   $1"; # print to the $email file handle. {curlies} are optional.

}

}

die "No emails found\n" unless $found; # error message goes to STDERR, not to the file