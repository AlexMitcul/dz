#ifndef STRUCTS_H
#define STRUCTS_H

typedef	struct s_info
{
	int	paragraphs_count;
	int	sentences_count;
	int	words_count;
}		t_info;

typedef struct s_word
{
	int				repetition;
	char			*value;
	struct s_word	*next;
}					t_word;

#define DELIMETERS " \t\n,.:;'{}[]()!?/|\\@#$%^&*"

#endif
