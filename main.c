#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "../libft/libft.h"

void print_error(const char *msg)
{
	printf("ERROR: %s\n", msg);
}

int	test_split(void)
{
	int i = 0;
	char **arr = ft_split("  word start ex  ", ' ');
	if (!arr)
		return (0);
	if (strcmp(arr[0], "word") != 0)
		return (0);
	if (strcmp(arr[1], "start") != 0)
		return (0);
	if (strcmp(arr[2], "ex") != 0)
		return (0);
	if (arr[3] != NULL)
		return (0);
	free(arr);
	return (1);
}
int test_atoi(void)
{
	const char *str = "\n +12352626";
	const char *str2 = "\v\n -9929112";
	if (atoi(str) != ft_atoi(str))
		return (0);
	if (atoi(str2) != ft_atoi(str2))
		return (0);
	return (1);
}

int test_itoa(void)
{
	char *s1 = ft_itoa(-1245186919); 
	char *s2 = ft_itoa(5186919); 
	if (strcmp(s1, "-1245186919") != 0)
		return (0);
	if (strcmp(s2, "5186919") != 0)
		return (0);
	free(s1);
	free(s2);
	return (1);
}

int test_calloc(void)
{
	void *ptr = ft_calloc(5, 100);
	void *ptr2 = calloc(5, 100);
	if (memcmp(ptr, ptr2, 5 * 100)) 
		return (0);
	free(ptr);
	free(ptr2);
	return (1);
}

int	test_strchr(void)
{
	const char *str = "bssgwhh";
	char c = 0;
	if (strchr(str, c) != ft_strchr(str, c))
		return (0);
	return (1);
}
int	test_strrchr(void)
{
	const char *str = "bssgwhh";
	char c = 'b';
	if (strrchr(str, c) != ft_strrchr(str, c))
		return (0);
	return (1);
}

int	test_strjoin(void)
{
	char *joined = ft_strjoin("join1", "join25151");
	if (strcmp(joined, "join1join25151") != 0)
		return (0);
	free(joined);
	return (1);
}

int	test_strtrim(void)
{
	char *s = ft_strtrim("strabcsttr", "str");
	if (strcmp(s, "abc") != 0)
		return (0);
	return (1);
}

int test_substr(void)
{
	char *sub = ft_substr("stringdatatest", 5, 3);

	if (strcmp(sub, "gda") != 0)
		return (0);
	free(sub);
	sub = ft_substr("ABCD", 818918, 0);
	if (strcmp(sub, "") != 0)
		return (0);
	free(sub);
	return (1);
}

int test_strdup(void)
{
	char	*to_dup = "stringtoduplicate";
	char *str = ft_strdup(to_dup);
	if (strcmp(str, to_dup) != 0)
		return (0);
	free(str);
	str = ft_strdup("");
	if (strcmp(str, "") != 0)
		return (0);
	free(str);
	return (1);
}

int test_strlcpy()
{
	char buf[256];
	char buf2[256];
	const char *str = "string copy";

	memset(buf, '1', 256);
	memset(buf2, '1', 256);
	if (ft_strlcpy(buf, str, 3) != strlcpy(buf2, str, 3))
		return (0);
	if (memcmp(buf, buf2, 256) != 0)
		return (0);
	return (1);
}

int test_strlcat()
{
	char buf[256] = "B";
	char buf2[256] = "B";

	if (ft_strlcat(buf, "AAAAAAAAA", 0) != strlcat(buf2, "AAAAAAAAA", 0))
		return (0);
	if (memcmp(buf, buf2, 256) != 0)
		return (0);
	return (1);
}

int test_strnstr(void)
{
	const char *haystack = "haystackstrngsada";
	const char *needle = "str";

	if (ft_strnstr(haystack, needle, sizeof(haystack) - 1) !=
		strnstr(haystack, needle, sizeof(haystack) - 1))
		return (0);
	return (1);
}

int bonus_cmp_list(t_list *lst)
{
	int i = 0;

	while (lst != NULL)
	{
		if (i == 0 && lst->content != NULL) 
			return (0);
		if (i == 1 && strcmp(lst->content, "c2") != 0)
			return (0);
		if (i == 2 && strcmp(lst->content, "c1") != 0)
			return (0);
		if (i == 3 && strcmp(lst->content, "c3") != 0)
			return (0);
		lst = lst->next;
		i++;
	}

	return (1);
}

/*
 * BONUS TESTS
 */

int bonus_flag = 0;

void bonus_del(void *p)
{
	bonus_flag++;
}

int test_bonus(void)
{
	char c1[] = "c1";
	char c2[] = "c2";
	char c3[] = "c3";
	char *c4 = NULL;
	t_list *n1 = ft_lstnew(c1);
	t_list *n2 = ft_lstnew(c2);
	t_list *n3 = ft_lstnew(c3);
	t_list *n4 = ft_lstnew(c4);
	if (!n1 || !n2 || !n3 || !n4)
		return (0);
	ft_lstadd_front(&n1, n2); 
	ft_lstadd_back(&n2, n3);
	ft_lstadd_front(&n2, n4);
	if (ft_lstsize(n2) != 4)
		return (0);
	if (!bonus_cmp_list(n2))
		return (0);
	ft_lstclear(&n2, bonus_del);
	if (n2 != NULL || bonus_flag != 4)
		return (0);
	return (1);
}

int main(void)
{
	if (!test_calloc())
		print_error("calloc");
	if (!test_strdup())
		print_error("strdup");
	if (!test_split())
		print_error("split");
	if (!test_atoi())
		print_error("atoi");
	if (!test_itoa())
		print_error("itoa");
	if (!test_strchr())
		print_error("strchr");
	if (!test_strrchr())
		print_error("strrchr");
	if (!test_strnstr())
		print_error("strnstr");
	if (!test_strlcpy())
		print_error("strlcpy");
	if (!test_strlcat())
		print_error("strlcat");
	if (!test_strjoin())
		print_error("strjoin");
	if (!test_strtrim())
		print_error("strtrim");
	if (!test_substr())
		print_error("substr");
	if (!test_bonus())
		print_error("bonus");
	printf("-- LIBFT TEST FINISHED --\n");
	return (0);
}
