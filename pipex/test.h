#ifndef TEST_H
# define TEST_H

# define CMD_PATH "/bin/" 

typedef struct s_pipex
{
	pid_t pid1;
	pid_t pid2;
	int tube[2];
	int infile;
	int outfile;
} t_pipex;

#endif
