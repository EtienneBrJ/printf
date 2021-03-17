/**
 * *_strcat - This function appends the src string to the dest string.
 * @dest: the destination string
 * @src: the source string
 *
 * Return: A pointer to the dest string
 */
char *_strcat(char *dest, char *src)
{
	char *pointer = dest;

	while (*dest != '\0')
		dest++;
	/* ^ iteration pour arriver au dernier charactère de la string dest */

	while (*src != '\0')
	{
		*dest = *src;
/* on est au début de la string src, et à la fin de la string dest */
/* ^l'index actuel de la string dest devient l'index actuel de la string src */
		src++;
		dest++;
	}
	*dest = '\0';
	return (pointer);
}
