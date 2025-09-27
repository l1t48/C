lab: huvud.o driv.o list.o
	gcc huvud.o driv.o  list.o  -o lab
    
huvud.o: node.h driv.h
	gcc -c huvud.c

driv.o: driv.h node.h list.h
	gcc -c driv.c
    
list.o: node.h list.h
	gcc -c list.c

clean:
	rm -f *.o
	rm -f lab
