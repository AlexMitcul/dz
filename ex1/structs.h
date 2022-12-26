#ifndef STRUCTS_H
#define STRUCTS_H

typedef	struct s_word_info
{
	int	paragraph;
	int	sentence;
	int	position_in_sentence;
}				t_word_info;

typedef struct		s_word
{
	char			*value;
	int				count;
	t_word_info		*word_infos;
	struct s_word	*next;
}					t_word;

typedef struct s_dict
{
	int				length;
	int				words;
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
