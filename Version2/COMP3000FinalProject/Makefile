all: ConfigMonitor.o RealTimeMonitor.o Filesort.o
	gcc -o ConfigMonitor ConfigMonitor.o
	gcc -pthread -o RealTimeMonitor RealTimeMonitor.o
	gcc -o Filesort Filesort.o
	
MonitorAll.o: ConfigMonitor.c
	gcc -c ConfigMonitor.c

RealTimeMonitor.o: RealTimeMonitor.c
	gcc -c RealTimeMonitor.c

Filesort.o: Filesort.c
	gcc -c Filesort.c

clean:
	rm -f *.o ConfigMonitor RealTimeMonitor Filesort
