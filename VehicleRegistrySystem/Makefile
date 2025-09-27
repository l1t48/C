lab: main.o lab.o FileHandling.o
	gcc main.o lab.o  FileHandling.o  -o lab
    
main.o: 
	gcc -c main.c

FileHandling.o:
	gcc -c FileHandling.c
    
lab.o: lab.h
	gcc -c lab.c

clean:
	rm -f *.o
	rm -f lab
	rm -f saving_file.txt
