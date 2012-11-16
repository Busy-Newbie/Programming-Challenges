#Busy Newbie got AC somehow :)
while True:
	a,b,c=raw_input().split()
	A,B,C=int(a),int(b),int(c)
	if (A==0 and B==0 and C==0): break
	if (B-A==C-B):print "AP %d"%(C+C-B)
	else:print "GP %d"%(C*C/B)