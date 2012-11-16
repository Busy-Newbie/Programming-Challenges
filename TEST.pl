@numbers=();
$inp=<STDIN>;
while ($inp!=42)
{
	push(@numbers, $inp);
	$inp=<STDIN>;
}
while ($inp=shift(@numbers))
{
	print "$inp";
}
#print "@numbers";