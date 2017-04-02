#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 1024

void lower(char src[], char dst[])
{
	int i;
	for (i = 0; i <= strlen(src); i++)
		dst[i] = (char)tolower(src[i]);
}

void strfind(char fullpath[], char fileset[], char filename[], char strname[])
{
	FILE *fd;
	int i = 0, k = 0;
	char line[BUFF_SIZE];
	char tmp[BUFF_SIZE];

	if ((fd = fopen(fullpath, "r")) != NULL)
	{
		while (fgets(line, BUFF_SIZE, fd) != NULL)
		{
			lower(line, tmp);
			i++;
			if (strstr(tmp, strname) != NULL)
			{
				while (line[k] == ' ' || line[k] == '\t')
					k++;

				if (isAllowed(fileset))
					printf("%s:%d:%s", fileset, i, &line[k]);
			}
			k = 0;
			memset(line, 0, sizeof(line));
		}
	}
}
int isAllowed(char fileset[])
{
	int i;
	int len = strlen(fileset);

	while (fileset[len] != '.')
		len--;

	len++;
	if (!strcmp(&fileset[len], "bvh") || !strcmp(&fileset[len], "rb") || !strcmp(&fileset[len], "m") || !strcmp(&fileset[len], "cpp") ||
		!strcmp(&fileset[len], "c") || !strcmp(&fileset[len], "h") || !strcmp(&fileset[len], "hpp") || !strcmp(&fileset[len], "lua") ||
		!strcmp(&fileset[len], "inl") || !strcmp(&fileset[len], "py") || !strcmp(&fileset[len], "java") || !strcmp(&fileset[len], "tex") ||
		!strcmp(&fileset[len], "txt"))
	{
		return 1;
	}
	else
		return 0;
}

void filefind(char fileset[], char filename[], char strname[])
{
	int ie = 0;
	FILE *fp;
	char head[BUFF_SIZE];

	fp = popen("git rev-parse --show-toplevel", "r");
	fgets(head, BUFF_SIZE, fp);

	strcpy(&head[strlen(head) - 1], "/\n");
	if (strstr(fileset, filename) != NULL)
	{
		while (fileset[ie] == '.' || fileset[ie] == '/')
			ie++;
		fileset[strlen(fileset) - 1] = 0;
		strcpy(&head[strlen(head) - 1], &fileset[ie]);
		strfind(head, fileset, filename, strname);
	}
}

int main(int argc, char* argv[])
{
	char buff[BUFF_SIZE];
	FILE *fp;

	char fileset[BUFF_SIZE];
	char filename[BUFF_SIZE];
	char strname[BUFF_SIZE];

	lower(argv[2], filename); lower(argv[3], strname);

	fp = popen("git ls-files `git rev-parse --show-toplevel`", "r");

	printf("searching %s in %s ...\n", argv[3], argv[2]);
	while (fgets(buff, BUFF_SIZE, fp) != NULL)
	{
		lower(buff, fileset);
		filefind(fileset, filename, strname);
	}
	pclose(fp);
	return 0;
}