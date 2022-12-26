#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct		s_word
{
	char			*value;
	int				count;
	struct s_word	*next;
}					t_word;

typedef struct s_dict
{
	t_word			*word;
}				t_dict;

typedef struct s_text_info
{
	int	characters_count;
	int	words_count;
	int	paragraph_count;
	int	sentences_count;
}			t_text_info;

#endif
