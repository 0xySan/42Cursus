#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *args[] = {"-lar", "/"}; // arg[0] = command puis arg[1] = fichier ou autre commande
	execve("/bin/ls", args, NULL); // (emplacement commande, argument, NULL)
}
