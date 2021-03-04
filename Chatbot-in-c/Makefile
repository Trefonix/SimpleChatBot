chat: chatbot.o chatfunctions.o goodbye.o joke.o
	gcc -o chat chatbot.o chatfunctions.o goodbye.o joke.o

chatbot.o: chatbot.c chatfunctions.h
	gcc -c chatbot.c

chatfunctions.o: chatfunctions.c chatfunctions.h
	gcc -c chatfunctions.c

goodbye.o: goodbye.c goodbye.h
	gcc -c goodbye.c

joke.o: joke.c joke.h
	gcc -c joke.c

clean:
	-rm *.o *.gch chat
