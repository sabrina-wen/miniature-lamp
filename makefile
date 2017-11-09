all: batsignal.c
	gcc -o shmoop batsignal.c

run: all
	./shmoop
